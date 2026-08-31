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
CODE_HI = 0x08121330
ROM_END = 0x0A000000

INCLUDE_ASM_RE = re.compile(r'INCLUDE_ASM\("([^"]+)/([^"/]+)\.s"\)')

THUMB = """.syntax unified
{align}\t.global {name}
\t.thumb
\t.thumb_func
\t.type {name}, %function
{name}:
\t.incbin "roms/{code}.gba", {off:#x}, {size:#x}
.syntax divided
"""

DATA = """.syntax unified
{align}\t.global {name}
{name}:
\t.incbin "roms/{code}.gba", {off:#x}, {size:#x}
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


def load_funcmap(path):
    rows = []
    for line in Path(path).read_text().splitlines():
        nm, ua, sz, va, how = line.split("\t")
        rows.append([nm, int(ua, 16), int(sz), None if va == "-" else int(va, 16), how])
    return rows


def complete(rows, code_end):
    n = len(rows)
    i = 0
    while i < n:
        if rows[i][3] is not None:
            i += 1
            continue
        j = i
        while j < n and rows[j][3] is None:
            j += 1
        prev = rows[i - 1]
        start = prev[3] + prev[2]
        stop = rows[j][3] if j < n else code_end
        want = sum(rows[k][2] for k in range(i, j))
        span = stop - start
        for k in range(i, j):
            rows[k][3] = start
            share = rows[k][2] if want == 0 else round(span * rows[k][2] / want / 4) * 4
            start = min(start + max(0, share), stop)
        i = j
    addrs = [r[3] for r in rows] + [code_end]
    for i, r in enumerate(rows):
        r.append(max(0, addrs[i + 1] - r[3]))
    return rows


def symbol_map(rows, us, ot):
    pairs = {}
    for nm, ua, sz, va, how, vsz in rows:
        if va is None or vsz != sz:
            continue
        a = us[ua - ROM_BASE:ua - ROM_BASE + sz]
        b = ot[va - ROM_BASE:va - ROM_BASE + sz]
        if len(b) != sz or mask(a) != mask(b):
            continue
        for k in range(0, sz - 3, 4):
            w1 = struct.unpack_from("<I", a, k)[0]
            w2 = struct.unpack_from("<I", b, k)[0]
            if (w1 >> 24) in (0x02, 0x03, 0x08, 0x09) and (w2 >> 24) in (0x02, 0x03, 0x08, 0x09):
                pairs.setdefault(w1, {})
                pairs[w1][w2] = pairs[w1].get(w2, 0) + 1
    res = {}
    for k, v in pairs.items():
        best = sorted(v.items(), key=lambda x: -x[1])
        if len(best) == 1 or best[0][1] > 2 * best[1][1]:
            res[k] = best[0][0]
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
    args = p.parse_args()
    ver, code = args.version, args.code

    us = Path("roms/B8CE.gba").read_bytes()
    ot = Path(f"roms/{code}.gba").read_bytes()
    rows = load_funcmap(f"config/{ver}/funcmap.txt")

    provisional = [r for r in rows if r[3] is not None]
    guess_end = provisional[-1][3] + (CODE_HI - provisional[-1][1])
    rows = complete(rows, guess_end)
    tr = translator(symbol_map(rows, us, ot))

    code_end, how_end = tr(CODE_HI)
    if code_end != guess_end:
        rows = [r[:5] for r in rows]
        rows = complete(rows, code_end)
        tr = translator(symbol_map(rows, us, ot))
    print(f"{ver}: code region {rows[0][3]:#x} .. {code_end:#x} ({how_end})")

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
    wrote = missing = 0
    for src in sorted(Path("src").glob("*.c")):
        for m in INCLUDE_ASM_RE.finditer(src.read_text()):
            tu, name = m.group(1), m.group(2)
            r = byname.get(name)
            if r is None or r[5] == 0:
                missing += 1
                print(f"  missing layout for {tu}/{name}")
                continue
            usasm = Path(f"asm/us/nonmatchings/{tu}/{name}.s")
            tmpl = DATA if usasm.exists() and ".thumb_func" not in usasm.read_text() else THUMB
            d = asm_root / tu
            d.mkdir(parents=True, exist_ok=True)
            (d / f"{name}.s").write_text(
                tmpl.format(name=name, code=code, off=r[3] - ROM_BASE, size=r[5],
                            align="\t.align 2, 0\n" if r[3] % 4 == 0 else ""))
            wrote += 1
    print(f"  chunks: {wrote} written, {missing} missing")

    first = rows[0][3]
    Path(f"asm/{ver}").mkdir(parents=True, exist_ok=True)
    Path(f"asm/{ver}/header.s").write_text(
        f'\t.arm\n\t.section .text\n\t.global _start\n_start:\n'
        f'\tb EntryPoint\n\t.incbin "roms/{code}.gba", 0x4, 0xBC\n')
    Path(f"asm/{ver}/crt0.s").write_text(
        f'\t.arm\n\t.section .text\n\t.global EntryPoint\nEntryPoint:\n'
        f'\t.incbin "roms/{code}.gba", 0xC0, {first - ROM_BASE - 0xC0:#x}\n')

    units, data_idx = [], 0
    data_bounds = []
    for line in Path("config/us/units.txt").read_text().splitlines():
        s = line.strip()
        if s.startswith("data.s(") or s.startswith("data2.s("):
            data_idx += 1
        units.append(line)

    tbl_start, _ = tr(0x09D6D4BC)
    tbl_end, _ = tr(0x09D6D5ED)
    data_bounds = [(code_end, tbl_start), (tbl_end, ROM_END)]
    for i, (lo, hi) in enumerate(data_bounds):
        nm = "data.s" if i == 0 else "data2.s"
        Path(f"asm/{ver}/{nm}").write_text(
            f'\t.section .rodata\n\t.global data_{lo:08X}\ndata_{lo:08X}:\n'
            f'\t.incbin "roms/{code}.gba", {lo - ROM_BASE:#x}, {hi - lo:#x}\n')
    print(f"  data.s {data_bounds[0][0]:#x}..{data_bounds[0][1]:#x}  "
          f"data2.s {data_bounds[1][0]:#x}..{data_bounds[1][1]:#x}")

    Path(f"config/{ver}/units.txt").write_text("\n".join(units) + "\n")
    for nm, how in uncertain:
        print(f"    {how:9s} {nm}")


if __name__ == "__main__":
    main()
