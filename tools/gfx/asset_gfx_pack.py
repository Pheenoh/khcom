#!/usr/bin/env python3
import argparse
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools" / "gfx"))
from asset_gfx_layout import (
    VERSIONS,
    demux_parts,
    ensure_demuxed,
    probe_regional_movie_sha256,
    remux_from_source_root,
    sha256_hex,
    version_spec,
    write_demux,
)

GBAGFX = ROOT / "tools" / "gbagfx" / "gbagfx"


def cmd_status(version):
    spec = version_spec(version)
    extract = spec["extract"]
    if not extract.exists():
        print(f"error: missing {extract}; run python3 tools/extract_assets.py {version}", file=sys.stderr)
        return 1
    digest = sha256_hex(extract.read_bytes())
    ok = digest == spec["expected_sha256"]
    print(f"version {version}")
    print(f"manifest {spec['manifest'].relative_to(ROOT)}")
    print(f"slice {extract.relative_to(ROOT)}")
    print(f"sha256 {digest}")
    print(f"match_expected {ok}")
    print(f"gbagfx_present {GBAGFX.exists()}")
    print(f"built_present {spec['build'].exists()}")
    if spec["build"].exists():
        built = sha256_hex(spec["build"].read_bytes())
        print(f"built_sha256 {built}")
        print(f"built_matches_slice {built == spec['expected_sha256']}")
    print(f"source_root_present {(spec['source_root'] / 'pack_parts.json').exists()}")
    print("format movie_streams (MovieOpen); demux/remux copy-through")
    if "head_unit" in spec:
        head = spec["head_unit"]
        print(f"jp_head_unit slice-only {head['extract'].relative_to(ROOT)} size={head['size']}")
    return 0 if ok else 1


def cmd_demux(version):
    spec = version_spec(version)
    extract = spec["extract"]
    if not extract.exists():
        print(f"error: missing {extract}; run python3 tools/extract_assets.py {version}", file=sys.stderr)
        return 1
    data = extract.read_bytes()
    digest = sha256_hex(data)
    if digest != spec["expected_sha256"]:
        print(f"error: slice sha256 mismatch: {digest}", file=sys.stderr)
        return 1
    parts = demux_parts(data, version)
    meta = write_demux(parts, spec["source_root"], version)
    rebuilt = remux_from_source_root(spec["source_root"])
    out_digest = sha256_hex(rebuilt)
    print(f"demuxed {len(meta['parts'])} parts -> {spec['source_root'].relative_to(ROOT)}")
    print(f"roundtrip_sha256 {out_digest}")
    print(f"match_expected {out_digest == spec['expected_sha256']}")
    return 0 if out_digest == spec["expected_sha256"] else 1


def cmd_built(version):
    spec = version_spec(version)
    extract = spec["extract"]
    if not extract.exists():
        print(f"error: missing {extract}; run python3 tools/extract_assets.py {version}", file=sys.stderr)
        return 1
    try:
        rebuilt, wrote = ensure_demuxed(version)
    except ValueError as exc:
        print(f"error: {exc}", file=sys.stderr)
        return 1
    digest = sha256_hex(rebuilt)
    if digest != spec["expected_sha256"]:
        print(f"error: remux sha256 mismatch: {digest}", file=sys.stderr)
        return 1
    spec["build"].parent.mkdir(parents=True, exist_ok=True)
    spec["build"].write_bytes(rebuilt)
    print(f"built {spec['build'].relative_to(ROOT)}")
    print(f"sha256 {digest}")
    print(f"match_expected True")
    print(f"demux_refreshed {wrote}")
    print(f"source_root {spec['source_root'].relative_to(ROOT)}")
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
    ap.add_argument("--version", choices=tuple(VERSIONS.keys()), default="us")
    args = ap.parse_args()
    if args.mode == "probe":
        return cmd_probe()
    if args.mode in ("status", "slice"):
        return cmd_status(args.version)
    if args.mode == "demux":
        return cmd_demux(args.version)
    if args.mode == "built":
        return cmd_built(args.version)
    return 1


if __name__ == "__main__":
    sys.exit(main())
