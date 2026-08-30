#!/usr/bin/env python3
"""Split a translation unit into several, by address.

    python3 tools/split_tu.py unk_0800216c engine:0x0800216C save:0x080089E0

Each argument names a new TU and the address it starts at, in order. Moves the
per-function asm into new directories, rewrites the INCLUDE_ASM paths, carries
any already-decompiled C along, and updates config/<ver>/units.txt.
"""

import argparse
import re
import shutil
import sys
from pathlib import Path

ADDR_RE = re.compile(r"([0-9A-F]{8})")
INC_RE = re.compile(r'INCLUDE_ASM\("([^/]+)/([^"]+)\.s"\);')


def addr_of(name):
    m = ADDR_RE.search(name)
    return int(m.group(1), 16) if m else None


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("tu")
    parser.add_argument("splits", nargs="+", help="name:0xADDR")
    parser.add_argument("--version", default="us")
    args = parser.parse_args()

    splits = []
    for s in args.splits:
        name, addr = s.split(":")
        splits.append((int(addr, 16), name))
    splits.sort()

    src = Path("src") / f"{args.tu}.c"
    asm_dir = Path(f"asm/{args.version}/nonmatchings") / args.tu
    text = src.read_text()

    header, body = "", text
    m = re.match(r"((?:#include[^\n]*\n)+\n?)", text)
    if m:
        header, body = m.group(1), text[m.end():]

    segments = []
    pos = 0
    for m in INC_RE.finditer(body):
        if m.start() > pos:
            chunk = body[pos:m.start()].strip("\n")
            if chunk.strip():
                segments.append((addr_of(chunk) or 0, "c", chunk))
        segments.append((addr_of(m.group(2)), "asm", m.group(2)))
        pos = m.end()
    tail = body[pos:].strip("\n")
    if tail.strip():
        segments.append((addr_of(tail) or 0, "c", tail))

    for i, (a, kind, val) in enumerate(segments):
        if a is None:
            sys.exit(f"cannot determine address for segment {i}: {val[:60]}")

    def owner(a):
        chosen = splits[0][1]
        for start, name in splits:
            if a >= start:
                chosen = name
        return chosen

    groups = {}
    for a, kind, val in sorted(segments):
        groups.setdefault(owner(a), []).append((kind, val))

    for name, items in groups.items():
        out_dir = Path(f"asm/{args.version}/nonmatchings") / name
        out_dir.mkdir(parents=True, exist_ok=True)
        lines = [header.rstrip("\n"), ""]
        for kind, val in items:
            if kind == "asm":
                src_f, dst_f = asm_dir / f"{val}.s", out_dir / f"{val}.s"
                if src_f.resolve() != dst_f.resolve():
                    shutil.move(str(src_f), dst_f)
                lines.append(f'INCLUDE_ASM("{name}/{val}.s");')
            else:
                lines.append("")
                lines.append(val)
                lines.append("")
        (Path("src") / f"{name}.c").write_text("\n".join(lines).rstrip("\n") + "\n")
        print(f"{name}.c: {sum(1 for k, _ in items if k == 'asm')} asm, "
              f"{sum(1 for k, _ in items if k == 'c')} C")

    keep = {n for _, n in splits}
    remaining = [f for f in asm_dir.glob("*.s")] if asm_dir.exists() and args.tu not in keep else []
    if remaining:
        sys.exit(f"unmoved asm files remain: {[f.name for f in remaining][:5]}")
    if asm_dir.exists() and args.tu not in keep:
        asm_dir.rmdir()
    if src.name not in {f"{n}.c" for n in groups}:
        src.unlink()

    units = Path(f"config/{args.version}/units.txt")
    lines = units.read_text().splitlines()
    out = []
    for line in lines:
        if line.strip() == f"{args.tu}.c":
            out.extend(f"{name}.c" for _, name in splits)
        else:
            out.append(line)
    units.write_text("\n".join(out) + "\n")
    print(f"updated {units}")


if __name__ == "__main__":
    main()
