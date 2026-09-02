#!/usr/bin/env python3
"""Print a human-readable summary of an objdiff progress report.

Units are bucketed by the progress categories the report already carries, so
this stays in step with decomp.yaml rather than duplicating its path prefixes.
A unit counts as linked once every byte the report attributes to it matches.

Two linking figures are shown because they answer different questions. The file
count is how many units are finished; "Linked code" is how many bytes live in
those finished units, which is the byte-weighted number decomp.dev publishes as
complete_code_percent. They diverge sharply while the large units are partial.
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
    units = report.get("units", [])

    def files(category):
        done = total = 0
        for u in units:
            if category is not None:
                cats = u.get("metadata", {}).get("progress_categories") or []
                if category not in cats:
                    continue
            m = u["measures"]
            size = to_int(m, "total_code") + to_int(m, "total_data")
            if not size:
                continue
            total += 1
            if to_int(m, "matched_code") + to_int(m, "matched_data") == size:
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

    def block(name, m, category):
        mc, tc = to_int(m, "matched_code"), to_int(m, "total_code")
        md, td = to_int(m, "matched_data"), to_int(m, "total_data")
        mf, tf = m.get("matched_functions", 0), m.get("total_functions", 0)
        done, total = files(category)
        cc = to_int(m, "complete_code")
        emit(f"  {name}: {pct(mc + md, tc + td):.2f}% matched, "
             f"{pct(done, total):.2f}% linked ({done} / {total} files)")
        emit(f"    Code: {mc:,} / {tc:,} bytes ({mf:,} / {tf:,} functions)")
        emit(f"    Linked code: {cc:,} / {tc:,} bytes ({pct(cc, tc):.2f}%)")
        if td:
            emit(f"    Data: {md:,} / {td:,} bytes ({pct(md, td):.2f}%)")

    emit("Progress:")
    block("All", report["measures"], None)
    for c in report.get("categories", []):
        block(c["name"], c["measures"], c["id"])

    if summary:
        summary.write("```\n")
        summary.close()


if __name__ == "__main__":
    main()
