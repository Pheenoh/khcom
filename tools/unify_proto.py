#!/usr/bin/env python3
import argparse
import collections
import glob
import os
import re
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
LEDGER = os.path.join(REPO, "docs", "proto_ledger.tsv")
TYPE = r"(?:const\s+)?(?:void|u8|u16|u32|s8|s16|s32|vu8|vu16|vu32|char|int|long|struct\s+\w+|[A-Z]\w+)\s*\**"
DECL = re.compile(r"^[ \t]*(" + TYPE + r")\s*([A-Za-z_]\w{2,})\s*\(([^;{)]*)\)\s*;[ \t]*$", re.M)
DEFN = re.compile(r"^(" + TYPE + r")\s*([A-Za-z_]\w{2,})\s*\(([^;{)]*)\)\s*\{[ \t]*$", re.M)


def sources():
    return sorted(glob.glob(os.path.join(REPO, "include", "*.h"))) + \
           sorted(glob.glob(os.path.join(REPO, "src", "*.c")))


def scan():
    sites = collections.defaultdict(list)
    defs = {}

    for path in sources():
        depth = 0

        for line in open(path, errors="ignore"):
            if depth == 0 and "INCLUDE_ASM" not in line:
                m = DECL.match(line)

                if m:
                    sites[m.group(2)].append(path)
                m = DEFN.match(line)

                if m and path.endswith(".c"):
                    defs.setdefault(m.group(2), (path, m.group(1).strip(), m.group(3).strip()))
            depth += line.count("{") - line.count("}")
    return sites, defs


def signatures(name):
    out = set()

    for path in sources():
        depth = 0

        for line in open(path, errors="ignore"):
            if depth == 0:
                m = DECL.match(line)

                if m and m.group(2) == name:
                    args = re.sub(r"\b([A-Za-z_]\w*\s*\**)\s*[a-z_]\w*\s*(?=,|$)", r"\1", m.group(3))
                    out.add((re.sub(r"\s+", "", m.group(1)), re.sub(r"\s+", "", args)))
            depth += line.count("{") - line.count("}")
    return out


def type_headers():
    owner = {}

    for path in glob.glob(os.path.join(REPO, "include", "*.h")):
        body = open(path, errors="ignore").read()

        for m in re.finditer(r"\}\s*([A-Z]\w+)\s*;", body):
            owner.setdefault(m.group(1), os.path.basename(path))
    return owner


def needed_types(canon, owner):
    return {t for t in re.findall(r"\b([A-Z]\w+)\b", canon) if t in owner}


def rewrite(name, canon):
    touched = []

    for path in sources():
        s = open(path).read()
        out = []
        depth = 0
        hit = False

        for line in s.split("\n"):
            m = DECL.match(line + "\n") if depth == 0 else None

            if m and m.group(2) == name and line.strip() != canon:
                indent = line[:len(line) - len(line.lstrip())]
                out.append(indent + canon)
                hit = True
            else:
                out.append(line)
            depth += line.count("{") - line.count("}")

        if hit:
            open(path, "w").write("\n".join(out))
            touched.append(path)
    return touched


def ensure_types(paths, canon, owner):
    for t in needed_types(canon, owner):
        h = owner[t]

        for path in paths:
            if os.path.basename(path) == h:
                continue
            s = open(path).read()

            if re.search(r"\}\s*" + t + r"\s*;", s) or '"%s"' % h in s:
                continue

            if path.endswith(".h"):
                s = s.replace('#include "types.h"', '#include "types.h"\n#include "%s"' % h, 1)
            else:
                s = re.sub(r'(#include [^\n]*\n)', r'\1#include "%s"\n' % h, s, count=1)
            open(path, "w").write(s)


def build():
    r = subprocess.run(["ninja"], cwd=REPO, capture_output=True, text=True)
    out = r.stdout + r.stderr

    if r.returncode == 0:
        return "unified", ""
    if "com_us.gba: FAILED" in out:
        rom = os.path.join(REPO, "roms", "B8CE.gba")
        new = os.path.join(REPO, "build", "us", "com_us.gba")
        d = 0

        if os.path.exists(new):
            a, b = open(rom, "rb").read(), open(new, "rb").read()
            d = sum(1 for i in range(min(len(a), len(b))) if a[i] != b[i]) + abs(len(a) - len(b))
        return "load-bearing", "%d bytes differ" % d
    hard = [l for l in out.split("\n")
            if re.search(r"conflicting types|syntax error|undeclared|parse error|undefined reference|error:", l)]
    return "no-compile", (hard or [""])[0].strip()[:130]


def revert():
    subprocess.run(["git", "checkout", "--", "include", "src"], cwd=REPO, capture_output=True)


def record(name, sites, variants, verdict, note):
    new = not os.path.exists(LEDGER)
    os.makedirs(os.path.dirname(LEDGER), exist_ok=True)

    with open(LEDGER, "a") as f:
        if new:
            f.write("symbol\tsites\tvariants\tverdict\tnote\n")
        f.write("%s\t%d\t%d\t%s\t%s\n" % (name, sites, variants, verdict, note))


def done():
    if not os.path.exists(LEDGER):
        return set()
    keep = set()

    for l in open(LEDGER):
        f = l.rstrip("\n").split("\t")

        if len(f) > 3 and f[3] in ("unified", "load-bearing", "already-uniform"):
            keep.add(f[0])
    return keep


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("symbols", nargs="*")
    ap.add_argument("--pick", type=int, default=0)
    ap.add_argument("--kind", default="voidp")
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--header")
    ap.add_argument("--apply", action="store_true")
    ap.add_argument("--commit", action="store_true")
    args = ap.parse_args()
    sites, defs = scan()
    owner = type_headers()
    seen = done()
    cand = []

    for name, paths in sites.items():
        if len(paths) < 2 or name in seen or name not in defs:
            continue
        sg = signatures(name)

        if len(sg) < 2:
            continue
        argsets = {a for _, a in sg}

        if args.kind == "voidp" and not (any("void*" in a for a in argsets) and any("void*" not in a for a in argsets)):
            continue
        cand.append((len(paths), name))
    cand.sort(reverse=True)

    if args.list:
        for n, name in cand[:40]:
            print("%-28s %3d sites" % (name, n))
        return
    if args.header:
        h = os.path.join(REPO, "include", args.header)
        decls = {m.group(2) for m in DECL.finditer(open(h).read())}
        names = sorted(n for n in decls if n in defs and len(sites[n]) > 1)
        print("%s declares %d functions, %d duplicated elsewhere" % (args.header, len(decls), len(names)))

        if subprocess.run(["git", "diff", "--quiet"], cwd=REPO).returncode != 0:
            sys.exit("working tree is dirty")
        touched = set()

        for n in names:
            _p, ret, params = defs[n]
            c = "%s %s(%s);" % (ret, n, params)
            t = rewrite(n, c)
            touched.update(t)

            if t:
                ensure_types(t, c, owner)

        for path in sources():
            if os.path.basename(path) == args.header:
                continue
            src = open(path).read()
            o = src

            for n in names:
                src = re.sub(r"^[ \t]*(?:const\s+)?[A-Za-z_]\w*\s*\**\s*" + n + r"\s*\([^;{)]*\)\s*;[ \t]*\n", "", src, flags=re.M)

            if src != o:
                open(path, "w").write(src)
                touched.add(path)

        for path in sorted(touched):
            if os.path.basename(path) == args.header:
                continue
            src = open(path).read()

            if '"%s"' % args.header not in src:
                if path.endswith(".h"):
                    src = src.replace('#include "types.h"', '#include "types.h"\n#include "%s"' % args.header, 1)
                else:
                    src = re.sub(r'(#include [^\n]*\n)', r'\1#include "%s"\n' % args.header, src, count=1)
                open(path, "w").write(src)
        verdict, note = build()

        if not (args.apply and verdict == "unified"):
            revert()
        record("HEADER:" + args.header, len(touched), len(names), verdict, note)
        print("%-28s %d files -> %-13s %s" % (args.header, len(touched), verdict, note))
        return
    names = args.symbols or [n for _, n in cand[:args.pick]]

    if subprocess.run(["git", "diff", "--quiet"], cwd=REPO).returncode != 0:
        sys.exit("working tree is dirty; commit or stash first")

    for name in names:
        path, ret, params = defs[name]
        canon = "%s %s(%s);" % (ret, name, params)
        n = len(sites[name])
        v = len(signatures(name))
        touched = rewrite(name, canon)

        if touched:
            ensure_types(touched, canon, owner)

        if not touched:
            record(name, n, v, "already-uniform", "")
            print("%-28s already uniform" % name)
            continue
        verdict, note = build()

        if not (args.apply and verdict == "unified"):
            revert()
        elif args.commit:
            subprocess.run(["git", "add", "-u", "include", "src"], cwd=REPO, capture_output=True)
            subprocess.run(["git", "commit", "-q", "-m", "Unify the %s prototype" % name], cwd=REPO, capture_output=True)
        record(name, n, v, verdict, note)
        print("%-28s %2d sites %d variants -> %-13s %s" % (name, n, v, verdict, note))


if __name__ == "__main__":
    main()
