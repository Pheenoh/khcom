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
import bisect
import re
import struct
import subprocess
import sys
from pathlib import Path

ROM_BASE = 0x08000000
CODE_LO = 0x08000240
CODE_HI = 0x081213C4
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
    owner = {}
    cur = None
    for line in Path(mapfile).read_text().splitlines():
        m = re.match(r"^ \.text +0x08[0-9a-f]{6} +0x[0-9a-f]+ (\S+)$", line)
        if m:
            cur = m.group(1)
            continue
        if "=" in line:
            continue
        m = MAP_RE.match(line)
        if m:
            rows.append((int(m.group(1), 16), m.group(2)))
            owner.setdefault(m.group(2), cur)
    rows = sorted(set(rows))
    rows = [r for r in rows if CODE_LO <= r[0] < CODE_HI]
    return ([(a, (rows[i + 1][0] if i + 1 < len(rows) else CODE_HI), n)
             for i, (a, n) in enumerate(rows)], owner)


def near_identical(a, b, share=64):
    diff = sum(1 for k in range(0, len(a) - 1, 2) if a[k:k + 2] != b[k:k + 2])
    return diff <= 8 and diff * share <= len(a)


def blpair(b, k):
    h1 = b[k] | (b[k + 1] << 8)
    h2 = b[k + 2] | (b[k + 3] << 8)
    if not (0xF000 <= h1 <= 0xF7FF and 0xF800 <= h2 <= 0xFFFF):
        return None
    off = ((h1 & 0x7FF) << 12) | ((h2 & 0x7FF) << 1)
    return (off - 0x800000 if off & 0x400000 else off) + 4


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
    funcs, owner = us_functions(args.map)
    n = len(funcs)
    addr = [None] * n
    how = ["-"] * n

    dropped = set()
    per_obj = {}
    for a, e, nm in funcs:
        if nm in usn or nm in otn:
            per_obj.setdefault(owner.get(nm), []).append(nm)
    for obj, names in per_obj.items():
        if obj and not any(nm in otn for nm in names):
            dropped.add(obj)
    for i, (a, e, nm) in enumerate(funcs):
        if owner.get(nm) in dropped or (nm in usn and nm not in otn):
            how[i] = "absent"

    for i, (a, e, nm) in enumerate(funcs):
        if how[i] == "absent":
            continue
        if nm in otn:
            addr[i] = otn[nm]
            how[i] = "named"

    span = CODE_HI - ROM_BASE + 0x1000
    mus, mot = mask(us[:span]), mask(ot[:span])
    for i, (a, e, nm) in enumerate(funcs):
        if addr[i] is not None or how[i] == "absent":
            continue
        sz = e - a
        if sz < 24 or sz > 16384:
            continue
        pat = mus[a - ROM_BASE:a - ROM_BASE + sz]
        j = mot.find(pat)
        if j < 0 or j % 2 or mot.find(pat, j + 1) >= 0:
            continue
        addr[i] = ROM_BASE + j
        how[i] = "global"

    span_of = {}
    for i, (a, e, nm) in enumerate(funcs):
        if addr[i] is None:
            continue
        o = owner.get(nm)
        if o is None:
            continue
        d = span_of.setdefault(o, {"named": [], "all": [], "lo": a, "hi": e})
        d["lo"] = min(d["lo"], a)
        d["hi"] = max(d["hi"], e)
        d["all"].append(addr[i])
        if how[i] == "named":
            d["named"].append(addr[i])
    ranges = {}
    for o, d in span_of.items():
        ref = d["named"] or d["all"]
        ref = sorted(ref)
        mid = ref[len(ref) // 2]
        slack = max(2 * (d["hi"] - d["lo"]), 0x2000)
        ranges[o] = (mid - slack, mid + slack)
    outside = [funcs[i][2] for i in range(n) if how[i] == "global"
               and (r := ranges.get(owner.get(funcs[i][2])))
               and not (r[0] <= addr[i] <= r[1])]
    if outside:
        print(f"  {len(outside)} unique hits outside their unit's range, kept: "
              + " ".join(outside))

    def guess(i):
        o = owner.get(funcs[i][2])
        for same in (True, False):
            slack = 0
            for j in range(i - 1, -1, -1):
                if same and owner.get(funcs[j][2]) != o:
                    break
                if addr[j] is not None:
                    return addr[j] + (funcs[j][1] - funcs[j][0]) + slack
                slack += funcs[j][1] - funcs[j][0]
            slack = 0
            for j in range(i + 1, n):
                if same and owner.get(funcs[j][2]) != o:
                    break
                if addr[j] is not None:
                    return addr[j] - slack - (funcs[i][1] - funcs[i][0])
                slack += funcs[j][1] - funcs[j][0]
        return None

    def window(i, accept):
        a, e, nm = funcs[i]
        sz = e - a
        g = guess(i)
        if g is None:
            g = a
        off = a - ROM_BASE
        pat = mus[off:off + sz]
        g -= (g - ROM_BASE - (off % 4)) % 4
        for d in range(0, WINDOW, 4):
            for cand in (g + d, g - d):
                o = cand - ROM_BASE
                if cand < CODE_LO or o + sz > len(mot):
                    continue
                if accept(pat, mot[o:o + sz]):
                    return cand
        return None

    def in_range(i):
        a, e, nm = funcs[i]
        r = ranges.get(owner.get(nm))
        if r is None:
            return None
        pat = mus[a - ROM_BASE:e - ROM_BASE]
        lo, hi = max(r[0], CODE_LO) - ROM_BASE, min(r[1], CODE_HI) - ROM_BASE
        j = mot.find(pat, lo, hi)
        if j < 0 or j % 2 or mot.find(pat, j + 1, hi) >= 0:
            return None
        return ROM_BASE + j

    def search(accept, label, use_range):
        for _ in range(PASSES):
            progress = False
            for i, (a, e, nm) in enumerate(funcs):
                if addr[i] is not None or how[i] == "absent":
                    continue
                sz = e - a
                if sz < 4 or sz > 16384:
                    continue
                cand = window(i, accept)
                if cand is None and use_range:
                    cand = in_range(i)
                if cand is not None:
                    addr[i] = cand
                    how[i] = label
                    progress = True
            if not progress:
                break

    def verify(k, cur):
        a, e, nm = funcs[k]
        if cur < CODE_LO or cur - ROM_BASE + (e - a) > len(mot):
            return None
        pat = mus[a - ROM_BASE:e - ROM_BASE]
        got = mot[cur - ROM_BASE:cur - ROM_BASE + (e - a)]

        if pat == got:
            return "fill"
        if near_identical(pat, got, 16):
            return "near"
        return None

    def fill():
        i = 0
        while i < n:
            if addr[i] is not None or how[i] == "absent":
                i += 1
                continue
            j = i
            while j < n and addr[j] is None and how[j] != "absent":
                j += 1

            if i > 0 and addr[i - 1] is not None:
                cur = addr[i - 1] + (funcs[i - 1][1] - funcs[i - 1][0])

                for k in range(i, j):
                    label = verify(k, cur)

                    if label is None:
                        break
                    addr[k] = cur
                    how[k] = label
                    cur += funcs[k][1] - funcs[k][0]

            if j < n and addr[j] is not None:
                cur = addr[j]

                for k in range(j - 1, i - 1, -1):
                    if addr[k] is not None:
                        break
                    cur -= funcs[k][1] - funcs[k][0]
                    label = verify(k, cur)

                    if label is None:
                        break
                    addr[k] = cur
                    how[k] = label
            i = j

    start_of = {a: i for i, (a, e, nm) in enumerate(funcs)}

    def crossref():
        placed, corrected = 0, []
        for _ in range(PASSES):
            votes = {}
            for i, (a, e, nm) in enumerate(funcs):
                if addr[i] is None or how[i] == "absent":
                    continue
                sz = e - a
                x = us[a - ROM_BASE:a - ROM_BASE + sz]
                y = ot[addr[i] - ROM_BASE:addr[i] - ROM_BASE + sz]
                if len(y) != sz or mask(x) != mask(y):
                    continue
                for k in range(0, sz - 3, 2):
                    o1, o2 = blpair(x, k), blpair(y, k)
                    if o1 is None or o2 is None:
                        continue
                    t = a + k + o1
                    if a <= t < e:
                        continue
                    j = start_of.get(t)
                    if j is None or how[j] == "absent":
                        continue
                    votes.setdefault(j, set()).add(addr[i] + k + o2)
            progress = 0
            for j, cands in sorted(votes.items()):
                if len(cands) != 1:
                    continue
                t = next(iter(cands))
                if t == addr[j] or t % 2 or not CODE_LO <= t < CODE_HI:
                    continue
                if addr[j] is not None:
                    corrected.append(f"{funcs[j][2]}({how[j]}{addr[j] - t:+#x})")
                addr[j] = t
                how[j] = "xref"
                progress += 1
            placed += progress
            if not progress:
                break
        if corrected:
            print(f"  {len(corrected)} placements corrected by call sites: "
                  + " ".join(corrected))
        return placed

    search(lambda pat, got: pat == got, "body", True)
    fill()
    search(near_identical, "near", False)
    fill()
    if crossref():
        fill()
        crossref()

    def entry_candidates():
        spans = sorted((addr[i], addr[i] + (funcs[i][1] - funcs[i][0]))
                       for i in range(n) if addr[i] is not None and how[i] != "absent")
        starts = [x[0] for x in spans]

        def owner_span(p):
            k = bisect.bisect_right(starts, p) - 1
            return spans[k] if k >= 0 and spans[k][0] <= p < spans[k][1] else None
        cands = set()

        for k in range(CODE_LO - ROM_BASE, min(CODE_HI, len(ot)) - ROM_BASE - 3, 2):
            o = blpair(ot, k)

            if o is None:
                continue
            p = ROM_BASE + k
            t = p + o

            if not CODE_LO <= t < CODE_HI:
                continue
            sp = owner_span(p)

            if sp and sp[0] <= t < sp[1]:
                continue
            cands.add(t)

        for k in range(0, len(ot) - 3, 4):
            w = struct.unpack_from("<I", ot, k)[0]

            if w & 1 and CODE_LO <= (w & ~1) < CODE_HI:
                cands.add(w & ~1)
        return sorted(cands)

    def entries():
        cands = entry_candidates()
        placed = 0
        i = 0

        while i < n:
            if addr[i] is not None or how[i] == "absent":
                i += 1
                continue
            j = i

            while j < n and addr[j] is None and how[j] != "absent":
                j += 1

            if i > 0 and addr[i - 1] is not None and j < n and addr[j] is not None:
                lo = addr[i - 1] + 1
                hi = addr[j]
                a = bisect.bisect_left(cands, lo)
                b = bisect.bisect_left(cands, hi)

                if b - a == j - i:
                    for k in range(i, j):
                        cur = cands[a + k - i]
                        addr[k] = cur
                        how[k] = verify(k, cur) or "entry"
                        placed += 1
            i = j

        if placed:
            print(f"  {placed} rows placed from target call and pointer targets")
        return placed

    entries()

    def monotone():
        by_obj = {}
        for i, (a, e, nm) in enumerate(funcs):
            if addr[i] is not None and how[i] != "absent":
                by_obj.setdefault(owner.get(nm), []).append(i)
        demoted = []
        for o, idx in by_obj.items():
            best = [None] * len(idx)
            score = [0] * len(idx)
            for k, i in enumerate(idx):
                w = 1000 if how[i] in ("named", "xref") else 1
                score[k] = w
                for j in range(k):
                    if addr[idx[j]] < addr[i] and score[j] + w > score[k]:
                        score[k] = score[j] + w
                        best[k] = j
            k = max(range(len(idx)), key=lambda k: score[k])
            keep = set()
            while k is not None:
                keep.add(idx[k])
                k = best[k]
            for i in idx:
                if i not in keep:
                    demoted.append(funcs[i][2])
                    addr[i] = None
                    how[i] = "-"
        if demoted:
            print(f"  {len(demoted)} out-of-order placements demoted: " + " ".join(demoted))

    monotone()

    out = Path(f"config/{args.version}/funcmap.txt")
    out.parent.mkdir(parents=True, exist_ok=True)
    with out.open("w") as f:
        for i, (a, e, nm) in enumerate(funcs):
            va = "-" if addr[i] is None else f"{addr[i]:#010x}"
            f.write(f"{nm}\t{a:#010x}\t{e - a}\t{va}\t{how[i]}\n")
    counts = {k: how.count(k) for k in
              ("named", "xref", "global", "body", "fill", "near", "entry", "absent", "-")}
    print(f"{out}: {n} functions -> "
          + ", ".join(f"{k} {v}" for k, v in counts.items()))


if __name__ == "__main__":
    main()
