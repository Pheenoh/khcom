#!/usr/bin/env python3
"""Print a human-readable summary of an objdiff progress report."""

import argparse
import json
import os
import sys
from pathlib import Path


def convert_numbers(data):
    for key, value in data.items():
        if isinstance(value, str) and value.isdigit():
            data[key] = int(value)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("report", type=Path)
    args = parser.parse_args()

    if not args.report.is_file():
        sys.exit(f"Report file {args.report} does not exist")
    report = json.loads(args.report.read_text())

    convert_numbers(report["measures"])
    for category in report.get("categories", []):
        convert_numbers(category["measures"])

    summary_path = os.getenv("GITHUB_STEP_SUMMARY")
    summary = open(summary_path, "a", encoding="utf-8") if summary_path else None
    if summary:
        summary.write("```\n")

    def emit(s):
        print(s)
        if summary:
            summary.write(s + "\n")

    def unit_counts(prefixes):
        total = complete = 0
        for u in report.get("units", []):
            if prefixes is not None and not any(u["name"].startswith(x) for x in prefixes):
                continue
            um = dict(u["measures"])
            convert_numbers(um)
            total += 1
            if um.get("total_code", 0) and um.get("matched_code", 0) == um["total_code"]:
                complete += 1
        return complete, total

    def print_category(name, m, prefixes=None):
        total_code = m.get("total_code", 0)
        matched_code = m.get("matched_code", 0)
        complete_units, total_units = unit_counts(prefixes)
        emit(
            f"  {name}: {m.get('matched_code_percent', 0):.4f}% matched"
            f" ({complete_units} / {total_units} files complete)"
        )
        emit(
            f"    Code: {matched_code} / {total_code} bytes"
            f" ({m.get('matched_functions', 0)} / {m.get('total_functions', 0)} functions)"
        )
        if m.get("total_data", 0):
            emit(
                f"    Data: {m.get('matched_data', 0)} / {m['total_data']} bytes"
                f" ({m.get('matched_data_percent', 0):.4f}%)"
            )

    emit("Progress:")
    print_category("All", report["measures"])
    prefixes = {"Code": ["src/"], "Assembly": ["asm/"], "tools": ["tools/"]}
    for category in report.get("categories", []):
        print_category(category["name"], category["measures"],
                       prefixes.get(category["name"]))

    if summary:
        summary.write("```\n")
        summary.close()


if __name__ == "__main__":
    main()
