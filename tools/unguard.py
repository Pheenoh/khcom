#!/usr/bin/env python3
import argparse
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def block(src, unit, sym):
    inc = 'INCLUDE_ASM("%s/%s.s");' % (unit, sym)
    i = src.find(inc)

    if i < 0:
        return None
    j = src.find("\n", i) + 1

    if not src[j:].startswith("#endif\n"):
        return None
    end = j + len("#endif\n")
    k = src.rfind("\n#else\n", 0, i)

    if k < 0:
        return None
    open_at = -1

    for m in re.finditer(r"^#if(n?)def (VERSION_\w+)\n", src[:k + 1], re.M):
        open_at = m.start()
        neg, tag = m.group(1) == "n", m.group(2)
    if open_at < 0:
        return None
    body = src[src.find("\n", open_at) + 1:k + 1]
    return open_at, end, body, neg, tag


def apply(unit, sym, to):
    path = os.path.join(REPO, "src", unit + ".c")
    src = open(path).read()
    b = block(src, unit, sym)

    if b is None:
        return "no-block"
    start, end, body, neg, tag = b

    if to is None:
        new = body.lstrip("\n")
    else:
        new = "#ifndef %s\n%s#else\nINCLUDE_ASM(\"%s/%s.s\");\n#endif\n" % (to, body, unit, sym)
    open(path, "w").write(src[:start] + new + src[end:])
    return "ok"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("targets", nargs="+", metavar="unit:symbol")
    ap.add_argument("--to", help="narrow the guard to this tag instead of removing it")
    args = ap.parse_args()

    for t in args.targets:
        unit, sym = t.split(":")
        print("%-40s %s" % (t, apply(unit, sym, args.to)))


if __name__ == "__main__":
    main()
