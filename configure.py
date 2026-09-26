#!/usr/bin/env python3

import argparse
import json
import os
import re
import subprocess
import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent / "tools"))
import ninja_syntax
from assembler_flags import software_fp_flags
from asset_objects import materialize_assets
from assetgen import ManifestError
from assetgen import plan as asset_plan
from regional_data import asset_symbols, load_sidecars

ASM_FILE_REF_RE = re.compile(r'\.(?:include|incbin)\s+"([^"]+)"')
LEGACY_ASM_UNITS = {"libagbsyscall.s", "m4a_1.s", "transform_veneers.s"}

def asm_file_deps(path, missing):
    seen = set()
    queued = set()
    out = []
    stack = [Path(path)]
    queued.add(str(Path(path)))
    while stack:
        cur = stack.pop()
        key = str(cur)
        if key in seen or not cur.exists() or cur.suffix not in {".s", ".inc", ".asm"}:
            continue
        seen.add(key)
        try:
            body = cur.read_text()
        except OSError:
            continue
        for m in ASM_FILE_REF_RE.finditer(body):
            ref = Path(m.group(1))
            rkey = str(ref)
            if rkey in queued:
                continue
            if not ref.exists():
                if rkey.startswith("assets/"):
                    missing.add(rkey)
                continue
            queued.add(rkey)
            out.append(rkey)
            if ref.suffix in {".s", ".inc", ".asm"}:
                stack.append(ref)
    return out

EWRAM_HEAP_SIZE = 0x34000
IWRAM_HEAP_SIZE = 0x6800
IWRAM_BEFORE_HEAP = [("src/m4a2.o", ".bss")]
IWRAM_AFTER_HEAP = [
    ("src/main.o", ".bss"),
    ("src/taskpool.o", ".bss"),
    ("src/malloc.o", ".bss"),
    ("src/sprite.o", ".bss"),
    ("src/engine.o", ".iwram.*"),
    ("src/pallet.o", ".bss"),
    ("src/engine.o", ".iwram_common.*"),
]
BIOS_SYMBOLS = {"gSoundInfoPtr": 0x03007FF0, "gIntrCheck": 0x03007FF8}

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
    "--binutils-prefix",
    default="arm-none-eabi-",
    help="binutils tool prefix (default: %(default)s)",
)
parser.add_argument(
    "--asset-gfx-mode",
    choices=("slice", "built"),
    default="slice",
    help="asset_gfx path: baserom slice (default) or MovieOpen demux/remux built pack (us/jp/eu)",
)
args = parser.parse_args()

legacy_assembler = Path("tools/legacy/bin/arm-elf-as")
legacy_linker = Path("tools/legacy/bin/arm-elf-ld")
legacy_tools = [legacy_assembler, legacy_linker, Path("tools/legacy/lib/libgcc.a"), Path("tools/legacy/lib/libc.a")]
if any(not path.is_file() for path in legacy_tools):
    sys.exit("error: run python3 tools/setup_legacy_toolchain.py before configuring")
for tool, expected in ((legacy_assembler, "GNU assembler 2.10"), (legacy_linker, "GNU ld 2.10")):
    if subprocess.check_output([str(tool), "--version"], text=True).splitlines()[0] != expected:
        sys.exit(f"error: {tool} must be binutils 2.10; run python3 tools/setup_legacy_toolchain.py")

version = args.version
code, sha1 = VERSIONS[version]
prefix = args.binutils_prefix
raw_as_flags = software_fp_flags(f"{prefix}as")
asset_gfx_mode = args.asset_gfx_mode

build_dir = f"build/{version}"
name = f"com_{version}"
elf = f"{build_dir}/{name}.elf"
rom = f"{build_dir}/{name}.gba"
verified = f"{build_dir}/verified.gba"
assets_stamp = f"assets/{version}/.stamp"
mapfile = f"{build_dir}/{name}.map"
ldscript = f"{build_dir}/ldscript.ld"

report_python = ".venv/bin/python3" if Path(".venv/bin/python3").exists() else "python3"

symbols_file = Path(f"config/{version}/symbols.txt")
symbols = []
if symbols_file.exists():
    for line in symbols_file.read_text().splitlines():
        line = line.split("#")[0].strip()
        if not line:
            continue
        name, addr = (x.strip() for x in line.split("="))
        symbols.append((name, int(addr, 16)))

regional_files = sorted(Path("config").glob("*_data.yaml"))
regional = load_sidecars("config")
regional_plan = regional["regions"][version]
symbols.extend(asset_symbols(regional_plan, symbols))

try:
    groups = asset_plan(version)
except ManifestError as error:
    sys.exit(f"error: {error}")
units_file = Path(f"config/{version}/units.txt")
listed = {line.split()[0] for line in units_file.read_text().splitlines() if line.strip() and not line.startswith("#")}
groups = {group_name: group for group_name, group in groups.items()
          if not group["objects"] or any(unit_name in listed for unit_name in group["objects"])}
generated = {}
for group_name, group in groups.items():
    for unit_name, unit in group["objects"].items():
        generated[unit_name] = (group_name, unit)

def rel(path):
    return os.path.relpath(str(path))

sources = {}
for path in sorted(Path("src").rglob("*.c")):
    if path.name in sources:
        sys.exit(f"error: {path} and {sources[path.name]} share the basename {path.name}")
    sources[path.name] = path

units = []
archives = []
linked = set()
for line in units_file.read_text().splitlines():
    line = line.strip()
    if not line or line.startswith("#"):
        continue
    parts = line.split(None, 1)
    name = parts[0]
    flags = parts[1] if len(parts) > 1 else None
    if name.startswith("@"):
        arch, member = name[1:].split(":")
        path = f"tools/legacy/lib/{arch}"
        obj = f"{build_dir}/lib/{arch}/{member}"
        archives.append((path, member, obj))
        units.append((None, obj, None))
        continue
    if name in generated:
        src = Path(f"{build_dir}/gen") / name
        obj = f"{build_dir}/gen/{src.stem}.o"
    elif name.endswith(".c"):
        src = sources.get(name, Path("src") / name)
        obj = f"{build_dir}/src/{src.stem}.o"
    else:
        src = Path(f"asm/{version}") / name
        if not src.exists():
            src = Path("asm") / name
        obj = f"{build_dir}/asm/{src.stem}.o"
    if name not in generated and not src.exists():
        sys.exit(f"error: unit {src} listed in {units_file} does not exist")
    if obj in linked:
        sys.exit(f"error: unit {name} is listed twice in {units_file}")
    linked.add(obj)
    units.append((src, obj, flags))

asset_gfx_build = f"{build_dir}/assets/asset_gfx.bin"
asset_gfx_asm = f"{build_dir}/asm/asset_gfx.s"
asset_gfx_unit = "asset_gfx.s"
asset_gfx_sym = {
    "us": "data_084E0B04",
    "jp": "data_084D4390",
    "eu": "data_084B423C",
}[version]
asset_gfx_extract = {
    "us": "assets/us/084E0B04-0886AD18.bin",
    "jp": "assets/jp/084D4390-0885E300.bin",
    "eu": "assets/eu/084B423C-0883F2D0.bin",
}[version]
asset_gfx_manifest = f"config/asset_gfx_{version}.yaml"
if asset_gfx_mode == "built":
    Path(f"{build_dir}/asm").mkdir(parents=True, exist_ok=True)
    Path(asset_gfx_asm).write_text(
        "\t.section .rodata\n"
        f"\t.global {asset_gfx_sym}\n"
        f"{asset_gfx_sym}:\n"
        f'\t.incbin "{asset_gfx_build}"\n'
    )
    rewritten = []
    for src, obj, flags in units:
        if src is not None and src.name == asset_gfx_unit:
            rewritten.append((Path(asset_gfx_asm), obj, flags))
        else:
            rewritten.append((src, obj, flags))
    units = rewritten

units = materialize_assets(regional_plan, units, version, build_dir)

headers = sorted(str(p) for p in Path("include").glob("*.h"))
generated_headers = sorted(rel(group["header"]) for group in groups.values())
asm_includes = sorted(str(p) for p in Path("include").glob("*.inc"))
missing_assets = set()
edges = []
emitted = set()
for src, obj, flags in units:
    if src is None or obj in emitted:
        continue
    emitted.add(obj)
    rule = "cc" if src.suffix == ".c" else "as"
    variables = {"cflags": f"-mthumb-interwork -fno-common {flags}"} if flags else None
    deps = []
    if src.name in generated:
        group_name, unit = generated[src.name]
        deps += [rel(groups[group_name]["header"])]
        if rule == "as":
            deps += [rel(path) for path in unit["binaries"]]
        else:
            deps += headers + generated_headers + ["tools/legacy/bin/arm-elf-as"]
        edges.append((obj, rule, src, deps, variables))
        continue
    if rule == "as":
        deps += asm_includes
        deps.extend(asm_file_deps(src, missing_assets))
        if src.name in LEGACY_ASM_UNITS:
            variables = {"as": "$legacy_as", "asflags": "$legacy_asflags"}
            deps.append(str(legacy_assembler))
    if rule == "cc":
        deps += headers + generated_headers + ["tools/legacy/bin/arm-elf-as"]
    if any(dep.startswith("assets/") for dep in deps):
        deps.append(assets_stamp)
    edges.append((obj, rule, src, deps, variables))
if asset_gfx_mode == "built":
    asset_gfx_obj_suffix = "/asset_gfx.o"
    patched = []
    for obj, rule, src, deps, variables in edges:
        if obj.endswith(asset_gfx_obj_suffix):
            deps = [d for d in deps if not d.startswith("assets/")]
            if asset_gfx_build not in deps:
                deps.append(asset_gfx_build)
            if asset_gfx_asm not in deps:
                deps.append(asset_gfx_asm)
        patched.append((obj, rule, src, deps, variables))
    edges = patched
    missing_assets.difference_update(
        p for p in list(missing_assets)
        if p.startswith("assets/") and Path(p).name == Path(asset_gfx_extract).name
    )

if any(dep.startswith("assets/") for edge in edges for dep in edge[3]) and not Path(assets_stamp).exists():
    missing_assets.add(assets_stamp)
pending_build_assets = sorted(p for p in missing_assets if p.startswith("build/"))
missing_extract = sorted(p for p in missing_assets if not p.startswith("build/"))
if missing_extract:
    first = missing_extract[0]
    sys.exit(f"error: {len(missing_extract)} extracted asset files for {version} are missing (first: {first});"
             f" run python3 tools/extract_assets.py {version}")
allowed_build_assets = set()
if asset_gfx_mode == "built":
    allowed_build_assets.add(asset_gfx_build)
pending_uncovered = [p for p in pending_build_assets if p not in allowed_build_assets]
if pending_uncovered:
    first = pending_uncovered[0]
    sys.exit(
        f"error: build asset {first} is missing; use --asset-gfx-mode=built or extract slice assets"
    )

objs_linked = [obj for _src, obj, _flags in units]
Path(build_dir).mkdir(parents=True, exist_ok=True)
with open(ldscript, "w") as f:
    f.write("ENTRY(_start);\n\n")
    for name, addr in symbols:
        f.write(f"{name} = {addr:#010x};\n")
    if symbols:
        f.write("\n")
    f.write("SECTIONS\n{\n    . = 0x8000000;\n\n    .text :\n    {\n")
    for obj in objs_linked:
        f.write(f"        {obj}(.text);\n")
    f.write("        *(.rodata);\n        *(.data);\n    }\n")
    f.write("\n    .iwram 0x03000000 (NOLOAD) :\n    {\n")
    for obj, section in IWRAM_BEFORE_HEAP:
        f.write(f"        {build_dir}/{obj}({section});\n")
    f.write(f"        gIwramHeapStart = .;\n        . += {IWRAM_HEAP_SIZE:#x};\n")
    for obj, section in IWRAM_AFTER_HEAP:
        f.write(f"        {build_dir}/{obj}({section});\n")
    f.write("    }\n")
    for name, addr in BIOS_SYMBOLS.items():
        f.write(f"    {name} = {addr:#010x};\n")
    f.write("\n    .ewram 0x02000000 (NOLOAD) :\n    {\n")
    f.write(f"        gEwramHeapStart = .;\n        . += {EWRAM_HEAP_SIZE:#x};\n")
    f.write("        *(.bss);\n        *(.ewram_common.*);\n    }\n")
    f.write("\n    /DISCARD/ : { *(*); }\n}\n")

out = Path("build.ninja")
with out.open("w") as f:
    n = ninja_syntax.Writer(f)

    n.variable("ninja_required_version", "1.3")
    n.variable("as", f"{prefix}as")
    n.variable("legacy_as", "tools/legacy/bin/arm-elf-as")
    n.variable("legacy_asflags", "-marm7tdmi -mthumb-interwork -mno-fpu -I . -I include")
    n.variable("ld", str(legacy_linker))
    n.variable("ar", f"{prefix}ar")
    n.variable("objcopy", f"{prefix}objcopy")
    n.variable("cpp", f"{prefix}cpp")
    n.variable("agbcc", "tools/agbcc/bin/agbcc")
    n.variable(
        "asflags",
        f"{raw_as_flags} -I . -I include",
    )
    n.variable("asdefines", f"--defsym VERSION_{version.upper()}=1")
    n.variable("cppflags", f"-nostdinc -undef -I include -I {build_dir}/gen -I tools/agbcc/include -DVERSION_{version.upper()}")
    n.variable("cflags", "-mthumb-interwork -fno-common -O2 -fprologue-bugfix")
    n.variable("pyreport", report_python)
    n.newline()

    n.rule(
        "as",
        command="$as $asflags $asdefines -o $out $in",
        description="AS $out",
    )
    n.rule(
        "cc",
        command="$cpp $cppflags -o $out.i $in && $agbcc $cflags -o $out.s $out.i && $legacy_as $legacy_asflags -o $out $out.s",
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
        command=f'$objcopy -O binary --only-section=.text --pad-to=0x0A000000 --gap-fill=0xFF $in $out'
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
        "assetgen",
        command="python3 tools/assetgen.py $version $manifest",
        description="ASSETGEN $manifest",
    )
    n.rule(
        "check",
        command=f"python3 -c \"import hashlib,sys; sys.exit(hashlib.sha1(open('{rom}','rb').read()).hexdigest() != '{sha1}')\""
                f" && cp {rom} {verified}"
                + (f" && {report_python} tools/regional_data.py {version} --rom {verified} --binutils-prefix {prefix}"
                   if regional_files else "")
                + " && touch $out",
        description=f"CHECK {rom}",
    )
    if asset_gfx_mode == "built":
        n.rule(
            "asset_gfx_pack",
            command=f"python3 tools/gfx/asset_gfx_pack.py --mode built --version {version} && test -f $out",
            description="ASSET_GFX $out",
        )
    n.newline()

    for path, member, obj in archives:
        n.build(obj, "arx", implicit=[path],
                variables={"archive": path, "member": member})
    if asset_gfx_mode == "built":
        n.build(
            asset_gfx_build,
            "asset_gfx_pack",
            implicit=[
                "tools/gfx/asset_gfx_pack.py",
                "tools/gfx/asset_gfx_layout.py",
                "tools/movie_assets.py",
                asset_gfx_manifest,
                f"config/asset_inventory_{version}_gfx.yaml",
                asset_gfx_extract,
            ],
        )
    manifests = sorted(rel(group["manifest"].path) for group in groups.values())
    for group_name, group in groups.items():
        outputs = [rel(unit["source"]) for unit in group["objects"].values()] + [rel(group["header"])]
        n.build(
            outputs,
            "assetgen",
            implicit=manifests + ["tools/assetgen.py", "tools/sprite_sheet.py", "tools/gbagfx/gbagfx", assets_stamp]
            + [rel(path) for path in group["sources"]],
            implicit_outputs=[rel(path) for path in group["binaries"]],
            variables={"version": version, "manifest": rel(group["manifest"].path)},
        )
    for obj, rule, src, deps, variables in edges:
        n.build(obj, rule, str(src), implicit=deps, variables=variables)
    objs = list(objs_linked)
    n.newline()

    n.build(
        elf,
        "ld",
        objs,
        implicit=[ldscript, str(legacy_linker)],
        variables={"ldscript": ldscript, "map": mapfile},
    )
    n.build(rom, "rom", elf, implicit=["tools/gbafix.py"])
    n.build(f"{build_dir}/ok", "check", rom,
            implicit=(["tools/regional_data.py", "tools/rom_data_evidence.py"] + [str(path) for path in regional_files]
                      if regional_files else []),
            implicit_outputs=[verified])
    n.newline()

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
    f"-DVERSION_{version.upper()}",
]
compile_commands = [
    {
        "directory": str(root),
        "file": str(root / src),
        "output": str(root / obj),
        "arguments": cc_args + [str(src)],
    }
    for obj, src in dict(
        (obj, src) for src, obj, _flags in units
        if src is not None and src.suffix == ".c"
    ).items()
]
Path("compile_commands.json").write_text(json.dumps(compile_commands, indent=2) + "\n")

print(f"configured for {version} ({code}); run: ninja")
