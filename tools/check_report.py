#!/usr/bin/env python3
"""Refuse to publish a progress report that is internally inconsistent.

decomp.dev consumes the uploaded report verbatim, so a malformed one is
published rather than rejected. Validate the invariants that matter before the
artifact leaves CI.
"""

import argparse
import json
import sys
from pathlib import Path

PERCENTS = (
    "matched_code_percent",
    "matched_data_percent",
    "matched_functions_percent",
    "complete_code_percent",
    "complete_data_percent",
    "fuzzy_match_percent",
)
TOTAL_FOR = {
    "matched_code_percent": "total_code",
    "complete_code_percent": "total_code",
    "fuzzy_match_percent": "total_code",
    "matched_data_percent": "total_data",
    "complete_data_percent": "total_data",
    "matched_functions_percent": "total_functions",
}


def amount(measures, key):
    try:
        return int(measures.get(key, 0) or 0)
    except (TypeError, ValueError):
        return 0


def check_measures(where, measures, errors):
    for key in PERCENTS:
        if key not in measures:
            continue
        value = float(measures[key])
        if not 0.0 <= value <= 100.0:
            errors.append(f"{where}: {key} out of range ({value})")
        if not amount(measures, TOTAL_FOR[key]):
            errors.append(f"{where}: {key} present but {TOTAL_FOR[key]} is zero")

    for matched, total in (("matched_code", "total_code"),
                           ("matched_data", "total_data"),
                           ("matched_functions", "total_functions")):
        if amount(measures, matched) > amount(measures, total):
            errors.append(f"{where}: {matched} exceeds {total}")

    if amount(measures, "complete_units") > amount(measures, "total_units"):
        errors.append(f"{where}: complete_units exceeds total_units")
    if amount(measures, "complete_code") > amount(measures, "total_code"):
        errors.append(f"{where}: complete_code exceeds total_code")


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("report", type=Path)
    args = parser.parse_args()
    report = json.loads(args.report.read_text())
    errors = []

    units = report.get("units")
    if not units:
        errors.append("report has no units")
        units = []

    for unit in units:
        check_measures(f"unit {unit.get('name', '?')}", unit.get("measures", {}), errors)

    check_measures("project", report.get("measures", {}), errors)
    for category in report.get("categories", []):
        check_measures(f"category {category.get('id', '?')}", category.get("measures", {}), errors)

    project = report.get("measures", {})
    for key in ("total_code", "total_functions"):
        rolled = sum(amount(u.get("measures", {}), key) for u in units)
        if amount(project, key) != rolled:
            errors.append(f"project {key} is {amount(project, key)}, units sum to {rolled}")

    if amount(project, "total_units") != len(units):
        errors.append(f"project total_units is {amount(project, 'total_units')}, {len(units)} units present")

    if errors:
        for e in errors:
            print(f"error: {e}", file=sys.stderr)
        return 1
    print(f"report OK: {len(units)} units, "
          f"{amount(project, 'complete_units')} complete, "
          f"{amount(project, 'matched_code')}/{amount(project, 'total_code')} bytes")
    return 0


if __name__ == "__main__":
    sys.exit(main())
