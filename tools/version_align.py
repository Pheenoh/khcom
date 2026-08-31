#!/usr/bin/env python3
"""Align the US function layout onto another version's ROM.

The debug registration tables give the same task_*/mode_* names in every
region, which pins about a third of the functions exactly. The rest are
placed by searching for the US body near where the walk expects it, with
BL displacements and ROM/RAM pool words masked out so that only the
instruction shape has to agree. Runs that stay unresolved are filled by
contiguity when their neighbours account for the gap exactly.

Writes config/<version>/funcmap.txt: name, US address, US size, version
address. That file is the input to tools/gen_version.py and is slow enough
to produce that it is committed rather than regenerated on every build.
"""

import argparse
import re
import struct
import subprocess
import sys
from pathlib import Path

ROM_BASE = 0x08000000
CODE_LO = 0x08000240
CODE_HI = 0x08121330
WINDOW = 0x600
PASSES = 4

MAP_RE = re.compile(r"^\s+(0x08[0-9a-f]{6})\s+(\S+)$")


def named(rom):
    out = subprocess.run(
        [sys.executable, "tools/gen_symbols.py", rom, "-o", "/dev/stdout"],
        capture_output=True, text=True, check=True).stdout
    d = {}
    for line in out.splitlines():
        if line.startswith("#") or not line.strip():
            continue
        parts = line.split()
        if len(parts) == 3 and parts[0] == "thumb_func":
            d[parts[2]] = int(parts[1], 16)
    return d


def us_functions(mapfile):
    rows = []
    for line in Path(mapfile).read_text().splitlines():
        if "=" in line:
            continue
        m = MAP_RE.match(line)
        if m:
            rows.append((int(m.group(1), 16), m.group(2)))
    rows = sorted(set(rows))
    rows = [r for r in rows if CODE_LO <= r[0] < CODE_HI]
    return [(a, (rows[i + 1][0] if i + 1 < len(rows) else CODE_HI), n)
            for i, (a, n) in enumerate(rows)]


def mask(b):
    out = bytearray(b)
    for k in range(0, len(b) - 1, 2):
        h = struct.unpack_from("<H", b, k)[0]
        if 0xF000 <= h <= 0xFFFF:
            struct.pack_into("<H", out, k, 0)
    for k in range(0, len(b) - 3, 4):
        w = struct.unpack_from("<I", b, k)[0]
        if (w >> 24) in (0x08, 0x09, 0x02, 0x03):
            struct.pack_into("<I", out, k, 0)
    return bytes(out)


def main():
    p = argparse.ArgumentParser()
    p.add_argument("version")
    p.add_argument("code")
    p.add_argument("--map", default="build/us/com_us.map")
    args = p.parse_args()

    us = Path("roms/B8CE.gba").read_bytes()
    ot = Path(f"roms/{args.code}.gba").read_bytes()
    usn = named("roms/B8CE.gba")
    otn = named(f"roms/{args.code}.gba")
    funcs = us_functions(args.map)
    n = len(funcs)
    addr = [None] * n
    how = ["-"] * n

    for i, (a, e, nm) in enumerate(funcs):
        if nm in usn and nm in otn:
            addr[i] = otn[nm]
            how[i] = "named"

    def guess(i):
        slack = 0
        for j in range(i - 1, -1, -1):
            if addr[j] is not None:
                return addr[j] + (funcs[j][1] - funcs[j][0]) + slack
            slack += funcs[j][1] - funcs[j][0]
        slack = 0
        for j in range(i + 1, n):
            if addr[j] is not None:
                return addr[j] - slack - (funcs[i][1] - funcs[i][0])
            slack += funcs[j][1] - funcs[j][0]
        return None

    for _ in range(PASSES):
        progress = False
        for i, (a, e, nm) in enumerate(funcs):
            if addr[i] is not None:
                continue
            sz = e - a
            if sz < 4 or sz > 16384:
                continue
            g = guess(i)
            if g is None:
                g = a
            pat = mask(us[a - ROM_BASE:a - ROM_BASE + sz])
            for d in range(0, WINDOW, 2):
                for cand in (g + d, g - d):
                    if cand < CODE_LO:
                        continue
                    if mask(ot[cand - ROM_BASE:cand - ROM_BASE + sz]) == pat:
                        addr[i] = cand
                        how[i] = "body"
                        progress = True
                        break
                if addr[i] is not None:
                    break
        if not progress:
            break

    i = 0
    while i < n:
        if addr[i] is not None:
            i += 1
            continue
        j = i
        while j < n and addr[j] is None:
            j += 1
        if i > 0 and addr[i - 1] is not None and j < n and addr[j] is not None:
            start = addr[i - 1] + (funcs[i - 1][1] - funcs[i - 1][0])
            need = sum(funcs[k][1] - funcs[k][0] for k in range(i, j))
            if start + need == addr[j]:
                cur = start
                for k in range(i, j):
                    addr[k] = cur
                    how[k] = "fill"
                    cur += funcs[k][1] - funcs[k][0]
        i = j

    out = Path(f"config/{args.version}/funcmap.txt")
    out.parent.mkdir(parents=True, exist_ok=True)
    with out.open("w") as f:
        for i, (a, e, nm) in enumerate(funcs):
            va = "-" if addr[i] is None else f"{addr[i]:#010x}"
            f.write(f"{nm}\t{a:#010x}\t{e - a}\t{va}\t{how[i]}\n")
    counts = {k: how.count(k) for k in ("named", "body", "fill", "-")}
    print(f"{out}: {n} functions -> "
          + ", ".join(f"{k} {v}" for k, v in counts.items()))


if __name__ == "__main__":
    main()
