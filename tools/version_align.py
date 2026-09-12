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
import difflib
import re
import struct
import subprocess
import sys
from pathlib import Path

ROM_BASE = 0x08000000
CODE_LO = 0x08000240
CODE_HI = 0x081213C4
WINDOW = 0x600
SNAP = 64
PASSES = 4
PREFIX = 16
SIM_WORDS = 64
MATCH_BONUS = 8
VOTER_MIN = 8
TRUSTED = ("named", "xref", "global", "body", "fill", "near", "match")

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


def is_push(h):
    return (h & 0xFE00) == 0xB400


def info(b):
    return sum(1 for k in range(0, len(b) - 1, 2) if b[k:k + 2] != b"\0\0")


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

    def code_pointer(w):
        return w & 1 and CODE_LO <= (w & ~1) < CODE_HI

    us_tables = []
    for k in range(CODE_HI - ROM_BASE, len(us) - 3, 4):
        w = struct.unpack_from("<I", us, k)[0]
        if code_pointer(w) and (w & ~1) in start_of:
            us_tables.append((k, start_of[w & ~1]))
    ot_tables = {}
    for k in range(CODE_HI - ROM_BASE, len(ot) - 3, 4):
        w = struct.unpack_from("<I", ot, k)[0]
        if code_pointer(w):
            ot_tables.setdefault(w, []).append(k)

    def table_votes(votes):
        for p, j in us_tables:
            if how[j] == "absent":
                continue
            for d in (-4, 4):
                q = p + d
                if q < CODE_HI - ROM_BASE or q + 4 > len(us):
                    continue
                w = struct.unpack_from("<I", us, q)[0]
                if not code_pointer(w):
                    continue
                b = start_of.get(w & ~1)
                if b is None or b == j or addr[b] is None or how[b] == "absent":
                    continue
                got = set()
                for r in ot_tables.get(addr[b] | 1, []):
                    if r - d < 0 or r - d + 4 > len(ot):
                        continue
                    v = struct.unpack_from("<I", ot, r - d)[0]
                    if code_pointer(v):
                        got.add(v & ~1)
                if len(got) == 1:
                    votes.setdefault(j, set()).add(next(iter(got)))

    def crossref():
        placed, corrected = 0, []
        for _ in range(PASSES):
            votes = {}
            table_votes(votes)
            for i, (a, e, nm) in enumerate(funcs):
                if addr[i] is None or how[i] == "absent":
                    continue
                sz = e - a
                x = us[a - ROM_BASE:a - ROM_BASE + sz]
                y = ot[addr[i] - ROM_BASE:addr[i] - ROM_BASE + sz]
                if len(y) != sz or mask(x) != mask(y) or info(mask(x)) < VOTER_MIN:
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
                for k in range(0, sz - 3, 2):
                    if (a + k) % 4:
                        continue
                    w = struct.unpack_from("<I", x, k)[0]
                    v = struct.unpack_from("<I", y, k)[0]
                    if not (w & 1) or not (v & 1):
                        continue
                    t = w & ~1
                    if a <= t < e or not CODE_LO <= t < CODE_HI:
                        continue
                    j = start_of.get(t)
                    if j is None or how[j] == "absent":
                        continue
                    votes.setdefault(j, set()).add(v & ~1)
            progress = 0
            occupied = {addr[m]: m for m in range(n)
                        if addr[m] is not None and how[m] != "absent"
                        and verify(m, addr[m]) is not None}
            for j, cands in sorted(votes.items()):
                if len(cands) != 1:
                    continue
                t = next(iter(cands))
                if t == addr[j] or t % 2 or not CODE_LO <= t < CODE_HI:
                    continue
                if occupied.get(t, j) != j:
                    continue
                if addr[j] is not None:
                    if verify(j, addr[j]) == "fill":
                        continue
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

        for k in range(CODE_LO - ROM_BASE, min(CODE_HI, ROM_BASE + len(ot)) - ROM_BASE - 3, 2):
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

        strong = set(cands)

        run = 0

        for k in range(0, len(ot) - 3, 4):
            w = struct.unpack_from("<I", ot, k)[0]

            if not code_pointer(w):
                run = 0
                continue
            cands.add(w & ~1)

            if k < CODE_HI - ROM_BASE:
                continue
            run += 1

            if run >= 2:
                strong.add(w & ~1)
                strong.add(struct.unpack_from("<I", ot, k - 4)[0] & ~1)
        return sorted(cands), strong

    def shape_eq(h1, h2):
        if h1 == h2:
            return True
        if (h1 & 0xF800) == 0x4800 and (h1 & 0xFF00) == (h2 & 0xFF00):
            return True
        if 0xD000 <= h1 < 0xDF00 and (h1 & 0xFF00) == (h2 & 0xFF00):
            return True
        return (h1 & 0xF800) == 0xE000 and (h2 & 0xF800) == 0xE000

    def halfwords(b):
        return [struct.unpack_from("<H", b, k)[0] for k in range(0, len(b) - 1, 2)]

    def prologue(hw):
        if not hw or not is_push(hw[0]):
            return 0
        i = 1

        while i < len(hw) and (hw[i] & 0xFFC0) == 0x4640:
            i += 1
        if i < len(hw) and is_push(hw[i]):
            i += 1
        if i < len(hw) and (hw[i] & 0xFF80) == 0xB080:
            i += 1
        return i

    def prefix_score(pat, got, cap):
        p1, p2 = prologue(pat), prologue(got)

        if p1 and not p2:
            return 0
        base = 1 if p1 and p2 else 0
        s = 0

        while (p1 + s < len(pat) and p2 + s < len(got) and base + s < cap
               and shape_eq(pat[p1 + s], got[p2 + s])):
            s += 1
        if not base and (p1 or p2) and s < 4:
            return 0
        return base + s

    def score(k, c):
        a, e, nm = funcs[k]
        cap = min(e - a, PREFIX) // 2
        o = c - ROM_BASE

        if c < CODE_LO or o + 2 * cap + 16 > len(ot):
            return 0
        pat = halfwords(mask(us[a - ROM_BASE:a - ROM_BASE + 2 * cap + 16]))
        got = halfwords(mask(ot[o:o + 2 * cap + 16]))
        return prefix_score(pat, got, cap)

    def shape(hw):
        out = []

        for h in hw:
            if (h & 0xF800) == 0x4800 or 0xD000 <= h < 0xDF00:
                h &= 0xFF00
            elif (h & 0xF800) == 0xE000:
                h = 0xE000
            out.append(h)
        return out

    sim_cache = {}

    def sim(k, c):
        key = (k, c)

        if key not in sim_cache:
            a, e, nm = funcs[k]
            n2 = min(e - a, 2 * SIM_WORDS)
            x = shape(halfwords(mask(us[a - ROM_BASE:a - ROM_BASE + n2])))
            y = shape(halfwords(mask(ot[c - ROM_BASE:c - ROM_BASE + n2])))
            sim_cache[key] = difflib.SequenceMatcher(None, x, y, autojunk=False).ratio()
        return sim_cache[key]

    def mid_prologue(c):
        if c - 2 < CODE_LO:
            return False
        h = struct.unpack_from("<H", ot, c - 2 - ROM_BASE)[0]
        return is_push(h) or (h & 0xFFC0) == 0x4640

    def dense(k, lo, hi):
        full = min(funcs[k][1] - funcs[k][0], PREFIX) // 2
        return [c for c in range(lo + (lo & 1), hi, 2)
                if not mid_prologue(c) and score(k, c) >= full]

    def assign(rows, cands, weight):
        m, kk = len(rows), len(cands)
        best = [[0] * (kk + 1) for _ in range(m + 1)]
        back = [[0] * (kk + 1) for _ in range(m + 1)]

        for r in range(1, m + 1):
            for c in range(1, kk + 1):
                best[r][c], back[r][c] = best[r - 1][c], 1

                if best[r][c - 1] > best[r][c]:
                    best[r][c], back[r][c] = best[r][c - 1], 2
                w = weight(rows[r - 1], cands[c - 1])

                if w > 0 and best[r - 1][c - 1] + w > best[r][c]:
                    best[r][c], back[r][c] = best[r - 1][c - 1] + w, 3
        out = {}
        r, c = m, kk

        while r > 0 and c > 0:
            if back[r][c] == 3:
                out[rows[r - 1]] = cands[c - 1]
                r, c = r - 1, c - 1
            elif back[r][c] == 1:
                r -= 1
            else:
                c -= 1
        return out

    def entries_once(cands, strong):
        placed = 0
        i = 0

        def put(k, at):
            addr[k] = at
            how[k] = verify(k, at) or (
                "match" if score(k, at) >= 2 or sim(k, at) >= 0.5 else "entry")

        while i < n:
            if addr[i] is not None or how[i] == "absent":
                i += 1
                continue
            j = i

            while j < n and addr[j] is None and how[j] != "absent":
                j += 1

            if i > 0 and addr[i - 1] is not None and j < n and addr[j] is not None:
                lo = addr[i - 1] + 2
                hi = addr[j]
                win = set(cands[bisect.bisect_left(cands, lo):bisect.bisect_left(cands, hi)])
                cur = addr[i - 1] + (funcs[i - 1][1] - funcs[i - 1][0])
                exact = cur if (verify(i - 1, addr[i - 1]) is not None and lo <= cur < hi
                                and not mid_prologue(cur)) else None
                rows = list(range(i, j))
                extra = set()

                for k in rows:
                    extra.update(dense(k, lo, hi))
                if exact is not None and score(i, exact) >= 2:
                    extra.add(exact)
                allc = sorted(win | extra)
                fwd = {}
                pos = cur

                for k in rows:
                    fwd[k] = pos
                    pos += funcs[k][1] - funcs[k][0]
                bwd = {}
                pos = hi

                for k in reversed(rows):
                    pos -= funcs[k][1] - funcs[k][0]
                    bwd[k] = pos

                def weight(k, c):
                    s = score(k, c)

                    if not s:
                        return 1 if c in strong else 0
                    w = s + round(8 * sim(k, c)) + MATCH_BONUS

                    if c in strong:
                        w += 3
                    if abs(c - fwd[k]) <= SNAP or abs(c - bwd[k]) <= SNAP:
                        w += 6
                    if c == exact and k == i:
                        w += 2
                    return w

                got = assign(rows, allc, weight)
                hard = [c for c in allc if c in strong]
                forced = (len(hard) == len(rows) and len(got) == len(rows)
                          and all(c in strong for c in got.values()))

                for k in rows:
                    c = got.get(k)

                    if c is None:
                        continue
                    ok = score(k, c) >= 2 or sim(k, c) >= 0.5 or forced or c == exact

                    if not ok and score(k, c):
                        for x in (fwd[k], bwd[k]):
                            near = [d for d in allc if abs(d - x) <= SNAP and weight(k, d) > 0]

                            if near == [c]:
                                ok = True
                    if ok:
                        put(k, c)
                        placed += 1
            i = j

        return placed

    def entries():
        total = 0

        for _ in range(PASSES):
            got = entries_once(*entry_candidates())

            if not got:
                break
            total += got
            fill()

        if total:
            print(f"  {total} rows placed from target call and pointer targets")
        return total

    entries()

    def in_gap(k, lo, hi):
        sz = funcs[k][1] - funcs[k][0]

        for cur in range(lo, hi - sz + 1, 2):
            if verify(k, cur) is not None:
                return True
        return False

    def mark_absent():
        gone = []
        i = 0

        while i < n:
            if addr[i] is not None:
                i += 1
                continue
            j = i

            while j < n and addr[j] is None:
                j += 1
            run = [k for k in range(i, j) if how[k] != "absent"]

            if run and i > 0 and addr[i - 1] is not None and j < n and addr[j] is not None:
                lo = addr[i - 1] + (funcs[i - 1][1] - funcs[i - 1][0])
                avail = addr[j] - lo
                need = sum(funcs[k][1] - funcs[k][0] for k in run)
                trusted = how[i - 1] in TRUSTED and how[j] in TRUSTED

                if avail <= 0 or (trusted and need > avail + SNAP
                                  and not any(in_gap(k, lo, addr[j]) for k in run)):
                    for k in run:
                        how[k] = "absent"
                        gone.append(funcs[k][2])
            i = j

        if gone:
            print(f"  {len(gone)} rows with no room in the target marked absent: "
                  + " ".join(gone[:6]) + (" ..." if len(gone) > 6 else ""))
        return len(gone)

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

    for _ in range(PASSES):
        got = entries()
        got += crossref()

        if mark_absent():
            fill()
            got += entries()

        if not got:
            break
        monotone()

    out = Path(f"config/{args.version}/funcmap.txt")
    out.parent.mkdir(parents=True, exist_ok=True)
    with out.open("w") as f:
        for i, (a, e, nm) in enumerate(funcs):
            va = "-" if addr[i] is None else f"{addr[i]:#010x}"
            f.write(f"{nm}\t{a:#010x}\t{e - a}\t{va}\t{how[i]}\n")
    counts = {k: how.count(k) for k in
              ("named", "xref", "global", "body", "fill", "near", "match", "entry", "absent", "-")}
    print(f"{out}: {n} functions -> "
          + ", ".join(f"{k} {v}" for k, v in counts.items()))


if __name__ == "__main__":
    main()
