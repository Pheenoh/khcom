#!/usr/bin/env python3
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def body_of(src, name):
    m = re.search(r"^[A-Za-z][^\n]*\b%s\s*\([^;\n]*\)[ \t]*\{\n.*?\n\}\n" % re.escape(name),
                  src, re.M | re.S)
    if m is None:
        raise SystemExit("no body for %s" % name)
    return m


def wrap(unit, sym, tag, old, new):
    path = os.path.join(REPO, "src", unit + ".c")
    src = open(path).read()
    m = body_of(src, sym)
    body = m.group(0)

    if body.count(old) != 1:
        raise SystemExit("%s: %d matches for %r" % (sym, body.count(old), old))
    ind = re.search(r"^([ \t]*)" + re.escape(old), body, re.M).group(1)
    rep = "#ifdef %s\n%s%s\n#else\n%s%s\n#endif\n" % (tag, ind, new, ind, old)
    open(path, "w").write(src[:m.start()] + body.replace(ind + old + "\n", rep, 1) + src[m.end():])


def main():
    for line in sys.stdin:
        line = line.rstrip("\n")

        if not line or line.startswith("#"):
            continue
        unit, sym, tag, old, new = line.split("\t")
        wrap(unit, sym, tag, old, new)
        print("%-18s %-26s %s" % (unit, sym, tag))


if __name__ == "__main__":
    main()
