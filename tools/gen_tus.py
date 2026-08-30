#!/usr/bin/env python3
"""Convert luvdis module .s files into C translation units + per-function asm.

For each module (e.g. asm/us/btl.s) this produces:
  asm/us/nonmatchings/btl/<func>.s   one file per function (or data chunk)
  src/btl.c                          INCLUDE_ASM() per file, in address order

The per-function files are self-contained (luvdis macros expanded) and
switch to unified syntax internally, restoring divided syntax for the
compiler-generated code around them.

Functions decompiled to C later replace their INCLUDE_ASM line; the asm
file is then deleted, which is how progress is measured.
"""

import argparse
import re
from pathlib import Path

START_RE = re.compile(
    r"\t(thumb_func_start|arm_func_start|non_word_aligned_thumb_func_start) (\S+)"
)
LABEL_RE = re.compile(r"^(_[0-9A-Fa-f]{8}):")

EXPAND = {
    "thumb_func_start": "\t.align 2, 0\n\t.global {0}\n\t.thumb\n\t.thumb_func\n\t.type {0}, %function\n",
    "non_word_aligned_thumb_func_start": "\t.global {0}\n\t.thumb\n\t.thumb_func\n\t.type {0}, %function\n",
    "arm_func_start": "\t.align 2, 0\n\t.global {0}\n\t.arm\n\t.type {0}, %function\n",
}

HEADER = ".syntax unified\n"
FOOTER = ".syntax divided\n"


def split_module(path: Path, out_dir: Path):
    """Split one module into per-function files. Returns ordered file names."""
    lines = path.read_text().splitlines(keepends=True)
    # skip the embedded macro block
    for i, line in enumerate(lines):
        if line.startswith("@ End embedded Luvdis macros"):
            body = lines[i + 1:]
            break
    else:
        raise SystemExit(f"{path}: no luvdis macro block")

    chunks = []  # (name, [lines])
    current_name = None
    current = []
    data_count = 0

    def flush():
        nonlocal current, current_name, data_count
        content = [l for l in current if l.strip()]
        if not content:
            current = []
            return
        if current_name is None:
            # data chunk: name after its first label if present
            m = next((LABEL_RE.match(l) for l in content if LABEL_RE.match(l)), None)
            if m:
                name = m.group(1)
            else:
                data_count += 1
                name = f"{path.stem}_data_{data_count}"
        else:
            name = current_name
        chunks.append((name, current))
        current = []
        current_name = None

    for line in body:
        m = START_RE.match(line)
        if m:
            flush()
            kind, name = m.groups()
            current_name = name
            current.append(EXPAND[kind].format(name))
        else:
            current.append(line)
    flush()

    out_dir.mkdir(parents=True, exist_ok=True)
    names = []
    for name, content in chunks:
        (out_dir / f"{name}.s").write_text(HEADER + "".join(content) + FOOTER)
        names.append(name)
    return names


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("modules", nargs="+", help="module .s files to convert")
    parser.add_argument("--asm-root", default="asm/us/nonmatchings")
    parser.add_argument("--src-root", default="src")
    parser.add_argument("--keep", action="store_true",
                        help="keep the original module file")
    args = parser.parse_args()

    Path(args.src_root).mkdir(exist_ok=True)
    for mod in args.modules:
        mod = Path(mod)
        tu = mod.stem
        names = split_module(mod, Path(args.asm_root) / tu)
        with open(Path(args.src_root) / f"{tu}.c", "w") as f:
            f.write('#include "macros.h"\n\n')
            for name in names:
                f.write(f'INCLUDE_ASM("{tu}/{name}.s");\n')
        if not args.keep:
            mod.unlink()
        print(f"{tu}: {len(names)} chunks")


if __name__ == "__main__":
    main()
