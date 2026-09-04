#!/usr/bin/env python3
import argparse
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MAP = os.path.join(REPO, "build", "us", "com_us.map")
MAP_LINE = re.compile(r"^ +(0x0[89][0-9a-f]{6}) +([A-Za-z_]\w*)$")


def text_symbols():
    syms = []

    for line in open(MAP):
        m = MAP_LINE.match(line.rstrip())

        if m:
            syms.append((int(m.group(1), 16), m.group(2)))
    syms.sort()
    return {name: (addr, nxt) for (addr, name), (nxt, _) in zip(syms, syms[1:] + [(0, "")])}


def jp_unaligned():
    return unaligned("jp")


def unaligned(ver):
    bad = set()

    for line in open(os.path.join(REPO, "config", ver, "funcmap.txt")):
        f = line.rstrip("\n").split("\t")

        if len(f) >= 4 and f[3] == "-":
            bad.add(f[0])
    return bad


def attempted(ledger):
    seen = set()

    if ledger and os.path.exists(ledger):
        for line in open(ledger):
            f = line.split("\t")

            if f and not f[0].startswith("#") and f[0] != "symbol":
                seen.add(f[0])
    return seen


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("unit")
    ap.add_argument("-n", type=int, default=12)
    ap.add_argument("--max-size", type=int, default=600)
    ap.add_argument("--ledger")
    ap.add_argument("--all", action="store_true")
    args = ap.parse_args()

    if not os.path.exists(MAP):
        sys.exit("no build/us/com_us.map: run configure.py && ninja first")
    src = open(os.path.join(REPO, "src", args.unit + ".c")).read()
    syms = text_symbols()
    bad = unaligned("jp")
    bad_eu = unaligned("eu")
    done = attempted(args.ledger)
    rows = []
    guarded = False

    for line in src.split("\n"):
        s = line.strip()

        if s == "#else":
            guarded = True
        elif s == "#endif":
            guarded = False
        m = re.search(r'INCLUDE_ASM\("[^"/]+/(\w+)\.s"\)', line)

        if not m or guarded:
            continue
        sym = m.group(1)

        if sym not in syms:
            continue
        addr, nxt = syms[sym]
        size = nxt - addr

        if size < 16:
            continue
        why = ""
        note = "needs-eu-guard" if sym in bad_eu else ""

        if sym in bad:
            why = "jp-unaligned"
        elif sym in done:
            why = "attempted"
        elif size > args.max_size:
            why = "large"
        rows.append((size, sym, addr, why, note))
    rows.sort()
    n = 0

    for size, sym, addr, why, note in rows:
        if why and not args.all:
            continue
        print("%-28s 0x%08X %5d %s" % (sym, addr, size, why or note))
        n += 1

        if n >= args.n and not args.all:
            break


if __name__ == "__main__":
    main()
