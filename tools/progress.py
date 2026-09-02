#!/usr/bin/env python3
"""Print a human-readable summary of an objdiff progress report.

Units are bucketed by the progress categories the report already carries, so
this stays in step with decomp.yaml rather than duplicating its path prefixes.

"Linked" is the byte-weighted completion decomp.dev publishes as
complete_code_percent: the share of code living in units where every byte
matches. It is read from the report rather than recomputed, so this output and
the published figure cannot drift apart.
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

    summary_path = os.getenv("GITHUB_STEP_SUMMARY")
    summary = open(summary_path, "a", encoding="utf-8") if summary_path else None
    if summary:
        summary.write("```\n")

    def emit(s):
        print(s)
        if summary:
            summary.write(s + "\n")

    def block(name, m):
        mc, tc = to_int(m, "matched_code"), to_int(m, "total_code")
        td = to_int(m, "total_data")
        # Only a percentage is published for data, so recover the byte count.
        md = to_int(m, "matched_data") or round(td * float(m.get("matched_data_percent", 0.0)) / 100.0)
        mf, tf = m.get("matched_functions", 0), m.get("total_functions", 0)
        cc = to_int(m, "complete_code")
        cu, tu = to_int(m, "complete_units"), to_int(m, "total_units")
        # Code only, so this headline is the same number decomp.dev publishes as
        # matched_code_percent. Data has its own line.
        emit(f"  {name}: {pct(mc, tc):.2f}% matched, "
             f"{pct(cc, tc):.2f}% linked ({cu} / {tu} files)")
        emit(f"    Code: {mc} / {tc} bytes ({mf} / {tf} functions)")
        if td:
            emit(f"    Data: {md} / {td} bytes ({pct(md, td):.2f}%)")

    emit("Progress:")
    block("All", report["measures"])
    for c in report.get("categories", []):
        block(c["name"], c["measures"])

    if summary:
        summary.write("```\n")
        summary.close()


if __name__ == "__main__":
    main()
