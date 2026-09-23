import hashlib
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools"))
from movie_assets import movie_extent

VERSIONS = {
    "us": {
        "rom_base": 0x084E0B04,
        "pack_end": 0x0886AD18,
        "extract": ROOT / "assets" / "us" / "084E0B04-0886AD18.bin",
        "build": ROOT / "build" / "us" / "assets" / "asset_gfx.bin",
        "source_root": ROOT / "assets" / "us" / "src" / "gfx" / "asset_gfx",
        "manifest": ROOT / "config" / "asset_gfx_us.yaml",
        "inventory": ROOT / "config" / "asset_inventory_us_gfx.yaml",
        "asm_unit": "asset_gfx.s",
        "global_sym": "data_084E0B04",
        "expected_sha256": "abd74f58e092cdb9c28f71d42d934645ce95cd714cb7108b2d6632f0101f7312",
        "regions": (
            ("00_head", 0x084E0B04, 0x084E0F34, "padding"),
            ("01_gUnk_084E0F34", 0x084E0F34, 0x084F4660, "movie"),
            ("02_gUnk_084F4660", 0x084F4660, 0x0855CCB4, "movie"),
            ("03_gUnk_0855CCB4", 0x0855CCB4, 0x086FBA14, "movie"),
            ("04_gUnk_086FBA14", 0x086FBA14, 0x0886AB40, "movie"),
            ("05_gUnk_0886AB40", 0x0886AB40, 0x0886AB90, "movie_sub_table"),
            ("06_gUnk_0886AB90", 0x0886AB90, 0x0886AC70, "movie_sub_table"),
            ("07_gUnk_0886AC70", 0x0886AC70, 0x0886AD10, "movie_sub_table"),
            ("08_sMovieHeapName", 0x0886AD10, 0x0886AD18, "literal"),
        ),
    },
    "jp": {
        "rom_base": 0x084D4390,
        "pack_end": 0x0885E300,
        "extract": ROOT / "assets" / "jp" / "084D4390-0885E300.bin",
        "build": ROOT / "build" / "jp" / "assets" / "asset_gfx.bin",
        "source_root": ROOT / "assets" / "jp" / "src" / "gfx" / "asset_gfx",
        "manifest": ROOT / "config" / "asset_gfx_jp.yaml",
        "inventory": ROOT / "config" / "asset_inventory_jp_gfx.yaml",
        "asm_unit": "asset_gfx.s",
        "global_sym": "data_084D4390",
        "expected_sha256": "81e666166a0946b25cef38efd656ccaed50a7e5f3980a792afb4574645352f82",
        "head_unit": {
            "asm_unit": "asset_movie_opening_pad.s",
            "extract": ROOT / "assets" / "jp" / "084D4194-084D4390.bin",
            "rom_start": 0x084D4194,
            "rom_end": 0x084D4390,
            "size": 508,
            "expected_sha256": "13c995087c43bd9f25fa7d771744a40981545343434fae560a6886820adfec4c",
            "path_mode": "slice",
        },
        "regions": (
            ("00_head", 0x084D4390, 0x084D47D8, "padding"),
            ("01_gUnk_084E0F34", 0x084D47D8, 0x084E7F04, "movie"),
            ("02_gUnk_084F4660", 0x084E7F04, 0x08550558, "movie"),
            ("03_gUnk_0855CCB4", 0x08550558, 0x086EF2B8, "movie"),
            ("04_gUnk_086FBA14", 0x086EF2B8, 0x0885DF78, "movie"),
            ("05_gUnk_0886AB40", 0x0885DF78, 0x0885E02C, "movie_sub_table"),
            ("06_gUnk_0886AB90", 0x0885E02C, 0x0885E1D8, "movie_sub_table"),
            ("07_gUnk_0886AC70", 0x0885E1D8, 0x0885E2F8, "movie_sub_table"),
            ("08_sMovieHeapName", 0x0885E2F8, 0x0885E300, "literal"),
        ),
    },
    "eu": {
        "rom_base": 0x084B423C,
        "pack_end": 0x0883F2D0,
        "extract": ROOT / "assets" / "eu" / "084B423C-0883F2D0.bin",
        "build": ROOT / "build" / "eu" / "assets" / "asset_gfx.bin",
        "source_root": ROOT / "assets" / "eu" / "src" / "gfx" / "asset_gfx",
        "manifest": ROOT / "config" / "asset_gfx_eu.yaml",
        "inventory": ROOT / "config" / "asset_inventory_eu_gfx.yaml",
        "asm_unit": "asset_gfx.s",
        "global_sym": "data_084B423C",
        "expected_sha256": "4436be20c8fb71b53506460553f2fa02679c12cb86284df308278022c117874a",
        "regions": (
            ("00_head", 0x084B423C, 0x084B466C, "padding"),
            ("01_gUnk_084E0F34", 0x084B466C, 0x084C7D98, "movie"),
            ("02_gUnk_084F4660", 0x084C7D98, 0x085303EC, "movie"),
            ("03_gUnk_0855CCB4", 0x085303EC, 0x086CF14C, "movie"),
            ("04_gUnk_086FBA14", 0x086CF14C, 0x0883E040, "movie"),
            ("05_gUnkEu_0883E040", 0x0883E040, 0x0883E070, "movie_sub_table"),
            ("06_gUnkEu_0883E070", 0x0883E070, 0x0883E150, "movie_sub_table"),
            ("07_gUnkEu_0883E150", 0x0883E150, 0x0883E278, "movie_sub_table"),
            ("08_gUnk_0886AB40", 0x0883E278, 0x0883E2C8, "movie_sub_table"),
            ("09_gUnk_0886AB90", 0x0883E2C8, 0x0883E3A8, "movie_sub_table"),
            ("10_gUnk_0886AC70", 0x0883E3A8, 0x0883E454, "movie_sub_table"),
            ("11_gUnkEu_0883E454", 0x0883E454, 0x0883E494, "movie_sub_table"),
            ("12_gUnkEu_0883E494", 0x0883E494, 0x0883E574, "movie_sub_table"),
            ("13_gUnkEu_0883E574", 0x0883E574, 0x0883E8D4, "movie_sub_table"),
            ("14_gUnkEu_0883E8D4", 0x0883E8D4, 0x0883E914, "movie_sub_table"),
            ("15_gUnkEu_0883E914", 0x0883E914, 0x0883E9F4, "movie_sub_table"),
            ("16_gUnkEu_0883E9F4", 0x0883E9F4, 0x0883ECE8, "movie_sub_table"),
            ("17_gUnkEu_0883ECE8", 0x0883ECE8, 0x0883ED28, "movie_sub_table"),
            ("18_gUnkEu_0883ED28", 0x0883ED28, 0x0883EE08, "movie_sub_table"),
            ("19_gUnkEu_0883EE08", 0x0883EE08, 0x0883F0F8, "movie_sub_table"),
            ("20_gUnkEu_0883F0F8", 0x0883F0F8, 0x0883F138, "movie_sub_table"),
            ("21_gUnkEu_0883F138", 0x0883F138, 0x0883F218, "movie_sub_table"),
            ("22_gUnkEu_0883F218", 0x0883F218, 0x0883F2C8, "movie_sub_table"),
            ("23_sMovieHeapName", 0x0883F2C8, 0x0883F2D0, "literal"),
        ),
    },
}

US_ROM_BASE = VERSIONS["us"]["rom_base"]
US_PACK_END = VERSIONS["us"]["pack_end"]
US_EXPECTED_SIZE = US_PACK_END - US_ROM_BASE
US_EXPECTED_SHA256 = VERSIONS["us"]["expected_sha256"]
US_EXTRACT = VERSIONS["us"]["extract"]
US_BUILD = VERSIONS["us"]["build"]
US_SOURCE_ROOT = VERSIONS["us"]["source_root"]
US_REGIONS = VERSIONS["us"]["regions"]
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


def version_spec(version):
    if version not in VERSIONS:
        raise ValueError(f"unknown asset_gfx version: {version}")
    return VERSIONS[version]


def sha256_hex(data):
    return hashlib.sha256(data).hexdigest()


def region_blob(data, start, end, rom_base):
    off = start - rom_base
    size = end - start
    return data[off : off + size]


def demux_parts(data, version="us"):
    spec = version_spec(version)
    rom_base = spec["rom_base"]
    expected = spec["pack_end"] - rom_base
    if len(data) != expected:
        raise ValueError(f"{version}: expected {expected} bytes, got {len(data)}")
    parts = []
    for name, start, end, kind in spec["regions"]:
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


def write_demux(parts, source_root, version="us"):
    spec = version_spec(version)
    source_root = Path(source_root)
    source_root.mkdir(parents=True, exist_ok=True)
    meta = {
        "version": version,
        "sha256_slice": spec["expected_sha256"],
        "parts": [],
    }
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


def ensure_demuxed(version="us", extract_path=None, source_root=None):
    spec = version_spec(version)
    extract_path = Path(extract_path or spec["extract"])
    source_root = Path(source_root or spec["source_root"])
    data = extract_path.read_bytes()
    digest = sha256_hex(data)
    if digest != spec["expected_sha256"]:
        raise ValueError(f"{version} slice sha256 mismatch: {digest}")
    meta_path = source_root / "pack_parts.json"
    if meta_path.is_file():
        try:
            rebuilt = remux_from_source_root(source_root)
            if sha256_hex(rebuilt) == spec["expected_sha256"]:
                return rebuilt, False
        except (FileNotFoundError, ValueError, KeyError):
            pass
    parts = demux_parts(data, version)
    write_demux(parts, source_root, version)
    rebuilt = remux_from_parts(parts)
    if sha256_hex(rebuilt) != spec["expected_sha256"]:
        raise ValueError(f"{version} demux/remux round-trip failed")
    return rebuilt, True


def probe_regional_movie_sha256():
    results = {}
    for version, spec in VERSIONS.items():
        path = spec["extract"]
        base = spec["rom_base"]
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
