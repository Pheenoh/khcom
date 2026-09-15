#!/usr/bin/env python3
"""Dual-path pack helper for asset_gfx_gap_43 leaf gUnk_09618118 (palette).

slice (default): host mega remains baserom extract .incbin.
built: gbagfx PNG(indexed)->gbapal for the leaf, patch into mega copy.

Does not touch MovieOpen asset_gfx remux / asset_fmv.
"""
import argparse
import struct
import subprocess
import sys
import zlib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools" / "gfx"))
from asset_gfx_gap_43_layout import (
    VERSIONS,
    expected_pack_size,
    leaf_bytes,
    leaf_offset,
    sha1_hex,
    sha256_hex,
    version_spec,
)

GBAGFX = ROOT / "tools" / "gbagfx" / "gbagfx"


def _upconvert_5(c):
    return (c << 3) | (c >> 2)


def gba_pal_to_rgb8(entry):
    r = entry & 0x1F
    g = (entry >> 5) & 0x1F
    b = (entry >> 10) & 0x1F
    return _upconvert_5(r), _upconvert_5(g), _upconvert_5(b)


def write_indexed_palette_png(path, gbapal):
    """Write a 16x1 indexed PNG whose PLTE has exactly len(gbapal)/2 colors."""
    if len(gbapal) % 2:
        raise ValueError("gbapal size must be even")
    n = len(gbapal) // 2
    if n < 1 or n > 256:
        raise ValueError(f"unsupported palette color count: {n}")
    plte = bytearray()
    for i in range(0, len(gbapal), 2):
        entry = gbapal[i] | (gbapal[i + 1] << 8)
        plte.extend(gba_pal_to_rgb8(entry))
    width, height = n, 1
    raw = b"\x00" + bytes(range(n))

    def chunk(tag, data):
        return struct.pack(">I", len(data)) + tag + data + struct.pack(
            ">I", zlib.crc32(tag + data) & 0xFFFFFFFF
        )

    ihdr = struct.pack(">IIBBBBB", width, height, 8, 3, 0, 0, 0)
    png = (
        b"\x89PNG\r\n\x1a\n"
        + chunk(b"IHDR", ihdr)
        + chunk(b"PLTE", bytes(plte))
        + chunk(b"IDAT", zlib.compress(raw))
        + chunk(b"IEND", b"")
    )
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(png)


def require_extract(spec):
    extract = spec["extract"]
    if not extract.exists():
        raise FileNotFoundError(
            f"missing {extract}; run python3 tools/extract_assets.py <version>"
        )
    data = extract.read_bytes()
    expected = expected_pack_size(spec)
    if len(data) != expected:
        raise ValueError(f"slice size {len(data)} != expected {expected}")
    digest = sha256_hex(data)
    if digest != spec["expected_sha256"]:
        raise ValueError(f"slice sha256 mismatch: {digest}")
    return data


def require_gbagfx():
    if not GBAGFX.exists():
        raise FileNotFoundError(
            f"missing {GBAGFX}; run sh tools/fetch_gbagfx.sh"
        )


def gbagfx_png_to_gbapal(png_path, out_path):
    require_gbagfx()
    out_path.parent.mkdir(parents=True, exist_ok=True)
    subprocess.check_call([str(GBAGFX), str(png_path), str(out_path)])


def cmd_status(version):
    spec = version_spec(version)
    extract = spec["extract"]
    leaf = spec["leaf"]
    print(f"version {version}")
    print(f"manifest {spec['manifest'].relative_to(ROOT)}")
    print(f"unit {spec['asm_unit']} sym {spec['global_sym']}")
    print(f"path_mode_default slice")
    print(f"leaf {leaf['id']} rom=0x{leaf['rom_start']:08X} size={leaf['size']} format={leaf['format']}")
    print(f"gbagfx_present {GBAGFX.exists()}")
    if not extract.exists():
        print(f"slice missing {extract.relative_to(ROOT)}")
        return 1
    data = extract.read_bytes()
    digest = sha256_hex(data)
    ok = digest == spec["expected_sha256"] and len(data) == expected_pack_size(spec)
    print(f"slice {extract.relative_to(ROOT)}")
    print(f"sha256 {digest}")
    print(f"match_expected {ok}")
    pal = leaf_bytes(data, spec)
    print(f"leaf_sha1 {sha1_hex(pal)}")
    print(f"leaf_match_expected {sha1_hex(pal) == leaf['expected_sha1']}")
    print(f"built_present {spec['build'].exists()}")
    if spec["build"].exists():
        built = spec["build"].read_bytes()
        print(f"built_sha256 {sha256_hex(built)}")
        print(f"built_matches_slice {sha256_hex(built) == spec['expected_sha256']}")
        bpal = leaf_bytes(built, spec)
        print(f"built_leaf_sha1 {sha1_hex(bpal)}")
        print(f"built_leaf_match {sha1_hex(bpal) == leaf['expected_sha1']}")
    src = spec["source_root"]
    print(f"source_root_present {(src / leaf['png']).exists()}")
    return 0 if ok else 1


def cmd_dump(version):
    spec = version_spec(version)
    data = require_extract(spec)
    leaf = spec["leaf"]
    pal = leaf_bytes(data, spec)
    if sha1_hex(pal) != leaf["expected_sha1"]:
        print(f"error: leaf sha1 mismatch: {sha1_hex(pal)}", file=sys.stderr)
        return 1
    root = spec["source_root"]
    root.mkdir(parents=True, exist_ok=True)
    gbapal_path = root / leaf["gbapal"]
    png_path = root / leaf["png"]
    gbapal_path.write_bytes(pal)
    write_indexed_palette_png(png_path, pal)
    # Prove gbagfx roundtrip when available.
    if GBAGFX.exists():
        tmp = root / ("." + leaf["gbapal"] + ".roundtrip.gbapal")
        gbagfx_png_to_gbapal(png_path, tmp)
        rt = tmp.read_bytes()
        tmp.unlink(missing_ok=True)
        if rt != pal:
            print("error: gbagfx PNG->gbapal roundtrip mismatch", file=sys.stderr)
            return 1
        print("gbagfx_roundtrip_ok True")
    else:
        print("gbagfx_roundtrip_ok skipped (gbagfx missing)")
    print(f"dumped {gbapal_path.relative_to(ROOT)}")
    print(f"dumped {png_path.relative_to(ROOT)}")
    print(f"leaf_sha1 {sha1_hex(pal)}")
    return 0


def ensure_png(spec):
    leaf = spec["leaf"]
    png_path = spec["source_root"] / leaf["png"]
    if png_path.exists():
        return png_path
    data = require_extract(spec)
    pal = leaf_bytes(data, spec)
    write_indexed_palette_png(png_path, pal)
    (spec["source_root"] / leaf["gbapal"]).write_bytes(pal)
    return png_path


def cmd_built(version):
    spec = version_spec(version)
    data = bytearray(require_extract(spec))
    leaf = spec["leaf"]
    png_path = ensure_png(spec)
    require_gbagfx()
    out_pal = spec["source_root"] / leaf["gbapal"]
    gbagfx_png_to_gbapal(png_path, out_pal)
    pal = out_pal.read_bytes()
    if len(pal) != leaf["size"]:
        print(
            f"error: built gbapal size {len(pal)} != {leaf['size']} "
            f"(PNG PLTE must have exactly {leaf['size'] // 2} colors)",
            file=sys.stderr,
        )
        return 1
    if sha1_hex(pal) != leaf["expected_sha1"]:
        print(f"error: built leaf sha1 mismatch: {sha1_hex(pal)}", file=sys.stderr)
        return 1
    off = leaf_offset(spec)
    data[off : off + leaf["size"]] = pal
    digest = sha256_hex(data)
    if digest != spec["expected_sha256"]:
        print(f"error: patched mega sha256 mismatch: {digest}", file=sys.stderr)
        return 1
    spec["build"].parent.mkdir(parents=True, exist_ok=True)
    spec["build"].write_bytes(data)
    print(f"built {spec['build'].relative_to(ROOT)}")
    print(f"sha256 {digest}")
    print(f"leaf_sha1 {sha1_hex(pal)}")
    print(f"match_expected True")
    print(f"source_png {png_path.relative_to(ROOT)}")
    return 0


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument(
        "--mode",
        choices=("slice", "built", "status", "dump"),
        default="status",
    )
    ap.add_argument("--version", choices=tuple(VERSIONS.keys()), default="us")
    args = ap.parse_args()
    try:
        if args.mode in ("status", "slice"):
            return cmd_status(args.version)
        if args.mode == "dump":
            return cmd_dump(args.version)
        if args.mode == "built":
            return cmd_built(args.version)
    except (FileNotFoundError, ValueError, subprocess.CalledProcessError) as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 1
    return 1


if __name__ == "__main__":
    sys.exit(main())
