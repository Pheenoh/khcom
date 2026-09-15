"""Layout for asset_gfx_gap_195 host mega + palette leaves (32B each).

Parent mega stays slice until fuller pack RE. Built mode rebuilds listed leaves via
gbagfx PNG(indexed)->gbapal and patches them into a copy of the extract slice.
MovieOpen asset_gfx remux is intentionally untouched.
"""
import hashlib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

LEAF_SIZE = 0x20
LEAF_FORMAT = "palette"

# Shared leaf metadata (rom addresses are per-version below).
# Consumers: LoadObjPalette(..., 0x20) / LoadObjPalette(..., 32).
LEAF_META = {
    "gUnk_09A3C89C": {
        "consumer": "LoadObjPalette(..., 32) bos5",
        "expected_sha1": "5da586ba31e87f088db8a8e6b23afdc0a4d08044",
    },
    "gUnk_09A3C97C": {
        "consumer": "LoadObjPalette(..., 32) bos5",
        "expected_sha1": "f47145c22d9fdb72c4aac2250d250a505fe5dacd",
    },
    "gUnk_09A3C99C": {
        "consumer": "LoadObjPalette(..., 32) bos5",
        "expected_sha1": "e5895f3bd934b7d32dd2e96a8122db856d53ca2f",
    },
    "gUnk_09A3C9BC": {
        "consumer": "LoadObjPalette(..., 32) bos5",
        "expected_sha1": "d7b494010b18ed49ec3471489d1f40de493bc02e",
    },
    "gUnk_09A3CC3C": {
        "consumer": "LoadObjPalette(..., 32) bos5",
        "expected_sha1": "bf51a0326246b202cd501f21e197bba1c9362018",
    },
    "gUnk_09A3CC5C": {
        "consumer": "LoadObjPalette(..., 32) bos5",
        "expected_sha1": "fb3509387ac30452cb2eb4ac5f3a5b7c1f9d0454",
    },
    "gUnk_09A3CC7C": {
        "consumer": "LoadObjPalette(..., 32) bos5",
        "expected_sha1": "7c22253ceda86021426c1297908e054676d05859",
    },
    "gUnk_09A3CC9C": {
        "consumer": "LoadObjPalette(..., 0x20) mode_jiminy",
        "expected_sha1": "099b710e870ff122d89615001ad4be7a61026b21",
    },
    "gUnk_09A3D07C": {
        "consumer": "LoadObjPalette(..., 32) bos5/mode_worldinspect",
        "expected_sha1": "48b9c6232707e66a4630e7451788b310a3a580e4",
    },
    "gUnk_09A3D09C": {
        "consumer": "LoadObjPalette(..., 0x20) mode_worldinspect",
        "expected_sha1": "715e9a30cb6280f400388a34dd3ed031bcc3a033",
    },
    "gUnk_09A3D0BC": {
        "consumer": "LoadObjPalette(..., 0x20) mode_worldinspect",
        "expected_sha1": "ac63649ee098c799ad4e03781c54bc1c959d906a",
    },
    "gUnk_09A3D2DC": {
        "consumer": "LoadObjPalette(..., 0x20) mode_mapinspect",
        "expected_sha1": "dc1c394483e795a1adf63ab5ba27dac00a0db865",
    },
    "gUnk_09A3D57C": {
        "consumer": "LoadObjPalette(..., 32) mode_worldwarp",
        "expected_sha1": "0eeecb1d1e9b234d4623b091fd7f8bce60c6bc46",
    },
    "gUnk_09A3D59C": {
        "consumer": "LoadObjPalette(..., 32) mode_worldwarp",
        "expected_sha1": "e6bc11348dc0da8364f7adf8db1aa8253c4f99b2",
    },
    "gUnk_09A3D5BC": {
        "consumer": "LoadObjPalette(..., 32) mode_worldwarp",
        "expected_sha1": "ac63649ee098c799ad4e03781c54bc1c959d906a",
    },
    "gUnk_09A3D7FC": {
        "consumer": "LoadObjPalette(..., 0x20) mode_ms",
        "expected_sha1": "a610dd5bb4bd63eaff341e540913743bddbda083",
    },
    "gUnk_09A3D85C": {
        "consumer": "LoadObjPalette(..., 0x20) mode_ms",
        "expected_sha1": "0993deb6471323bbc732b4eca512deb79abd35a9",
    },
    "gUnk_09A3DA7C": {
        "consumer": "LoadObjPalette(..., 0x20) mode_ms",
        "expected_sha1": "d6f823392f2666e293585e08fa36c4f1b502c4b4",
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
        "leaves": [
            _leaf("gUnk_09A3C89C", 0x09A3C89C),
            _leaf("gUnk_09A3C97C", 0x09A3C97C),
            _leaf("gUnk_09A3C99C", 0x09A3C99C),
            _leaf("gUnk_09A3C9BC", 0x09A3C9BC),
            _leaf("gUnk_09A3CC3C", 0x09A3CC3C),
            _leaf("gUnk_09A3CC5C", 0x09A3CC5C),
            _leaf("gUnk_09A3CC7C", 0x09A3CC7C),
            _leaf("gUnk_09A3CC9C", 0x09A3CC9C),
            _leaf("gUnk_09A3D07C", 0x09A3D07C),
            _leaf("gUnk_09A3D09C", 0x09A3D09C),
            _leaf("gUnk_09A3D0BC", 0x09A3D0BC),
            _leaf("gUnk_09A3D2DC", 0x09A3D2DC),
            _leaf("gUnk_09A3D57C", 0x09A3D57C),
            _leaf("gUnk_09A3D59C", 0x09A3D59C),
            _leaf("gUnk_09A3D5BC", 0x09A3D5BC),
            _leaf("gUnk_09A3D7FC", 0x09A3D7FC),
            _leaf("gUnk_09A3D85C", 0x09A3D85C),
            _leaf("gUnk_09A3DA7C", 0x09A3DA7C),
        ],
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
        "leaves": [
            _leaf("gUnk_09A3C89C", 0x099F1324),
            _leaf("gUnk_09A3C97C", 0x099F1404),
            _leaf("gUnk_09A3C99C", 0x099F1424),
            _leaf("gUnk_09A3C9BC", 0x099F1444),
            _leaf("gUnk_09A3CC3C", 0x099F16C4),
            _leaf("gUnk_09A3CC5C", 0x099F16E4),
            _leaf("gUnk_09A3CC7C", 0x099F1704),
            _leaf("gUnk_09A3CC9C", 0x099F1724),
            _leaf("gUnk_09A3D07C", 0x099F1B04),
            _leaf("gUnk_09A3D09C", 0x099F1B24),
            _leaf("gUnk_09A3D0BC", 0x099F1B44),
            _leaf("gUnk_09A3D2DC", 0x099F1D64),
            _leaf("gUnk_09A3D57C", 0x099F2004),
            _leaf("gUnk_09A3D59C", 0x099F2024),
            _leaf("gUnk_09A3D5BC", 0x099F2044),
            _leaf("gUnk_09A3D7FC", 0x099F2284),
            _leaf("gUnk_09A3D85C", 0x099F22E4),
            _leaf("gUnk_09A3DA7C", 0x099F2504),
        ],
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
        "leaves": [
            _leaf("gUnk_09A3C89C", 0x09A9A360),
            _leaf("gUnk_09A3C97C", 0x09A9A440),
            _leaf("gUnk_09A3C99C", 0x09A9A460),
            _leaf("gUnk_09A3C9BC", 0x09A9A480),
            _leaf("gUnk_09A3CC3C", 0x09A9A700),
            _leaf("gUnk_09A3CC5C", 0x09A9A720),
            _leaf("gUnk_09A3CC7C", 0x09A9A740),
            _leaf("gUnk_09A3CC9C", 0x09A9A760),
            _leaf("gUnk_09A3D07C", 0x09A9AB40),
            _leaf("gUnk_09A3D09C", 0x09A9AB60),
            _leaf("gUnk_09A3D0BC", 0x09A9AB80),
            _leaf("gUnk_09A3D2DC", 0x09A9ADA0),
            _leaf("gUnk_09A3D57C", 0x09A9B040),
            _leaf("gUnk_09A3D59C", 0x09A9B060),
            _leaf("gUnk_09A3D5BC", 0x09A9B080),
            _leaf("gUnk_09A3D7FC", 0x09A9B2C0),
            _leaf("gUnk_09A3D85C", 0x09A9B320),
            _leaf("gUnk_09A3DA7C", 0x09A9B540),
        ],
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


def leaf_offset(spec, leaf):
    return leaf["rom_start"] - spec["rom_base"]


def leaf_bytes(data, spec, leaf):
    off = leaf_offset(spec, leaf)
    size = leaf["size"]
    return data[off : off + size]


def expected_pack_size(spec):
    return spec["pack_end"] - spec["rom_base"]
