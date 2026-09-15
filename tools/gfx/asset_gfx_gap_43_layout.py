"""Layout for asset_gfx_gap_43 host mega + palette leaves (32B each).

Parent mega stays slice until fuller pack RE. Built mode rebuilds listed leaves via
gbagfx PNG(indexed)->gbapal and patches them into a copy of the extract slice.
MovieOpen asset_gfx remux is intentionally untouched.

EU note: the leaves ABS live in unit asset_gfx_gap_38_at_09041E7F.s (not the small
asm/eu/asset_gfx_gap_43.s slice); US/JP use asm/*/asset_gfx_gap_43.s.
"""
import hashlib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

LEAF_SIZE = 0x20
LEAF_FORMAT = "palette"

# Shared leaf metadata (rom addresses are per-version below).
# Consumers: LoadObjPalette(..., 0x20) / LoadPalette(..., 32).
LEAF_META = {
    "gUnk_09611AB8": {
        "consumer": "LoadObjPalette(..., 0x20) mode_jiminy/msg",
        "expected_sha1": "1b135bb0893b38982f2f5e7481348bc1de7ad88f",
    },
    "gUnk_09614AB8": {
        "consumer": "LoadObjPalette(..., 0x20) mode_jiminy",
        "expected_sha1": "f3ce5818afe11cc0bd86f13cdba2823ebe143e2c",
    },
    "gUnk_09614D58": {
        "consumer": "LoadObjPalette(..., 0x20) mode_jiminy",
        "expected_sha1": "ae9775356b47fe8f99e2cfadbdcb0d41157fb69a",
    },
    "gUnk_09618118": {
        "consumer": "LoadObjPalette(..., 0x20) field_transition/btl2",
        "expected_sha1": "4867c27391463f6144ac876476edcebd33c4e959",
    },
}


def _leaf(symbol, rom_start):
    meta = LEAF_META[symbol]
    return {
        "id": symbol,
        "symbol": symbol,
        "rom_start": rom_start,
        "rom_end": rom_start + LEAF_SIZE,
        "size": LEAF_SIZE,
        "format": LEAF_FORMAT,
        "png": f"{symbol}.png",
        "gbapal": f"{symbol}.gbapal",
        "consumer": meta["consumer"],
        "expected_sha1": meta["expected_sha1"],
    }


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
        "leaves": [
            _leaf("gUnk_09611AB8", 0x09611AB8),
            _leaf("gUnk_09614AB8", 0x09614AB8),
            _leaf("gUnk_09614D58", 0x09614D58),
            _leaf("gUnk_09618118", 0x09618118),
        ],
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
        "leaves": [
            _leaf("gUnk_09611AB8", 0x095CA594),
            _leaf("gUnk_09614AB8", 0x095CD594),
            _leaf("gUnk_09614D58", 0x095CD834),
            _leaf("gUnk_09618118", 0x095D0BF4),
        ],
    },
    "eu": {
        # Leaves live in the large EU gap_38 mega, not asm/eu/asset_gfx_gap_43.s.
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
        "leaves": [
            _leaf("gUnk_09611AB8", 0x09544B24),
            _leaf("gUnk_09614AB8", 0x095479A4),
            _leaf("gUnk_09614D58", 0x09547C44),
            _leaf("gUnk_09618118", 0x0954B004),
        ],
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


def leaf_offset(spec, leaf):
    return leaf["rom_start"] - spec["rom_base"]


def leaf_bytes(data, spec, leaf):
    off = leaf_offset(spec, leaf)
    size = leaf["size"]
    return data[off : off + size]


def expected_pack_size(spec):
    return spec["pack_end"] - spec["rom_base"]
