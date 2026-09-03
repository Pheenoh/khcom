#!/usr/bin/env python3
"""Explain a non-US build's residual against its ROM, unit by unit.

Walks the built map against config/<ver>/funcmap.txt: per unit, the built
start and size against the funcmap's expected start and extent, so the unit
where the drift changes is the one after the offender; per C function, whether
it is byte-identical to the ROM at its expected address; and a classified
list of every C function whose body the target does not have, which is the
guard list the next pass applies.
"""

import argparse
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
import gen_version as g


def nobl(b):
    out = bytearray(b)
    k = 0
    while k + 3 < len(b):
        h1 = out[k] | (out[k + 1] << 8)
        h2 = out[k + 2] | (out[k + 3] << 8)
        if 0xF000 <= h1 <= 0xF7FF and h2 >= 0xF800:
            out[k:k + 4] = b"\0\0\0\0"
            k += 4
        else:
            k += 2
    return bytes(out)


def blpair(b, k):
    h1 = b[k] | (b[k + 1] << 8)
    h2 = b[k + 2] | (b[k + 3] << 8)
    if not (0xF000 <= h1 <= 0xF7FF and 0xF800 <= h2 <= 0xFFFF):
        return None
    off = ((h1 & 0x7FF) << 12) | ((h2 & 0x7FF) << 1)
    return (off - 0x800000 if off & 0x400000 else off) + 4


def load_map(path):
    units, syms = [], {}
    cur = None
    for line in Path(path).read_text().splitlines():
        m = re.match(r"^ \.text +0x(08[0-9a-f]{6}) +0x([0-9a-f]+) (\S+)$", line)
        if m:
            cur = m.group(3)
            units.append((cur, int(m.group(1), 16), int(m.group(2), 16)))
            continue
        if re.match(r"^ \.\w+ ", line) or line.startswith((".", "LOAD", "OUTPUT")):
            cur = None
        if cur is None or "=" in line:
            continue
        m = re.match(r"^ +0x(08[0-9a-f]{6}) +(\S+)$", line)
        if m:
            syms.setdefault(m.group(2), int(m.group(1), 16))
    return units, syms


def main():
    p = argparse.ArgumentParser()
    p.add_argument("version")
    p.add_argument("code")
    p.add_argument("--guards", help="write the guard list (tsv) here")
    p.add_argument("--full", action="store_true", help="print every unit, not just drift changes")
    args = p.parse_args()
    ver, code = args.version, args.code

    us = Path("roms/B8CE.gba").read_bytes()
    ot = Path(f"roms/{code}.gba").read_bytes()
    built = Path(f"build/{ver}/com_{ver}.gba").read_bytes()
    rows = g.load_funcmap(f"config/{ver}/funcmap.txt")
    us_units, us_syms = load_map("build/us/com_us.map")
    owner = {}
    for obj, lo, size in us_units:
        for nm, a in us_syms.items():
            if lo <= a < lo + size:
                owner.setdefault(nm, obj)
    flexible = {name for f in Path("src").glob("*.c") for _tu, name in g.active_includes(f, ver)}
    filler_at = {int(m.group(1), 16) for name in flexible
                 if (m := re.fullmatch(rf"{ver}_([0-9A-Fa-f]{{8}})", name))}

    def identical(r):
        return g.mask(us[r[1] - g.ROM_BASE:r[1] - g.ROM_BASE + r[2]]) == \
            g.mask(ot[r[3] - g.ROM_BASE:r[3] - g.ROM_BASE + r[2]])

    def near(r):
        return g.near_identical(g.mask(us[r[1] - g.ROM_BASE:r[1] - g.ROM_BASE + r[2]]),
                                g.mask(ot[r[3] - g.ROM_BASE:r[3] - g.ROM_BASE + r[2]]))

    placed_raw = {r[0]: r[3] for r in rows}
    rows = g.complete(rows, g.CODE_HI, flexible, owner,
                      lambda r: r[0] in flexible or identical(r))
    byname = {r[0]: r for r in rows}
    ver_units, ver_syms = load_map(f"build/{ver}/com_{ver}.map")
    allsyms = {}
    for line in Path(f"build/{ver}/com_{ver}.map").read_text().splitlines():
        m = re.match(r"^ +0x(0[2389][0-9a-f]{6}) +(\S+)$", line)
        if m and "=" not in line:
            allsyms.setdefault(int(m.group(1), 16), m.group(2))
    sym_addrs = sorted(allsyms)
    import bisect

    def name_of(w):
        i = bisect.bisect_right(sym_addrs, w) - 1
        if i < 0 or w - sym_addrs[i] > 0x4000:
            return f"{w:#x}"
        off = w - sym_addrs[i]
        return allsyms[sym_addrs[i]] + (f"+{off:#x}" if off else "")

    expected = {}
    for r in rows:
        if r[5] and placed_raw[r[0]] is not None:
            o = owner.get(r[0])
            if o and o not in expected:
                expected[o] = r[3]
    order = sorted(expected, key=expected.get)
    extent = {o: (expected[order[i + 1]] - expected[o]) if i + 1 < len(order) else None
              for i, o in enumerate(order)}

    print(f"{ver}: ROM {len(built)} bytes, target {len(ot)}, delta {len(built) - len(ot):+#x}")
    print()
    print(f"{'unit':26s} {'built':>10s} {'expected':>10s} {'drift':>8s} {'size':>7s} {'extent':>7s}  culprit")
    last = 0
    culprits = []
    for obj, lo, size in ver_units:
        m = re.search(rf"/{ver}_([0-9A-F]{{8}})\.o$", obj)
        if m:
            expected[obj] = int(m.group(1), 16)
    order = sorted(expected, key=expected.get)
    extent = {o: (expected[order[i + 1]] - expected[o]) if i + 1 < len(order) else None
              for i, o in enumerate(order)}
    for obj, lo, size in ver_units:
        o = obj.replace(f"build/{ver}/", "build/us/")
        if obj in expected:
            o = obj
        if o not in expected:
            continue
        exp = expected[o]
        if o == obj:
            drift = lo - exp
        else:
            first = next(r for r in rows if owner.get(r[0]) == o and r[5] and placed_raw[r[0]] is not None)
            sym = ver_syms.get(first[0])
            drift = (sym - first[3]) if sym is not None else None
        ext = extent.get(o)
        mark = ""
        if ext is not None and size != ext:
            mark = f"{size - ext:+#x}"
            culprits.append((obj, size - ext))
        if args.full or (drift is not None and drift != last) or mark:
            dcol = "?" if drift is None else f"{drift:+#x}"
            ecol = "?" if ext is None else f"{ext:#x}"
            print(f"{obj.rsplit('/', 1)[-1]:26s} {lo:#10x} {exp:#10x} {dcol:>8s} {size:#7x} {ecol:>7s}  {mark}")
        if drift is not None:
            last = drift

    print()
    total_delta = len(built) - len(ot)
    anchors = sorted((ver_syms[r[0]], ver_syms[r[0]] - r[3]) for r in rows
                     if r[5] and placed_raw[r[0]] is not None and r[0] in ver_syms)
    anchor_addrs = [a for a, _d in anchors]
    code_end_built = max(lo + size for _o, lo, size in ver_units)
    end_drift = anchors[-1][1] if anchors else 0

    def drift_at(a):
        if a >= code_end_built:
            return (end_drift, total_delta)
        i = bisect.bisect_right(anchor_addrs, a) - 1
        return (anchors[i][1],) if i >= 0 else ()

    ident_ok = ident_bad = 0
    calls = {}
    bad = []
    residual = {}
    constant_only = set()
    explained = 0
    for r in rows:
        if r[0] in flexible or not r[5] or placed_raw[r[0]] is None or not identical(r):
            continue
        a = ver_syms.get(r[0])
        if a is None:
            continue
        raw1 = built[a - g.ROM_BASE:a - g.ROM_BASE + r[2]]
        raw2 = ot[r[3] - g.ROM_BASE:r[3] - g.ROM_BASE + r[2]]
        b1, b2 = nobl(raw1), nobl(raw2)
        for k in range(0, r[2] - 3, 2):
            o1, o2 = blpair(raw1, k), blpair(raw2, k)
            if o1 is None or o2 is None or a + o1 == r[3] + o2:
                continue
            t1, t2 = a + k + o1, r[3] + k + o2
            calls.setdefault((name_of(t1), t1, t2), []).append(r[0])
        if b1 == b2:
            ident_ok += 1
        else:
            ident_bad += 1
            diffs = [k for k in range(0, r[2] - 3, 4) if b1[k:k + 4] != b2[k:k + 4]]
            unit = owner.get(r[0], "?").rsplit("/", 1)[-1][:-2]
            for k in diffs:
                w1 = int.from_bytes(raw1[k:k + 4], "little")
                w2 = int.from_bytes(raw2[k:k + 4], "little")
                ds = drift_at(w1) if (w1 >> 24) in (0x08, 0x09) else (0,)
                if any(w1 - d == w2 for d in ds):
                    explained += 1
                    continue
                kind = "ram" if (w1 >> 24) in (0x02, 0x03) else ("rodata" if w1 >= code_end_built else "text")
                residual.setdefault((kind, name_of(w1)), []).append((w1, w2, r[0], unit))
                if kind != "rodata" or abs(w2 - w1) > 0x10000:
                    constant_only.add(r[0])
            bad.append((r[0], unit, a, r[3], len(diffs)))
    print(f"identical C functions: {ident_ok} byte-exact in place, {ident_bad} differ only in pool words;"
          f" {explained} of those words are the drift itself")
    print(f"  {sum(len(v) for v in residual.values())} words in {len(residual)} symbols are not:")
    for kind in ("ram", "rodata", "text"):
        items = sorted(((k, v) for k, v in residual.items() if k[0] == kind), key=lambda kv: -len(kv[1]))
        if not items:
            continue
        print(f"  [{kind}] {sum(len(v) for _k, v in items)} words, {len(items)} symbols")
        for (_kind, nm), uses in items[:40 if kind == "text" else 200]:
            w1, w2, _f, unit = uses[0]
            others = {u[3] for u in uses}
            print(f"    {nm:30s} {w1:#010x} -> {w2:#010x} ({w2 - w1:+#x}) x{len(uses)} in {' '.join(sorted(others))}")

    print()
    print(f"  {sum(len(v) for v in calls.values())} call sites reach"
          f" {len(calls)} misplaced symbols:")
    for (nm, t1, t2), sites in sorted(calls.items(), key=lambda kv: -len(kv[1])):
        print(f"    {nm:30s} {t1:#010x} -> {t2:#010x} ({t2 - t1:+#x}) x{len(sites)}"
              f" from {' '.join(sorted(set(sites))[:3])}")

    guards = []
    n = len(rows)
    for i, r in enumerate(rows):
        if r[0] in flexible or r[4] == "absent":
            continue
        o = owner.get(r[0])
        if not o or not o.startswith("build/us/src/"):
            continue
        unit = o.rsplit("/", 1)[-1][:-2]
        if placed_raw[r[0]] is None:
            j = i
            while j > 0 and placed_raw[rows[j - 1][0]] is None and rows[j - 1][4] != "absent":
                j -= 1
            k = i
            while k + 1 < n and placed_raw[rows[k + 1][0]] is None and rows[k + 1][4] != "absent":
                k += 1
            prev = rows[j - 1] if j > 0 else None
            nxt = rows[k + 1] if k + 1 < n else None
            room = None
            if prev and nxt and placed_raw[prev[0]] is not None and placed_raw[nxt[0]] is not None \
                    and owner.get(prev[0]) == owner.get(nxt[0]) == o:
                room = placed_raw[nxt[0]] - (placed_raw[prev[0]] + prev[2])
            cls = "absent" if room is not None and room <= 0 else "divergent"
        elif not identical(r):
            cls = "constant-only" if near(r) else "divergent"
        elif r[0] in constant_only:
            cls = "constant-only"
        elif i + 1 < n and rows[i + 1][3] > r[3] + r[2] and owner.get(rows[i + 1][0]) == o \
                and placed_raw[rows[i + 1][0]] is not None and r[3] + r[2] not in filler_at:
            cls = "longer"
        else:
            continue
        guards.append((r[0], unit, cls))
    print()
    counts = {}
    for _nm, unit, cls in guards:
        counts[cls] = counts.get(cls, 0) + 1
    print(f"guards needed: {len(guards)} " + ", ".join(f"{k} {v}" for k, v in sorted(counts.items())))
    per_unit = {}
    for _nm, unit, _cls in guards:
        per_unit[unit] = per_unit.get(unit, 0) + 1
    print("  " + " ".join(f"{u} {c}" for u, c in sorted(per_unit.items(), key=lambda x: -x[1])))
    if args.guards:
        with open(args.guards, "w") as f:
            f.write("symbol\tunit\tclass\n")
            for nm, unit, cls in guards:
                f.write(f"{nm}\t{unit}\t{cls}\n")
        print(f"  written to {args.guards}")


if __name__ == "__main__":
    main()
