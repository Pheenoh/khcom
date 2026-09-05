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
# away unless it is placed here.
# An int means every version places the unit at the same address; a dict gives
# a per-version address. US and JP agree below 0x02034A08 and in IWRAM, and JP
# is shifted down by 0x90..0xA4 above that; EU differs from 0x02034898 on and
# in IWRAM from 0x03007484, so most units need the dict form.
UNIT_COMMON = {
    "src/pallet.o": {"us": 0X02039B70, "jp": 0x02039ae0, "eu": 0x0203a180},
    "src/status.o": {"us": 0X0203C550, "jp": 0x0203c4c0, "eu": 0x0203cb40},
    "src/mode_debflag.o": {"us": 0X02039B94, "jp": 0x02039b04, "eu": 0x0203a1a4},
    "src/wlogo.o": {"us": 0X0203AB38, "jp": 0x0203aaa8, "eu": 0x0203b10c},
    "src/msg.o": {"us": 0x02039DD0, "jp": 0x02039D40, "eu": 0x0203A3E0},
}

UNIT_BSS = {
    "src/mode_chkbtl.o": {"us": 0X02039B84, "jp": 0x02039af4, "eu": 0x0203a194},
    "src/mode_vsbattle.o": {"us": 0X02039B98, "jp": 0x02039b08, "eu": 0x0203a1a8},
    "src/evt.o": {"us": 0X02039DC8, "jp": 0x02039d38, "eu": 0x0203a3d8},
    "src/fld.o": {"us": 0X0203C7AC, "jp": 0x0203c71c, "eu": 0x0203cd9c},
    "src/unk_0800eebc.o": {"us": 0X02039CA8, "jp": 0x02039c18, "eu": 0x0203a2b8},
    "src/unk_08019050.o": {"us": 0X02039DC0, "jp": 0x02039d30, "eu": 0x0203a3d0},
    "src/taskpool.o": {"us": 0x03007488, "jp": 0x03007488, "eu": 0x0300748C},
    "src/malloc.o": {"us": 0x030074A8, "jp": 0x030074A8, "eu": 0x030074B0},
    "src/engine.o": 0x0203401C,
    "src/mode_ms.o": {"us": 0x020358C8, "jp": 0x02035828, "eu": 0x02035ED8},
    "src/card.o": {"us": 0x02034AA4, "jp": 0x02034A04, "eu": 0x02034AC0},
    "src/util.o": 0x0203407C,
    "src/save.o": 0x02034088,
    "src/mode_debug.o": {"us": 0x02034898, "jp": 0x02034898, "eu": 0x020348A0},
    "src/mode_chksnd.o": {"us": 0x020348A0, "jp": 0x020348A0, "eu": 0x020348A8},
    "src/mode_chkeff.o": {"us": 0x020348B8, "jp": 0x020348B8, "eu": 0x020348C0},
    "src/mode_dummy.o": {"us": 0x020348BC, "jp": 0x020348BC, "eu": 0x020348C8},
    "src/mode_debflag.o": {"us": 0x020348C0, "jp": 0x020348C0, "eu": 0x020348CC},
    "src/unk_0801007c.o": {"us": 0x020348C8, "jp": 0x020348C8, "eu": 0x020349CC},
    "src/btl.o": {"us": 0x0203492C, "jp": 0x0203492C, "eu": 0x02034A2C},
    "src/msg.o": {"us": 0x02034A80, "jp": 0x020349E0, "eu": 0x02034AA0},
    "src/mode_eventselect.o": {"us": 0x02034A94, "jp": 0x020349F4, "eu": 0x02034AB0},
    "src/wlogo.o": {"us": 0x02034C38, "jp": 0x02034B98, "eu": 0x02034E28},
    "src/chara.o": {"us": 0x02034CD8, "jp": 0x02034C38, "eu": 0x02034EC8},
    "src/mode_copyright1.o": {"us": 0x02034ED4, "jp": 0x02034E34, "eu": 0x020350C4},
    "src/mode_status.o": {"us": 0x02034EE0, "jp": 0x02034E40, "eu": 0x020350D0},
    "src/status.o": {"us": 0x02034EFC, "jp": 0x02034E5C, "eu": 0x020350EC},
    "src/key.o": 0x02034000,
    "src/mode_movie.o": {"us": 0x02034938, "jp": 0x02034938, "eu": 0x020348D8},
    "src/bos4.o": {"us": 0x02034F0C, "jp": 0x02034E6C, "eu": 0x020350FC},
    "src/map.o": {"us": 0x02034F1C, "jp": 0x02034E7C, "eu": 0x02035110},
    "src/poo.o": {"us": 0x02034DA8, "jp": 0x02034D08, "eu": 0x02034F98},
    "src/mode_allmap.o": {"us": 0x02034E3C, "jp": 0x02034D9C, "eu": 0x0203502C},
    "src/allmap.o": {"us": 0x02034E84, "jp": 0x02034DE4, "eu": 0x02035074},
    "src/mode_title.o": {"us": 0x02034E98, "jp": 0x02034DF8, "eu": 0x02035088},
    "src/title.o": {"us": 0x02034ED0, "jp": 0x02034E30, "eu": 0x020350C0},
    "src/mode_copyright2.o": {"us": 0x02034EDC, "jp": 0x02034E38, "eu": 0x020350CC},
    "src/mode_backupstat.o": {"us": 0x02035FE8, "jp": 0x02035F58, "eu": 0x020365F8},
    "src/unk_0810fe94.o": {"us": 0x02036014, "jp": 0x02035F84, "eu": 0x02036624},
    "src/sroll.o": {"us": 0x02036028, "jp": 0x02035F98, "eu": 0x02036638},
    "src/lib.o": {"us": 0x02038628, "jp": 0x02038598, "eu": 0x02038C38},
    "src/agb_sram.o": {"us": 0x02038698, "jp": 0x02038608, "eu": 0x02038CA8},
    "src/unk_08104a84.o": {"us": 0x02035C10, "jp": 0x02035B70, "eu": 0x02036220},
    "src/mode_ms2.o": {"us": 0x02035E28, "jp": 0x02035D88, "eu": 0x02036438},
    "src/mode_mapinspect.o": {"us": 0x02035FC4, "jp": 0x02035F30, "eu": 0x020365D4},
    "src/mode_test.o": {"us": 0x02034A08, "jp": 0x02034964, "eu": 0x02034A34},
    "src/main.o": 0x03006C00,
    "src/sprite.o": {"us": 0x030074C8, "jp": 0x030074C8, "eu": 0x030074D0},
    "src/pallet.o": {"us": 0x0300756C, "jp": 0x0300756C, "eu": 0x03007574},
    "src/mode_jiminy.o": {"us": 0x02034934, "jp": 0x02034934, "eu": 0x020349C8},
    "src/bos5.o": {"us": 0x02034FE8, "jp": 0x02034F48, "eu": 0x020351D8},
    "src/bos7.o": {"us": 0x02036020, "jp": 0x02035F90, "eu": 0x02036630},
    "src/bos6.o": {"us": 0x02036008, "jp": 0x02035F78, "eu": 0x02036618},
    "src/mode_worldinspect.o": {"us": 0x02035118, "jp": 0x02035078, "eu": 0x02035308},
    "src/mode_sio2.o": {"us": 0x02034CF4, "jp": 0x02034C54, "eu": 0x02034EE4},
    "src/sio.o": 0x0203406C,
    "src/mode_sio.o": {"us": 0x02034B3C, "jp": 0x02034A9C, "eu": 0x02034B54},
    "src/mode_worldwarp.o": {"us": 0x020354E8, "jp": 0x02035448, "eu": 0x02035978},
    "src/bos3.o": {"us": 0x0203C3BC, "jp": 0x0203C32C, "eu": 0x0203C998},
    "src/snd_stream.o": {"us": 0x0203C7F0, "jp": 0x0203C760, "eu": 0x0203CDE0},
    "src/movie.o": {"us": 0x0203C7C4, "jp": 0x0203C734, "eu": 0x0203CDB4},
    "src/m4a2.o": {"us": 0x0203C850, "jp": 0x0203C7C0, "eu": 0x0203CE40},
    "src/bos2.o": {"us": 0x0203ACC0, "jp": 0x0203AC30, "eu": 0x0203B290},
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
    unit_common = {}
    for obj, addr in UNIT_COMMON.items():
        a = addr.get(version) if isinstance(addr, dict) else addr
        if a is not None and f"{build_dir}/{obj}" in linked:
            unit_common[obj] = a
    placements = [(a, obj, ".bss COMMON" if obj not in unit_common else ".bss") for obj, a in unit_bss.items()]
    placements += [(a, obj, "COMMON") for obj, a in unit_common.items()]
    for addr, obj, sec in sorted(placements):
        name = obj.rsplit("/", 1)[-1].removesuffix(".o")
        tag = "bss" if sec != "COMMON" else "common"
        f.write(f"\n    .{tag}.{name} {addr:#x} (NOLOAD) :\n"
                f"    {{\n        {build_dir}/{obj}({sec});\n    }}\n")
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
        command=f"python3 -c \"import hashlib,sys; sys.exit(hashlib.sha1(open('{rom}','rb').read()).hexdigest() != '{sha1}')\" && touch $out",
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
