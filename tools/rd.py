#!/usr/bin/env python3
import bisect
import os
import re
import subprocess
import sys
import tempfile

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BRANCHES = ("bl", "b", "beq", "bne", "bcs", "bcc", "bmi", "bpl", "bvs", "bvc", "bhi", "bls", "bge", "blt", "bgt", "ble")

rom = open(os.path.join(REPO, "roms", "B8CE.gba"), "rb").read()
syms = {}

for line in open(os.path.join(REPO, "build", "us", "com_us.map")):
    m = re.match(r"^\s+0x0([0-9a-f]{7})\s+([A-Za-z_][A-Za-z0-9_]*)$", line)

    if m:
        syms.setdefault(int(m.group(1), 16), m.group(2))

for line in open(os.path.join(REPO, "config", "us", "symbols.txt")):
    m = re.match(r"^([A-Za-z_]\w*)\s*=\s*(0x[0-9A-Fa-f]+)", line)

    if m:
        syms.setdefault(int(m.group(2), 16), m.group(1))
addrs = sorted(syms)


def name(a):
    if a in syms:
        return syms[a]
    i = bisect.bisect_right(addrs, a) - 1

    if i >= 0 and a - addrs[i] < 0x4000:
        return "%s+0x%x" % (syms[addrs[i]], a - addrs[i])
    return ""


def run(start, end):
    s = start - 0x08000000
    e = end - 0x08000000

    with tempfile.NamedTemporaryFile(suffix=".bin") as tmp:
        tmp.write(rom[s:e])
        tmp.flush()
        out = subprocess.run(["arm-none-eabi-objdump", "-D", "-b", "binary", "-m", "arm7tdmi", "-Mforce-thumb",
                              "--adjust-vma=0x%x" % start, tmp.name], capture_output=True, text=True).stdout

    for line in out.splitlines():
        m = re.match(r"^\s*([0-9a-f]+):\s+([0-9a-f ]+?)\s+(\S+)\s*(.*)$", line)

        if not m:
            continue
        a = int(m.group(1), 16)
        op = m.group(3)
        args = m.group(4)

        if re.fullmatch(r"[0-9a-f]{4}", op) and args.startswith("bl"):
            op, args = args.split(None, 1)
        note = ""
        mm = re.search(r"\[pc, #(\d+)\]", args)

        if mm:
            pa = (a & ~3) + 4 + int(mm.group(1))
            v = int.from_bytes(rom[pa - 0x08000000:pa - 0x08000000 + 4], "little")
            note = "=0x%08x %s" % (v, name(v))
        mm = re.match(r"^\s*(0x[0-9a-f]+)", args)

        if op.rstrip(".n").rstrip(".") in BRANCHES and mm and op.startswith("bl"):
            note = name(int(mm.group(1), 16))

        if op == ".word":
            note = name(int(args.split()[0], 16))
        print("%08x  %-8s %-28s %s" % (a, op, args, note))


if __name__ == "__main__":
    a = sys.argv[1]

    if a.startswith("0x"):
        run(int(a, 16), int(sys.argv[2], 16))
    else:
        st = [k for k, v in syms.items() if v == a][0]
        i = addrs.index(st)
        en = int(sys.argv[2], 16) if len(sys.argv) > 2 else addrs[i + 1]
        print("%s 0x%08x..0x%08x (%d bytes)" % (a, st, en, en - st))
        run(st, en)
