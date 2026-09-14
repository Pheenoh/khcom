import hashlib
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools"))
from movie_assets import movie_extent

US_ROM_BASE = 0x084E0B04
US_PACK_END = 0x0886AD18
US_EXPECTED_SIZE = US_PACK_END - US_ROM_BASE
US_EXPECTED_SHA256 = "abd74f58e092cdb9c28f71d42d934645ce95cd714cb7108b2d6632f0101f7312"
US_EXTRACT = ROOT / "assets" / "us" / "084E0B04-0886AD18.bin"
US_BUILD = ROOT / "build" / "us" / "assets" / "asset_gfx.bin"
US_SOURCE_ROOT = ROOT / "assets" / "us" / "src" / "gfx" / "asset_gfx"

US_REGIONS = (
    ("00_head", 0x084E0B04, 0x084E0F34, "padding"),
    ("01_gUnk_084E0F34", 0x084E0F34, 0x084F4660, "movie"),
    ("02_gUnk_084F4660", 0x084F4660, 0x0855CCB4, "movie"),
    ("03_gUnk_0855CCB4", 0x0855CCB4, 0x086FBA14, "movie"),
    ("04_gUnk_086FBA14", 0x086FBA14, 0x0886AB40, "movie"),
    ("05_gUnk_0886AB40", 0x0886AB40, 0x0886AB90, "movie_sub_table"),
    ("06_gUnk_0886AB90", 0x0886AB90, 0x0886AC70, "movie_sub_table"),
    ("07_gUnk_0886AC70", 0x0886AC70, 0x0886AD10, "movie_sub_table"),
    ("08_sMovieHeapName", 0x0886AD10, 0x0886AD18, "literal"),
)

DUMP_REGIONS = (
    ("asset_gfx.head", 0x084E0B04, 0x084E0F34, "padding"),
    ("gUnk_084E0F34", 0x084E0F34, 0x084F4660, "movie"),
    ("gUnk_084F4660", 0x084F4660, 0x0855CCB4, "movie"),
    ("gUnk_0855CCB4", 0x0855CCB4, 0x086FBA14, "movie"),
    ("gUnk_086FBA14", 0x086FBA14, 0x0886AB40, "movie"),
    ("gUnk_0886AB40", 0x0886AB40, 0x0886AB90, "movie_sub_table"),
    ("gUnk_0886AB90", 0x0886AB90, 0x0886AC70, "movie_sub_table"),
    ("gUnk_0886AC70", 0x0886AC70, 0x0886AD10, "movie_sub_table"),
    ("sMovieHeapName", 0x0886AD10, 0x0886AD18, "literal"),
)


def sha256_hex(data):
    return hashlib.sha256(data).hexdigest()


def region_blob(data, start, end, rom_base=US_ROM_BASE):
    off = start - rom_base
    size = end - start
    return data[off : off + size]


def demux_parts(data, regions=US_REGIONS, rom_base=US_ROM_BASE):
    if len(data) != US_EXPECTED_SIZE and regions is US_REGIONS:
        raise ValueError(f"expected {US_EXPECTED_SIZE} bytes, got {len(data)}")
    parts = []
    for name, start, end, kind in regions:
        blob = region_blob(data, start, end, rom_base)
        if kind == "movie":
            extent = movie_extent(blob)
            parts.append(
                {
                    "id": name,
                    "kind": kind,
                    "rom_start": start,
                    "rom_end": end,
                    "files": [
                        (f"{name}.movie.bin", blob[:extent]),
                        (f"{name}.pad.bin", blob[extent:]),
                    ],
                    "movie_extent": extent,
                    "region_pad": len(blob) - extent,
                }
            )
        else:
            suffix = {
                "padding": "pad.bin",
                "movie_sub_table": "subs.bin",
                "literal": "bin",
            }[kind]
            parts.append(
                {
                    "id": name,
                    "kind": kind,
                    "rom_start": start,
                    "rom_end": end,
                    "files": [(f"{name}.{suffix}", blob)],
                }
            )
    return parts


def write_demux(parts, source_root):
    source_root = Path(source_root)
    source_root.mkdir(parents=True, exist_ok=True)
    meta = {"version": "us", "sha256_slice": US_EXPECTED_SHA256, "parts": []}
    for part in parts:
        entry = {
            "id": part["id"],
            "kind": part["kind"],
            "rom_start": f"0x{part['rom_start']:08X}",
            "rom_end": f"0x{part['rom_end']:08X}",
            "files": [],
        }
        if "movie_extent" in part:
            entry["movie_extent"] = part["movie_extent"]
            entry["region_pad"] = part["region_pad"]
        for filename, blob in part["files"]:
            path = source_root / filename
            path.write_bytes(blob)
            entry["files"].append(
                {"name": filename, "size": len(blob), "sha256": sha256_hex(blob)}
            )
        meta["parts"].append(entry)
    (source_root / "pack_parts.json").write_text(json.dumps(meta, indent=2) + "\n")
    return meta


def remux_from_parts(parts):
    out = bytearray()
    for part in parts:
        for _, blob in part["files"]:
            out.extend(blob)
    return bytes(out)


def remux_from_source_root(source_root):
    source_root = Path(source_root)
    meta_path = source_root / "pack_parts.json"
    if not meta_path.is_file():
        raise FileNotFoundError(f"missing {meta_path}; run demux first")
    meta = json.loads(meta_path.read_text())
    out = bytearray()
    for part in meta["parts"]:
        for file_info in part["files"]:
            path = source_root / file_info["name"]
            blob = path.read_bytes()
            if len(blob) != file_info["size"]:
                raise ValueError(f"size mismatch for {path}")
            if sha256_hex(blob) != file_info["sha256"]:
                raise ValueError(f"sha256 mismatch for {path}")
            out.extend(blob)
    return bytes(out)


def ensure_demuxed(extract_path=US_EXTRACT, source_root=US_SOURCE_ROOT):
    extract_path = Path(extract_path)
    source_root = Path(source_root)
    data = extract_path.read_bytes()
    digest = sha256_hex(data)
    if digest != US_EXPECTED_SHA256:
        raise ValueError(f"slice sha256 mismatch: {digest}")
    meta_path = source_root / "pack_parts.json"
    if meta_path.is_file():
        try:
            rebuilt = remux_from_source_root(source_root)
            if sha256_hex(rebuilt) == US_EXPECTED_SHA256:
                return rebuilt, False
        except (FileNotFoundError, ValueError, KeyError):
            pass
    parts = demux_parts(data)
    write_demux(parts, source_root)
    rebuilt = remux_from_parts(parts)
    if sha256_hex(rebuilt) != US_EXPECTED_SHA256:
        raise ValueError("demux/remux round-trip failed")
    return rebuilt, True


def probe_regional_movie_sha256():
    results = {}
    specs = (
        ("us", US_EXTRACT, US_ROM_BASE),
        ("eu", ROOT / "assets" / "eu" / "084B423C-0883F2D0.bin", 0x084B423C),
        ("jp", ROOT / "assets" / "jp" / "084D4390-0885E300.bin", 0x084D4390),
    )
    for version, path, base in specs:
        if not path.is_file():
            results[version] = {"present": False}
            continue
        data = path.read_bytes()
        movies = []
        i = 0
        while i + 32 <= len(data):
            width, height = struct.unpack_from("<II", data, i)
            if width == 240 and height == 160:
                try:
                    extent = movie_extent(data[i:])
                    movies.append(
                        {
                            "rom": f"0x{base + i:08X}",
                            "extent": extent,
                            "sha256": sha256_hex(data[i : i + extent]),
                        }
                    )
                    i += max(extent, 4)
                    continue
                except ValueError:
                    pass
            i += 4
        results[version] = {
            "present": True,
            "path": str(path.relative_to(ROOT)),
            "size": len(data),
            "sha256": sha256_hex(data),
            "movies": movies,
        }
    return results
