#!/usr/bin/env python3
"""Split a per-function asm chunk that hides further functions in its tail.

    python3 tools/split_func.py hum MakeSaveHeaderData MakeSaveSystem:0x08059EE4

The chunk keeps everything before the first split address; each remaining
address becomes its own chunk file, emitted as a byte blob taken from the base
ROM. The INCLUDE_ASM lines are inserted into the owning translation unit right
after the original.
"""

import argparse
import re
import sys
from pathlib import Path

ROMS = {"us": "B8CE", "jp": "B8CJ", "eu": "B8CP"}
BYTE_RE = re.compile(r"^\s*\.byte\s+(.*)$")
LABEL_RE = re.compile(r"^(\w+):\s*@\s*([0-9A-Fa-f]{8})\s*$")

HEADER = """.syntax unified
\t.align 2, 0
\t.global {name}
\t.thumb
\t.thumb_func
\t.type {name}, %function
{name}: @ {addr:08X}
"""


def emit_bytes(data):
    rows = []
    for i in range(0, len(data), 16):
        rows.append("\t.byte " + ", ".join("0x%02X" % b for b in data[i:i + 16]) + "\n")
    return "".join(rows)


def parse_bytes(line):
    return bytes(int(x, 16) for x in BYTE_RE.match(line).group(1).split(","))


def patch_tu(tu_name, chunk, names):
    anchor = f'INCLUDE_ASM("{tu_name}/{chunk}.s");\n'
    tu = next((p for p in sorted(Path("src").glob("*.c"))
               if anchor in p.read_text()), None)

    if tu is None:
        sys.exit(f"error: {anchor.strip()} not found in any src/*.c")
    text = tu.read_text()
    added = "".join(f'INCLUDE_ASM("{tu_name}/{n}.s");\n' for n in names)
    tu.write_text(text.replace(anchor, anchor + added, 1))
    print(f"  patched {tu}")


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("tu")
    parser.add_argument("chunk")
    parser.add_argument("splits", nargs="+", help="name:0xADDR")
    parser.add_argument("--version", default="us")
    args = parser.parse_args()

    splits = sorted((int(a, 16), n) for n, a in (s.split(":") for s in args.splits))

    asm_dir = Path(f"asm/{args.version}/nonmatchings") / args.tu
    path = asm_dir / f"{args.chunk}.s"
    lines = path.read_text().splitlines(keepends=True)

    start = next((int(m.group(2), 16) for m in map(LABEL_RE.match, lines) if m), None)
    if start is None:
        m = re.search(r"^(?:func_|_)([0-9A-Fa-f]{8}):", "".join(lines), re.M)
        if m:
            start = int(m.group(1), 16)
    if start is None:
        sys.exit(f"error: no address label in {path}")

    labels = {}
    for i, line in enumerate(lines):
        m = re.match(r"^_([0-9A-Fa-f]{8}):\s*$", line)
        if m:
            labels[int(m.group(1), 16)] = i

    if all(addr in labels for addr, _ in splits):
        cuts = [labels[addr] for addr, _ in splits]
        end = len(lines)
        while end > 0 and lines[end - 1].startswith(".syntax divided"):
            end -= 1
        bounds = cuts + [end]
        head = "".join(lines[:cuts[0]]).rstrip("\n") + "\n"
        path.write_text(head + ".syntax divided\n")
        for i, (addr, name) in enumerate(splits):
            body = "".join(lines[bounds[i] + 1:bounds[i + 1]])
            (asm_dir / f"{name}.s").write_text(
                HEADER.format(name=name, addr=addr) + body + ".syntax divided\n"
            )
        patch_tu(args.tu, args.chunk, [n for _, n in splits])
        for _, name in splits:
            print(f"wrote {asm_dir / (name + '.s')}")
        return

    tail = len(lines)
    while tail > 0 and not BYTE_RE.match(lines[tail - 1]):
        tail -= 1
    head = tail
    while head > 0 and BYTE_RE.match(lines[head - 1]):
        head -= 1
    blob = b"".join(parse_bytes(l) for l in lines[head:tail])
    if not blob:
        sys.exit(f"error: {path} has no trailing byte blob")

    rom = Path(f"roms/{ROMS[args.version]}.gba").read_bytes()
    origin = rom.index(blob, start - 0x08000000) + 0x08000000
    bounds = [a for a, _ in splits] + [origin + len(blob)]
    if splits[0][0] < origin or bounds[-1] < bounds[-2]:
        sys.exit("error: split address outside the chunk's byte blob")

    kept = blob[: splits[0][0] - origin]
    body = "".join(lines[:head]) + emit_bytes(kept) + ".syntax divided\n"
    path.write_text(body)

    for i, (addr, name) in enumerate(splits):
        chunk = blob[addr - origin: bounds[i + 1] - origin]
        (asm_dir / f"{name}.s").write_text(
            HEADER.format(name=name, addr=addr) + emit_bytes(chunk) + ".syntax divided\n"
        )

    patch_tu(args.tu, args.chunk, [n for _, n in splits])

    for _, name in splits:
        print(f"wrote {asm_dir / (name + '.s')}")


if __name__ == "__main__":
    main()
