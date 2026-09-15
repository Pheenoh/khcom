"""Layout for asset_gfx_gap_87 host mega + palette leaves (32B each).

Parent mega stays slice until fuller pack RE. Built mode rebuilds listed leaves via
gbagfx PNG(indexed)->gbapal and patches them into a copy of the extract slice.
MovieOpen asset_gfx remux is intentionally untouched.

Host unit: asset_gfx_gap_87_at_0961A9FD.s (US/JP/EU). Deferred: gUnk_096FBF04 (EU addr outside host mega).
"""
import hashlib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

LEAF_SIZE = 0x20
LEAF_FORMAT = "palette"

# Shared leaf metadata (rom addresses are per-version below).
# Consumers: LoadObjPalette(..., 0x20|32) wlogo / btl / bos2 / card / mode_sio.
LEAF_META = {
    "gUnk_096FAC64": {
        "consumer": "LoadObjPalette(..., 0x20) btl/btl3/btl4/mode_sio",
        "expected_sha1": "26cbeaad5636ffcd9f232dfbf3415ec9f22f4f0e",
    },
    "gUnk_096FAC84": {
        "consumer": "LoadObjPalette(..., 0x20) wlogo",
        "expected_sha1": "baccd56ffe5e97ba92ca0e5fddabadd7826af201",
    },
    "gUnk_096FACA4": {
        "consumer": "LoadObjPalette(..., 0x20) wlogo",
        "expected_sha1": "2d4d07ad2e965d1ce327af22f26e8e9ef5fdd16b",
    },
    "gUnk_096FAD64": {
        "consumer": "LoadObjPalette(..., 0x20) wlogo",
        "expected_sha1": "c9c5d876f113052e9829dcfee3dd53a9baab0fee",
    },
    "gUnk_096FADA4": {
        "consumer": "LoadObjPalette(..., 0x20) wlogo",
        "expected_sha1": "6a07d0fbd1d4e91d9ee1dc27b350ef1e6eb6fa21",
    },
    "gUnk_096FADC4": {
        "consumer": "LoadObjPalette(..., 0x20) wlogo",
        "expected_sha1": "27172a96661c6ff1d8fda991c903beedcdecadf3",
    },
    "gUnk_096FADE4": {
        "consumer": "LoadObjPalette(..., 0x20) wlogo",
        "expected_sha1": "b74ece71dd3ebfeede88033519404199afa600f4",
    },
    "gUnk_096FAE24": {
        "consumer": "LoadObjPalette(..., 0x20) wlogo",
        "expected_sha1": "0ed21cccf46c1243906b44b27431e630d94e3bdf",
    },
    "gUnk_096FAE44": {
        "consumer": "LoadObjPalette(..., 0x20) wlogo",
        "expected_sha1": "ebf11d6197c1be7956ca4925a77a50a01c99f1b4",
    },
    "gUnk_096FAE64": {
        "consumer": "LoadObjPalette(..., 0x20) wlogo",
        "expected_sha1": "68317193a78d3a6dc9a76210b8000b7b667ee0f3",
    },
    "gUnk_096FAE84": {
        "consumer": "LoadObjPalette(..., 0x20) wlogo",
        "expected_sha1": "3954f178a7e07bb82850abbc01676c8b92e8587e",
    },
    "gUnk_096FB0A4": {
        "consumer": "LoadObjPalette(..., 0x20) wlogo",
        "expected_sha1": "2d7587c6d6b4187eec6dc69a4cad469e65b4993f",
    },
    "gUnk_096FB864": {
        "consumer": "LoadObjPalette(..., 32) bos2",
        "expected_sha1": "b799dff6a74402399695aaafe8a2d45eca4b9621",
    },
    "gUnk_096FB884": {
        "consumer": "LoadObjPalette(..., 32) bos2",
        "expected_sha1": "f0f70362d09d2fd1bc4dd10dd82c5ba3e83834fa",
    },
    "gUnk_096FB8C4": {
        "consumer": "LoadObjPalette(..., 32) bos2",
        "expected_sha1": "c6bb0c82f19d523591ebdb3ddaea9eef107174e0",
    },
    "gUnk_096FB8E4": {
        "consumer": "LoadObjPalette(..., 32) bos2",
        "expected_sha1": "07c5a0158c6a833f4af26636df034012c59e0b86",
    },
    "gUnk_096FBA44": {
        "consumer": "LoadObjPalette(..., 32) card",
        "expected_sha1": "d4b1d67bbbc328f9b1120ef0dddfc562ff4ca800",
    },
    "gUnk_096FBA64": {
        "consumer": "LoadObjPalette(..., 32) card",
        "expected_sha1": "c8d773710a128b67553a87ae70f496cd28b49785",
    },
    "gUnk_096FBA84": {
        "consumer": "LoadObjPalette(..., 32) card",
        "expected_sha1": "331c2b2f8d303ab649e62170b51ea813073c5806",
    },
    "gUnk_096FBAA4": {
        "consumer": "LoadObjPalette(..., 32) card/mode_sio",
        "expected_sha1": "d6f823392f2666e293585e08fa36c4f1b502c4b4",
    },
    "gUnk_096FBCC4": {
        "consumer": "LoadObjPalette(..., 32) mode_sio",
        "expected_sha1": "8528a9cfdf40e717468a2899110b9b0666e6036e",
    },
    "gUnk_096FBD24": {
        "consumer": "LoadObjPalette(..., 32) mode_sio",
        "expected_sha1": "48153af31e38e2344a761160bb63451c15cce280",
    },
    "gUnk_096FBD44": {
        "consumer": "LoadObjPalette(..., 32) mode_sio",
        "expected_sha1": "d6f823392f2666e293585e08fa36c4f1b502c4b4",
    },
    "gUnk_096FBD64": {
        "consumer": "LoadObjPalette(..., 32) mode_sio",
        "expected_sha1": "0f777be0a8db0c1e1e4a14ddecf21edd7464ed23",
    },
    "gUnk_096FBDA4": {
        "consumer": "LoadObjPalette(..., 32) mode_sio",
        "expected_sha1": "6c5e46550f4e010e0b6b76373de9d35d1ed7c623",
    },
    "gUnk_096FBDE4": {
        "consumer": "LoadObjPalette(..., 32) mode_sio",
        "expected_sha1": "11a00e481d990c41c505e92c5b2eeba8815cbc77",
    },
    "gUnk_096FBE04": {
        "consumer": "LoadObjPalette(..., 32) mode_sio",
        "expected_sha1": "559e70ea6c2c2d4de1d880ca92614163129c79e0",
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
        "rom_base": 0x0961A9FD,
        "pack_end": 0x096FC004,
        "extract": ROOT / "assets" / "us" / "0961A9FD-096FC004.bin",
        "build": ROOT / "build" / "us" / "assets" / "asset_gfx_gap_87.bin",
        "source_root": ROOT / "assets" / "us" / "src" / "gfx" / "asset_gfx_gap_87",
        "manifest": ROOT / "config" / "asset_gfx_gap_87_us.yaml",
        "inventory": ROOT / "config" / "asset_inventory_us_gfx_gap_87.yaml",
        "asm_unit": "asset_gfx_gap_87_at_0961A9FD.s",
        "global_sym": "data_0961A9FD",
        "expected_sha256": "ca73a09e27ecc2b17b6e76d4175ba119d15ffffe2caf9ae031203e4231f10e70",
        "leaves": [
            _leaf("gUnk_096FAC64", 0x096FAC64),
            _leaf("gUnk_096FAC84", 0x096FAC84),
            _leaf("gUnk_096FACA4", 0x096FACA4),
            _leaf("gUnk_096FAD64", 0x096FAD64),
            _leaf("gUnk_096FADA4", 0x096FADA4),
            _leaf("gUnk_096FADC4", 0x096FADC4),
            _leaf("gUnk_096FADE4", 0x096FADE4),
            _leaf("gUnk_096FAE24", 0x096FAE24),
            _leaf("gUnk_096FAE44", 0x096FAE44),
            _leaf("gUnk_096FAE64", 0x096FAE64),
            _leaf("gUnk_096FAE84", 0x096FAE84),
            _leaf("gUnk_096FB0A4", 0x096FB0A4),
            _leaf("gUnk_096FB864", 0x096FB864),
            _leaf("gUnk_096FB884", 0x096FB884),
            _leaf("gUnk_096FB8C4", 0x096FB8C4),
            _leaf("gUnk_096FB8E4", 0x096FB8E4),
            _leaf("gUnk_096FBA44", 0x096FBA44),
            _leaf("gUnk_096FBA64", 0x096FBA64),
            _leaf("gUnk_096FBA84", 0x096FBA84),
            _leaf("gUnk_096FBAA4", 0x096FBAA4),
            _leaf("gUnk_096FBCC4", 0x096FBCC4),
            _leaf("gUnk_096FBD24", 0x096FBD24),
            _leaf("gUnk_096FBD44", 0x096FBD44),
            _leaf("gUnk_096FBD64", 0x096FBD64),
            _leaf("gUnk_096FBDA4", 0x096FBDA4),
            _leaf("gUnk_096FBDE4", 0x096FBDE4),
            _leaf("gUnk_096FBE04", 0x096FBE04),
        ],
    },
    "jp": {
        "rom_base": 0x095D34D9,
        "pack_end": 0x096B47E0,
        "extract": ROOT / "assets" / "jp" / "095D34D9-096B47E0.bin",
        "build": ROOT / "build" / "jp" / "assets" / "asset_gfx_gap_87.bin",
        "source_root": ROOT / "assets" / "jp" / "src" / "gfx" / "asset_gfx_gap_87",
        "manifest": ROOT / "config" / "asset_gfx_gap_87_jp.yaml",
        "inventory": ROOT / "config" / "asset_inventory_jp_gfx_gap_87.yaml",
        "asm_unit": "asset_gfx_gap_87_at_0961A9FD.s",
        "global_sym": "data_095D34D9",
        "expected_sha256": "b215bc82381e391b73494dbd1222786b814b335e77c75e7e2da09205b5f8368d",
        "leaves": [
            _leaf("gUnk_096FAC64", 0x096B3440),
            _leaf("gUnk_096FAC84", 0x096B3460),
            _leaf("gUnk_096FACA4", 0x096B3480),
            _leaf("gUnk_096FAD64", 0x096B3540),
            _leaf("gUnk_096FADA4", 0x096B3580),
            _leaf("gUnk_096FADC4", 0x096B35A0),
            _leaf("gUnk_096FADE4", 0x096B35C0),
            _leaf("gUnk_096FAE24", 0x096B3600),
            _leaf("gUnk_096FAE44", 0x096B3620),
            _leaf("gUnk_096FAE64", 0x096B3640),
            _leaf("gUnk_096FAE84", 0x096B3660),
            _leaf("gUnk_096FB0A4", 0x096B3880),
            _leaf("gUnk_096FB864", 0x096B4040),
            _leaf("gUnk_096FB884", 0x096B4060),
            _leaf("gUnk_096FB8C4", 0x096B40A0),
            _leaf("gUnk_096FB8E4", 0x096B40C0),
            _leaf("gUnk_096FBA44", 0x096B4220),
            _leaf("gUnk_096FBA64", 0x096B4240),
            _leaf("gUnk_096FBA84", 0x096B4260),
            _leaf("gUnk_096FBAA4", 0x096B4280),
            _leaf("gUnk_096FBCC4", 0x096B44A0),
            _leaf("gUnk_096FBD24", 0x096B4500),
            _leaf("gUnk_096FBD44", 0x096B4520),
            _leaf("gUnk_096FBD64", 0x096B4540),
            _leaf("gUnk_096FBDA4", 0x096B4580),
            _leaf("gUnk_096FBDE4", 0x096B45C0),
            _leaf("gUnk_096FBE04", 0x096B45E0),
        ],
    },
    "eu": {
        "rom_base": 0x095DBEDD,
        "pack_end": 0x096C934C,
        "extract": ROOT / "assets" / "eu" / "095DBEDD-096C934C.bin",
        "build": ROOT / "build" / "eu" / "assets" / "asset_gfx_gap_87.bin",
        "source_root": ROOT / "assets" / "eu" / "src" / "gfx" / "asset_gfx_gap_87",
        "manifest": ROOT / "config" / "asset_gfx_gap_87_eu.yaml",
        "inventory": ROOT / "config" / "asset_inventory_eu_gfx_gap_87.yaml",
        "asm_unit": "asset_gfx_gap_87_at_0961A9FD.s",
        "global_sym": "data_095DBEDD",
        "expected_sha256": "9df28ac8c7f8b75f17c419c1c0be71d49d21b49844845fbcffdd89c6873bbef7",
        "leaves": [
            _leaf("gUnk_096FAC64", 0x096C818C),
            _leaf("gUnk_096FAC84", 0x096C81AC),
            _leaf("gUnk_096FACA4", 0x096C81CC),
            _leaf("gUnk_096FAD64", 0x096C828C),
            _leaf("gUnk_096FADA4", 0x096C82CC),
            _leaf("gUnk_096FADC4", 0x096C82EC),
            _leaf("gUnk_096FADE4", 0x096C830C),
            _leaf("gUnk_096FAE24", 0x096C834C),
            _leaf("gUnk_096FAE44", 0x096C836C),
            _leaf("gUnk_096FAE64", 0x096C838C),
            _leaf("gUnk_096FAE84", 0x096C83AC),
            _leaf("gUnk_096FB0A4", 0x096C85CC),
            _leaf("gUnk_096FB864", 0x096C8D8C),
            _leaf("gUnk_096FB884", 0x096C8DAC),
            _leaf("gUnk_096FB8C4", 0x096C8DEC),
            _leaf("gUnk_096FB8E4", 0x096C8E0C),
            _leaf("gUnk_096FBA44", 0x096C8F6C),
            _leaf("gUnk_096FBA64", 0x096C8F8C),
            _leaf("gUnk_096FBA84", 0x096C8FAC),
            _leaf("gUnk_096FBAA4", 0x096C8FCC),
            _leaf("gUnk_096FBCC4", 0x096C91EC),
            _leaf("gUnk_096FBD24", 0x096C924C),
            _leaf("gUnk_096FBD44", 0x096C926C),
            _leaf("gUnk_096FBD64", 0x096C928C),
            _leaf("gUnk_096FBDA4", 0x096C92CC),
            _leaf("gUnk_096FBDE4", 0x096C930C),
            _leaf("gUnk_096FBE04", 0x096C932C),
        ],
    },
}


def version_spec(version):
    if version not in VERSIONS:
        raise ValueError(f"unknown asset_gfx_gap_87 version: {version}")
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
