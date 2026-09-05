#!/usr/bin/env python3
"""Walk every asm chunk of a unit and list the function entries hidden in it.

    python3 tools/gap_walk.py map            # report
    python3 tools/gap_walk.py map --emit     # print split_func.py commands

Decodes each chunk linearly from its symbol, tracking pc-relative literals,
forward branch targets and jump tables, ends a function at the first
terminator past every forward target, skips the literal pool and alignment
zeros, and treats what follows as the next entry. `chunk_scan.py` only sees
entries that a `bl` or a pointer word references, which undercounted map by
an order of magnitude (40 against 415); this walk needs no references at all.
An entry that has no push prologue and no reference is printed with a `?` so
it can be checked by hand, but it is emitted too, because every one so far
has been a leaf function.
"""

import argparse
import bisect
import os
import re
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import chunk_scan as cs

REPO = cs.REPO
B = cs.ROM_BASE
ROM = open(os.path.join(REPO, "roms", "B8CE.gba"), "rb").read()


def hw(a):
    return struct.unpack_from("<H", ROM, a - B)[0]


def wd(a):
    return struct.unpack_from("<I", ROM, a - B)[0]


def walk(start, end):
    pc = start
    maxt = start
    pool = set()
    tables = set()

    while pc < end:
        if pc in pool or pc in tables:
            pc += 4
            continue

        if pc % 4 == 0 and (pc - 4) in tables and start <= wd(pc) < end:
            tables.add(pc)
            maxt = max(maxt, wd(pc) & ~1)
            pc += 4
            continue
        h = hw(pc)
        nxt = pc + 2
        term = False

        if 0xF000 <= h <= 0xF7FF and pc + 2 < end and 0xF800 <= hw(pc + 2) <= 0xFFFF:
            nxt = pc + 4
        elif 0xE000 <= h <= 0xE7FF:
            off = h & 0x7FF

            if off & 0x400:
                off -= 0x800
            t = pc + 4 + off * 2

            if t > pc:
                maxt = max(maxt, t)
            term = True
        elif 0xD000 <= h <= 0xDDFF:
            off = h & 0xFF

            if off & 0x80:
                off -= 0x100
            t = pc + 4 + off * 2

            if t > pc:
                maxt = max(maxt, t)
        elif 0x4800 <= h <= 0x4FFF:
            pool.add(((pc + 4) & ~3) + (h & 0xFF) * 4)
        elif (h & 0xFF00) == 0x4700 or 0xBD00 <= h <= 0xBDFF:
            term = True
        elif (h & 0xFF87) in (0x4687, 0x46C7):
            term = True

            for pa in sorted(pool):
                tb = wd(pa)

                if start <= tb < end:
                    k = tb

                    while k + 4 <= end:
                        e = wd(k)

                        if not (start <= e < end):
                            break
                        maxt = max(maxt, e & ~1)
                        tables.add(k)
                        k += 4

        if term and pc >= maxt:
            fend = nxt
            pe = fend

            while True:
                q = (pe + 3) & ~3

                if q + 4 > end:
                    break

                if q in pool or q in tables:
                    pe = q + 4
                elif start <= wd(q) < fend and pe > fend:
                    pe = q + 4
                else:
                    break
            pe = (pe + 3) & ~3
            return fend, min(pe, end)
        pc = nxt
    return end, end


def entry_ok(a):
    h = hw(a)
    return (h & 0xFF00) == 0xB500 or h == 0x4770 or (0x2000 <= h <= 0x27FF and hw(a + 2) == 0x4770)


def references(lo, hi, spans, starts):
    seen = {}

    for k in range(lo - B, hi - B - 3, 2):
        o = cs.blpair(ROM, k)

        if o is None:
            continue
        p = B + k
        t = p + o

        if not lo <= t < hi:
            continue
        i = bisect.bisect_right(starts, p) - 1

        if i >= 0 and spans[i][0] <= p < spans[i][1] and spans[i][0] <= t < spans[i][1]:
            continue
        seen.setdefault(t, set()).add(p)

    for k in range(0, len(ROM) - 3, 4):
        w = struct.unpack_from("<I", ROM, k)[0]

        if w & 1 and lo <= (w & ~1) < hi:
            seen.setdefault(w & ~1, set()).add(B + k)
    return seen


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("unit")
    ap.add_argument("--emit", action="store_true")
    args = ap.parse_args()
    rows = cs.symbols(os.path.join(REPO, "build", "us", "com_us.map"))
    starts = [a for a, _ in rows]
    addr = {n: a for a, n in rows}
    spans = [(a, starts[i + 1] if i + 1 < len(starts) else a) for i, (a, _n) in enumerate(rows)]
    text = open(os.path.join(REPO, "src", args.unit + ".c")).read()
    chunks = []

    for m in re.finditer(r'INCLUDE_ASM\("[^"/]+/([^"/]+)\.s"\)', text):
        a = addr.get(m.group(1))

        if a is not None:
            k = bisect.bisect_right(starts, a)
            chunks.append((m.group(1), a, starts[k] if k < len(starts) else a))

    if not chunks:
        return
    seen = references(min(c[1] for c in chunks), max(c[2] for c in chunks), spans, starts)
    total = 0

    for sym, a, e in chunks:
        cur = a
        found = []

        while cur < e:
            fend, pe = walk(cur, e)

            if pe >= e:
                break

            while pe < e and hw(pe) == 0:
                pe += 2

            if pe >= e:
                break
            found.append(pe)
            cur = pe

        if not found:
            continue
        total += len(found)

        if args.emit:
            print("python3 tools/split_func.py %s %s %s"
                  % (args.unit, sym, " ".join("func_%08X:0x%08X" % (x, x) for x in found)))
        else:
            print("%-22s %6d bytes -> %d hidden" % (sym, e - a, len(found)))

            for x in found:
                flag = "" if entry_ok(x) or x in seen else "  ?"
                print("   %08X refs=%d%s" % (x, len(seen.get(x, ())), flag))

    if not args.emit:
        print("%d hidden entries in %s" % (total, args.unit))


if __name__ == "__main__":
    main()
