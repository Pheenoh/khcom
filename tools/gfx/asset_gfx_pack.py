#!/usr/bin/env python3
import argparse
import hashlib
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
MANIFEST = ROOT / "config" / "asset_gfx_us.yaml"
EXPECTED = "abd74f58e092cdb9c28f71d42d934645ce95cd714cb7108b2d6632f0101f7312"
EXTRACT = ROOT / "assets" / "us" / "084E0B04-0886AD18.bin"
BUILD = ROOT / "build" / "us" / "assets" / "asset_gfx.bin"
GBAGFX = ROOT / "tools" / "gbagfx" / "gbagfx"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--mode", choices=("slice", "built", "status"), default="status")
    args = ap.parse_args()

    if args.mode in ("status", "slice"):
        if not EXTRACT.exists():
            print(f"error: missing {EXTRACT}; run python3 tools/extract_assets.py us", file=sys.stderr)
            return 1
        digest = hashlib.sha256(EXTRACT.read_bytes()).hexdigest()
        ok = digest == EXPECTED
        print(f"manifest {MANIFEST.relative_to(ROOT)}")
        print(f"slice {EXTRACT.relative_to(ROOT)}")
        print(f"sha256 {digest}")
        print(f"match_expected {ok}")
        print(f"gbagfx_present {GBAGFX.exists()}")
        print(f"built_present {BUILD.exists()}")
        print("format movie_streams (MovieOpen); dump: python3 tools/gfx/asset_gfx_dump.py")
        if args.mode == "slice":
            return 0 if ok else 1
        return 0 if ok else 1

    print(
        "error: asset_gfx built mode blocked; container RE done (240x160@15fps "
        "MovieOpen streams) but matching video/audio encode and region pad are not",
        file=sys.stderr,
    )
    print(f"gbagfx_present {GBAGFX.exists()}", file=sys.stderr)
    print(f"build_path {BUILD}", file=sys.stderr)
    print("dump: python3 tools/gfx/asset_gfx_dump.py", file=sys.stderr)
    print(f"fetch: sh tools/fetch_gbagfx.sh", file=sys.stderr)
    return 2


if __name__ == "__main__":
    sys.exit(main())
