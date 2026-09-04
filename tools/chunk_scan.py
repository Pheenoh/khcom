#!/usr/bin/env python3
"""Find function entries inside an asm chunk that its symbol does not cover.

A chunk's extent is the distance to the next symbol in the map, not the size of
the function it names, so a chunk can hold further functions with no symbol of
their own. Candidates come from the ROM's own evidence -- addresses that some
`bl` calls, or that appear as a Thumb pointer word in data -- rather than from
decoding, because a decoder cannot tell a function entry from a literal pool at
a chunk's tail. A `bl` whose target lies inside the calling function is a long
branch relaxed past `b`'s range and is not an entry.
"""

import argparse
import bisect
import os
import re
import struct

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
ROM_BASE = 0x08000000


def symbols(mapfile):
    rows = []

    for line in open(mapfile):
        m = re.match(r"^\s+0x0*([0-9a-f]{8})\s+([A-Za-z_]\w*)$", line)

        if m:
            rows.append((int(m.group(1), 16), m.group(2)))
    rows.sort()
    return rows


def hw(b, i):
    return struct.unpack_from("<H", b, i)[0]


def blpair(b, k):
    h1, h2 = hw(b, k), hw(b, k + 2)

    if not (0xF000 <= h1 <= 0xF7FF and 0xF800 <= h2 <= 0xFFFF):
        return None
    off = ((h1 & 0x7FF) << 12) | ((h2 & 0x7FF) << 1)
    return (off - 0x800000 if off & 0x400000 else off) + 4


def call_targets(rom, lo, hi, spans, starts, votes=2):
    seen = {}

    for k in range(lo - ROM_BASE, min(hi, len(rom) + ROM_BASE) - ROM_BASE - 3, 2):
        o = blpair(rom, k)

        if o is None:
            continue
        p = ROM_BASE + k
        t = p + o

        if not lo <= t < hi:
            continue
        i = bisect.bisect_right(starts, p) - 1

        if i >= 0 and spans[i][0] <= p < spans[i][1] and spans[i][0] <= t < spans[i][1]:
            continue
        seen.setdefault(t, set()).add(p)

    for k in range(0, len(rom) - 3, 4):
        w = struct.unpack_from("<I", rom, k)[0]

        if w & 1 and lo <= (w & ~1) < hi:
            seen.setdefault(w & ~1, set()).add(ROM_BASE + k)
    return {t for t, ps in seen.items() if len(ps) >= votes and t % 2 == 0}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--min", type=int, default=1500)
    ap.add_argument("--unit")
    args = ap.parse_args()
    rom = open(os.path.join(REPO, "roms", "B8CE.gba"), "rb").read()
    rows = symbols(os.path.join(REPO, "build", "us", "com_us.map"))
    starts = [a for a, _ in rows]
    addr = {n: a for a, n in rows}
    total = 0
    found = 0
    spans = [(a, starts[i + 1] if i + 1 < len(starts) else a) for i, (a, _n) in enumerate(rows)]
    targets = call_targets(rom, 0x08000240, 0x081213C4, spans, starts)

    for path in sorted(os.listdir(os.path.join(REPO, "src"))):
        if not path.endswith(".c"):
            continue
        unit = path[:-2]

        if args.unit and unit != args.unit:
            continue
        text = open(os.path.join(REPO, "src", path)).read()

        for m in re.finditer(r'INCLUDE_ASM\("[^"/]+/([^"/]+)\.s"\)', text):
            sym = m.group(1)
            a = addr.get(sym)

            if a is None:
                continue
            k = bisect.bisect_right(starts, a)
            e = starts[k] if k < len(starts) else a

            if e - a < args.min:
                continue
            total += 1
            hits = []

            for t in sorted(t for t in targets if a < t < e):
                if not hits or t - hits[-1] >= 8:
                    hits.append(t)

            if hits:
                found += len(hits)
                print("%-22s %-22s %6d bytes -> %d hidden: %s"
                      % (unit, sym, e - a, len(hits),
                         " ".join("%08X" % x for x in hits[:6])
                         + (" ..." if len(hits) > 6 else "")))
    print("\n%d chunks over %d bytes scanned, %d call-confirmed hidden entries"
          % (total, args.min, found))


if __name__ == "__main__":
    main()
