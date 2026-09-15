"""Layout for asset_gfx_gap_158 host mega + palette leaves (32B each).

Parent mega stays slice until fuller pack RE. Built mode rebuilds listed leaves via
gbagfx PNG(indexed)->gbapal and patches them into a copy of the extract slice.
MovieOpen asset_gfx remux is intentionally untouched.

Deferred: gUnk_0984A778 / gUnk_0984A7B8 (indexed dual-bank arrays via title.c t=0|0x20);
gUnk_0984A618 LoadBgPalette 0xA0 multi-bank.
"""
import hashlib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

LEAF_SIZE = 0x20
LEAF_FORMAT = "palette"

# Shared leaf metadata (rom addresses are per-version below).
# Consumers: LoadObjPalette(..., 0x20) title / mode_title.
LEAF_META = {
    "gUnk_0984A6B8": {
        "consumer": "LoadObjPalette(..., 0x20) mode_title",
        "expected_sha1": "9194c1ed5dc3a47091f61fc656a57ddd762120f8",
    },
    "gUnk_0984A6D8": {
        "consumer": "LoadObjPalette(..., 0x20) mode_title",
        "expected_sha1": "acc3c311fd5e8d8462df57cb2b9d62de3e97b6b1",
    },
    "gUnk_0984A6F8": {
        "consumer": "LoadObjPalette(..., 0x20) mode_title",
        "expected_sha1": "fb247e9bfdd46ddfa4e05f44b70301dd704e51c2",
    },
    "gUnk_0984A718": {
        "consumer": "LoadObjPalette(..., 0x20) mode_title/title",
        "expected_sha1": "470372cfb34583c77e5024c845a2b4d582c3cbe9",
    },
    "gUnk_0984A738": {
        "consumer": "LoadObjPalette(..., 0x20) mode_title",
        "expected_sha1": "4758be661b3c7eed43f3d251132d9c7b40906710",
    },
    "gUnk_0984A7D8": {
        "consumer": "LoadObjPalette(..., 0x20) title",
        "expected_sha1": "080deda1b378766a85e27bbe2229f2efee36edf1",
    },
    "gUnk_0984A7F8": {
        "consumer": "LoadObjPalette(..., 0x20) title",
        "expected_sha1": "8326f05e915f60c03ae463afe7b063a3c4090412",
    },
    "gUnk_0984AA18": {
        "consumer": "LoadObjPalette(..., 0x20) mode_title",
        "expected_sha1": "0602dc3b4dbc2969eb41f63d82d808c7f8967395",
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
        "rom_base": 0x096FE36C,
        "pack_end": 0x0984B838,
        "extract": ROOT / "assets" / "us" / "096FE36C-0984B838.bin",
        "build": ROOT / "build" / "us" / "assets" / "asset_gfx_gap_158.bin",
        "source_root": ROOT / "assets" / "us" / "src" / "gfx" / "asset_gfx_gap_158",
        "manifest": ROOT / "config" / "asset_gfx_gap_158_us.yaml",
        "inventory": ROOT / "config" / "asset_inventory_us_gfx_gap_158.yaml",
        "asm_unit": "asset_gfx_gap_158.s",
        "global_sym": "data_096FE36C",
        "expected_sha256": "3b671f1478c5dc20dc09d1f8d6da00806d3d9fd02c418c41e48764e2b0db767f",
        "leaves": [
            _leaf("gUnk_0984A6B8", 0x0984A6B8),
            _leaf("gUnk_0984A6D8", 0x0984A6D8),
            _leaf("gUnk_0984A6F8", 0x0984A6F8),
            _leaf("gUnk_0984A718", 0x0984A718),
            _leaf("gUnk_0984A738", 0x0984A738),
            _leaf("gUnk_0984A7D8", 0x0984A7D8),
            _leaf("gUnk_0984A7F8", 0x0984A7F8),
            _leaf("gUnk_0984AA18", 0x0984AA18),
        ],
    },
    "jp": {
        "rom_base": 0x096B6B48,
        "pack_end": 0x0980034C,
        "extract": ROOT / "assets" / "jp" / "096B6B48-0980034C.bin",
        "build": ROOT / "build" / "jp" / "assets" / "asset_gfx_gap_158.bin",
        "source_root": ROOT / "assets" / "jp" / "src" / "gfx" / "asset_gfx_gap_158",
        "manifest": ROOT / "config" / "asset_gfx_gap_158_jp.yaml",
        "inventory": ROOT / "config" / "asset_inventory_jp_gfx_gap_158.yaml",
        "asm_unit": "asset_gfx_gap_158.s",
        "global_sym": "data_096B6B48",
        "expected_sha256": "1617c8eb98110ff85c1ebaf6513c4c16370038469538478d114bc244342643cd",
        "leaves": [
            _leaf("gUnk_0984A6B8", 0x097FF38C),
            _leaf("gUnk_0984A6D8", 0x097FF3AC),
            _leaf("gUnk_0984A6F8", 0x097FF3CC),
            _leaf("gUnk_0984A718", 0x097FF3EC),
            _leaf("gUnk_0984A738", 0x097FF40C),
            _leaf("gUnk_0984A7D8", 0x097FF4AC),
            _leaf("gUnk_0984A7F8", 0x097FF4CC),
            _leaf("gUnk_0984AA18", 0x097FF6EC),
        ],
    },
    "eu": {
        "rom_base": 0x096CB6CC,
        "pack_end": 0x0982820C,
        "extract": ROOT / "assets" / "eu" / "096CB6CC-0982820C.bin",
        "build": ROOT / "build" / "eu" / "assets" / "asset_gfx_gap_158.bin",
        "source_root": ROOT / "assets" / "eu" / "src" / "gfx" / "asset_gfx_gap_158",
        "manifest": ROOT / "config" / "asset_gfx_gap_158_eu.yaml",
        "inventory": ROOT / "config" / "asset_inventory_eu_gfx_gap_158.yaml",
        "asm_unit": "asset_gfx_gap_158.s",
        "global_sym": "data_096CB6CC",
        "expected_sha256": "608e18a851c2c35a6bb9de5a222f1aea19fa4ed449226eda9153175a7f7b5aa8",
        "leaves": [
            _leaf("gUnk_0984A6B8", 0x0981ED60),
            _leaf("gUnk_0984A6D8", 0x0981ED80),
            _leaf("gUnk_0984A6F8", 0x0981EDA0),
            _leaf("gUnk_0984A718", 0x0981EDC0),
            _leaf("gUnk_0984A738", 0x0981EDE0),
            _leaf("gUnk_0984A7D8", 0x0981EE80),
            _leaf("gUnk_0984A7F8", 0x0981EEA0),
            _leaf("gUnk_0984AA18", 0x0981F0C0),
        ],
    },
}


def version_spec(version):
    if version not in VERSIONS:
        raise ValueError(f"unknown asset_gfx_gap_158 version: {version}")
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
