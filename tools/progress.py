#!/usr/bin/env python3
"""Print a human-readable summary of an objdiff progress report.

Code and data are told apart by input section name, so what the ROM's data
region is declared as in asm/<ver>/data.s decides which column its 32 MB lands
in. Code, Asm and Vendored are path buckets over src/, asm/ and the linked
archive members, not sections.
"""

import argparse
import json
import os
import sys
from pathlib import Path


def to_int(data, key):
    v = data.get(key, 0)
    if v is None:
        return 0
    return int(v) if isinstance(v, str) and v.isdigit() else v


def pct(matched, total):
    return 100.0 * matched / total if total else 0.0


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
            m = u["measures"]
            total += 1
            size = to_int(m, "total_code") + to_int(m, "total_data")
            matched = to_int(m, "matched_code") + to_int(m, "matched_data")
            if size and matched == size:
                done += 1
        return done, total

    summary_path = os.getenv("GITHUB_STEP_SUMMARY")
    summary = open(summary_path, "a", encoding="utf-8") if summary_path else None
    if summary:
        summary.write("```\n")

    def emit(s):
        print(s)
        if summary:
            summary.write(s + "\n")

    def block(name, m, prefix):
        mc, tc = to_int(m, "matched_code"), to_int(m, "total_code")
        md, td = to_int(m, "matched_data"), to_int(m, "total_data")
        mf, tf = m.get("matched_functions", 0), m.get("total_functions", 0)
        done, total = files(prefix)
        emit(f"  {name}: {pct(mc + md, tc + td):.2f}% matched, "
             f"{pct(done, total):.2f}% linked ({done} / {total} files)")
        emit(f"    Code: {mc:,} / {tc:,} bytes ({mf:,} / {tf:,} functions)")
        emit(f"    Data: {md:,} / {td:,} bytes ({pct(md, td):.2f}%)")

    emit("Progress:")
    block("All", report["measures"], None)
    for c in report.get("categories", []):
        block(c["name"], c["measures"], prefixes.get(c["name"]))

    if summary:
        summary.write("```\n")
        summary.close()


if __name__ == "__main__":
    main()
