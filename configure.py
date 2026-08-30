#!/usr/bin/env python3

###
# Generates build files for the project.
#
# Usage:
#   python3 configure.py
#   ninja
#
# Append --help to see available options.
###

import argparse
import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent / "tools"))
import ninja_syntax

# Game versions
DEFAULT_VERSION = "us"
VERSIONS = {
    # version: (game code, sha1)
    "us": ("B8CE", "10729bd884f8fdca7a310b6d606c52e46657aa48"),
    "jp": ("B8CJ", "59ec0a0a4ccd1e6acb3bbd7bfb21d63988958cfa"),
    "eu": ("B8CP", "8db73586cdb11b3795907edebf43228dbcd3e6b2"),
}

parser = argparse.ArgumentParser()
parser.add_argument(
    "--version",
    choices=VERSIONS.keys(),
    default=DEFAULT_VERSION,
    help="version to build (default: %(default)s)",
)
parser.add_argument(
    "--binutils-prefix",
    default="arm-none-eabi-",
    help="binutils tool prefix (default: %(default)s)",
)
args = parser.parse_args()

version = args.version
code, sha1 = VERSIONS[version]
prefix = args.binutils_prefix

baserom = f"roms/{code}.gba"
build_dir = f"build/{version}"
name = f"com_{version}"
elf = f"{build_dir}/{name}.elf"
rom = f"{build_dir}/{name}.gba"
mapfile = f"{build_dir}/{name}.map"
ldscript = f"{build_dir}/ldscript.ld"

if not Path(baserom).exists():
    print(f"warning: base ROM {baserom} not found; the build will fail without it")

# Units are linked in the order listed in config/<version>/units.txt
units_file = Path(f"config/{version}/units.txt")
asm_srcs = [
    Path(f"asm/{version}") / line.strip()
    for line in units_file.read_text().splitlines()
    if line.strip() and not line.startswith("#")
]
for src in asm_srcs:
    if not src.exists():
        sys.exit(f"error: unit {src} listed in {units_file} does not exist")

# Generate the linker script
objs_in_order = [f"{build_dir}/asm/{src.stem}.o" for src in asm_srcs]
Path(build_dir).mkdir(parents=True, exist_ok=True)
with open(ldscript, "w") as f:
    f.write("ENTRY(_start);\n\nSECTIONS\n{\n    . = 0x8000000;\n\n    .text :\n    {\n")
    for obj in objs_in_order:
        f.write(f"        {obj}(.text);\n")
    f.write("    }\n\n    /DISCARD/ : { *(*); }\n}\n")

out = Path("build.ninja")
with out.open("w") as f:
    n = ninja_syntax.Writer(f)

    n.variable("ninja_required_version", "1.3")
    n.variable("as", f"{prefix}as")
    n.variable("ld", f"{prefix}ld")
    n.variable("objcopy", f"{prefix}objcopy")
    n.variable("asflags", "-mcpu=arm7tdmi -march=armv4t -mthumb-interwork -I include")
    n.newline()

    n.rule(
        "as",
        command="$as $asflags -o $out $in",
        description="AS $out",
    )
    n.rule(
        "ld",
        command="$ld -T $ldscript -Map $map -o $out $in",
        description="LD $out",
    )
    n.rule(
        "rom",
        command="$objcopy -O binary $in $out",
        description="ROM $out",
    )
    n.rule(
        "check",
        command=f'echo "{sha1}  {rom}" | sha1sum -c && touch $out',
        description=f"CHECK {rom}",
    )
    n.newline()

    objs = []
    for src in asm_srcs:
        obj = f"{build_dir}/asm/{src.stem}.o"
        n.build(obj, "as", str(src), implicit=[baserom])
        objs.append(obj)
    n.newline()

    n.build(
        elf,
        "ld",
        objs,
        implicit=[ldscript],
        variables={"ldscript": ldscript, "map": mapfile},
    )
    n.build(rom, "rom", elf)
    n.build(f"{build_dir}/ok", "check", rom)
    n.newline()

    n.build("all", "phony", f"{build_dir}/ok")
    n.default("all")

# objdiff config
import json

objdiff_config = {
    "min_version": "2.0.0",
    "custom_make": "ninja",
    "build_target": False,
    "build_base": True,
    "watch_patterns": ["*.c", "*.h", "*.s", "*.inc"],
    "units": [],
}
Path("objdiff.json").write_text(json.dumps(objdiff_config, indent=2) + "\n")

print(f"configured for {version} ({code}); run: ninja")
