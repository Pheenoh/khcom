#!/usr/bin/env python3
import argparse
import glob
import os
import re
import subprocess
import sys
import time

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
MAP = os.path.join(REPO, "build", "us", "com_us.map")
LEDGER = os.path.join(REPO, "permuter", "ledger.tsv")
PERMUTER = os.path.join(REPO, "tools", "decomp-permuter", "permuter.py")
PYTHON = os.path.join(REPO, ".venv", "bin", "python3")

FUNC_START = re.compile(r"^[A-Za-z_][\w\s\*]*\**\s*\w+\s*\([^;]*\)\s*\{\s*$")
GLOBAL_DEF = re.compile(r"^(?!extern\b|typedef\b|static\b|#)[A-Za-z_][\w\s\*]*?\s+\**(g[A-Z]\w*)(\[[^;]*\])*\s*;\s*$")
MAP_LINE = re.compile(r"^ +(0x0[89][0-9a-f]{6}) +([A-Za-z_]\w*)$")


def parked_functions(units):
    found = []

    for path in sorted(glob.glob(os.path.join(REPO, "src", "*.c"))):
        unit = os.path.basename(path)[:-2]

        if units and unit not in units:
            continue
        lines = open(path).read().split("\n")
        i = 0

        while i < len(lines):
            if lines[i].strip() != "#ifdef NON_MATCHING":
                i += 1
                continue
            depth = 0
            body = []
            j = i + 1

            while j < len(lines):
                s = lines[j].strip()

                if s.startswith("#if"):
                    depth += 1
                elif s == "#endif" and depth:
                    depth -= 1
                elif s == "#else" and depth == 0:
                    break
                body.append(lines[j])
                j += 1
            k = j
            sym = None

            while k < len(lines) and lines[k].strip() != "#endif":
                m = re.search(r'INCLUDE_ASM\("[^"/]+/(\w+)\.s"\)', lines[k])

                if m:
                    sym = m.group(1)
                k += 1

            if sym:
                found.append((unit, sym, "\n".join(body).strip("\n"), lines[:i]))
            i = k + 1
    return found


def text_symbols():
    syms = []

    for line in open(MAP):
        m = MAP_LINE.match(line.rstrip())

        if m:
            syms.append((int(m.group(1), 16), m.group(2)))
    syms.sort()
    return syms


def address_range(syms, sym):
    for n, (addr, name) in enumerate(syms):
        if name == sym:
            for addr2, _ in syms[n + 1:]:
                if addr2 > addr:
                    return addr, addr2
    return None, None


def preamble(lines):
    out = []

    for line in lines:
        if FUNC_START.match(line) or "INCLUDE_ASM(" in line:
            break
        m = GLOBAL_DEF.match(line)

        if m:
            line = "extern " + line.lstrip()
        out.append(line)

    while out and out[-1].strip() == "":
        out.pop()
    return "\n".join(out)


def run(cmd, **kw):
    return subprocess.run(cmd, cwd=REPO, capture_output=True, text=True, **kw)


def match_size(cand, sym, start, end, tmp):
    r = run(["tools/match.sh", cand, sym, "0x%08X" % start, "0x%08X" % end], env={**os.environ, "MATCH_TMP": tmp})
    out = r.stdout + r.stderr

    if r.returncode != 0 and "EXACT MATCH" not in out:
        return None, out.strip().split("\n")[-1][:200]
    if "EXACT MATCH" in out:
        return 0, "EXACT MATCH"
    m = re.search(r"diff \(rom (\d+)B, new (\d+)B\)", out)
    return (int(m.group(1)), int(m.group(2))) if m else (None, "unparsed"), out.split("\n")[0]


def best_output(d):
    best = None

    for sub in glob.glob(os.path.join(d, "output-*-*")):
        try:
            score = int(open(os.path.join(sub, "score.txt")).read().strip())
        except (OSError, ValueError):
            continue

        if best is None or score < best[0]:
            best = (score, sub)
    return best


def ledger(row):
    new = not os.path.exists(LEDGER)
    os.makedirs(os.path.dirname(LEDGER), exist_ok=True)

    with open(LEDGER, "a") as f:
        if new:
            f.write("date\tunit\tsymbol\tstart\tsize\tbase\tbest\tseconds\tstatus\tbest_source\n")
        f.write("\t".join(str(x) for x in row) + "\n")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("symbols", nargs="*")
    ap.add_argument("--unit", action="append", default=[])
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--budget", type=int, default=600)
    ap.add_argument("-j", type=int, default=8)
    ap.add_argument("--keep", action="store_true")
    args = ap.parse_args()

    if not os.path.exists(MAP):
        sys.exit("no build/us/com_us.map: run configure.py && ninja first")
    syms = text_symbols()
    parked = parked_functions(set(args.unit))

    if args.symbols:
        parked = [p for p in parked if p[1] in args.symbols]

    if args.list:
        for unit, sym, body, _ in parked:
            start, end = address_range(syms, sym)
            size = end - start if start else 0
            print("%-18s %-28s %s %5d %4d lines" % (unit, sym, "0x%08X" % start if start else "?", size, body.count("\n") + 1))
        return

    for unit, sym, body, head in parked:
        start, end = address_range(syms, sym)
        t0 = time.time()

        if start is None:
            print("%-28s NOT IN MAP" % sym)
            ledger([time.strftime("%Y-%m-%d"), unit, sym, "?", 0, "?", "?", 0, "not-in-map", ""])
            continue
        d = os.path.join(REPO, "permuter", sym)
        os.makedirs(d, exist_ok=True)
        cand = os.path.join(d, "cand.c")

        if not args.keep:
            for sub in glob.glob(os.path.join(d, "output-*-*")):
                subprocess.run(["rm", "-rf", sub])

        with open(cand, "w") as f:
            f.write(preamble(head) + "\n\n" + body + "\n")
        size, note = match_size(cand, sym, start, end, os.path.join(d, "mt"))

        if size is None:
            print("%-28s SETUP FAILED: %s" % (sym, note))
            ledger([time.strftime("%Y-%m-%d"), unit, sym, "0x%08X" % start, end - start, "?", "?", 0, "setup-failed", note])
            continue

        if size == 0:
            print("%-28s ALREADY MATCHES standalone; land it" % sym)
            ledger([time.strftime("%Y-%m-%d"), unit, sym, "0x%08X" % start, end - start, 0, 0, 0, "matches", cand])
            continue
        r = run(["tools/permuter_setup.sh", cand, sym, "0x%08X" % start, "0x%08X" % end])

        if r.returncode != 0:
            print("%-28s permuter_setup failed: %s" % (sym, (r.stderr or r.stdout).strip().split("\n")[-1][:200]))
            ledger([time.strftime("%Y-%m-%d"), unit, sym, "0x%08X" % start, end - start, "?", "?", 0, "setup-failed", "permuter_setup"])
            continue
        log = open(os.path.join(d, "run.log"), "w")
        p = subprocess.run(["timeout", str(args.budget), PYTHON, PERMUTER, d, "-j", str(args.j), "--stop-on-zero", "--better-only"],
                           cwd=REPO, stdout=log, stderr=subprocess.STDOUT, text=True)
        log.close()
        text = open(os.path.join(d, "run.log")).read()
        m = re.search(r"base score = (\d+)", text)
        base = int(m.group(1)) if m else "?"
        best = best_output(d)
        elapsed = int(time.time() - t0)

        if best and best[0] == 0:
            status = "zero"
        elif p.returncode == 124:
            status = "timeout"
        elif p.returncode != 0:
            status = "error"
        else:
            status = "done"
        best_score = best[0] if best else base
        best_src = os.path.join(best[1], "source.c") if best else ""
        print("%-28s rom %4dB new %4dB  base %-5s best %-5s %4ds  %s" % (sym, size[0], size[1], base, best_score, elapsed, status))
        ledger([time.strftime("%Y-%m-%d"), unit, sym, "0x%08X" % start, end - start, base, best_score, elapsed, status, best_src])


if __name__ == "__main__":
    main()
