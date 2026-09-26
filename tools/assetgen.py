#!/usr/bin/env python3
import argparse
import os
import subprocess
import sys
import tempfile
from pathlib import Path

import yaml

import sprite_sheet

YAML_LOADER = getattr(yaml, "CSafeLoader", yaml.SafeLoader)


def load_yaml(text):
    return yaml.load(text, Loader=YAML_LOADER)

ROOT = Path(__file__).resolve().parent.parent
MANIFEST_DIR = ROOT / "config" / "assets"
GBAGFX = ROOT / "tools" / "gbagfx" / "gbagfx"
VERSIONS = ("us", "jp", "eu")
SOURCE_EXT = {"tiles4": "png", "tiles8": "png", "palette": "pal", "tilemap": "bin", "raw": "bin", "sprite_sheet": "png"}
BINARY_EXT = {"tiles4": "4bpp", "tiles8": "8bpp", "palette": "gbapal", "tilemap": "bin", "raw": "bin",
              "sprite_sheet": "4bpp"}
ASM_KINDS = ("sprite", "anim")


class ManifestError(Exception):
    pass


class Manifest:
    def __init__(self, path):
        self.path = Path(path)
        with self.path.open() as handle:
            doc = load_yaml(handle)
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

    def kind(self, entry):
        if "record" not in entry:
            return None
        return self.types[entry["record"]].get("kind", "struct")

    def data(self, entry, version, key):
        return entry[version].get(key, entry.get(key))

    def size(self, entry, version):
        kind = self.kind(entry)
        if kind is None:
            return entry[version]["size"]
        if kind == "struct":
            return record_size(self.types[entry["record"]], version)
        if kind == "table":
            return 4 * len(self.data(entry, version, "items"))
        if kind == "sprite":
            count = len(self.data(entry, version, "oam"))
            return 2 + 6 * count + (2 if count else 0)
        if kind == "anim":
            return 6 + 4 * len(self.data(entry, version, "frames"))
        raise ManifestError(f"{self.group}: unknown record kind {kind}")

    def fields(self, entry, version):
        fields = dict(entry.get("fields", {}))
        fields.update(entry[version].get("fields", {}))
        return fields

    def source(self, entry, version):
        if "record" in entry:
            return None
        return ROOT / "assets" / version / self.group / f"{entry['name']}.{SOURCE_EXT[entry['format']]}"

    def binary(self, entry, version):
        if "record" in entry or entry.get("tiles"):
            return None
        return ROOT / "build" / version / "gen" / self.group / f"{entry['name']}.{BINARY_EXT[entry['format']]}"

    def sources(self, entry, version):
        source = self.source(entry, version)
        if source is None:
            return []
        if entry["format"] == "sprite_sheet" and sprite_sheet.layer_count(self.sheet(entry, version)) > 1:
            return [source, source.with_name(f"{entry['name']}.layers.png")]
        return [source]

    def frames(self, entry, version):
        return self.data(entry, version, "frames")

    def animations(self, entry, version):
        return self.data(entry, version, "animations")

    def item_symbol(self, item, version):
        return item.get(version, {}).get("symbol", item["symbol"])

    def sheet(self, entry, version):
        try:
            return {"cell": self.data(entry, version, "cell"), "anchor": self.data(entry, version, "anchor"),
                    "columns": self.data(entry, version, "columns"),
                    "frames": [[sprite_sheet.piece_from_yaml(piece) for piece in frame["pieces"]]
                               for frame in self.frames(entry, version)]}
        except sprite_sheet.SheetError as error:
            raise ManifestError(f"{self.group}: {entry['name']}: {error}")

    def names(self, entry, version):
        if entry.get("format") != "sprite_sheet":
            return {}
        items = self.frames(entry, version) + self.animations(entry, version)
        return {item["symbol"]: self.item_symbol(item, version) for item in items}

    def symbols(self, entry, version):
        if entry.get("format") != "sprite_sheet":
            return [self.symbol(entry, version)]
        block = [] if entry.get("tiles") else [self.symbol(entry, version)]
        return list(self.names(entry, version).values()) + block

    def anim_type(self):
        names = [name for name, rtype in self.types.items() if rtype.get("kind") == "anim"]
        if not names:
            raise ManifestError(f"{self.group}: a sprite sheet with animations needs an anim record type")
        return names[0]

    def members(self, version):
        objects = self.objects.get(version, [])
        found = {obj["name"]: [] for obj in objects}
        for entry in self.entries:
            if version not in entry:
                continue
            address = entry[version]["address"]
            owner = [obj for obj in objects if any(lo <= address < hi for lo, hi, _data in spans(obj))]
            if len(owner) != 1:
                raise ManifestError(f"{self.group}: {entry['name']} is in {len(owner)} {version} objects")
            found[owner[0]["name"]].append(entry)
        for obj in objects:
            members = sorted(found[obj["name"]], key=lambda e: e[version]["address"])
            for lo, hi, data in spans(obj):
                position = lo
                for entry in members:
                    if not lo <= entry[version]["address"] < hi:
                        continue
                    position = aligned(position, entry)
                    if entry[version]["address"] != position:
                        raise ManifestError(f"{self.group}: {obj['name']} has a gap before {entry['name']} at {position:#x} in {version}")
                    position += self.size(entry, version)
                    kind = self.kind(entry)
                    if "data_start" in obj and (kind == "table") != data:
                        raise ManifestError(f"{self.group}: {obj['name']} holds {entry['name']} in its {'.data' if data else 'payload'} range, which takes {'only' if data else 'no'} table records")
                    if obj["name"].endswith(".c") and entry.get("format") == "sprite_sheet":
                        raise ManifestError(f"{self.group}: {obj['name']} holds sprite sheet {entry['name']} but is not an assembler object")
                    if obj["name"].endswith(".s") and (kind == "struct" or kind == "table" and not data):
                        raise ManifestError(f"{self.group}: {obj['name']} holds a {kind} record but is not a C object")
                    if obj["name"].endswith(".c") and kind in ASM_KINDS:
                        raise ManifestError(f"{self.group}: {obj['name']} holds a {kind} record but is not an assembler object")
                if not position <= hi < position + 4:
                    raise ManifestError(f"{self.group}: {obj['name']} ends at {position:#x}, not {hi:#x}, in {version}")
            found[obj["name"]] = members
        return found


def spans(obj):
    out = [(obj["start"], obj["end"], False)]
    if "data_start" in obj:
        out.append((obj["data_start"], obj["data_end"], True))
    return out


def in_data(obj, entry, version):
    return "data_start" in obj and obj["data_start"] <= entry[version]["address"] < obj["data_end"]


def aligned(position, entry):
    align = entry.get("align", 1)
    return (position + align - 1) // align * align


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


def entry_lookup(manifests):
    lookup = {}
    for manifest in manifests:
        for entry in manifest.entries:
            if entry["name"] in lookup:
                raise ManifestError(f"{manifest.group}: {entry['name']} is also an entry of {lookup[entry['name']].group}")
            lookup[entry["name"]] = manifest
    return lookup


def lender(lookup, entry, version):
    name = entry["tiles"]
    if name not in lookup or version not in lookup[name].by_name[name]:
        raise ManifestError(f"{entry['name']}: borrows tiles from {name}, which has no {version} entry")
    owner = lookup[name]
    target = owner.by_name[name]
    if target.get("tiles") or target.get("format") not in ("tiles4", "sprite_sheet") or target[version].get("compress"):
        raise ManifestError(f"{entry['name']}: {name} is not an uncompressed tile block of its own")
    return owner, target


def plan(version, manifests=None):
    manifests = load_manifests() if manifests is None else manifests
    lookup = {e["name"]: m for m in manifests for e in m.entries}
    out = {}
    for manifest in manifests:
        members = manifest.members(version)
        gen = ROOT / "build" / version / "gen"
        objects = {}
        for obj in manifest.objects.get(version, []):
            objects[obj["name"]] = {"source": gen / obj["name"], "members": members[obj["name"]],
                                    "binaries": [manifest.binary(e, version) for e in members[obj["name"]]
                                                 if manifest.binary(e, version) is not None]}
        sources = {path for e in manifest.entries if version in e and "record" not in e
                   for path in manifest.sources(e, version)}
        for e in manifest.entries:
            if version in e and e.get("format") == "sprite_sheet" and e.get("tiles"):
                owner, target = lender(lookup, e, version)
                sources.update(owner.sources(target, version))
        sources = sorted(sources, key=str)
        binaries = sorted({manifest.binary(e, version) for e in manifest.entries
                           if version in e and manifest.binary(e, version) is not None}, key=str)
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


def borrowed_block(lookup, entry, version, tmp):
    owner, target = lender(lookup, entry, version)
    if target["format"] == "sprite_sheet":
        return encode_sheet(owner, target, version)[2]
    return encode(owner, target, version, tmp)


def encode_sheet(manifest, entry, version, main=None, extra=None, borrowed=None):
    layout = manifest.sheet(entry, version)
    if main is None:
        paths = manifest.sources(entry, version)
        for path in paths:
            if not path.exists():
                raise ManifestError(f"{path} is missing; run python3 tools/extract_assets.py")
        main = paths[0].read_bytes()
        extra = paths[1].read_bytes() if len(paths) > 1 else None
    animations = manifest.animations(entry, version)
    try:
        layers = sprite_sheet.read_sheets(layout, main, extra)
        if entry.get("tiles"):
            if borrowed is None:
                raise ManifestError(f"{entry['name']}: {version} needs the tiles of {entry['tiles']}")
            oam, block = sprite_sheet.encode_view(layout, layers, borrowed), b""
        else:
            oam, block = sprite_sheet.encode(layout, layers)
        size = len(sprite_sheet.record_bytes(oam, animations)) + len(block)
    except sprite_sheet.SheetError as error:
        raise ManifestError(f"{entry['name']}: {version} {error}")
    if size != entry[version]["size"]:
        raise ManifestError(f"{entry['name']}: {version} sheet encodes to {size} bytes, manifest says {entry[version]['size']}")
    return oam, animations, block


def decode_sheet(manifest, entry, version, data, palette_bytes, borrowed=None):
    layout = manifest.sheet(entry, version)
    animations = manifest.animations(entry, version)
    try:
        oam, anims, block = sprite_sheet.parse_records(data, len(layout["frames"]), len(animations))
        if anims != [{"fields": anim["fields"], "frames": anim["frames"]} for anim in animations]:
            raise ManifestError(f"{entry['name']}: {version} animation headers differ from the description")
        if entry.get("tiles"):
            if block or borrowed is None:
                raise ManifestError(f"{entry['name']}: {version} borrows tiles but holds a block or has no lender")
            layout, layers = sprite_sheet.decode_view(oam, borrowed, layout)
        else:
            layout, layers = sprite_sheet.decode(oam, block, layout)
        main, extra = sprite_sheet.write_sheets(layout, layers, palette_bytes)
    except sprite_sheet.SheetError as error:
        raise ManifestError(f"{entry['name']}: {version} {error}")
    oam_out, animations, block_out = encode_sheet(manifest, entry, version, main, extra, borrowed)
    if sprite_sheet.record_bytes(oam_out, animations) + block_out != data:
        raise ManifestError(f"{entry['name']}: {version} sheet does not re-encode to the ROM bytes")
    return dict(zip(manifest.sources(entry, version), (main, extra)))


def decode(manifest, version, rom, rom_base=0x08000000, lookup=None):
    written = checked = 0
    palettes = {name: owner.by_name[name] for name, owner in lookup.items()} if lookup else manifest.by_name

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
            palette = palettes.get(entry.get("palette"))
            palette_bytes = rom_bytes(palette) if palette is not None and version in palette else b""
            if entry["format"] == "sprite_sheet":
                borrowed = None
                if entry.get("tiles"):
                    owner, target = lender(lookup or {e["name"]: manifest for e in manifest.entries}, entry, version)
                    borrowed = rom_bytes(target)
                    if target["format"] == "sprite_sheet":
                        frames, anims = owner.frames(target, version), owner.animations(target, version)
                        borrowed = sprite_sheet.parse_records(borrowed, len(frames), len(anims))[2]
                files = decode_sheet(manifest, entry, version, data, palette_bytes, borrowed)
            else:
                decoded = decode_one(manifest, entry, version, data, tmp, palette_bytes)
                source = manifest.source(entry, version)
                probe = probe_dir / source.name
                probe.write_bytes(decoded)
                if encode(manifest, entry, version, tmp, probe) != data:
                    raise ManifestError(f"{entry['name']}: {version} {entry['format']} source does not re-encode to the ROM bytes")
                files = {source: decoded}
            checked += 1
            for source, decoded in files.items():
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


def resolver(all_manifests, version):
    lookup = {}
    for other in all_manifests:
        for entry in other.entries:
            if version in entry:
                lookup[entry["name"]] = other.symbol(entry, version)
                lookup.update(other.names(entry, version))

    def resolve(name):
        return lookup.get(name, name)

    return resolve


def emit_c(manifest, version, members, out_path, all_manifests):
    resolve = resolver(all_manifests, version)
    defined = {manifest.symbol(e, version) for e in members}
    referenced = set()
    for entry in members:
        kind = manifest.kind(entry)
        if kind == "table":
            referenced.update(resolve(item) for item in manifest.data(entry, version, "items"))
        elif kind == "struct":
            rtype = manifest.types[entry["record"]]
            fields = manifest.fields(entry, version)
            for field in rtype["fields"]:
                if version not in field_versions(field) or not field["type"].endswith("*"):
                    continue
                value = fields[field["name"]]
                if value not in (0, None):
                    referenced.add(resolve(value))
    lines = []
    headers = sorted({manifest.types[e["record"]].get("header") for e in members if "record" in e} - {None}) or ["types.h"]
    for header in headers:
        lines.append(f'#include "{header}"')
    lines.append("")
    for name in sorted(referenced - defined):
        lines.append(f"extern u8 {name}[];")
    if referenced - defined:
        lines.append("")
    declared = False
    for entry in members:
        symbol = manifest.symbol(entry, version)
        if "record" not in entry:
            lines.append(f"extern const u8 {symbol}[{manifest.size(entry, version)}];")
            declared = True
        elif manifest.kind(entry) == "table" and symbol in referenced:
            ctype = manifest.types[entry["record"]]["type"]
            count = "" if manifest.data(entry, version, "scalar") else f"[{len(manifest.data(entry, version, 'items'))}]"
            lines.append(f"extern {ctype} {symbol}{count};")
            declared = True
    if declared:
        lines.append("")
    for entry in members:
        symbol = manifest.symbol(entry, version)
        kind = manifest.kind(entry)
        if kind == "table":
            ctype = manifest.types[entry["record"]]["type"]
            items = [f"({ctype}){resolve(item)}" for item in manifest.data(entry, version, "items")]
            if manifest.data(entry, version, "scalar"):
                lines.append(f"{ctype} {symbol} = {items[0]};")
            else:
                lines.append(f"{ctype} {symbol}[{len(items)}] = {{")
                for item in items:
                    lines.append(f"    {item},")
                lines.append("};")
        elif kind == "struct":
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


def words(values):
    return ", ".join(str(v) for v in values)


def emit_sheet(manifest, entry, version, sheet, lines):
    oam, animations, block = sheet
    for frame, attrs_list in zip(manifest.frames(entry, version), oam):
        symbol = manifest.item_symbol(frame, version)
        lines.append(f"\t.global {symbol}")
        lines.append(f"{symbol}:")
        lines.append(f"\t.hword {len(attrs_list)}")
        for attrs in attrs_list:
            lines.append(f"\t.hword {words(attrs)}")
        if attrs_list:
            lines.append("\t.hword 0")
    for anim in animations:
        symbol = manifest.item_symbol(anim, version)
        lines.append(f"\t.global {symbol}")
        lines.append(f"{symbol}:")
        lines.append(f"\t.hword {anim['fields']['unk_00']}, {anim['fields']['unk_02']}, {len(anim['frames'])}")
        for frame in anim["frames"]:
            lines.append(f"\t.hword {words(frame)}")
    binary = manifest.binary(entry, version)
    if binary is None:
        return
    write_if_changed(binary, block)
    symbol = manifest.symbol(entry, version)
    lines.append(f"\t.global {symbol}")
    lines.append(f"{symbol}:")
    lines.append(f'\t.incbin "{binary.relative_to(ROOT).as_posix()}"')


def emit_s(manifest, version, members, out_path, tmp, obj, sheets, resolve):
    lines = ["\t.section .rodata"]
    position = obj["start"]
    if position % 4 == 0:
        lines.append("\t.balign 4")
    elif position % 2 == 0:
        lines.append("\t.balign 2")
    tables = [e for e in members if in_data(obj, e, version)]
    for entry in members:
        if in_data(obj, entry, version):
            continue
        symbol = manifest.symbol(entry, version)
        pad = aligned(position, entry) - position
        if pad:
            lines.append(f"\t.byte {words([0] * pad)}")
            position += pad
        if entry.get("format") == "sprite_sheet":
            emit_sheet(manifest, entry, version, sheets[entry["name"]], lines)
            position += manifest.size(entry, version)
            continue
        lines.append(f"\t.global {symbol}")
        lines.append(f"{symbol}:")
        kind = manifest.kind(entry)
        if kind == "sprite":
            oam = manifest.data(entry, version, "oam")
            lines.append(f"\t.hword {len(oam)}")
            for attrs in oam:
                lines.append(f"\t.hword {words(attrs)}")
            if oam:
                lines.append("\t.hword 0")
        elif kind == "anim":
            fields = manifest.fields(entry, version)
            frames = manifest.data(entry, version, "frames")
            lines.append(f"\t.hword {fields['unk_00']}, {fields['unk_02']}, {len(frames)}")
            for frame in frames:
                lines.append(f"\t.hword {words(frame)}")
        else:
            binary = manifest.binary(entry, version)
            data = encode(manifest, entry, version, tmp)
            binary.parent.mkdir(parents=True, exist_ok=True)
            write_if_changed(binary, data)
            lines.append(f'\t.incbin "{binary.relative_to(ROOT).as_posix()}"')
        position += manifest.size(entry, version)
    if obj["end"] > position:
        lines.append(f"\t.byte {words([0] * (obj['end'] - position))}")
    if "data_start" in obj:
        lines.append("\t.section .data")
        position = obj["data_start"]
        if position % 4 == 0:
            lines.append("\t.balign 4")
        for entry in tables:
            symbol = manifest.symbol(entry, version)
            lines.append(f"\t.global {symbol}")
            lines.append(f"{symbol}:")
            items = [resolve(item) if item else 0 for item in manifest.data(entry, version, "items")]
            lines.append(f"\t.4byte {words(items)}")
            position += manifest.size(entry, version)
        if obj["data_end"] > position:
            lines.append(f"\t.byte {words([0] * (obj['data_end'] - position))}")
    write_if_changed(out_path, "\n".join(lines) + "\n")


def emit_header(manifest, version, members_by_object, out_path, sheets):
    guard = "GUARD_GEN_" + manifest.group.upper() + "_H"
    lines = [f"#ifndef {guard}", f"#define {guard}", ""]
    headers = {manifest.types[e["record"]].get("header") for members in members_by_object.values()
               for e in members if "record" in e}
    if any(manifest.animations(e, version) for members in members_by_object.values()
           for e in members if e.get("format") == "sprite_sheet"):
        headers.add(manifest.types[manifest.anim_type()].get("header"))
    headers = sorted(headers - {None})
    if not headers:
        headers = ["types.h"]
    for header in headers:
        lines.append(f'#include "{header}"')
    lines.append("")
    for name, members in members_by_object.items():
        for entry in members:
            if entry.get("format") == "sprite_sheet":
                for frame in manifest.frames(entry, version):
                    if frame.get("declare") is not False:
                        lines.append(f"extern u8 {manifest.item_symbol(frame, version)}[];")
                for anim in manifest.animations(entry, version):
                    if anim.get("declare") is not False:
                        lines.append(f"extern {manifest.anim_type()} {manifest.item_symbol(anim, version)};")
                if entry.get("declare") is not False and not entry.get("tiles"):
                    lines.append(f"extern u8 {manifest.symbol(entry, version)}[{len(sheets[entry['name']][2])}];")
                continue
            if entry.get("declare") is False:
                continue
            symbol = manifest.symbol(entry, version)
            kind = manifest.kind(entry)
            if kind == "table":
                ctype = manifest.types[entry["record"]]["type"]
                if manifest.data(entry, version, "scalar"):
                    lines.append(f"extern {ctype} {symbol};")
                else:
                    lines.append(f"extern {ctype} {symbol}[{len(manifest.data(entry, version, 'items'))}];")
            elif kind == "struct":
                lines.append(f"extern const {entry['record']} {symbol};")
            elif kind == "anim":
                lines.append(f"extern {entry['record']} {symbol};")
            elif kind == "sprite":
                lines.append(f"extern u8 {symbol}[];")
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
    clashes = sorted(symbol for members in members_by_object.values()
                     for e in members for symbol in manifest.symbols(e, version) if symbol in ledger)
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
    objects = {obj["name"]: obj for obj in manifest.objects.get(version, [])}
    lookup = {e["name"]: m for m in all_manifests for e in m.entries}
    with tempfile.TemporaryDirectory() as tmpdir:
        tmp = Path(tmpdir)
        sheets = {e["name"]: encode_sheet(manifest, e, version,
                                          borrowed=borrowed_block(lookup, e, version, tmp) if e.get("tiles") else None)
                  for members in members_by_object.values() for e in members if e.get("format") == "sprite_sheet"}
        resolve = resolver(all_manifests, version) if any("data_start" in obj for obj in objects.values()) else None
        for name, members in members_by_object.items():
            if name.endswith(".c"):
                emit_c(manifest, version, members, gen / name, all_manifests)
            else:
                emit_s(manifest, version, members, gen / name, tmp, objects[name], sheets, resolve)
    emit_header(manifest, version, members_by_object, gen / f"{manifest.group}.h", sheets)


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
