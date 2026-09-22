#!/usr/bin/env python3
import argparse
import hashlib
import os
import re
import subprocess
import sys
from pathlib import Path

import yaml

import assetgen
import baserom

YAML_LOADER = getattr(yaml, "CSafeLoader", yaml.SafeLoader)


def load_yaml(text):
    return yaml.load(text, Loader=YAML_LOADER)

ROOT = baserom.ROOT
ROM_BASE = 0x08000000
ROM_LIMIT = 0x0A000000
COMMON = {"assets/common/movie_codec.bin": ("gUnk_081196B4", 15100)}
LEGACY_COMMON = {"asm/movie_codec.bin": "assets/common/movie_codec.bin"}
KEEP = {"manifest.yaml", ".stamp", ".gitkeep"}

DIRECTIVE_RE = re.compile(r'^[^@\n]*?\.(include|incbin)\s+"([^"]+)"([^@\n]*)', re.M)
ROM_INCBIN_RE = re.compile(r'^(\s*)\.incbin\s+"roms/([A-Z0-9]{4})\.gba"\s*,\s*([^,\s]+)\s*,\s*([^,\s]+)\s*$')
LEGACY_COMMON_RE = re.compile(r'(\.incbin\s+)"(' + "|".join(re.escape(k) for k in LEGACY_COMMON) + r')"')
RANGE_RE = re.compile(r'assets/([a-z]+)/([0-9A-F]{8})-([0-9A-F]{8})\.bin')


class AssetError(Exception):
    pass


def asset_path(version, start, end):
    return f"assets/{version}/{start:08X}-{end:08X}.bin"


def migrate_line(line, codes):
    body = line.rstrip("\r\n")
    ending = line[len(body):]
    m = ROM_INCBIN_RE.match(body)
    if m:
        indent, code, offset, size = m.groups()
        if code not in codes:
            raise AssetError(f"unknown ROM code {code} in {body.strip()}")
        start = ROM_BASE + int(offset, 0)
        end = start + int(size, 0)
        return f'{indent}.incbin "{asset_path(codes[code], start, end)}"{ending}'
    return LEGACY_COMMON_RE.sub(lambda c: f'{c.group(1)}"{LEGACY_COMMON[c.group(2)]}"', line)


def migrate_text(text, codes):
    lines = text.splitlines(keepends=True)
    out = [migrate_line(line, codes) for line in lines]
    return "".join(out), sum(a != b for a, b in zip(lines, out))


def migrate(root=ROOT):
    root = Path(root)
    codes = {code: name for name, (code, _sha1) in baserom.versions(root).items()}
    files = sorted(p for p in (root / "asm" / "us").rglob("*") if p.suffix in {".s", ".inc"})
    files += sorted(p for p in (root / "asm").glob("*") if p.is_file() and p.suffix in {".s", ".inc"})
    changed = lines = 0
    for path in files:
        text = path.read_text()
        new, count = migrate_text(text, codes)
        if count:
            path.write_text(new)
            changed += 1
            lines += count
    return changed, lines


def generated_units(root):
    return {obj["name"] for manifest in assetgen.load_manifests(root / "config" / "assets")
            for objects in manifest.objects.values() for obj in objects}


def unit_roots(root, version):
    roots = []
    generated = generated_units(root)
    for line in (root / "config" / version / "units.txt").read_text().splitlines():
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        name = line.split(None, 1)[0]
        if name.startswith("@") or name in generated:
            continue
        if name.endswith(".c"):
            continue
        src = root / "asm" / version / name
        roots.append(src if src.exists() else root / "asm" / name)
    return roots


def reachable(root, version):
    search = [root, root / "include"]
    order = []
    seen = set()
    stack = list(reversed(unit_roots(root, version)))
    while stack:
        cur = stack.pop()
        if cur in seen:
            continue
        if not cur.exists():
            raise AssetError(f"{cur.relative_to(root)} is linked by config/{version}/units.txt but does not exist")
        seen.add(cur)
        order.append(cur)
        found = []
        for kind, ref, _rest in DIRECTIVE_RE.findall(cur.read_text()):
            if kind != "include":
                continue
            target = next((base / ref for base in search if (base / ref).exists()), None)
            if target is None:
                raise AssetError(f"{cur.relative_to(root)} includes missing {ref}")
            found.append(target)
        stack.extend(reversed(found))
    return order


def symbol_address(root, version, name):
    for line in (root / "config" / version / "symbols.txt").read_text().splitlines():
        left, _sep, right = line.split("#", 1)[0].partition("=")
        if left.strip() == name:
            return int(right.strip(), 16)
    raise AssetError(f"{name} is missing from config/{version}/symbols.txt")


def plan(root, version):
    root = Path(root)
    known = baserom.versions(root)
    sites = {}
    ranges = {}
    for asm in reachable(root, version):
        where = asm.relative_to(root)
        for kind, ref, rest in DIRECTIVE_RE.findall(asm.read_text()):
            if kind != "incbin":
                continue
            if not ref.startswith("assets/"):
                raise AssetError(f"{where} incbins {ref}; asm may only incbin extracted assets/ files")
            m = RANGE_RE.fullmatch(ref)
            if m:
                if m.group(1) not in known:
                    raise AssetError(f"{where} incbins {ref} for an unknown version")
                if m.group(1) != version:
                    raise AssetError(f"{where} incbins {ref}, which belongs to {m.group(1)}")
                if rest.strip():
                    raise AssetError(f"{where} incbins part of {ref}; an address-named asset is included whole")
                if ref in sites:
                    raise AssetError(f"{ref} is incbinned by both {sites[ref]} and {where}")
                start, end = int(m.group(2), 16), int(m.group(3), 16)
            elif ref in COMMON:
                if ref in ranges:
                    continue
                name, size = COMMON[ref]
                start = symbol_address(root, version, name)
                end = start + size
            else:
                raise AssetError(f"{where} incbins unknown asset {ref}")
            if not ROM_BASE <= start < end <= ROM_LIMIT:
                raise AssetError(f"{where}: {ref} is not a range inside the ROM")
            sites[ref] = where
            ranges[ref] = (start, end)
    check_overlaps(ranges)
    return ranges


def check_overlaps(ranges):
    spans = sorted((start, end, ref) for ref, (start, end) in ranges.items())
    for (_s1, e1, a), (s2, _e2, b) in zip(spans, spans[1:]):
        if e1 > s2:
            raise AssetError(f"{a} overlaps {b}")


def write_if_changed(path, data):
    path = Path(path)
    if path.exists() and path.read_bytes() == data:
        return False
    path.parent.mkdir(parents=True, exist_ok=True)
    tmp = path.with_name(path.name + ".tmp")
    tmp.write_bytes(data)
    os.replace(tmp, path)
    return True


def manifest_bytes(version, code, sha1, entries):
    document = {"version": version, "code": code, "rom_sha1": sha1, "files": entries}
    return yaml.safe_dump(document, sort_keys=True).encode()


def decoded_sources(root, version):
    root = Path(root)
    refs = {}
    for manifest in assetgen.load_manifests(root / "config" / "assets"):
        for entry in manifest.entries:
            if "record" in entry or version not in entry:
                continue
            refs[manifest.source(entry, version).relative_to(root).as_posix()] = manifest
    return refs


def decode(root, version, rom):
    root = Path(root)
    checked = written = 0
    try:
        for manifest in assetgen.load_manifests(root / "config" / "assets"):
            done, wrote = assetgen.decode(manifest, version, rom)
            checked += done
            written += wrote
    except (assetgen.ManifestError, subprocess.CalledProcessError) as error:
        raise AssetError(str(error))
    return checked, written


def write_manifest(root, version, ranges):
    root = Path(root)
    _name, code, sha1 = baserom.resolve(version, root)
    entries = {}
    for ref, (start, end) in sorted(ranges.items()):
        data = (root / ref).read_bytes()
        entries[ref] = {"start": f"{start:#010x}", "end": f"{end:#010x}", "sha256": hashlib.sha256(data).hexdigest()}
    for ref in sorted(decoded_sources(root, version)):
        path = root / ref
        if not path.exists():
            raise AssetError(f"{ref} was not decoded")
        entries[ref] = {"sha256": hashlib.sha256(path.read_bytes()).hexdigest()}
    manifest = manifest_bytes(version, code, sha1, entries)
    write_if_changed(root / "assets" / version / "manifest.yaml", manifest)
    write_if_changed(root / "assets" / version / ".stamp", (hashlib.sha256(manifest).hexdigest() + "\n").encode())
    return entries


def extract(root, version, rom):
    root = Path(root)
    _name, code, _sha1 = baserom.resolve(version, root)
    ranges = plan(root, version)
    written = total = 0
    for ref, (start, end) in sorted(ranges.items()):
        if end - ROM_BASE > len(rom):
            raise AssetError(f"{ref} ends past the {len(rom):#x}-byte {code} ROM")
        data = rom[start - ROM_BASE:end - ROM_BASE]
        written += write_if_changed(root / ref, data)
        total += end - start
    return ranges, written, total


def verify(root, version):
    root = Path(root)
    ranges = plan(root, version)
    manifest_path = root / "assets" / version / "manifest.yaml"
    if not manifest_path.exists():
        return [f"{manifest_path.relative_to(root)} is missing"]
    manifest = manifest_path.read_bytes()
    entries = load_yaml(manifest)["files"]
    problems = []
    for ref, (start, end) in sorted(ranges.items()):
        entry = entries.get(ref)
        path = root / ref
        if entry is None:
            problems.append(f"{ref} is not in the manifest")
        elif (int(entry["start"], 16), int(entry["end"], 16)) != (start, end):
            problems.append(f"{ref} has a different range in the manifest")
        elif not path.exists():
            problems.append(f"{ref} is missing")
        elif hashlib.sha256(path.read_bytes()).hexdigest() != entry["sha256"]:
            problems.append(f"{ref} differs from the manifest")
    sources = decoded_sources(root, version)
    for ref in sorted(sources):
        entry = entries.get(ref)
        path = root / ref
        if entry is None:
            problems.append(f"{ref} is not in the manifest")
        elif not path.exists():
            problems.append(f"{ref} is missing")
        elif hashlib.sha256(path.read_bytes()).hexdigest() != entry["sha256"]:
            problems.append(f"{ref} differs from the manifest")
    problems += [f"{ref} is in the manifest but nothing uses it" for ref in sorted(set(entries) - set(ranges) - set(sources))]
    stamp = root / "assets" / version / ".stamp"
    if not stamp.exists() or stamp.read_text().strip() != hashlib.sha256(manifest).hexdigest():
        problems.append(f"{stamp.relative_to(root)} does not match the manifest")
    return problems


def prune(root, version, keep):
    root = Path(root)
    directory = root / "assets" / version
    removed = 0
    if not directory.is_dir():
        return removed
    for path in sorted(directory.rglob("*")):
        if not path.is_file() or path.name in KEEP:
            continue
        if path.relative_to(root).as_posix() not in keep:
            path.unlink()
            removed += 1
    return removed


def main():
    known = baserom.versions()
    parser = argparse.ArgumentParser()
    parser.add_argument("versions", nargs="*", metavar="version")
    parser.add_argument("--verify", action="store_true")
    parser.add_argument("--decode", action="store_true")
    parser.add_argument("--prune", action="store_true")
    parser.add_argument("--migrate", action="store_true")
    args = parser.parse_args()
    unknown = [v for v in args.versions if v not in known]
    if unknown:
        parser.error(f"unknown version {unknown[0]}; expected one of {', '.join(known)}")
    try:
        if args.migrate:
            changed, lines = migrate(ROOT)
            print(f"migrated {lines} incbin lines in {changed} files")
            return 0
        if args.verify:
            chosen = args.versions or [v for v in known if (ROOT / "assets" / v / "manifest.yaml").exists()]
            if not chosen:
                raise AssetError("nothing to verify; run python3 tools/extract_assets.py first")
            failed = False
            for version in chosen:
                problems = verify(ROOT, version)
                for problem in problems:
                    print(f"{version}: {problem}")
                print(f"{version}: {'FAILED' if problems else 'OK'}")
                failed |= bool(problems)
            return 1 if failed else 0
        chosen = args.versions or [v for v in known if any(p.exists() for p in baserom.candidates(v))]
        if not chosen:
            codes = ", ".join(f"roms/{code}.gba" for code, _sha1 in known.values())
            raise AssetError(f"no ROM found; put at least one of {codes} in place")
        for version in chosen:
            source, rom = baserom.load(version)
            if source is None:
                raise AssetError(baserom.missing_message(version, purpose="extraction").removeprefix("error: "))
            if args.decode:
                ranges = plan(ROOT, version)
                written = total = 0
            else:
                ranges, written, total = extract(ROOT, version, rom)
            checked, decoded = decode(ROOT, version, rom)
            entries = write_manifest(ROOT, version, ranges)
            pruned = prune(ROOT, version, set(entries)) if args.prune else 0
            print(f"{version}: {len(ranges)} files, {total} bytes, {written} written, {checked} sources checked,"
                  f" {decoded} decoded, {pruned} pruned, from {source.relative_to(ROOT)}")
    except AssetError as error:
        sys.exit(f"error: {error}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
