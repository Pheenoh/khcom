#!/usr/bin/env python3
"""Dual-path pack helper for asset_gfx_gap_1 leaf gUnk_08C6A88C (tiles4).

slice (default): host mega remains baserom extract .incbin.
built: gbagfx PNG->.4bpp (-num_tiles 2) for the leaf, patch into mega copy.

Does not touch MovieOpen asset_gfx remux / asset_fmv.
"""
import argparse
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools" / "gfx"))
from asset_gfx_gap_1_layout import (
    VERSIONS,
    expected_pack_size,
    leaf_bytes,
    leaf_offset,
    sha1_hex,
    sha256_hex,
    version_spec,
)

GBAGFX = ROOT / "tools" / "gbagfx" / "gbagfx"


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


def gbagfx_4bpp_to_png(fourbpp_path, png_path, width=1):
    require_gbagfx()
    png_path.parent.mkdir(parents=True, exist_ok=True)
    subprocess.check_call(
        [str(GBAGFX), str(fourbpp_path), str(png_path), "-width", str(width)]
    )


def gbagfx_png_to_4bpp(png_path, out_path, num_tiles=2):
    require_gbagfx()
    out_path.parent.mkdir(parents=True, exist_ok=True)
    subprocess.check_call(
        [str(GBAGFX), str(png_path), str(out_path), "-num_tiles", str(num_tiles)]
    )


def cmd_status(version):
    spec = version_spec(version)
    extract = spec["extract"]
    leaf = spec["leaf"]
    print(f"version {version}")
    print(f"manifest {spec['manifest'].relative_to(ROOT)}")
    print(f"unit {spec['asm_unit']} sym {spec['global_sym']}")
    print(f"path_mode_default slice")
    print(
        f"leaf {leaf['id']} rom=0x{leaf['rom_start']:08X} size={leaf['size']} "
        f"format={leaf['format']} num_tiles={leaf['num_tiles']}"
    )
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
    tiles = leaf_bytes(data, spec)
    print(f"leaf_sha1 {sha1_hex(tiles)}")
    print(f"leaf_match_expected {sha1_hex(tiles) == leaf['expected_sha1']}")
    print(f"built_present {spec['build'].exists()}")
    if spec["build"].exists():
        built = spec["build"].read_bytes()
        print(f"built_sha256 {sha256_hex(built)}")
        print(f"built_matches_slice {sha256_hex(built) == spec['expected_sha256']}")
        btiles = leaf_bytes(built, spec)
        print(f"built_leaf_sha1 {sha1_hex(btiles)}")
        print(f"built_leaf_match {sha1_hex(btiles) == leaf['expected_sha1']}")
    src = spec["source_root"]
    print(f"source_root_present {(src / leaf['png']).exists()}")
    return 0 if ok else 1


def cmd_dump(version):
    spec = version_spec(version)
    data = require_extract(spec)
    leaf = spec["leaf"]
    tiles = leaf_bytes(data, spec)
    if sha1_hex(tiles) != leaf["expected_sha1"]:
        print(f"error: leaf sha1 mismatch: {sha1_hex(tiles)}", file=sys.stderr)
        return 1
    root = spec["source_root"]
    root.mkdir(parents=True, exist_ok=True)
    fourbpp_path = root / leaf["fourbpp"]
    png_path = root / leaf["png"]
    fourbpp_path.write_bytes(tiles)
    require_gbagfx()
    gbagfx_4bpp_to_png(fourbpp_path, png_path, width=1)
    # Prove gbagfx roundtrip PNG -> .4bpp with -num_tiles 2.
    tmp = root / ("." + leaf["fourbpp"] + ".roundtrip.4bpp")
    gbagfx_png_to_4bpp(png_path, tmp, num_tiles=leaf["num_tiles"])
    rt = tmp.read_bytes()
    tmp.unlink(missing_ok=True)
    if rt != tiles:
        print("error: gbagfx PNG->4bpp roundtrip mismatch", file=sys.stderr)
        return 1
    print("gbagfx_roundtrip_ok True")
    print(f"dumped {fourbpp_path.relative_to(ROOT)}")
    print(f"dumped {png_path.relative_to(ROOT)}")
    print(f"leaf_sha1 {sha1_hex(tiles)}")
    return 0


def ensure_png(spec):
    leaf = spec["leaf"]
    png_path = spec["source_root"] / leaf["png"]
    if png_path.exists():
        return png_path
    data = require_extract(spec)
    tiles = leaf_bytes(data, spec)
    fourbpp_path = spec["source_root"] / leaf["fourbpp"]
    fourbpp_path.parent.mkdir(parents=True, exist_ok=True)
    fourbpp_path.write_bytes(tiles)
    gbagfx_4bpp_to_png(fourbpp_path, png_path, width=1)
    return png_path


def cmd_built(version):
    spec = version_spec(version)
    data = bytearray(require_extract(spec))
    leaf = spec["leaf"]
    png_path = ensure_png(spec)
    require_gbagfx()
    out_4bpp = spec["source_root"] / leaf["fourbpp"]
    gbagfx_png_to_4bpp(png_path, out_4bpp, num_tiles=leaf["num_tiles"])
    tiles = out_4bpp.read_bytes()
    if len(tiles) != leaf["size"]:
        print(
            f"error: built .4bpp size {len(tiles)} != {leaf['size']} "
            f"(use -num_tiles {leaf['num_tiles']})",
            file=sys.stderr,
        )
        return 1
    if sha1_hex(tiles) != leaf["expected_sha1"]:
        print(f"error: built leaf sha1 mismatch: {sha1_hex(tiles)}", file=sys.stderr)
        return 1
    off = leaf_offset(spec)
    data[off : off + leaf["size"]] = tiles
    digest = sha256_hex(data)
    if digest != spec["expected_sha256"]:
        print(f"error: patched mega sha256 mismatch: {digest}", file=sys.stderr)
        return 1
    spec["build"].parent.mkdir(parents=True, exist_ok=True)
    spec["build"].write_bytes(data)
    print(f"built {spec['build'].relative_to(ROOT)}")
    print(f"sha256 {digest}")
    print(f"leaf_sha1 {sha1_hex(tiles)}")
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
