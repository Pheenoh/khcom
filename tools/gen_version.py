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
SIZE_SLACK = 64

TARGET_ANCHORS = {
    "eu": {
        0x02034890: 0x02034898,
        0x08F7CF18: 0x08F8DE14,
        0x0976DB68: 0x0973BA18,
        0x0976DB9C: 0x0973BA4C,
        0x09ED77D4: 0x09F476C8,
        0x09ED82D4: 0x09F481C8,
        0x08130E6C: 0x0887F340,
        0x0976D8A6: 0x097385B0,
        0x0976DBDA: 0x0973BA8A,
        0x092EB78A: 0x093BAE12,
        0x09958124: 0x0994AFB0,
        0x09EE1538: 0x09F5C140,
        0x0951B2B8: 0x09539B24,
        0x090A4664: 0x09193560,
        0x09EEB000: 0x09F77120,
        0x09EEB008: 0x09F77128,
        0x09EEB03C: 0x09F7715C,
        0x09035730: 0x090CEA44,
        0x096B2664: 0x09677C0C,
        0x09992F70: 0x099991EC,
        0x09C5CC7C: 0x09CE23B0,
        0x09EFAF60: 0x09F87494,
        0x09EFAF6C: 0x09F874A0,
        0x020354A8: 0x02035938,
        0x020354B0: 0x02035940,
        0x09A324DC: 0x09A854A0,
        0x097DB5F8: 0x097B1D00,
        0x09841798: 0x09815E40,
        0x09A123DC: 0x09A62840,
        0x09A18EBC: 0x09A69320,
        0x09ED9B88: 0x09F49A8C,
        0x09EE78A4: 0x09F72CD8,
        0x09EF4F08: 0x09F802B0,
        0x096AD744: 0x0967818C,
        0x097A28DA: 0x09780322,
        0x09EF6934: 0x09F81FB0,
        0x098A8C66: 0x0988740A,
    },
    "jp": {
        0x09C8D47A: 0x09C678B4,
        0x09C8F1FA: 0x09C68CC6,
        0x09EFBAD4: 0x09ED304C,
    },
}

TARGET_ONLY_SYMBOLS = {
    "eu": {
        "gLanguage": 0x03007484,
        "gModeLang": 0x09F3EA64,
        "gUnkEu_08F6A73C": 0x08F6A73C,
        "gUnkEu_08F79038": 0x08F79038,
        "gUnkEu_09814E40": 0x09814E40,
        "gUnkEu_09815640": 0x09815640,
        "gUnkEu_09F80124": 0x09F80124,
        "gUnkEu_09F80138": 0x09F80138,
        "gUnkEu_09F801D4": 0x09F801D4,
        "gUnkEu_09F80200": 0x09F80200,
        "gUnkEu_09F80214": 0x09F80214,
        "gUnkEu_09F81A80": 0x09F81A80,
        "gUnkEu_09F81A9C": 0x09F81A9C,
        "gUnkEu_09F81AF0": 0x09F81AF0,
        "gUnkEu_09F81AD4": 0x09F81AD4,
        "gUnkEu_09F81AB8": 0x09F81AB8,
        "gUnkEu_09F81B0C": 0x09F81B0C,
        "gUnkEu_0974E3CC": 0x0974E3CC,
        "gUnkEu_0974EC7C": 0x0974EC7C,
        "gUnkEu_0975038C": 0x0975038C,
        "gUnkEu_0974FBDC": 0x0974FBDC,
        "gUnkEu_0974F42C": 0x0974F42C,
        "gUnkEu_097462F2": 0x097462F2,
        "gUnkEu_09746CA4": 0x09746CA4,
        "gUnkEu_097483B4": 0x097483B4,
        "gUnkEu_09747C04": 0x09747C04,
        "gUnkEu_09747454": 0x09747454,
        "gUnkEu_09748BA6": 0x09748BA6,
        "gUnkEu_0974A284": 0x0974A284,
        "gUnkEu_0974D47A": 0x0974D47A,
        "gUnkEu_0974C504": 0x0974C504,
        "gUnkEu_0974B306": 0x0974B306,
        "gUnkEu_0973F058": 0x0973F058,
        "gUnkEu_09741E9A": 0x09741E9A,
        "gUnkEu_09742A74": 0x09742A74,
        "gUnkEu_0974507E": 0x0974507E,
        "gUnkEu_097445AC": 0x097445AC,
        "gUnkEu_09743812": 0x09743812,
        "gUnkEu_09745B92": 0x09745B92,
        "gUnkEu_09F81A04": 0x09F81A04,
        "gUnkEu_09F80228": 0x09F80228,
        "gUnkEu_09750AF8": 0x09750AF8,
        "gUnkEu_09750EE4": 0x09750EE4,
        "gUnkEu_09751ADE": 0x09751ADE,
        "gUnkEu_097516F8": 0x097516F8,
        "gUnkEu_097512CA": 0x097512CA,
        "gUnkEu_09F81C54": 0x09F81C54,
        "gUnkEu_09F81C5C": 0x09F81C5C,
        "gUnkEu_09F81C74": 0x09F81C74,
        "gUnkEu_09F81C6C": 0x09F81C6C,
        "gUnkEu_09F81C64": 0x09F81C64,
        "gUnkEu_0973F402": 0x0973F402,
        "gUnkEu_0973FC6A": 0x0973FC6A,
        "gUnkEu_097415E8": 0x097415E8,
        "gUnkEu_09740D62": 0x09740D62,
        "gUnkEu_09740536": 0x09740536,
        "gUnkEu_09F81A1C": 0x09F81A1C,
        "gUnkEu_09F81A08": 0x09F81A08,
        "gUnkEu_09F81A34": 0x09F81A34,
        "gUnkEu_09F81A20": 0x09F81A20,
        "gUnkEu_09F81A7C": 0x09F81A7C,
        "gUnkEu_09F81A68": 0x09F81A68,
        "gUnkEu_09F81A64": 0x09F81A64,
        "gUnkEu_09F81A50": 0x09F81A50,
        "gUnkEu_09F81A4C": 0x09F81A4C,
        "gUnkEu_09F81A38": 0x09F81A38,
        "gUnkEu_0973EEFE": 0x0973EEFE,
        "gUnkEu_09F84EFC": 0x09F84EFC,
        "gUnkEu_08B51BA8": 0x08B51BA8,
        "gUnkEu_09F5C1FC": 0x09F5C1FC,
        "gUnkEu_0203C964": 0x0203C964,
        "gUnkEu_0203C970": 0x0203C970,
        "gUnkEu_0203C97C": 0x0203C97C,
        "gUnkEu_096CB088": 0x096CB088,
        "gUnkEu_09F80288": 0x09F80288,
        "gUnkEu_096CB104": 0x096CB104,
        "gUnkEu_09F80350": 0x09F80350,
        "gUnkEu_09F80364": 0x09F80364,
        "gUnkEu_09F8029C": 0x09F8029C,
        "gUnkEu_09F802C8": 0x09F802C8,
        "gUnkEu_09F802DC": 0x09F802DC,
        "gUnkEu_09F84FBC": 0x09F84FBC,
        "gUnkEu_09F84FD0": 0x09F84FD0,
        "gUnkEu_09F84FE4": 0x09F84FE4,
        "gUnkEu_08890E1C": 0x08890E1C,
        "gUnkEu_08890E44": 0x08890E44,
        "gUnkEu_08895AF4": 0x08895AF4,
        "gUnkEu_08895CF8": 0x08895CF8,
        "gUnkEu_08895DBC": 0x08895DBC,
        "gUnkEu_08891508": 0x08891508,
        "gUnkEu_088927F4": 0x088927F4,
        "gUnkEu_088928E4": 0x088928E4,
        "gUnkEu_090CE9EA": 0x090CE9EA,
        "gUnkEu_090D1DF4": 0x090D1DF4,
        "gUnkEu_097D8300": 0x097D8300,
        "gUnkEu_097D8F00": 0x097D8F00,
        "gUnkEu_097D9B00": 0x097D9B00,
        "gUnkEu_097DA700": 0x097DA700,
        "gUnkEu_099991E0": 0x099991E0,
        "gUnkEu_09F847D4": 0x09F847D4,
        "gUnkEu_09F84810": 0x09F84810,
        "gUnkEu_09F65FDC": 0x09F65FDC,
        "gUnkEu_09F65FF0": 0x09F65FF0,
        "gUnkEu_09F66004": 0x09F66004,
        "gUnkEu_09F6FDB4": 0x09F6FDB4,
        "gUnkEu_09F72BFC": 0x09F72BFC,
        "gUnkEu_09F7434C": 0x09F7434C,
        "gUnkEu_09F74360": 0x09F74360,
        "gUnkEu_09955250": 0x09955250,
        "gUnkEu_09957550": 0x09957550,
        "gUnkEu_09959850": 0x09959850,
        "gUnkEu_0995BB50": 0x0995BB50,
        "gUnkEu_0995DE50": 0x0995DE50,
        "gUnkEu_09960150": 0x09960150,
        "gUnkEu_09962450": 0x09962450,
        "gUnkEu_09964750": 0x09964750,
        "gUnkEu_09966A50": 0x09966A50,
        "gUnkEu_09968D50": 0x09968D50,
        "gUnkEu_099563D0": 0x099563D0,
        "gUnkEu_099586D0": 0x099586D0,
        "gUnkEu_0995A9D0": 0x0995A9D0,
        "gUnkEu_0995CCD0": 0x0995CCD0,
        "gUnkEu_0995EFD0": 0x0995EFD0,
        "gUnkEu_099612D0": 0x099612D0,
        "gUnkEu_099635D0": 0x099635D0,
        "gUnkEu_099658D0": 0x099658D0,
        "gUnkEu_09967BD0": 0x09967BD0,
        "gUnkEu_09969ED0": 0x09969ED0,
        "gUnkEu_08892780": 0x08892780,
        "gUnkEu_08892864": 0x08892864,
        "gUnkEu_0996D130": 0x0996D130,
        "gUnkEu_0996D930": 0x0996D930,
        "gUnkEu_0996E130": 0x0996E130,
        "gUnkEu_0996E930": 0x0996E930,
        "gUnkEu_09F843D8": 0x09F843D8,
        "gUnkEu_09F843E8": 0x09F843E8,
        "gUnkEu_09F843F8": 0x09F843F8,
        "gUnkEu_09F84408": 0x09F84408,
        "gUnkEu_09953BF0": 0x09953BF0,
        "gUnkEu_099543F0": 0x099543F0,
        "gUnkEu_09954BF0": 0x09954BF0,
        "gUnkEu_09938170": 0x09938170,
        "gUnkEu_09939D30": 0x09939D30,
        "gUnkEu_0993B8F0": 0x0993B8F0,
        "gUnkEu_0993D4B0": 0x0993D4B0,
        "gUnkEu_0993E9B0": 0x0993E9B0,
        "gUnkEu_0993FEB0": 0x0993FEB0,
        "gUnkEu_099413B0": 0x099413B0,
        "gUnkEu_099428B0": 0x099428B0,
        "gUnkEu_09943DB0": 0x09943DB0,
        "gUnkEu_099452B0": 0x099452B0,
        "gUnkEu_099467B0": 0x099467B0,
        "gUnkEu_09947CB0": 0x09947CB0,
        "gUnkEu_099491B0": 0x099491B0,
        "gUnkEu_0994A6B0": 0x0994A6B0,
        "gUnkEu_0994A8B0": 0x0994A8B0,
        "gUnkEu_0994AAB0": 0x0994AAB0,
        "gUnkEu_0994ACB0": 0x0994ACB0,
        "gUnkEu_09827920": 0x09827920,
        "gUnkEu_098272D0": 0x098272D0,
        "gUnkEu_09823D9C": 0x09823D9C,
        "gUnkEu_09827C34": 0x09827C34,
        "gUnkEu_0981F960": 0x0981F960,
        "gUnkEu_0982761C": 0x0982761C,
        "gUnkEu_097ADE00": 0x097ADE00,
        "gUnkEu_0981ECC0": 0x0981ECC0,
        "gUnkEu_09814A40": 0x09814A40,
    },
    "jp": {
        "gUnk_0814FBB0": 0x0814FBB0,
        "gUnk_0814FBBC": 0x0814FBBC,
        "gUnk_0814FBD4": 0x0814FBD4,
    },
}

TARGET_EXTRA_LABELS = {
    "eu": [0x080059F4, 0x08005A1C, 0x08005ADC, 0x0805E968, 0x0805E9AC, 0x080C2740, 0x080DA830,
           0x080DA848, 0x080DA860],
}

TARGET_FUNC_SIZE = {
    "jp": {
        "func_08066588": 156,
        "func_080A2980": 260,
        "task_title_logo_2": 196,
    },
    "eu": {
        "func_080A2980": 260,
        "func_08088EB4": 136,
        "func_0808CA78": 228,
        "func_0808CB60": 88,
        "func_0808CD48": 164,
        "func_0808D73C": 180,
        "func_0808D7EC": 76,
        "func_0808DB50": 468,
        "func_0808E3E0": 152,
        "func_0808E474": 276,
        "func_0808E890": 92,
        "func_0808E8E8": 80,
        "func_0808E934": 220,
        "func_0809B76C": 252,
        "func_0809B920": 252,
        "func_080A5C60": 76,
        "func_080B0754": 308,
        "func_080B4154": 192,
        "func_080EC04C": 148,
        "func_080ED250": 208,
        "func_080EEB00": 352,
        "func_080F7AB4": 52,
        "func_08100608": 56,
        "func_081017A0": 492,
        "func_080D6C54": 232,
        "func_080D6D2C": 148,
        "task_title_lumichange_2": 152,
        "func_080D6A64": 288,
        "func_080D6B7C": 232,
        "task_title_menu_2": 232,
        "task_title_lumichange_0": 264,
        "task_title_menu_0": 672,
        "task_title_obj_0": 700,
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

PART = """{align}	.global {name}
	.thumb
	.thumb_func
	.type {name}, %function
{name}:
	.incbin "roms/{code}.gba", {off:#x}, {size:#x}
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


def complete(rows, code_end, flexible, unit_of=None, clean=None, fixed=None):
    unit_of = unit_of or {}
    clean = clean or (lambda r: True)
    fixed = fixed or {}
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
        begin = prev[3] + fixed.get(prev[0], prev[2])
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
            nk = present[k + 1][4] if k + 1 < len(present) else None
            tsz = fixed.get(r[0], r[2])

            if (r[0] not in fixed
                    and nxt > r[3] and nk in ("named", "xref", "global", "body")
                    and r[4] in ("named", "xref", "global", "body")
                    and abs(nxt - r[3] - r[2]) <= SIZE_SLACK
                    and not clean(r)):
                tsz = nxt - r[3]
            start[id(r)] = r[3]
            size[id(r)] = tsz
            pos = r[3] + tsz
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
        if a < 0x02000000 or a >= 0x0E000000:
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
    fixed = TARGET_FUNC_SIZE.get(ver, {})

    provisional = [r for r in rows if r[3] is not None]
    guess_end = provisional[-1][3] + (CODE_HI - provisional[-1][1])
    rows = complete(rows, guess_end, flexible, owner, clean, fixed)
    res = symbol_map(rows, us, ot)
    res.update(anchors)
    tr = translator(res)

    code_end, how_end = tr(CODE_HI)
    if code_end != guess_end:
        rows = load_funcmap(f"config/{ver}/funcmap.txt")
        rows = complete(rows, code_end, flexible, owner, clean, fixed)
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
    for nm, a in TARGET_ONLY_SYMBOLS.get(ver, {}).items():
        out.append(f"{nm} = {a:#010x}")
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
                    cuts = ([at]
                            + [x for x in TARGET_EXTRA_LABELS.get(ver, [])
                               if at < x < at + gap[0]]
                            + [at + gap[0]])
                    body = "".join(
                        PART.format(name=name if lo == at else f"{ver}_{lo:08X}",
                                    code=code, off=lo - ROM_BASE, size=hi - lo,
                                    align="\t.align 2, 0\n" if lo % 4 == 0 else "")
                        for lo, hi in zip(cuts, cuts[1:]) if hi > lo)
                    (d / f"{name}.s").write_text(
                        ".syntax unified\n\t.text\n" + body + ".syntax divided\n")
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
            d = asm_root / tu
            d.mkdir(parents=True, exist_ok=True)
            if (usasm.exists() and r[5] != 0
                    and ".include \"asm/" in usasm.read_text()):
                (d / f"{name}.s").write_text(usasm.read_text())
            else:
                tmpl = DATA if usasm.exists() and ".thumb_func" not in usasm.read_text() else THUMB
                if r[5] == 0:
                    tmpl = EMPTY
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
    extra_labels = TARGET_EXTRA_LABELS.get(ver, [])
    slack = 0
    for at, (size, kind, a, b, clean) in sorted(gaps.items()):
        unit = owner.get(a[0], "?").rsplit("/", 1)[-1][:-2]
        if kind == "boundary":
            nm = f"{ver}_{at:08X}.s"
            cuts = [at] + [x for x in extra_labels if at < x < at + size] + [at + size]
            body = "".join(
                PART.format(name=f"{ver}_{lo:08X}", code=code, off=lo - ROM_BASE,
                            size=hi - lo,
                            align="\t.align 2, 0\n" if lo % 4 == 0 else "")
                for lo, hi in zip(cuts, cuts[1:]) if hi > lo)
            Path(f"asm/{ver}/{nm}").write_text(
                ".syntax unified\n\t.text\n" + body + ".syntax divided\n")
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
        elif name.endswith(".s"):
            obj = f"build/us/asm/{name[:-2]}.o"
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
        if not t or t.startswith("#"):
            head.append(line)
            continue
        key = unit_key(t.split()[0])

        if key is None and t.endswith(".s"):
            head.append(line)
            continue
        body.append((key, line))
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
