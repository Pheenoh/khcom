"""Layout for asset_gfx_gap_43 host mega + first leaf gUnk_09618118 (32-byte palette).

Parent mega stays slice until fuller pack RE. Built mode rebuilds only the leaf via
gbagfx PNG(indexed)->gbapal and patches it into a copy of the extract slice.
MovieOpen asset_gfx remux is intentionally untouched.

EU note: the leaf ABS lives in unit asset_gfx_gap_38_at_09041E7F.s (not the small
asm/eu/asset_gfx_gap_43.s slice); US/JP use asm/*/asset_gfx_gap_43.s.
"""
import hashlib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

# First leaf: LoadObjPalette(..., 0x20) in field_transition / btl2; ABS gUnk_09618118.
LEAF_ID = "gUnk_09618118"
LEAF_SIZE = 0x20
LEAF_FORMAT = "palette"

VERSIONS = {
    "us": {
        "rom_base": 0x090451AB,
        "pack_end": 0x096193B8,
        "extract": ROOT / "assets" / "us" / "090451AB-096193B8.bin",
        "build": ROOT / "build" / "us" / "assets" / "asset_gfx_gap_43.bin",
        "source_root": ROOT / "assets" / "us" / "src" / "gfx" / "asset_gfx_gap_43",
        "manifest": ROOT / "config" / "asset_gfx_gap_43_us.yaml",
        "inventory": ROOT / "config" / "asset_inventory_us_gfx_gap_43.yaml",
        "asm_unit": "asset_gfx_gap_43.s",
        "global_sym": "data_090451AB",
        "expected_sha256": "18201fa5c16ec1a38e758b439066e8dd048de7b19417e4bc9796eb0938c9babd",
        "leaf": {
            "id": LEAF_ID,
            "symbol": "gUnk_09618118",
            "rom_start": 0x09618118,
            "rom_end": 0x09618138,
            "size": LEAF_SIZE,
            "format": LEAF_FORMAT,
            "png": "gUnk_09618118.png",
            "gbapal": "gUnk_09618118.gbapal",
            "consumer": "LoadObjPalette(..., 0x20) field_transition/btl2",
            "expected_sha1": "4867c27391463f6144ac876476edcebd33c4e959",
        },
    },
    "jp": {
        "rom_base": 0x09012053,
        "pack_end": 0x095D1E94,
        "extract": ROOT / "assets" / "jp" / "09012053-095D1E94.bin",
        "build": ROOT / "build" / "jp" / "assets" / "asset_gfx_gap_43.bin",
        "source_root": ROOT / "assets" / "jp" / "src" / "gfx" / "asset_gfx_gap_43",
        "manifest": ROOT / "config" / "asset_gfx_gap_43_jp.yaml",
        "inventory": ROOT / "config" / "asset_inventory_jp_gfx_gap_43.yaml",
        "asm_unit": "asset_gfx_gap_43.s",
        "global_sym": "data_09012053",
        "expected_sha256": "572af203f1c3236133e2794c7a975462bc9215ff8d6a106d961da3e03aff17dd",
        "leaf": {
            "id": LEAF_ID,
            "symbol": "gUnk_09618118",
            "rom_start": 0x095D0BF4,
            "rom_end": 0x095D0C14,
            "size": LEAF_SIZE,
            "format": LEAF_FORMAT,
            "png": "gUnk_09618118.png",
            "gbapal": "gUnk_09618118.gbapal",
            "consumer": "LoadObjPalette(..., 0x20) field_transition/btl2",
            "expected_sha1": "4867c27391463f6144ac876476edcebd33c4e959",
        },
    },
    "eu": {
        # Leaf lives in the large EU gap_38 mega, not asm/eu/asset_gfx_gap_43.s.
        "rom_base": 0x090D76FB,
        "pack_end": 0x0954C2C9,
        "extract": ROOT / "assets" / "eu" / "090D76FB-0954C2C9.bin",
        "build": ROOT / "build" / "eu" / "assets" / "asset_gfx_gap_43.bin",
        "source_root": ROOT / "assets" / "eu" / "src" / "gfx" / "asset_gfx_gap_43",
        "manifest": ROOT / "config" / "asset_gfx_gap_43_eu.yaml",
        "inventory": ROOT / "config" / "asset_inventory_eu_gfx_gap_43.yaml",
        "asm_unit": "asset_gfx_gap_38_at_09041E7F.s",
        "global_sym": "data_090D76FB",
        "expected_sha256": "d160e72a0da37e8ed466465f73513595fc8b5cf785e169ad6e19d61b04cc2c95",
        "leaf": {
            "id": LEAF_ID,
            "symbol": "gUnk_09618118",
            "rom_start": 0x0954B004,
            "rom_end": 0x0954B024,
            "size": LEAF_SIZE,
            "format": LEAF_FORMAT,
            "png": "gUnk_09618118.png",
            "gbapal": "gUnk_09618118.gbapal",
            "consumer": "LoadObjPalette(..., 0x20) field_transition/btl2",
            "expected_sha1": "4867c27391463f6144ac876476edcebd33c4e959",
        },
    },
}


def version_spec(version):
    if version not in VERSIONS:
        raise ValueError(f"unknown asset_gfx_gap_43 version: {version}")
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
