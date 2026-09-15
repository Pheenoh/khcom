"""Layout for asset_gfx_gap_1 host mega + leaf gUnk_08C6A88C (64-byte tiles4).

Parent mega stays slice until fuller pack RE. Built mode rebuilds only the leaf via
gbagfx PNG->.4bpp (-num_tiles 2) and patches it into a copy of the extract slice.
MovieOpen asset_gfx remux is intentionally untouched.

EU note: the leaf ABS lives in unit rodata_script_at_08896652.s (not the small
asm/eu/asset_gfx_gap_1.s slice); US/JP use asm/*/asset_gfx_gap_1.s.
"""
import hashlib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

# Leaf: LoadObjTiles(..., 0x40) in mode_jiminy; ABS symbol gUnk_08C6A88C.
LEAF_ID = "gUnk_08C6A88C"
LEAF_SIZE = 0x40
LEAF_FORMAT = "tiles4"
LEAF_NUM_TILES = 2

VERSIONS = {
    "us": {
        "rom_base": 0x0886AD23,
        "pack_end": 0x08F6E184,
        "extract": ROOT / "assets" / "us" / "0886AD23-08F6E184.bin",
        "build": ROOT / "build" / "us" / "assets" / "asset_gfx_gap_1.bin",
        "source_root": ROOT / "assets" / "us" / "src" / "gfx" / "asset_gfx_gap_1",
        "manifest": ROOT / "config" / "asset_gfx_gap_1_us.yaml",
        "inventory": ROOT / "config" / "asset_inventory_us_gfx_gap_1.yaml",
        "asm_unit": "asset_gfx_gap_1.s",
        "global_sym": "data_0886AD23",
        "expected_sha256": "e0ba827cb486e4298fae856c41b3ce61caa4d3b004d422921a6210b530489678",
        "leaf": {
            "id": LEAF_ID,
            "symbol": "gUnk_08C6A88C",
            "rom_start": 0x08C6A88C,
            "rom_end": 0x08C6A8CC,
            "size": LEAF_SIZE,
            "format": LEAF_FORMAT,
            "num_tiles": LEAF_NUM_TILES,
            "png": "gUnk_08C6A88C.png",
            "fourbpp": "gUnk_08C6A88C.4bpp",
            "consumer": "LoadObjTiles(..., 0x40) mode_jiminy",
            "expected_sha1": "eb743dad9eeea2053ec6f4166945b204d27057fd",
        },
    },
    "jp": {
        "rom_base": 0x0885E30B,
        "pack_end": 0x08F6168C,
        "extract": ROOT / "assets" / "jp" / "0885E30B-08F6168C.bin",
        "build": ROOT / "build" / "jp" / "assets" / "asset_gfx_gap_1.bin",
        "source_root": ROOT / "assets" / "jp" / "src" / "gfx" / "asset_gfx_gap_1",
        "manifest": ROOT / "config" / "asset_gfx_gap_1_jp.yaml",
        "inventory": ROOT / "config" / "asset_inventory_jp_gfx_gap_1.yaml",
        "asm_unit": "asset_gfx_gap_1.s",
        "global_sym": "data_0885E30B",
        "expected_sha256": "43d50d5edd58f22f56edbf86665beace21432684d410ea195acab3887a496f9e",
        "leaf": {
            "id": LEAF_ID,
            "symbol": "gUnk_08C6A88C",
            "rom_start": 0x08C5DE74,
            "rom_end": 0x08C5DEB4,
            "size": LEAF_SIZE,
            "format": LEAF_FORMAT,
            "num_tiles": LEAF_NUM_TILES,
            "png": "gUnk_08C6A88C.png",
            "fourbpp": "gUnk_08C6A88C.4bpp",
            "consumer": "LoadObjTiles(..., 0x40) mode_jiminy",
            "expected_sha1": "eb743dad9eeea2053ec6f4166945b204d27057fd",
        },
    },
    "eu": {
        # Leaf lives in the large EU script mega, not asm/eu/asset_gfx_gap_1.s.
        "rom_base": 0x08896652,
        "pack_end": 0x08F7F15C,
        "extract": ROOT / "assets" / "eu" / "08896652-08F7F15C.bin",
        "build": ROOT / "build" / "eu" / "assets" / "asset_gfx_gap_1.bin",
        "source_root": ROOT / "assets" / "eu" / "src" / "gfx" / "asset_gfx_gap_1",
        "manifest": ROOT / "config" / "asset_gfx_gap_1_eu.yaml",
        "inventory": ROOT / "config" / "asset_inventory_eu_gfx_gap_1.yaml",
        "asm_unit": "rodata_script_at_08896652.s",
        "global_sym": "data_08896652",
        "expected_sha256": "c4da9fb2dec3c2955c39d2c318d1f0e7844617f73b253a3f9d7ef9b7c79a10fe",
        "leaf": {
            "id": LEAF_ID,
            "symbol": "gUnk_08C6A88C",
            "rom_start": 0x08C9C288,
            "rom_end": 0x08C9C2C8,
            "size": LEAF_SIZE,
            "format": LEAF_FORMAT,
            "num_tiles": LEAF_NUM_TILES,
            "png": "gUnk_08C6A88C.png",
            "fourbpp": "gUnk_08C6A88C.4bpp",
            "consumer": "LoadObjTiles(..., 0x40) mode_jiminy",
            "expected_sha1": "eb743dad9eeea2053ec6f4166945b204d27057fd",
        },
    },
}


def version_spec(version):
    if version not in VERSIONS:
        raise ValueError(f"unknown asset_gfx_gap_1 version: {version}")
    return VERSIONS[version]


def sha256_hex(data):
    return hashlib.sha256(data).hexdigest()


def sha1_hex(data):
    return hashlib.sha1(data).hexdigest()


def leaf_offset(spec):
    leaf = spec["leaf"]
    return leaf["rom_start"] - spec["rom_base"]


def leaf_bytes(data, spec):
    off = leaf_offset(spec)
    size = spec["leaf"]["size"]
    return data[off : off + size]


def expected_pack_size(spec):
    return spec["pack_end"] - spec["rom_base"]
