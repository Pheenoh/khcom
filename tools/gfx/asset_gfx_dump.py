#!/usr/bin/env python3
import argparse
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools"))
sys.path.insert(0, str(ROOT / "tools" / "gfx"))
from movie_assets import movie_extent
from asset_gfx_layout import (
    DUMP_REGIONS as REGIONS,
    US_EXTRACT as DEFAULT_BIN,
    US_EXPECTED_SIZE as EXPECTED_SIZE,
    US_ROM_BASE as ROM_BASE,
)


def parse_movie(data):
    width, height, rate, frames, blocks, channels, sample_rate, codec = struct.unpack_from("<IIf5I", data)
    type_size = struct.unpack_from("<I", data, 32)[0]
    frame_types = list(data[36 : 36 + frames])
    pos = 36 + type_size
    v_sec = struct.unpack_from("<I", data, pos)[0]
    v_size = struct.unpack_from("<I", data, pos + 4)[0]
    v_max = struct.unpack_from("<H", data, pos + 8)[0]
    v_sizes = list(struct.unpack_from("<" + "H" * frames, data, pos + 10))
    video_off = pos + 8 + v_sec
    pos = video_off + v_size
    audio = None
    if channels:
        a_type = struct.unpack_from("<I", data, pos)[0]
        a_meta_off = pos + 4
        pos = a_meta_off + a_type
        a_sec = struct.unpack_from("<I", data, pos)[0]
        a_size = struct.unpack_from("<I", data, pos + 4)[0]
        a_max = struct.unpack_from("<H", data, pos + 8)[0]
        a_sizes = list(struct.unpack_from("<" + "H" * blocks, data, pos + 10))
        audio_off = pos + 8 + a_sec
        pos = audio_off + a_size
        audio = {
            "meta_bytes": a_type,
            "meta_offset": a_meta_off,
            "sizes_sec_bytes": a_sec,
            "payload_bytes": a_size,
            "payload_offset": audio_off,
            "max_block": a_max,
            "block_count": blocks,
            "block_sizes_head": a_sizes[:8],
        }
    extent = movie_extent(data)
    return {
        "width": width,
        "height": height,
        "frame_rate": rate,
        "frame_count": frames,
        "audio_block_count": blocks,
        "channels": channels,
        "sample_rate": sample_rate,
        "audio_codec_id": codec,
        "frame_types_bytes": type_size,
        "frame_types_head": frame_types[:16],
        "frame_type_counts": {
            "I": frame_types.count(0),
            "P": frame_types.count(1),
            "filtered": frame_types.count(2),
        },
        "video_sizes_sec_bytes": v_sec,
        "video_payload_bytes": v_size,
        "video_payload_offset": video_off,
        "max_frame": v_max,
        "frame_sizes_head": v_sizes[:8],
        "movie_extent": extent,
        "region_pad": len(data) - extent,
        "audio": audio,
    }


def parse_subs(data):
    entries = []
    for i in range(0, len(data) // 16):
        off = i * 16
        frame, unk02 = struct.unpack_from("<hh", data, off)
        text_ptr = struct.unpack_from("<I", data, off + 4)[0]
        slot, unk09 = struct.unpack_from("<BB", data, off + 8)
        duration, unk0C, unk0E = struct.unpack_from("<HHH", data, off + 10)
        entries.append(
            {
                "index": i,
                "frame": frame,
                "unk_02": unk02,
                "text_ptr": f"0x{text_ptr:08X}",
                "slot": slot,
                "unk_09": unk09,
                "duration": duration,
                "unk_0C": unk0C,
                "unk_0E": unk0E,
            }
        )
    return entries


def dump_pack(path, as_json):
    data = Path(path).read_bytes()
    if len(data) != EXPECTED_SIZE:
        raise SystemExit(
            f"error: expected {EXPECTED_SIZE} bytes (US asset_gfx), got {len(data)} from {path}"
        )
    rows = []
    for name, start, end, kind in REGIONS:
        off = start - ROM_BASE
        size = end - start
        blob = data[off : off + size]
        row = {
            "id": name,
            "kind": kind,
            "rom_start": f"0x{start:08X}",
            "rom_end": f"0x{end:08X}",
            "file_offset": off,
            "size": size,
            "head8": blob[:8].hex(),
        }
        if kind == "movie":
            row["movie"] = parse_movie(blob)
        elif kind == "movie_sub_table":
            row["entries"] = parse_subs(blob)
            row["entry_count"] = len(row["entries"])
        elif kind == "literal":
            row["text"] = blob.split(b"\x00", 1)[0].decode("ascii", errors="replace")
        rows.append(row)

    if as_json:
        json.dump({"pack": "asset_gfx", "version": "us", "path": str(path), "regions": rows}, sys.stdout, indent=2)
        sys.stdout.write("\n")
        return 0

    print(f"pack asset_gfx us  path={path}  size={len(data)}")
    print("header note: bytes f0000000 a0000000 are LE u32 width=240 height=160 (not magic)")
    print()
    for row in rows:
        print(
            f"{row['id']:20} {row['kind']:16} {row['rom_start']}-{row['rom_end']} "
            f"size={row['size']:8} head8={row['head8']}"
        )
        if row["kind"] == "movie":
            m = row["movie"]
            print(
                f"  {m['width']}x{m['height']} @{m['frame_rate']}fps "
                f"frames={m['frame_count']} audioBlocks={m['audio_block_count']} "
                f"ch={m['channels']} sr={m['sample_rate']} codec={m['audio_codec_id']}"
            )
            print(
                f"  frameTypesBytes={m['frame_types_bytes']} "
                f"types={m['frame_type_counts']} video={m['video_payload_bytes']} "
                f"maxFrame={m['max_frame']} extent={m['movie_extent']} pad={m['region_pad']}"
            )
            if m["audio"]:
                a = m["audio"]
                print(
                    f"  audio meta={a['meta_bytes']} payload={a['payload_bytes']} "
                    f"maxBlock={a['max_block']}"
                )
        elif row["kind"] == "movie_sub_table":
            print(f"  MovieSub entries={row['entry_count']} (16 bytes each; text UTF-16LE via text_ptr)")
            for e in row["entries"][:3]:
                print(
                    f"    [{e['index']}] frame={e['frame']} slot={e['slot']} "
                    f"dur={e['duration']} text={e['text_ptr']}"
                )
            if row["entry_count"] > 3:
                print(f"    ... {row['entry_count'] - 3} more")
        elif row["kind"] == "literal":
            print(f"  text={row['text']!r}")
    return 0


def main():
    ap = argparse.ArgumentParser(description="Dump US asset_gfx movie pack layout")
    ap.add_argument(
        "path",
        nargs="?",
        default=str(DEFAULT_BIN),
        help="path to 084E0B04-0886AD18.bin (default: assets/us/... after extract)",
    )
    ap.add_argument("--json", action="store_true", help="emit machine-readable JSON")
    args = ap.parse_args()
    path = Path(args.path)
    if not path.is_file():
        print(
            f"error: missing {path}; run: python3 tools/extract_assets.py us",
            file=sys.stderr,
        )
        return 1
    return dump_pack(path, args.json)


if __name__ == "__main__":
    sys.exit(main())
