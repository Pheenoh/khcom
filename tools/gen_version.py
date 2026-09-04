#!/usr/bin/env python3
"""Generate a non-US version's build tree from the US one.

src/ is shared across versions, so every INCLUDE_ASM line in it has to
resolve for each version. This walks config/<version>/funcmap.txt (written
by tools/version_align.py) and emits, at that version's addresses:

  config/<version>/symbols.txt        globals, mapped through the pool words
                                      of instruction-identical function pairs
  asm/<version>/header.s, crt0.s      the pre-code region
  asm/<version>/nonmatchings/<tu>/    one incbin chunk per INCLUDE_ASM in src/
  asm/<version>/data.s, data2.s       the post-code region
  config/<version>/units.txt          the US link order

The chunks are incbins rather than disassembly: their job is to reproduce
the ROM's bytes at an address the link already fixes, and the readable
disassembly to decompile from lives on the US side. A chunk's extent comes
from the next function's address in this version, not from the US size, so
a function that is a different length here still tiles correctly.
"""

import argparse
import bisect
import re
import struct
from pathlib import Path

ROM_BASE = 0x08000000
CODE_HI = 0x081213C4
ROM_END = 0x0A000000

TARGET_ANCHORS = {
    "eu": {
        0x02034890: 0x02034898,
        0x09ED77D4: 0x09F476C8,
        0x09ED82D4: 0x09F481C8,
        0x08130E6C: 0x0887F340,
        0x0976D8A6: 0x097385B0,
        0x0976DBDA: 0x0973BA8A,
    },
    "jp": {
        0x09C8D47A: 0x09C678B4,
        0x09C8F1FA: 0x09C68CC6,
        0x09EFBAD4: 0x09ED304C,
    },
}

TARGET_DATA_SIZE = {
    "eu": {
        ("unk_0800c778_data.c", ".rodata"): 0x2928,
        ("unk_0800c778_data.c", ".data"): 0,
        ("mode_battle.c", ".rodata"): 0x914,
        ("mode_debug.c", ".rodata"): 0x1F4,
        ("mode_chkobj.c", ".rodata"): 0x6350,
        ("mode_chksnd.c", ".rodata"): 0x20E8,
        ("mode_dummy.c", ".rodata"): 0x19C,
    },
}

INCLUDE_ASM_RE = re.compile(r'INCLUDE_ASM\("([^"]+)/([^"/]+)\.s"\)')

THUMB = """.syntax unified
	.text
{align}\t.global {name}
\t.thumb
\t.thumb_func
\t.type {name}, %function
{name}:
\t.incbin "roms/{code}.gba", {off:#x}, {size:#x}
.syntax divided
"""

DATA = """.syntax unified
	.text
{align}\t.global {name}
{name}:
\t.incbin "roms/{code}.gba", {off:#x}, {size:#x}
.syntax divided
"""

EMPTY = """.syntax unified
	.text
\t.global {name}
\t.thumb
\t.thumb_func
\t.type {name}, %function
{name}:
.syntax divided
"""


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


def near_identical(a, b):
    diff = sum(1 for k in range(0, len(a) - 1, 2) if a[k:k + 2] != b[k:k + 2])
    return diff <= 8 and diff * 64 <= len(a)


VERSION_IF_RE = re.compile(r"#\s*(ifdef|ifndef|if|else|elif|endif)\b(.*)")


def active_includes(path, ver):
    """INCLUDE_ASM lines this version actually compiles.

    A function that only diverges in one version is guarded against that
    version alone, so the same line is C for one build and asm for another.
    Only VERSION_* conditions are interpreted; anything else stays active.
    """
    tag = f"VERSION_{ver.upper()}"
    stack = []
    out = []
    for line in Path(path).read_text().splitlines():
        m = VERSION_IF_RE.match(line.strip())
        if m:
            kind, rest = m.group(1), m.group(2)
            if kind in ("ifdef", "ifndef", "if", "elif"):
                versioned = "VERSION_" in rest
                if not versioned:
                    frame = (False, True)
                elif kind == "ifndef":
                    frame = (True, tag not in rest)
                else:
                    frame = (True, tag in rest)
                if kind == "elif" and stack:
                    stack[-1] = frame
                else:
                    stack.append(frame)
            elif kind == "else":
                if stack:
                    versioned, state = stack[-1]
                    stack[-1] = (versioned, not state if versioned else True)
            elif kind == "endif":
                if stack:
                    stack.pop()
            continue
        if all(state for _versioned, state in stack):
            m = INCLUDE_ASM_RE.search(line)
            if m:
                out.append((m.group(1), m.group(2)))
    return out


def load_funcmap(path):
    rows = []
    for line in Path(path).read_text().splitlines():
        nm, ua, sz, va, how = line.split("\t")
        rows.append([nm, int(ua, 16), int(sz), None if va == "-" else int(va, 16), how])
    return rows


def complete(rows, code_end, flexible, unit_of=None, clean=None):
    unit_of = unit_of or {}
    clean = clean or (lambda r: True)
    n = len(rows)
    i = 0
    while i < n:
        if rows[i][3] is not None or rows[i][4] == "absent":
            i += 1
            continue
        j = i
        while j < n and rows[j][3] is None and rows[j][4] != "absent":
            j += 1
        prev = next((rows[k] for k in range(i - 1, -1, -1)
                     if rows[k][3] is not None), None)
        nxt = next((rows[k] for k in range(j, n) if rows[k][3] is not None), None)
        if prev is None:
            i = j
            continue
        begin = prev[3] + prev[2]
        stop = nxt[3] if nxt is not None else code_end
        want = sum(rows[k][2] for k in range(i, j))
        span = max(0, stop - begin)
        if span == 0:
            for k in range(i, j):
                rows[k][4] = "absent"
            i = j
            continue
        for k in range(i, j):
            rows[k][3] = begin
            share = rows[k][2] if want == 0 else round(span * rows[k][2] / want / 4) * 4
            begin = min(begin + max(0, share), stop)
        i = j

    present = sorted((r for r in rows if r[3] is not None and r[4] != "absent"),
                     key=lambda r: r[3])
    size, start = {}, {}
    pos = present[0][3] if present else 0
    for k, r in enumerate(present):
        nxt = present[k + 1][3] if k + 1 < len(present) else code_end
        if r[0] in flexible:
            if (k and r[3] > pos and clean(present[k - 1])
                    and (r[4] in ("named", "xref", "global", "body")
                         or (r[4] != "-" and unit_of.get(r[0])
                             != unit_of.get(present[k - 1][0])))):
                pos = r[3]
            start[id(r)] = pos
            size[id(r)] = max(0, nxt - pos)
            pos = nxt
        else:
            start[id(r)] = r[3]
            size[id(r)] = r[2]
            pos = r[3] + r[2]
    for r in rows:
        r[3] = start.get(id(r), r[3] if r[3] is not None else 0)
        r.append(size.get(id(r), 0))
    return rows


def symbol_map(rows, us, ot):
    pairs = {}
    for nm, ua, sz, va, how, vsz in rows:
        if va is None or vsz != sz:
            continue
        a = us[ua - ROM_BASE:ua - ROM_BASE + sz]
        b = ot[va - ROM_BASE:va - ROM_BASE + sz]
        if len(b) != sz or not near_identical(mask(a), mask(b)):
            continue
        for k in range(0, sz - 3, 4):
            w1 = struct.unpack_from("<I", a, k)[0]
            w2 = struct.unpack_from("<I", b, k)[0]
            if (w1 >> 24) in (0x02, 0x03, 0x08, 0x09) and (w2 >> 24) in (0x02, 0x03, 0x08, 0x09):
                pairs.setdefault(w1, {})
                pairs[w1][w2] = pairs[w1].get(w2, 0) + 1
    res = {}
    tied = {}
    for k, v in pairs.items():
        best = sorted(v.items(), key=lambda x: -x[1])
        if len(best) == 1 or best[0][1] > 2 * best[1][1]:
            res[k] = best[0][0]
        else:
            tied[k] = [w for w, _n in best]
    keys = sorted(res)
    for k, cands in tied.items():
        i = bisect.bisect_left(keys, k)
        near = [keys[j] for j in (i - 1, i) if 0 <= j < len(keys)]
        if not near:
            continue
        deltas = {res[n] - n for n in near}
        pick = [w for w in cands if w - k in deltas]
        if len(pick) == 1:
            res[k] = pick[0]
    return res


def translator(res):
    keys = sorted(res)

    def tr(a):
        if a < 0x02000000:
            return a, "const"
        if a in res:
            return res[a], "exact"
        i = bisect.bisect_left(keys, a)
        lo = keys[i - 1] if i > 0 else None
        hi = keys[i] if i < len(keys) else None
        if lo is None and hi is None:
            return None, "unknown"
        if lo is None:
            return a + res[hi] - hi, "interp"
        if hi is None or (res[lo] - lo) == (res[hi] - hi):
            return a + res[lo] - lo, "interp"
        return a + res[lo] - lo, "interp?"

    return tr


def main():
    p = argparse.ArgumentParser()
    p.add_argument("version")
    p.add_argument("code")
    p.add_argument("-q", "--quiet", action="store_true")
    args = p.parse_args()
    ver, code = args.version, args.code

    us = Path("roms/B8CE.gba").read_bytes()
    ot = Path(f"roms/{code}.gba").read_bytes()
    rows = load_funcmap(f"config/{ver}/funcmap.txt")

    owner = {}
    cur = None
    for line in Path("build/us/com_us.map").read_text().splitlines():
        m = re.match(r"^ \.text +0x08[0-9a-f]{6} +0x[0-9a-f]+ (\S+)$", line)
        if m:
            cur = m.group(1)
            continue
        if cur is None or "=" in line:
            continue
        m = re.match(r"^ +0x08[0-9a-f]{6} +(\S+)$", line)
        if m:
            owner.setdefault(m.group(1), cur)

    flexible = set()
    for f in sorted(Path("src").glob("*.c")):
        for tu, name in active_includes(f, ver):
            flexible.add(name)

    def identical(r):
        a = us[r[1] - ROM_BASE:r[1] - ROM_BASE + r[2]]
        b = ot[r[3] - ROM_BASE:r[3] - ROM_BASE + r[2]]
        return mask(a) == mask(b)

    def clean(r):
        return r[0] in flexible or identical(r)

    anchors = TARGET_ANCHORS.get(ver, {})

    provisional = [r for r in rows if r[3] is not None]
    guess_end = provisional[-1][3] + (CODE_HI - provisional[-1][1])
    rows = complete(rows, guess_end, flexible, owner, clean)
    res = symbol_map(rows, us, ot)
    res.update(anchors)
    tr = translator(res)

    code_end, how_end = tr(CODE_HI)
    if code_end != guess_end:
        rows = load_funcmap(f"config/{ver}/funcmap.txt")
        rows = complete(rows, code_end, flexible, owner, clean)
        res = symbol_map(rows, us, ot)
        res.update(anchors)
        tr = translator(res)
    print(f"{ver}: code region {rows[0][3]:#x} .. {code_end:#x} ({how_end})")

    present = sorted((r for r in rows if r[5]), key=lambda r: r[3])
    gaps = {}
    for a, b in zip(present, present[1:]):
        end = a[3] + a[5]
        if b[3] <= end:
            continue
        kind = "boundary" if owner.get(a[0]) != owner.get(b[0]) else "inside"
        word = struct.unpack_from("<I", ot, end - ROM_BASE)[0]
        if b[3] - end == 4 and (word >> 24) in (0x02, 0x03, 0x08, 0x09):
            kind = "pool"
        gaps[end] = (b[3] - end, kind, a, b, clean(a))

    out, uncertain = [], []
    for line in Path("config/us/symbols.txt").read_text().splitlines():
        stripped = line.split("#")[0].strip()
        if not stripped:
            out.append(line)
            continue
        nm, a = (x.strip() for x in stripped.split("="))
        b, how = tr(int(a, 16))
        if b is None:
            b, how = int(a, 16), "unknown"
        if how in ("interp?", "unknown"):
            uncertain.append((nm, how))
        out.append(f"{nm} = {b:#010x}")
    Path(f"config/{ver}/symbols.txt").write_text("\n".join(out) + "\n")
    print(f"  symbols.txt: {len(out)} lines, {len(uncertain)} uncertain")

    byname = {r[0]: r for r in rows}
    asm_root = Path(f"asm/{ver}/nonmatchings")
    wrote = missing = absent = 0
    kept = set()
    filled = set()
    for src in sorted(Path("src").glob("*.c")):
        for tu, name in active_includes(src, ver):
            m = re.fullmatch(f"{ver}_([0-9A-Fa-f]{{8}})", name)
            if m:
                at = int(m.group(1), 16)
                gap = gaps.get(at)
                d = asm_root / tu
                d.mkdir(parents=True, exist_ok=True)
                if gap is None:
                    (d / f"{name}.s").write_text(EMPTY.format(name=name))
                else:
                    filled.add(at)
                    (d / f"{name}.s").write_text(
                        THUMB.format(name=name, code=code, off=at - ROM_BASE, size=gap[0],
                                     align="\t.align 2, 0\n" if at % 4 == 0 else ""))
                kept.add(d / f"{name}.s")
                wrote += 1
                continue
            r = byname.get(name)
            if r is None:
                missing += 1
                print(f"  missing layout for {tu}/{name}")
                continue
            if r[5] == 0:
                absent += 1
            usasm = Path(f"asm/us/nonmatchings/{tu}/{name}.s")
            tmpl = DATA if usasm.exists() and ".thumb_func" not in usasm.read_text() else THUMB
            if r[5] == 0:
                tmpl = EMPTY
            d = asm_root / tu
            d.mkdir(parents=True, exist_ok=True)
            (d / f"{name}.s").write_text(
                tmpl.format(name=name, code=code, off=r[3] - ROM_BASE, size=r[5],
                            align="\t.align 2, 0\n" if r[3] % 4 == 0 and r[5] else ""))
            kept.add(d / f"{name}.s")
            wrote += 1
    stale = 0
    for old in asm_root.glob("*/*.s"):
        if old not in kept:
            old.unlink()
            stale += 1
    for d in asm_root.glob("*"):
        if d.is_dir() and not any(d.iterdir()):
            d.rmdir()
    print(f"  chunks: {wrote} written ({absent} empty), {missing} missing"
          + (f", {stale} stale removed" if stale else ""))

    Path(f"asm/{ver}").mkdir(parents=True, exist_ok=True)

    fillers = []
    slack = 0
    for at, (size, kind, a, b, clean) in sorted(gaps.items()):
        unit = owner.get(a[0], "?").rsplit("/", 1)[-1][:-2]
        if kind == "boundary":
            nm = f"{ver}_{at:08X}.s"
            Path(f"asm/{ver}/{nm}").write_text(
                THUMB.format(name=nm[:-2], code=code, off=at - ROM_BASE, size=size,
                             align="\t.align 2, 0\n" if at % 4 == 0 else ""))
            fillers.append((at, nm))
            print(f"  filler {nm}: {size:#x} bytes after {a[0]} ({unit})")
        elif at in filled:
            pass
        elif kind == "pool":
            print(f"  gap {size:#x} at {at:#x} inside {unit} after {a[0]}: a pool word,"
                  f" so {a[0]} is longer in {ver}")
        elif clean:
            print(f"  gap {size:#x} at {at:#x} inside {unit} after {a[0]} before {b[0]}:"
                  f" needs INCLUDE_ASM(\"{unit}/{ver}_{at:08X}.s\")")
        else:
            slack += size
    if slack:
        print(f"  slack after divergent functions: {slack:#x} bytes")
    fresh = {nm for _at, nm in fillers}
    for old in Path(f"asm/{ver}").glob(f"{ver}_*.s"):
        if old.name not in fresh:
            old.unlink()

    def unit_key(name):
        if name.startswith("@"):
            arch, member = name[1:].split(":")
            obj = f"build/us/lib/{arch}/{member}"
        elif name.endswith(".c"):
            obj = f"build/us/src/{name[:-2]}.o"
        else:
            return None
        named = sorted(r[3] for r in rows
                       if owner.get(r[0]) == obj and r[5] and r[4] == "named")
        addrs = named or sorted(r[3] for r in rows
                                if owner.get(r[0]) == obj and r[5])
        if not addrs and any(owner.get(r[0]) == obj for r in rows):
            return "absent"
        return addrs[len(addrs) // 2] if addrs else None

    placed = re.compile(r"^ (\.\w+) +0x(0[89][0-9a-f]{6}) +0x([0-9a-f]+) "
                        r"build/us/src/(\S+)\.o$")
    spans = {}
    for line in Path("build/us/com_us.map").read_text().splitlines():
        m = placed.match(line)
        if m:
            spans[(m.group(4) + ".c", m.group(1))] = (int(m.group(2), 16),
                                                      int(m.group(3), 16))

    head, body, cdata = [], [], []
    for line in Path("config/us/units.txt").read_text().splitlines():
        t = line.strip()
        if t.endswith(")"):
            nm, _, sec = t.partition("(")
            if nm.endswith(".s"):
                continue
            lo, size = spans[(nm, sec[:-1])]
            here, _ = tr(lo)
            size = TARGET_DATA_SIZE.get(ver, {}).get((nm, sec[:-1]), size)
            cdata.append((here, size, line))
            continue
        if not t or t.startswith("#") or t.endswith(".s"):
            head.append(line)
            continue
        body.append((unit_key(t.split()[0]), line))
    dropped = [l for k, l in body if k == "absent"]
    for l in dropped:
        print(f"  unit dropped: {l}")
    body = [(k, l) for k, l in body if k != "absent"]
    body += [(at, nm) for at, nm in fillers]
    ordered = [l for k, l in sorted(body, key=lambda kl: (kl[0] is None, kl[0] or 0))]
    moved = [l for (k, l), l2 in zip(body, ordered) if l != l2]
    if moved:
        print(f"  units reordered: {len(moved)}")

    usrom = Path("roms/B8CE.gba").read_bytes()
    otrom = Path(f"roms/{code}.gba").read_bytes()
    pad = len(otrom)

    while pad > 0 and otrom[pad - 1] == 0xFF:
        pad -= 1
    found = []
    incbin = re.compile(r'\.incbin\s+"[^"]+",\s*(0x[0-9a-fA-F]+),\s*(0x[0-9a-fA-F]+)')
    for line in Path("config/us/units.txt").read_text().splitlines():
        t = line.strip()
        if not t.endswith(".s(.rodata)"):
            continue
        nm = t[:-len("(.rodata)")]
        src = Path("asm/us") / nm
        if not src.exists():
            continue
        m = incbin.search(src.read_text())
        if not m:
            continue
        off = int(m.group(1), 16)
        base = nm[:-2]

        if base == "padding":
            found.append((ROM_BASE + pad, base, "run"))
            continue
        pat = usrom[off:off + 64]
        i = otrom.find(pat)
        how = "content"

        if i < 0 or otrom.find(pat, i + 1) >= 0:
            i, how = tr(ROM_BASE + off)[0], "interp"

            if i is None:
                continue
            i -= ROM_BASE
        found.append((ROM_BASE + i, base, how))
    regions = []

    for here, base, how in sorted(found):
        if regions and here <= regions[-1][0]:
            print(f"  data region {base} dropped, not monotone ({how})")
            continue
        regions.append((here, base))

    used = {}

    def blob(lo, hi):
        out = []
        cuts = [a for a, _n in regions if lo < a < hi]
        for a, b in zip([lo] + cuts, cuts + [hi]):
            if a >= b:
                continue
            k = bisect.bisect_right([x[0] for x in regions], a) - 1
            base = regions[k][1] if k >= 0 else "data"
            used[base] = used.get(base, 0) + 1
            nm = f"{base}.s" if used[base] == 1 else f"{base}{used[base]}.s"
            out.append((nm, a, b))
        return out

    tail, bounds = [], []
    pos = code_end
    for lo, size, line in sorted(cdata):
        if lo > pos:
            for nm, a, b in blob(pos, lo):
                bounds.append((nm, a, b))
                tail.append(f"{nm}(.rodata)")
            pos = lo
        tail.append(line)
        pos += size
    for nm, a, b in blob(pos, ROM_END):
        bounds.append((nm, a, b))
        tail.append(f"{nm}(.rodata)")
    units = head + ordered + tail

    for nm, lo, hi in bounds:
        Path(f"asm/{ver}/{nm}").write_text(
            f'\t.section .rodata\n\t.global data_{lo:08X}\ndata_{lo:08X}:\n'
            f'\t.incbin "roms/{code}.gba", {lo - ROM_BASE:#x}, {hi - lo:#x}\n')
    fresh = {nm for nm, _lo, _hi in bounds}
    for old in Path(f"asm/{ver}").glob("*.s"):
        if old.name not in fresh and ".global data_" in old.read_text():
            old.unlink()
    print("  " + "  ".join(f"{nm} {lo:#x}..{hi:#x}" for nm, lo, hi in bounds))

    Path(f"config/{ver}/units.txt").write_text("\n".join(units) + "\n")
    print(f"  units.txt: {len(units)} entries")
    if not args.quiet:
        for nm, how in uncertain:
            print(f"    {how:9s} {nm}")


if __name__ == "__main__":
    main()
