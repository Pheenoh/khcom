#!/usr/bin/env python3
"""Derive a task's work-area struct from the ROM.

    python3 tools/work_struct.py task_bos_md_hahen MdHahenWork

The registration table gives each task its work size, and its four callbacks
receive the work pointer in r0. Tracking that pointer through register copies,
constant offsets and calls yields the offsets and widths actually used; the
declared size bounds the result, so anything past it is a tracking artifact and
is dropped with a note on stderr.

    --list   print every task with its size and callbacks
"""

import argparse
import collections
import re
import struct
import subprocess
import sys
from pathlib import Path

ROM_BASE = 0x08000000
CODE_END = ROM_BASE + 0x122000

INSN = re.compile(r"^\s*([0-9a-f]+):\s+([0-9a-f ]+?)\s\s+(.*)$")
MOVI = re.compile(r"^movs\s+(r\d+), #(\d+)$")
LSLI = re.compile(r"^lsls\s+(r\d+), (?:(r\d+), )?#(\d+)$")
ADDRR = re.compile(r"^adds\s+(r\d+), (r\d+), (r\d+)$")
ADDR3 = re.compile(r"^adds\s+(r\d+), (r\d+), #(\d+)$")
ADDI = re.compile(r"^adds\s+(r\d+), #(\d+)$")
COPY = re.compile(r"^(?:adds\s+(r\d+), (r\d+), #0|mov\s+(r\d+), (r\d+))$")
ACC = re.compile(r"^(ldrb|ldrh|ldr|strb|strh|str|ldrsh|ldrsb)\s+r\d+, \[(r\d+), #(\d+)\]")
ACCR = re.compile(r"^(ldrsh|ldrsb|ldrb|ldrh|ldr|strb|strh|str)\s+r\d+, \[(r\d+), (r\d+)\]")
CALL = re.compile(r"^bl\b")
KILL = re.compile(r"^(?:ldr|ldrb|ldrh|ldrsh|ldrsb|movs|mov|adds|subs|lsls|lsrs|asrs|muls|ands|orrs|eors|negs)\s+(r\d+)")

ARGS = ("r0", "r1", "r2", "r3")


def disassemble(rom_path):
    data = Path(rom_path).read_bytes()
    blob = Path("/tmp/mt/work_code.bin")
    blob.parent.mkdir(parents=True, exist_ok=True)
    blob.write_bytes(data[0xC0:0x117E44])
    out = subprocess.run(
        ["arm-none-eabi-objdump", "-b", "binary", "-m", "armv4t", "-M", "force-thumb",
         "-D", "--adjust-vma=%d" % (ROM_BASE + 0xC0), str(blob)],
        capture_output=True, text=True, check=True).stdout
    rows = []
    for line in out.splitlines():
        m = INSN.match(line)
        if m:
            rows.append((int(m.group(1), 16), re.sub(r"\s*@.*$", "", m.group(3)).strip()))
    return rows, {a: i for i, (a, _) in enumerate(rows)}


def read_tasks(rom_path):
    data = Path(rom_path).read_bytes()
    names = {}
    for m in re.finditer(rb"(?<![A-Za-z0-9_])(task_[A-Za-z0-9_]+)\x00", data):
        names[ROM_BASE + m.start(1)] = m.group(1).decode()
    words = struct.unpack("<%dI" % (len(data) // 4), data)

    def valid(w):
        return w == 0 or (w & 1 and ROM_BASE < w < CODE_END)

    tasks = {}
    for i, w in enumerate(words):
        if w not in names:
            continue
        fns = words[i + 1:i + 5]
        if len(fns) == 4 and all(map(valid, fns)) and any(fns) and words[i + 5] < 0x10000:
            tasks.setdefault(names[w], (words[i + 5], [f & ~1 for f in fns if f]))
    return tasks


def scan(rows, index, start, end):
    fields = collections.defaultdict(set)
    base, const = {"r0": 0}, {}
    i = index.get(start)
    if i is None:
        return fields
    while i < len(rows) and rows[i][0] < end:
        txt = rows[i][1]
        m = ACC.match(txt)
        if m and m.group(2) in base:
            fields[base[m.group(2)] + int(m.group(3))].add(m.group(1))
            i += 1
            continue
        m = ACCR.match(txt)
        if m and m.group(2) in base:
            fields[base[m.group(2)]].add(m.group(1) + "[]")
            i += 1
            continue
        m = COPY.match(txt)
        if m:
            dst, src = m.group(1) or m.group(3), m.group(2) or m.group(4)
            base[dst] = base[src] if src in base else None
            if base[dst] is None:
                del base[dst]
            i += 1
            continue
        m = ADDRR.match(txt)
        if m:
            d, a, b = m.groups()
            if a in base and b in const:
                base[d] = base[a] + const[b]
            elif b in base and a in const:
                base[d] = base[b] + const[a]
            else:
                base.pop(d, None)
            const.pop(d, None)
            i += 1
            continue
        m = ADDR3.match(txt)
        if m and m.group(2) in base:
            base[m.group(1)] = base[m.group(2)] + int(m.group(3))
            i += 1
            continue
        m = ADDI.match(txt)
        if m and m.group(1) in base:
            base[m.group(1)] += int(m.group(2))
            i += 1
            continue
        m = MOVI.match(txt)
        if m:
            const[m.group(1)] = int(m.group(2))
            base.pop(m.group(1), None)
            i += 1
            continue
        m = LSLI.match(txt)
        if m:
            d, src = m.group(1), m.group(2) or m.group(1)
            if src in const:
                const[d] = const[src] << int(m.group(3))
            else:
                const.pop(d, None)
            base.pop(d, None)
            i += 1
            continue
        if CALL.match(txt):
            for r in ARGS:
                if r in base:
                    fields[base[r]].add("addr")
                base.pop(r, None)
                const.pop(r, None)
            i += 1
            continue
        m = KILL.match(txt)
        if m:
            base.pop(m.group(1), None)
            const.pop(m.group(1), None)
        i += 1
    return fields


def width(kinds):
    if kinds & {"ldr", "str"}:
        return 4
    if kinds & {"ldrh", "strh", "ldrsh"}:
        return 2
    if kinds & {"ldrb", "strb", "ldrsb"}:
        return 1
    return 4


def ctype(kinds, w):
    if w == 4:
        return "u32"
    if w == 2:
        return "s16" if "ldrsh" in kinds and not kinds & {"ldrh", "strh"} else "u16"
    return "s8" if "ldrsb" in kinds and not kinds & {"ldrb", "strb"} else "u8"


def function_ends(mapfile):
    syms = []
    for line in Path(mapfile).read_text().splitlines():
        m = re.match(r"\s+0x0([0-9a-f]{7})\s+(\S+)\s*$", line)
        if m:
            syms.append(int(m.group(1), 16) | ROM_BASE)
    syms.sort()
    return {a: (syms[i + 1] if i + 1 < len(syms) else a) for i, a in enumerate(syms)}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("task", nargs="?")
    ap.add_argument("struct", nargs="?")
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--rom", default="roms/B8CE.gba")
    ap.add_argument("--map", default="build/us/com_us.map")
    args = ap.parse_args()

    tasks = read_tasks(args.rom)
    if args.list:
        for name in sorted(tasks):
            size, fns = tasks[name]
            print("%-34s size=0x%04X  %s" % (name, size, " ".join("%08X" % f for f in fns)))
        return
    if not args.task or not args.struct:
        ap.error("task and struct name are required unless --list is given")
    if args.task not in tasks:
        sys.exit("error: %s is not in the task table" % args.task)

    rows, index = disassemble(args.rom)
    ends = function_ends(args.map)
    size, fns = tasks[args.task]

    merged = collections.defaultdict(set)
    for fn in fns:
        end = ends.get(fn)
        if end:
            for off, kinds in scan(rows, index, fn, end).items():
                merged[off] |= kinds

    dropped = sorted(o for o in merged if o >= size)
    for o in dropped:
        del merged[o]
    if dropped:
        print("dropped %d offsets past size 0x%X: %s"
              % (len(dropped), size, ", ".join("0x%X" % o for o in dropped)), file=sys.stderr)

    offs = sorted(merged)
    print("typedef struct %s {" % args.struct)
    pos = 0
    for i, off in enumerate(offs):
        if off < pos:
            continue
        if off > pos:
            print("    u8 unk_%03X[0x%X];" % (pos, off - pos))
            pos = off
        w = width(merged[off])
        nxt = offs[i + 1] if i + 1 < len(offs) else size
        while w > 1 and (pos + w > nxt or pos % w):
            w //= 2
        print("    %s unk_%03X;" % (ctype(merged[off], w), off))
        pos += w
    if pos < size:
        print("    u8 unk_%03X[0x%X];" % (pos, size - pos))
    print("} %s;" % args.struct)


if __name__ == "__main__":
    main()
