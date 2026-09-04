#!/usr/bin/env python3
import argparse
import collections
import glob
import os
import re
import struct

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CODES = {"jp": "B8CJ", "eu": "B8CP"}


def guarded():
    out = []

    for path in sorted(glob.glob(os.path.join(REPO, "src", "*.c"))):
        body = open(path, errors="ignore").read()
        stack = []

        for line in body.split("\n"):
            s = line.strip()
            m = re.match(r"#if(n?)def\s+(\w+)", s)

            if m:
                stack.append([m.group(2), m.group(1) == "n"])
                continue

            if s.startswith("#else"):
                if stack:
                    stack[-1][1] = not stack[-1][1]
                continue

            if s.startswith("#endif"):
                if stack:
                    stack.pop()
                continue
            m = re.match(r'INCLUDE_ASM\("([^"]*)/([^"/]+)\.s"\)', s)

            if not (m and stack):
                continue
            tags = [t for t, _ in stack if t.startswith("VERSION_")]

            if not tags:
                continue
            sym = m.group(2)
            has_c = re.search(r"^[A-Za-z][^\n]*\b%s\s*\([^;\n]*\)[ \t]*\{" % re.escape(sym), body, re.M)
            out.append((os.path.basename(path)[:-2], sym, "+".join(tags), bool(has_c)))
    return out


def funcmap(ver):
    rows = []

    for line in open(os.path.join(REPO, "config", ver, "funcmap.txt")):
        f = line.rstrip("\n").split("\t")

        if len(f) >= 5:
            rows.append(f)
    placed = sorted([r for r in rows if r[3] != "-"], key=lambda r: int(r[3], 16))
    span = {}

    for i, r in enumerate(placed):
        a = int(r[3], 16)
        b = int(placed[i + 1][3], 16) if i + 1 < len(placed) else a + int(r[2])
        span[r[0]] = b - a
    return {r[0]: r for r in rows}, span


def mask(b):
    out = bytearray(b)

    for k in range(0, len(b) - 1, 2):
        if 0xF000 <= struct.unpack_from("<H", b, k)[0] <= 0xFFFF:
            struct.pack_into("<H", out, k, 0)

    for k in range(0, len(b) - 3, 4):
        if (struct.unpack_from("<I", b, k)[0] >> 24) in (0x08, 0x09, 0x02, 0x03):
            struct.pack_into("<I", out, k, 0)
    return bytes(out)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("version", choices=("jp", "eu"))
    ap.add_argument("--unit")
    ap.add_argument("--kind")
    args = ap.parse_args()
    fm, span = funcmap(args.version)
    us = open(os.path.join(REPO, "roms", "B8CE.gba"), "rb").read()
    tgt = open(os.path.join(REPO, "roms", CODES[args.version] + ".gba"), "rb").read()
    want = "VERSION_" + args.version.upper()
    buckets = collections.Counter()
    rows = []

    for unit, sym, tags, has_c in guarded():
        if not has_c or (want not in tags and "VERSION_US" not in tags):
            continue
        r = fm.get(sym)

        if r is None:
            kind, n, detail = "no-row", 0, ""
        elif r[4] == "absent":
            kind, n, detail = "absent", 0, ""
        elif r[3] == "-":
            kind, n, detail = "unaligned", 0, ""
        else:
            ua, sz, ta = int(r[1], 16), int(r[2]), int(r[3], 16)
            a = mask(us[ua - 0x08000000:ua - 0x08000000 + sz])
            b = mask(tgt[ta - 0x08000000:ta - 0x08000000 + sz])
            d = [(i, struct.unpack_from("<H", a, i)[0], struct.unpack_from("<H", b, i)[0])
                 for i in range(0, sz - 1, 2)
                 if struct.unpack_from("<H", a, i)[0] != struct.unpack_from("<H", b, i)[0]]
            n = len(d)
            kind = "identical" if n == 0 else "1-4-hw" if n <= 4 else "5-12-hw" if n <= 12 else "many"
            delta = span.get(sym, sz) - sz

            if delta:
                kind += "/span%+d" % delta
            detail = ";".join("+%03X:%04X/%04X" % t for t in d[:8])
        buckets[kind] += 1
        rows.append((unit, sym, tags, kind, n, detail))

    if args.unit or args.kind:
        for r in rows:
            if args.unit and r[0] != args.unit:
                continue
            if args.kind and not r[3].startswith(args.kind):
                continue
            print("%-18s %-26s %-22s %-16s %s" % (r[0], r[1], r[2], r[3], r[5]))
        return
    print("=== %s: %d whole-function guards with a C body ===" % (args.version, sum(buckets.values())))

    for k, v in buckets.most_common():
        print("  %-18s %d" % (k, v))


if __name__ == "__main__":
    main()
