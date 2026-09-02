#!/usr/bin/env python3
"""Make the objdiff progress report truthful before it is published.

An empty dimension is reported as 100 percent by the report generator, and
decomp.dev consumes that verbatim, so a project that measures no data at all
publishes "data: 100% matched". Drop the percentages for any dimension whose
total is zero, so the dimension reads as unmeasured rather than finished, then
recompute the category and project rollups from byte and function weights.

Also derive the completion measures decomp.dev renders as linking progress: a
unit is complete when every byte it owns is matched.
"""

import argparse
import json
from pathlib import Path

# Regions that can never be defined in a translation unit, header, or hand
# written asm: compressed art and audio, FMV, and 0xFF filler. They are real
# cartridge bytes and the build needs them, but they are not decompilation work,
# so counting them as unmatched data would report 31 MB as outstanding forever.
EXCLUDED_CATEGORIES = {"assets", "padding"}

DIMENSIONS = {
    "code": ("total_code", ("matched_code_percent", "complete_code_percent", "fuzzy_match_percent")),
    "data": ("total_data", ("matched_data_percent", "complete_data_percent")),
    "functions": ("total_functions", ("matched_functions_percent",)),
}


def amount(measures, key):
    try:
        return int(measures.get(key, 0) or 0)
    except (TypeError, ValueError):
        return 0


def is_complete(measures):
    owned = amount(measures, "total_code") + amount(measures, "total_data")
    if not owned:
        return False
    matched = amount(measures, "matched_code") + amount(measures, "matched_data")
    return matched == owned


def normalize_unit(unit):
    measures = unit.setdefault("measures", {})
    complete = is_complete(measures)
    unit.setdefault("metadata", {})["complete"] = complete

    for total_key, percent_keys in DIMENSIONS.values():
        total = amount(measures, total_key)
        for percent_key in percent_keys:
            if not total:
                measures.pop(percent_key, None)
            elif percent_key.startswith("complete_"):
                measures[percent_key] = 100.0 if complete else 0.0
            else:
                measures.setdefault(percent_key, 0.0)


def aggregate(units):
    result = {"total_units": len(units)}
    complete_units = [u for u in units if u.get("metadata", {}).get("complete")]
    result["complete_units"] = len(complete_units)

    for total_key, percent_keys in DIMENSIONS.values():
        total = sum(amount(u["measures"], total_key) for u in units)
        if not total:
            continue
        result[total_key] = total if total_key == "total_functions" else str(total)
        for percent_key in percent_keys:
            weighted = sum(
                amount(u["measures"], total_key) * float(u["measures"].get(percent_key, 0.0))
                for u in units
            )
            result[percent_key] = weighted / total

    matched_code = sum(amount(u["measures"], "matched_code") for u in units)
    matched_functions = sum(amount(u["measures"], "matched_functions") for u in units)
    if matched_code:
        result["matched_code"] = str(matched_code)
    if matched_functions:
        result["matched_functions"] = matched_functions

    complete_code = sum(amount(u["measures"], "total_code") for u in complete_units)
    if complete_code:
        result["complete_code"] = str(complete_code)
    return result


def drop_excluded(report):
    kept = []
    for unit in report.get("units", []):
        cats = set(unit.get("metadata", {}).get("progress_categories") or [])
        if cats & EXCLUDED_CATEGORIES:
            continue
        kept.append(unit)
    report["units"] = kept
    report["categories"] = [
        c for c in report.get("categories", []) if c.get("id") not in EXCLUDED_CATEGORIES
    ]


def normalize(report):
    drop_excluded(report)
    units = report["units"]
    for unit in units:
        normalize_unit(unit)

    by_category = {}
    for unit in units:
        for category in unit.get("metadata", {}).get("progress_categories", []):
            by_category.setdefault(category, []).append(unit)
    for category in report.get("categories", []):
        category["measures"] = aggregate(by_category.get(category["id"], []))
    report["measures"] = aggregate(units)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("report", type=Path)
    args = parser.parse_args()
    report = json.loads(args.report.read_text())
    normalize(report)
    args.report.write_text(json.dumps(report, indent=2) + "\n")


if __name__ == "__main__":
    main()
