"""Layout for asset_gfx_gap_195 host mega + first leaf gUnk_09A3D2DC (32-byte palette).

Parent mega stays slice until fuller pack RE. Built mode rebuilds only the leaf via
gbagfx PNG(indexed)->gbapal and patches it into a copy of the extract slice.
MovieOpen asset_gfx remux is intentionally untouched.
"""
import hashlib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

# First leaf: LoadObjPalette(..., 0x20) in mode_mapinspect; ABS symbol gUnk_09A3D2DC.
LEAF_ID = "gUnk_09A3D2DC"
LEAF_SIZE = 0x20
LEAF_FORMAT = "palette"

VERSIONS = {
    "us": {
        "rom_base": 0x0999389C,
        "pack_end": 0x09A3DF34,
        "extract": ROOT / "assets" / "us" / "0999389C-09A3DF34.bin",
        "build": ROOT / "build" / "us" / "assets" / "asset_gfx_gap_195.bin",
        "source_root": ROOT / "assets" / "us" / "src" / "gfx" / "asset_gfx_gap_195",
        "manifest": ROOT / "config" / "asset_gfx_gap_195_us.yaml",
        "inventory": ROOT / "config" / "asset_inventory_us_gfx_gap_195.yaml",
        "asm_unit": "asset_gfx_gap_195.s",
        "global_sym": "data_0999389C",
        "expected_sha256": "d52102817ac348841559fdfe92ccdcb36bf6228308b09117704e335324810419",
        "leaf": {
            "id": LEAF_ID,
            "symbol": "gUnk_09A3D2DC",
            "rom_start": 0x09A3D2DC,
            "rom_end": 0x09A3D2FC,
            "size": LEAF_SIZE,
            "format": LEAF_FORMAT,
            "png": "gUnk_09A3D2DC.png",
            "gbapal": "gUnk_09A3D2DC.gbapal",
            "consumer": "LoadObjPalette(..., 0x20) mode_mapinspect",
            "expected_sha1": "dc1c394483e795a1adf63ab5ba27dac00a0db865",
        },
    },
    "jp": {
        "rom_base": 0x099483B0,
        "pack_end": 0x099F29BC,
        "extract": ROOT / "assets" / "jp" / "099483B0-099F29BC.bin",
        "build": ROOT / "build" / "jp" / "assets" / "asset_gfx_gap_195.bin",
        "source_root": ROOT / "assets" / "jp" / "src" / "gfx" / "asset_gfx_gap_195",
        "manifest": ROOT / "config" / "asset_gfx_gap_195_jp.yaml",
        "inventory": ROOT / "config" / "asset_inventory_jp_gfx_gap_195.yaml",
        "asm_unit": "asset_gfx_gap_195.s",
        "global_sym": "data_099483B0",
        "expected_sha256": "a2ad9fe15cbd3cf89e34eba60ccee8b9b31e9ee5310f3f2c72d3776397d2722c",
        "leaf": {
            "id": LEAF_ID,
            "symbol": "gUnk_09A3D2DC",
            "rom_start": 0x099F1D64,
            "rom_end": 0x099F1D84,
            "size": LEAF_SIZE,
            "format": LEAF_FORMAT,
            "png": "gUnk_09A3D2DC.png",
            "gbapal": "gUnk_09A3D2DC.gbapal",
            "consumer": "LoadObjPalette(..., 0x20) mode_mapinspect",
            "expected_sha1": "dc1c394483e795a1adf63ab5ba27dac00a0db865",
        },
    },
    "eu": {
        "rom_base": 0x09999B58,
        "pack_end": 0x09A9B9F8,
        "extract": ROOT / "assets" / "eu" / "09999B58-09A9B9F8.bin",
        "build": ROOT / "build" / "eu" / "assets" / "asset_gfx_gap_195.bin",
        "source_root": ROOT / "assets" / "eu" / "src" / "gfx" / "asset_gfx_gap_195",
        "manifest": ROOT / "config" / "asset_gfx_gap_195_eu.yaml",
        "inventory": ROOT / "config" / "asset_inventory_eu_gfx_gap_195.yaml",
        "asm_unit": "asset_gfx_gap_195.s",
        "global_sym": "data_09999B58",
        "expected_sha256": "5207ef458b9091924c8e08f69536b0467d1986e4f0bede8c5c9c35c6d86c2b29",
        "leaf": {
            "id": LEAF_ID,
            "symbol": "gUnk_09A3D2DC",
            "rom_start": 0x09A9ADA0,
            "rom_end": 0x09A9ADC0,
            "size": LEAF_SIZE,
            "format": LEAF_FORMAT,
            "png": "gUnk_09A3D2DC.png",
            "gbapal": "gUnk_09A3D2DC.gbapal",
            "consumer": "LoadObjPalette(..., 0x20) mode_mapinspect",
            "expected_sha1": "dc1c394483e795a1adf63ab5ba27dac00a0db865",
        },
    },
}


def version_spec(version):
    if version not in VERSIONS:
        raise ValueError(f"unknown asset_gfx_gap_195 version: {version}")
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
