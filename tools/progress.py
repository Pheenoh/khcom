#!/usr/bin/env python3
"""Print a human-readable summary of an objdiff progress report.

Code, Asm and Vendored are path buckets, not sections: src/, asm/ and the
linked archive members. Data is the real one, summed from every unit's data
sections, and stays near zero until globals are defined in C rather than
declared extern at an address from config/<ver>/symbols.txt.
"""

import argparse
import json
import os
import sys
from pathlib import Path


def to_int(data, key):
    v = data.get(key, 0)
    return int(v) if isinstance(v, str) and v.isdigit() else v


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("report", type=Path)
    args = parser.parse_args()

    if not args.report.is_file():
        sys.exit(f"Report file {args.report} does not exist")
    report = json.loads(args.report.read_text())

    prefixes = {"Code": "src/", "Asm": "asm/", "Vendored": "tools/"}

    def files(prefix):
        done = total = 0
        for u in report.get("units", []):
            if prefix and not u["name"].startswith(prefix):
                continue
            total += 1
            tc = to_int(u["measures"], "total_code")
            if tc and to_int(u["measures"], "matched_code") == tc:
                done += 1
        return done, total

    def pct(matched, total):
        return 100.0 * matched / total if total else 0.0

    rows = []
    for c in report.get("categories", []):
        m = c["measures"]
        done, total = files(prefixes.get(c["name"]))
        mc, tc = to_int(m, "matched_code"), to_int(m, "total_code")
        rows.append((c["name"], pct(mc, tc), mc, tc,
                     m.get("matched_functions", 0), m.get("total_functions", 0),
                     done, total))
    m = report["measures"]
    done, total = files(None)
    mc, tc = to_int(m, "matched_code"), to_int(m, "total_code")
    total_row = ("All", pct(mc, tc), mc, tc,
                 m.get("matched_functions", 0), m.get("total_functions", 0),
                 done, total)
    md, td = to_int(m, "matched_data"), to_int(m, "total_data")
    data_row = (md, td, pct(md, td))

    summary_path = os.getenv("GITHUB_STEP_SUMMARY")
    summary = open(summary_path, "a", encoding="utf-8") if summary_path else None
    if summary:
        summary.write("```\n")

    def emit(s):
        print(s)
        if summary:
            summary.write(s + "\n")

    def line(row):
        name, pct, mc, tc, mf, tf, fd, ft = row
        return (f"  {name:<10} {pct:8.4f}%  {mc:>9,} / {tc:<11,} bytes"
                f"  {mf:>5,} / {tf:<6,} funcs  {fd:>3} / {ft:<3} files")

    emit("Progress:")
    for row in rows:
        emit(line(row))
    emit("  " + "-" * 86)
    emit(line(total_row))
    md, td, dpct = data_row
    emit(f"  {'Data':<10} {dpct:8.4f}%  {md:>9,} / {td:<11,} bytes")

    if summary:
        summary.write("```\n")
        summary.close()


if __name__ == "__main__":
    main()
