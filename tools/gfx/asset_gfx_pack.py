#!/usr/bin/env python3
import argparse
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools" / "gfx"))
from asset_gfx_layout import (
    US_BUILD,
    US_EXPECTED_SHA256,
    US_EXTRACT,
    US_SOURCE_ROOT,
    demux_parts,
    ensure_demuxed,
    probe_regional_movie_sha256,
    remux_from_source_root,
    sha256_hex,
    write_demux,
)

MANIFEST = ROOT / "config" / "asset_gfx_us.yaml"
GBAGFX = ROOT / "tools" / "gbagfx" / "gbagfx"


def cmd_status():
    if not US_EXTRACT.exists():
        print(f"error: missing {US_EXTRACT}; run python3 tools/extract_assets.py us", file=sys.stderr)
        return 1
    digest = sha256_hex(US_EXTRACT.read_bytes())
    ok = digest == US_EXPECTED_SHA256
    print(f"manifest {MANIFEST.relative_to(ROOT)}")
    print(f"slice {US_EXTRACT.relative_to(ROOT)}")
    print(f"sha256 {digest}")
    print(f"match_expected {ok}")
    print(f"gbagfx_present {GBAGFX.exists()}")
    print(f"built_present {US_BUILD.exists()}")
    if US_BUILD.exists():
        built = sha256_hex(US_BUILD.read_bytes())
        print(f"built_sha256 {built}")
        print(f"built_matches_slice {built == US_EXPECTED_SHA256}")
    print(f"source_root_present {(US_SOURCE_ROOT / 'pack_parts.json').exists()}")
    print("format movie_streams (MovieOpen); demux/remux copy-through")
    return 0 if ok else 1


def cmd_demux():
    if not US_EXTRACT.exists():
        print(f"error: missing {US_EXTRACT}; run python3 tools/extract_assets.py us", file=sys.stderr)
        return 1
    data = US_EXTRACT.read_bytes()
    digest = sha256_hex(data)
    if digest != US_EXPECTED_SHA256:
        print(f"error: slice sha256 mismatch: {digest}", file=sys.stderr)
        return 1
    parts = demux_parts(data)
    meta = write_demux(parts, US_SOURCE_ROOT)
    rebuilt = remux_from_source_root(US_SOURCE_ROOT)
    out_digest = sha256_hex(rebuilt)
    print(f"demuxed {len(meta['parts'])} parts -> {US_SOURCE_ROOT.relative_to(ROOT)}")
    print(f"roundtrip_sha256 {out_digest}")
    print(f"match_expected {out_digest == US_EXPECTED_SHA256}")
    return 0 if out_digest == US_EXPECTED_SHA256 else 1


def cmd_built():
    if not US_EXTRACT.exists():
        print(f"error: missing {US_EXTRACT}; run python3 tools/extract_assets.py us", file=sys.stderr)
        return 1
    try:
        rebuilt, wrote = ensure_demuxed(US_EXTRACT, US_SOURCE_ROOT)
    except ValueError as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 1
    digest = sha256_hex(rebuilt)
    if digest != US_EXPECTED_SHA256:
        print(f"error: remux sha256 mismatch: {digest}", file=sys.stderr)
        return 1
    US_BUILD.parent.mkdir(parents=True, exist_ok=True)
    US_BUILD.write_bytes(rebuilt)
    print(f"built {US_BUILD.relative_to(ROOT)}")
    print(f"sha256 {digest}")
    print(f"match_expected True")
    print(f"demux_refreshed {wrote}")
    print(f"source_root {US_SOURCE_ROOT.relative_to(ROOT)}")
    return 0


def cmd_probe():
    results = probe_regional_movie_sha256()
    us_movies = None
    for version in ("us", "jp", "eu"):
        info = results[version]
        if not info.get("present"):
            print(f"{version}: missing extract")
            continue
        print(f"{version}: {info['path']} size={info['size']} sha256={info['sha256'][:16]}...")
        digests = [m["sha256"] for m in info["movies"]]
        print(f"  movies={len(digests)}")
        for movie in info["movies"]:
            print(f"    {movie['rom']} extent={movie['extent']} sha256={movie['sha256'][:16]}...")
        if version == "us":
            us_movies = digests
        elif us_movies is not None:
            print(f"  movie_payloads_match_us {digests == us_movies}")
    return 0


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--mode", choices=("slice", "built", "status", "demux", "probe"), default="status")
    args = ap.parse_args()
    if args.mode in ("status", "slice"):
        return cmd_status()
    if args.mode == "demux":
        return cmd_demux()
    if args.mode == "built":
        return cmd_built()
    if args.mode == "probe":
        return cmd_probe()
    return 1


if __name__ == "__main__":
    sys.exit(main())
