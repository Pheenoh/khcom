#!/usr/bin/env python3

import argparse
import json
import re
import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent / "tools"))
import ninja_syntax

INCLUDE_ASM_RE = re.compile(r'INCLUDE_ASM\("([^"]+)"\)')

ARCHIVE_BSS = {"us": 0x020387B8, "jp": 0x02038728, "eu": 0x02038DC8}
BSS_MEMBERS = {"fp-bit.o": True, "dp-bit.o": True}

# Source units whose globals are defined in C rather than given an address in
# symbols.txt. The linker script ends in /DISCARD/, so a unit's .bss is thrown
# away unless it is placed here. IWRAM addresses are identical across versions,
# so one address serves all three.
# An int means every version places the unit at the same address; a dict gives
# a per-version address. RAM below 0x02034A08 and all of IWRAM agree across
# versions, but 0x02034A08..0x0203DF20 is shifted down by 0x90..0xA4 in JP, so
# any unit owning globals in that window needs the dict form.
UNIT_BSS = {
    "src/taskpool.o": 0x03007488,
    "src/malloc.o": 0x030074A8,
    "src/engine.o": 0x0203401C,
    "src/mode_ms.o": {"us": 0x020358C8, "jp": 0x02035828},
    "src/key.o": 0x02034000,
    "src/mode_movie.o": 0x02034938,
    "src/mode_worldinspect.o": {"us": 0x02035118, "jp": 0x02035078, "eu": None},
    "src/mode_sio2.o": {"us": 0x02034CF4, "jp": 0x02034C54, "eu": None},
    "src/sio.o": 0x0203406C,
    "src/mode_sio.o": {"us": 0x02034B3C, "jp": 0x02034A9C},
    "src/mode_worldwarp.o": {"us": 0x020354E8, "jp": 0x02035448},
}

DEFAULT_VERSION = "us"
ROM_TITLE = "KINGDOMHEART"
ROM_MAKER_CODE = "GD"

VERSIONS = {
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
    "--non-matching",
    action="store_true",
    help="build with NON_MATCHING defined; does not verify against the base ROM",
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
build_dir = f"build/{version}-nonmatching" if args.non_matching else f"build/{version}"
name = f"com_{version}"
elf = f"{build_dir}/{name}.elf"
rom = f"{build_dir}/{name}.gba"
mapfile = f"{build_dir}/{name}.map"
ldscript = f"{build_dir}/ldscript.ld"

report_python = ".venv/bin/python3" if Path(".venv/bin/python3").exists() else "python3"

if not Path(baserom).exists():
    print(f"warning: base ROM {baserom} not found; the build will fail without it")

symbols_file = Path(f"config/{version}/symbols.txt")
symbols = []
if symbols_file.exists():
    for line in symbols_file.read_text().splitlines():
        line = line.split("#")[0].strip()
        if not line:
            continue
        name, addr = (x.strip() for x in line.split("="))
        symbols.append((name, int(addr, 16)))

units_file = Path(f"config/{version}/units.txt")
units = []
archives = []
for line in units_file.read_text().splitlines():
    line = line.strip()
    if not line or line.startswith("#"):
        continue
    parts = line.split(None, 1)
    name = parts[0]
    flags = parts[1] if len(parts) > 1 else None
    section = ".text"
    if name.endswith(")") and "(" in name:
        name, _, spec = name.partition("(")
        section = spec[:-1]
    if name.startswith("@"):
        arch, member = name[1:].split(":")
        path = f"tools/agbcc/lib/{arch}"
        obj = f"{build_dir}/lib/{arch}/{member}"
        archives.append((path, member, obj))
        units.append((None, obj, None, section))
        continue
    if name.endswith(".c"):
        src = Path("src") / name
        obj = f"{build_dir}/src/{src.stem}.o"
    else:
        src = Path(f"asm/{version}") / name
        if not src.exists():
            src = Path("asm") / name
        obj = f"{build_dir}/asm/{src.stem}.o"
    if not src.exists():
        sys.exit(f"error: unit {src} listed in {units_file} does not exist")
    units.append((src, obj, flags, section))

objs_in_order = [(obj, section) for _, obj, _flags, section in units]
bss_members = [obj for src, obj, _f, _s in units if src is None and BSS_MEMBERS.get(obj.rsplit("/", 1)[-1])]
Path(build_dir).mkdir(parents=True, exist_ok=True)
with open(ldscript, "w") as f:
    f.write("ENTRY(_start);\n\n")
    for name, addr in symbols:
        f.write(f"{name} = {addr:#010x};\n")
    if symbols:
        f.write("\n")
    f.write("SECTIONS\n{\n    . = 0x8000000;\n\n    .text :\n    {\n")
    for obj, section in objs_in_order:
        f.write(f"        {obj}({section});\n")
    f.write("    }\n")
    if bss_members:
        f.write(f"\n    .bss {ARCHIVE_BSS[version]:#x} (NOLOAD) :\n    {{\n")
        for obj in bss_members:
            f.write(f"        {obj}(.bss);\n")
        f.write("    }\n")
    # Only place a unit this version actually links. EU builds from a whole-ROM
    # incbin and has no src/*.o at all, so an unconditional placement makes ld
    # fail on a missing object.
    linked = {o for _s, o, _f, _sec in units}
    unit_bss = {}
    for obj, addr in UNIT_BSS.items():
        a = addr.get(version) if isinstance(addr, dict) else addr
        if a is not None and f"{build_dir}/{obj}" in linked:
            unit_bss[obj] = a
    for obj, addr in sorted(unit_bss.items(), key=lambda kv: kv[1]):
        f.write(f"\n    .bss.{obj.rsplit('/', 1)[-1].removesuffix('.o')} {addr:#x} (NOLOAD) :\n"
                f"    {{\n        {build_dir}/{obj}(.bss COMMON);\n    }}\n")
    f.write("\n    /DISCARD/ : { *(*); }\n}\n")

out = Path("build.ninja")
with out.open("w") as f:
    n = ninja_syntax.Writer(f)

    n.variable("ninja_required_version", "1.3")
    n.variable("as", f"{prefix}as")
    n.variable("ld", f"{prefix}ld")
    n.variable("ar", f"{prefix}ar")
    n.variable("objcopy", f"{prefix}objcopy")
    n.variable("cpp", f"{prefix}cpp")
    n.variable("agbcc", "tools/agbcc/bin/agbcc")
    n.variable(
        "asflags",
        f"-mcpu=arm7tdmi -march=armv4t -mthumb-interwork -I include -I asm/{version}/nonmatchings",
    )
    defines = f"-DVERSION_{version.upper()}"
    if args.non_matching:
        defines += " -DNON_MATCHING"
    n.variable("cppflags", f"-nostdinc -undef -I include -I tools/agbcc/include {defines}")
    n.variable("cflags", "-mthumb-interwork -O2 -fprologue-bugfix")
    n.variable("pyreport", report_python)
    n.newline()

    n.rule(
        "as",
        command="$as $asflags -o $out $in",
        description="AS $out",
    )
    n.rule(
        "cc",
        command="$cpp $cppflags -o $out.i $in && $agbcc $cflags -o $out.s $out.i && $as $asflags -o $out $out.s",
        description="CC $out",
    )
    n.rule(
        "ld",
        command="$ld -T $ldscript -Map $map -o $out $in",
        description="LD $out",
    )
    n.rule(
        "arx",
        command="$ar p $archive $member > $out",
        description="AR $out",
    )
    n.rule(
        "rom",
        command=f'$objcopy -O binary --only-section=.text $in $out'
                f' && python3 tools/gbafix.py $out "{ROM_TITLE}" {code} {ROM_MAKER_CODE}',
        description="ROM $out",
    )
    n.rule(
        "report",
        command=f"$pyreport -m mapfile_parser objdiff_report $out --version {version} --quiet"
        f" && python3 tools/normalize_report.py $out"
        f" && python3 tools/check_report.py $out",
        description="REPORT $out",
    )
    n.rule(
        "progress",
        command="python3 tools/progress.py $in",
        description="PROGRESS",
        pool="console",
    )
    n.rule(
        "check",
        command=f'echo "{sha1}  {rom}" | sha1sum -c && touch $out',
        description=f"CHECK {rom}",
    )
    n.newline()

    headers = sorted(str(p) for p in Path("include").glob("*.h"))
    asm_includes = sorted(str(p) for p in Path("include").glob("*.inc"))
    objs = []
    for path, member, obj in archives:
        n.build(obj, "arx", implicit=[path],
                variables={"archive": path, "member": member})
        objs.append(obj)
    emitted = set()
    for src, obj, flags, _section in units:
        if src is None or obj in emitted:
            continue
        emitted.add(obj)
        rule = "cc" if src.suffix == ".c" else "as"
        variables = {"cflags": f"-mthumb-interwork {flags}"} if flags else None
        deps = [baserom]
        if rule == "as":
            deps += asm_includes
        if rule == "cc":
            deps += headers
            for m in INCLUDE_ASM_RE.finditer(src.read_text()):
                dep = f"asm/{version}/nonmatchings/{m.group(1)}"
                if Path(dep).exists():
                    deps.append(dep)
        n.build(obj, rule, str(src), implicit=deps, variables=variables)
        objs.append(obj)
    n.newline()

    n.build(
        elf,
        "ld",
        objs,
        implicit=[ldscript],
        variables={"ldscript": ldscript, "map": mapfile},
    )
    n.build(rom, "rom", elf, implicit=["tools/gbafix.py"])
    if not args.non_matching:
        n.build(f"{build_dir}/ok", "check", rom)
    n.newline()

    if args.non_matching:
        n.build("all", "phony", rom)
    else:
        report = f"{build_dir}/report.json"
        n.build(report, "report", implicit=[f"{build_dir}/ok", "decomp.yaml",
                                            "tools/normalize_report.py", "tools/check_report.py"])
        n.build("progress", "progress", report, implicit=["tools/progress.py"])
        n.newline()
        n.build("all", "phony", f"{build_dir}/ok")
    n.default("all")

objdiff_config = {
    "min_version": "2.0.0",
    "custom_make": "ninja",
    "build_target": False,
    "build_base": True,
    "watch_patterns": ["*.c", "*.h", "*.s", "*.inc"],
    "units": [],
}
Path("objdiff.json").write_text(json.dumps(objdiff_config, indent=2) + "\n")

root = Path.cwd()
cc_args = [
    "clang", "-nostdinc", "-fno-builtin", "--target=arm-none-eabi",
    "-mthumb", "-std=gnu89", "-Iinclude", "-Itools/agbcc/include",
    f"-Iasm/{version}/nonmatchings", f"-DVERSION_{version.upper()}",
]
compile_commands = [
    {
        "directory": str(root),
        "file": str(root / src),
        "output": str(root / obj),
        "arguments": cc_args + [str(src)],
    }
    for obj, src in dict(
        (obj, src) for src, obj, _flags, _section in units
        if src is not None and src.suffix == ".c"
    ).items()
]
Path("compile_commands.json").write_text(json.dumps(compile_commands, indent=2) + "\n")

mode = " (non-matching)" if args.non_matching else ""
print(f"configured for {version} ({code}){mode}; run: ninja")
