#!/usr/bin/env python3
import argparse
import os
import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
MANIFEST_DIR = ROOT / "config" / "assets"
GBAGFX = ROOT / "tools" / "gbagfx" / "gbagfx"
VERSIONS = ("us", "jp", "eu")
SOURCE_EXT = {"tiles4": "png", "tiles8": "png", "palette": "pal", "tilemap": "bin", "raw": "bin"}
BINARY_EXT = {"tiles4": "4bpp", "tiles8": "8bpp", "palette": "gbapal", "tilemap": "bin", "raw": "bin"}
INT_RE = re.compile(r"-?(0x[0-9A-Fa-f]+|\d+)$")
BARE_RE = re.compile(r"[A-Za-z0-9_./*\-+]+( [A-Za-z0-9_./*\-+]+)*$")


class ManifestError(Exception):
    pass


def parse_scalar(text):
    text = text.strip()
    if text in ("null", "~", ""):
        return None
    if text == "true":
        return True
    if text == "false":
        return False
    if INT_RE.match(text):
        return int(text, 0)
    if text[0] in "\"'":
        return text[1:-1]
    return text


def split_flow(text):
    parts, depth, cur = [], 0, ""
    for ch in text:
        if ch in "[{":
            depth += 1
        elif ch in "]}":
            depth -= 1
        if ch == "," and depth == 0:
            parts.append(cur)
            cur = ""
        else:
            cur += ch
    if cur.strip():
        parts.append(cur)
    return parts


def parse_flow(text):
    text = text.strip()
    if text.startswith("["):
        return [parse_flow(p) for p in split_flow(text[1:-1])]
    if text.startswith("{"):
        out = {}
        for part in split_flow(text[1:-1]):
            key, _sep, value = part.partition(":")
            out[key.strip()] = parse_flow(value)
        return out
    return parse_scalar(text)


def parse_block(lines, index, indent):
    out = None
    while index < len(lines):
        raw = lines[index]
        if not raw.strip():
            index += 1
            continue
        current = len(raw) - len(raw.lstrip(" "))
        if current < indent:
            break
        if current > indent:
            raise ManifestError(f"line {index + 1}: unexpected indentation")
        body = raw.strip()
        if body.startswith("- "):
            if out is None:
                out = []
            if not isinstance(out, list):
                raise ManifestError(f"line {index + 1}: sequence item inside a mapping")
            item = body[2:]
            if ":" in item and not item.startswith(("[", "{", "\"", "'")):
                lines[index] = " " * (indent + 2) + item
                value, index = parse_block(lines, index, indent + 2)
                out.append(value)
            else:
                out.append(parse_flow(item))
                index += 1
            continue
        if out is None:
            out = {}
        if not isinstance(out, dict):
            raise ManifestError(f"line {index + 1}: mapping key inside a sequence")
        key, sep, value = body.partition(":")
        if not sep:
            raise ManifestError(f"line {index + 1}: expected key: value")
        value = value.strip()
        if value:
            out[key.strip()] = parse_flow(value)
            index += 1
        else:
            nested, index = parse_block(lines, index + 1, indent + 2)
            out[key.strip()] = nested
    return out, index


def load_yaml(path):
    lines = Path(path).read_text().splitlines()
    value, index = parse_block(lines, 0, 0)
    if index != len(lines):
        raise ManifestError(f"{path}: trailing content at line {index + 1}")
    return value


def format_scalar(value, hex_keys=False):
    if value is None:
        return "null"
    if value is True:
        return "true"
    if value is False:
        return "false"
    if isinstance(value, int):
        return f"0x{value:08X}" if hex_keys else str(value)
    if BARE_RE.match(value) and not INT_RE.match(value) and value not in ("null", "true", "false", "~"):
        return value
    return "\"" + value.replace("\\", "\\\\").replace("\"", "\\\"") + "\""


HEX_KEYS = {"address", "start", "end"}


def format_flow(value, key=None):
    if isinstance(value, dict):
        return "{" + ", ".join(f"{k}: {format_flow(v, k)}" for k, v in value.items()) + "}"
    if isinstance(value, list):
        return "[" + ", ".join(format_flow(v, key) for v in value) + "]"
    return format_scalar(value, key in HEX_KEYS)


def is_flat(value):
    if isinstance(value, dict):
        return all(not isinstance(v, (dict, list)) or is_flat(v) for v in value.values()) and len(value) <= 24
    if isinstance(value, list):
        return all(not isinstance(v, (dict, list)) for v in value)
    return True


def dump_lines(value, indent, out, key=None):
    pad = " " * indent
    if isinstance(value, dict):
        for k, v in value.items():
            if isinstance(v, dict) and (not is_flat(v) or k in ("types", "objects", "fields") and indent == 0):
                out.append(f"{pad}{k}:")
                dump_lines(v, indent + 2, out, k)
            elif isinstance(v, list) and any(isinstance(x, (dict, list)) for x in v):
                out.append(f"{pad}{k}:")
                dump_lines(v, indent + 2, out, k)
            else:
                out.append(f"{pad}{k}: {format_flow(v, k)}")
    elif isinstance(value, list):
        for v in value:
            if isinstance(v, dict) and (not is_flat(v) or len(v) > 2):
                items = list(v.items())
                first_key, first_value = items[0]
                out.append(f"{pad}- {first_key}: {format_flow(first_value, first_key)}")
                rest = dict(items[1:])
                dump_lines(rest, indent + 2, out)
            else:
                out.append(f"{pad}- {format_flow(v, key)}")
    else:
        out.append(f"{pad}{format_flow(value, key)}")


def dump_yaml(value, path):
    out = []
    dump_lines(value, 0, out)
    Path(path).write_text("\n".join(out) + "\n")


class Manifest:
    def __init__(self, path):
        self.path = Path(path)
        doc = load_yaml(self.path)
        for key in ("group", "types", "objects", "entries"):
            if key not in doc:
                raise ManifestError(f"{self.path}: missing {key}")
        self.group = doc["group"]
        self.types = doc["types"]
        self.objects = doc["objects"]
        self.entries = doc["entries"]
        self.by_name = {}
        for entry in self.entries:
            if entry["name"] in self.by_name:
                raise ManifestError(f"{self.path}: duplicate entry {entry['name']}")
            self.by_name[entry["name"]] = entry

    def present(self, entry, version):
        return version in entry

    def symbol(self, entry, version):
        return entry[version].get("symbol", entry.get("symbol", entry["name"]))

    def size(self, entry, version):
        if "record" in entry:
            return record_size(self.types[entry["record"]], version)
        return entry[version]["size"]

    def fields(self, entry, version):
        fields = dict(entry.get("fields", {}))
        fields.update(entry[version].get("fields", {}))
        return fields

    def source(self, entry, version):
        if "record" in entry:
            return None
        return ROOT / "assets" / version / self.group / f"{entry['name']}.{SOURCE_EXT[entry['format']]}"

    def members(self, version):
        objects = self.objects.get(version, [])
        found = {obj["name"]: [] for obj in objects}
        for entry in self.entries:
            if version not in entry:
                continue
            address = entry[version]["address"]
            owner = [obj for obj in objects if obj["start"] <= address < obj["end"]]
            if len(owner) != 1:
                raise ManifestError(f"{self.group}: {entry['name']} is in {len(owner)} {version} objects")
            found[owner[0]["name"]].append(entry)
        for obj in objects:
            members = sorted(found[obj["name"]], key=lambda e: e[version]["address"])
            position = obj["start"]
            for entry in members:
                if entry[version]["address"] != position:
                    raise ManifestError(f"{self.group}: {obj['name']} has a gap before {entry['name']} at {position:#x} in {version}")
                position += self.size(entry, version)
            if position != obj["end"]:
                raise ManifestError(f"{self.group}: {obj['name']} ends at {position:#x}, not {obj['end']:#x}, in {version}")
            if obj["name"].endswith(".s") and any("record" in e for e in members):
                raise ManifestError(f"{self.group}: {obj['name']} holds records but is not a C object")
            found[obj["name"]] = members
        return found


def scalar_size(ctype):
    return {"u8": 1, "s8": 1, "u16": 2, "s16": 2, "u32": 4, "s32": 4}.get(ctype, 4 if ctype.endswith("*") else None)


def record_size(rtype, version):
    size, align = 0, 1
    for field in rtype["fields"]:
        if version not in field.get("versions", VERSIONS):
            continue
        width = scalar_size(field["type"])
        if width is None:
            raise ManifestError(f"unknown field type {field['type']}")
        size = (size + width - 1) // width * width
        size += width * field.get("count", 1)
        align = max(align, width)
    return (size + align - 1) // align * align


def load_manifests(directory=MANIFEST_DIR):
    return [Manifest(path) for path in sorted(Path(directory).glob("*.yaml"))]


def plan(version, manifests=None):
    manifests = load_manifests() if manifests is None else manifests
    out = {}
    for manifest in manifests:
        members = manifest.members(version)
        gen = ROOT / "build" / version / "gen"
        objects = {}
        for obj in manifest.objects.get(version, []):
            objects[obj["name"]] = {"source": gen / obj["name"], "members": members[obj["name"]]}
        sources = sorted({manifest.source(e, version) for e in manifest.entries
                          if version in e and "record" not in e}, key=str)
        binaries = sorted({gen / manifest.group / f"{e['name']}.{BINARY_EXT[e['format']]}"
                           for e in manifest.entries if version in e and "record" not in e}, key=str)
        out[manifest.group] = {"manifest": manifest, "objects": objects, "header": gen / f"{manifest.group}.h",
                               "sources": sources, "binaries": binaries}
    return out


def run_gbagfx(*args):
    subprocess.run([str(GBAGFX)] + [str(a) for a in args], check=True, stdout=subprocess.DEVNULL)


def gba_to_rgb(entry):
    return tuple(((entry >> shift) & 0x1F) * 255 // 31 for shift in (0, 5, 10))


def write_jasc(path, data):
    lines = ["JASC-PAL", "0100", str(len(data) // 2)]
    for offset in range(0, len(data), 2):
        entry = data[offset] | (data[offset + 1] << 8)
        lines.append("%d %d %d" % gba_to_rgb(entry))
    Path(path).write_text("\r\n".join(lines) + "\r\n")


def read_source(entry, source, tmp):
    fmt = entry["format"]
    if not source.exists():
        raise ManifestError(f"{source} is missing; run python3 tools/extract_assets.py")
    if fmt in ("palette", "tiles4", "tiles8"):
        out = tmp / f"{entry['name']}.{BINARY_EXT[fmt]}"
        run_gbagfx(source, out)
        return out.read_bytes()
    return source.read_bytes()


def compress(data, method, tmp, name):
    if method != "lz77":
        raise ManifestError(f"{name}: unsupported compression {method}")
    plain = tmp / f"{name}.plain"
    packed = tmp / f"{name}.plain.lz"
    plain.write_bytes(data)
    run_gbagfx(plain, packed)
    return packed.read_bytes()


def encode(manifest, entry, version, tmp, source=None):
    source = manifest.source(entry, version) if source is None else source
    data = read_source(entry, source, tmp)
    method = entry[version].get("compress")
    if method:
        data = compress(data, method, tmp, entry["name"])
    if len(data) != entry[version]["size"]:
        raise ManifestError(f"{entry['name']}: {version} source encodes to {len(data)} bytes, manifest says {entry[version]['size']}")
    return data


def decode_one(manifest, entry, version, data, tmp, palette_bytes):
    fmt = entry["format"]
    method = entry[version].get("compress")
    if method == "lz77":
        packed = tmp / f"{entry['name']}.bin.lz"
        plain = tmp / f"{entry['name']}.bin"
        packed.write_bytes(data)
        run_gbagfx(packed, plain)
        data = plain.read_bytes()
    elif method:
        raise ManifestError(f"{entry['name']}: unsupported compression {method}")
    if fmt in ("tilemap", "raw"):
        return data
    if fmt == "palette":
        out = tmp / f"{entry['name']}.pal"
        write_jasc(out, data)
        return out.read_bytes()
    depth = 4 if fmt == "tiles4" else 8
    unit = 32 if depth == 4 else 64
    if len(data) % unit:
        raise ManifestError(f"{entry['name']}: {len(data)} bytes is not a whole number of {depth}bpp tiles")
    tiles = len(data) // unit
    width = entry.get("width", 1)
    if tiles % width:
        raise ManifestError(f"{entry['name']}: width {width} does not divide {tiles} tiles")
    colors = 16 if depth == 4 else 256
    pal_path = tmp / f"{entry['name']}.hint.gbapal"
    pal_path.write_bytes((palette_bytes + bytes(colors * 2))[:colors * 2])
    raw = tmp / f"{entry['name']}.{BINARY_EXT[fmt]}"
    png = tmp / f"{entry['name']}.png"
    raw.write_bytes(data)
    run_gbagfx(raw, png, "-width", width, "-palette", pal_path)
    return png.read_bytes()


def decode(manifest, version, rom, rom_base=0x08000000):
    written = checked = 0

    def rom_bytes(entry):
        address, size = entry[version]["address"], entry[version]["size"]
        data = rom[address - rom_base:address - rom_base + size]
        if len(data) != size:
            raise ManifestError(f"{entry['name']}: {version} extent is outside the ROM")
        return data

    with tempfile.TemporaryDirectory() as tmpdir:
        tmp = Path(tmpdir)
        probe_dir = tmp / "probe"
        probe_dir.mkdir()
        for entry in manifest.entries:
            if "record" in entry or version not in entry:
                continue
            data = rom_bytes(entry)
            palette = manifest.by_name.get(entry.get("palette"))
            palette_bytes = rom_bytes(palette) if palette is not None and version in palette else b""
            decoded = decode_one(manifest, entry, version, data, tmp, palette_bytes)
            source = manifest.source(entry, version)
            probe = probe_dir / source.name
            probe.write_bytes(decoded)
            if encode(manifest, entry, version, tmp, probe) != data:
                raise ManifestError(f"{entry['name']}: {version} {entry['format']} source does not re-encode to the ROM bytes")
            checked += 1
            if not source.exists() or source.read_bytes() != decoded:
                source.parent.mkdir(parents=True, exist_ok=True)
                source.write_bytes(decoded)
                written += 1
    return checked, written


def field_versions(field):
    return field.get("versions", list(VERSIONS))


def c_value(manifest, resolve, field, value):
    ctype = field["type"]
    if field.get("count"):
        return "{ " + ", ".join(str(v) for v in value) + " }"
    if ctype.endswith("*"):
        if value == 0 or value is None:
            return "0"
        return f"({ctype}){resolve(value)}"
    return str(value)


def emit_c(manifest, version, members, out_path, all_manifests):
    lookup = {}
    for other in all_manifests:
        for entry in other.entries:
            if version in entry:
                lookup[entry["name"]] = other.symbol(entry, version)

    def resolve(name):
        return lookup.get(name, name)

    defined = {manifest.symbol(e, version) for e in members}
    referenced = set()
    for entry in members:
        if "record" not in entry:
            continue
        rtype = manifest.types[entry["record"]]
        fields = manifest.fields(entry, version)
        for field in rtype["fields"]:
            if version not in field_versions(field) or not field["type"].endswith("*"):
                continue
            value = fields[field["name"]]
            if value not in (0, None):
                referenced.add(resolve(value))
    lines = []
    headers = sorted({manifest.types[e["record"]]["header"] for e in members if "record" in e})
    for header in headers:
        lines.append(f'#include "{header}"')
    lines.append("")
    for name in sorted(referenced - defined):
        lines.append(f"extern u8 {name}[];")
    if referenced - defined:
        lines.append("")
    for entry in members:
        symbol = manifest.symbol(entry, version)
        if "record" not in entry:
            lines.append(f"extern const u8 {symbol}[{manifest.size(entry, version)}];")
    if any("record" not in e for e in members):
        lines.append("")
    for entry in members:
        symbol = manifest.symbol(entry, version)
        if "record" in entry:
            rtype = manifest.types[entry["record"]]
            fields = manifest.fields(entry, version)
            lines.append(f"const {entry['record']} {symbol} = {{")
            for field in rtype["fields"]:
                if version not in field_versions(field):
                    continue
                lines.append(f"    {c_value(manifest, resolve, field, fields[field['name']])},")
            lines.append("};")
        else:
            data = manifest.source(entry, version).read_bytes()
            if entry["format"] != "raw" or entry[version].get("compress"):
                raise ManifestError(f"{entry['name']}: only raw entries may sit inside a C object")
            if len(data) != entry[version]["size"]:
                raise ManifestError(f"{entry['name']}: {version} source is {len(data)} bytes, manifest says {entry[version]['size']}")
            lines.append(f"const u8 {symbol}[{len(data)}] = {{")
            for offset in range(0, len(data), 24):
                chunk = data[offset:offset + 24]
                lines.append("    " + ", ".join(str(b) for b in chunk) + ",")
            lines.append("};")
        lines.append("")
    write_if_changed(out_path, "\n".join(lines).rstrip("\n") + "\n")


def emit_s(manifest, version, members, out_path, tmp):
    lines = ["\t.section .rodata"]
    for entry in members:
        symbol = manifest.symbol(entry, version)
        binary = ROOT / "build" / version / "gen" / manifest.group / f"{entry['name']}.{BINARY_EXT[entry['format']]}"
        data = encode(manifest, entry, version, tmp)
        binary.parent.mkdir(parents=True, exist_ok=True)
        write_if_changed(binary, data)
        lines.append(f"\t.global {symbol}")
        lines.append(f"{symbol}:")
        lines.append(f'\t.incbin "{binary.relative_to(ROOT).as_posix()}"')
    write_if_changed(out_path, "\n".join(lines) + "\n")


def emit_header(manifest, version, members_by_object, out_path):
    guard = "GUARD_GEN_" + manifest.group.upper() + "_H"
    lines = [f"#ifndef {guard}", f"#define {guard}", ""]
    headers = sorted({manifest.types[e["record"]]["header"] for members in members_by_object.values()
                      for e in members if "record" in e})
    if not headers:
        headers = ["types.h"]
    for header in headers:
        lines.append(f'#include "{header}"')
    lines.append("")
    for name, members in members_by_object.items():
        for entry in members:
            symbol = manifest.symbol(entry, version)
            if "record" in entry:
                lines.append(f"extern const {entry['record']} {symbol};")
            elif name.endswith(".s"):
                lines.append(f"extern u8 {symbol}[{entry[version]['size']}];")
    lines += ["", "#endif"]
    write_if_changed(out_path, "\n".join(lines) + "\n")


def write_if_changed(path, content):
    path = Path(path)
    data = content if isinstance(content, bytes) else content.encode()
    if path.exists() and path.read_bytes() == data:
        return
    path.parent.mkdir(parents=True, exist_ok=True)
    tmp = path.with_name(path.name + ".tmp")
    tmp.write_bytes(data)
    os.replace(tmp, path)


def check_symbols(manifest, version, members_by_object):
    ledger = set()
    for line in (ROOT / "config" / version / "symbols.txt").read_text().splitlines():
        line = line.split("#")[0].strip()
        if line:
            ledger.add(line.split("=")[0].strip())
    clashes = sorted(manifest.symbol(e, version) for members in members_by_object.values()
                     for e in members if manifest.symbol(e, version) in ledger)
    if clashes:
        raise ManifestError(f"{manifest.group}: {version} symbols.txt still defines {', '.join(clashes[:5])}")


def generate(version, manifest_path, all_manifests=None):
    manifest = Manifest(manifest_path)
    all_manifests = load_manifests() if all_manifests is None else all_manifests
    members_by_object = manifest.members(version)
    if not GBAGFX.exists():
        raise ManifestError(f"{GBAGFX.relative_to(ROOT)} is missing; run sh tools/fetch_gbagfx.sh")
    check_symbols(manifest, version, members_by_object)
    gen = ROOT / "build" / version / "gen"
    gen.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory() as tmpdir:
        tmp = Path(tmpdir)
        for name, members in members_by_object.items():
            if name.endswith(".c"):
                emit_c(manifest, version, members, gen / name, all_manifests)
            else:
                emit_s(manifest, version, members, gen / name, tmp)
    emit_header(manifest, version, members_by_object, gen / f"{manifest.group}.h")


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("version", choices=VERSIONS)
    parser.add_argument("manifest")
    args = parser.parse_args()
    try:
        generate(args.version, args.manifest)
    except (ManifestError, subprocess.CalledProcessError) as error:
        sys.exit(f"error: {error}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
