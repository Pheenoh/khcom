#!/usr/bin/env python3

import argparse
import json
import re
import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent / "tools"))
import ninja_syntax
from regional_data import asset_symbols, linker_assertions, load_sidecars, managed_placements, validate_active_sections

ASM_FILE_REF_RE = re.compile(r'\.(?:include|incbin)\s+"([^"]+)"')


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
    "src/card.o": {"us": 0x02034B38, "jp": 0x02034A98, "eu": 0x02034B50},
    "src/main.o": 0x03007FF8,
    "src/memory_regions.o": 0x02000000,
    "src/boss_tm_state.o": {"us": 0x203ab50, "jp": 0x203aac0, "eu": 0x203b120},
    "src/bos4.o": {"us": 0x203c590, "jp": 0x203c500, "eu": 0x203cb80},
    "src/m4a2.o": {"us": 0x3007ff0, "jp": 0x3007ff0, "eu": 0x3007ff0},
    "src/engine.o": {"us": 0x3007574, "jp": 0x3007574, "eu": 0x300757c},
    "src/mode_eventselect.o": {"us": 0x02039DD4, "jp": 0x02039D44, "eu": 0x0203A3E4},
    "src/mode_test.o": {"us": 0x02039DC4, "jp": 0x02039D34, "eu": 0x0203A3D4},
    "src/pallet.o": {"us": 0X02039B70, "jp": 0x02039ae0, "eu": 0x0203a180},
    "src/status.o": {"us": 0X0203C550, "jp": 0x0203c4c0, "eu": 0x0203cb40},
    "src/mode_debflag.o": {"us": 0X02039B94, "jp": 0x02039b04, "eu": 0x0203a1a4},
    "src/wlogo.o": {"us": 0X0203AB38, "jp": 0x0203aaa8, "eu": 0x0203b10c},
    "src/msg.o": {"us": 0x02039DD0, "jp": 0x02039D40, "eu": 0x0203A3E0},
    "src/mode_allmap.o": {"us": 0x0203C4F0, "jp": 0x0203C460, "eu": 0x0203CAE0},
}

UNIT_BSS = {
    "src/m4a_catalog_data.o": {"us": 0x20387e0, "jp": 0x2038750, "eu": 0x2038df0},
    "src/memory_regions.o": 0x03000000,
    "src/mode_chkbtl_data.o": {"us": 0x02034890, "jp": 0x02034890, "eu": 0x02034898},
    "src/mode_battle.o": {"eu": 0x02034890},
    "src/event_scanline_state.o": {"us": 0x02039DCC, "jp": 0x02039D3C, "eu": 0x0203A3DC},
    "src/map_transition_state.o": {"us": 0x0203C7B0, "jp": 0x0203C720, "eu": 0x0203CDA0},
    "src/allmap_bottom_state.o": {"us": 0x0203C510, "jp": 0x0203C480, "eu": 0x0203CB00},
    "src/allmap_scroll_state.o": {"us": 0x0203C504, "jp": 0x0203C474, "eu": 0x0203CAF4},
    "src/allmap_top_state.o": {"us": 0x0203C4C0, "jp": 0x0203C430, "eu": 0x0203CAB0},
    "src/pooh_actor_state.o": {"us": 0x0203C420, "jp": 0x0203C390, "eu": 0x0203CA10},
    "src/boss_jafar_state.o": {"us": 0x0203AC80, "jp": 0x0203ABF0, "eu": 0x0203B250},
    "src/sio_card_trade_state.o": {"us": 0x0203AB10, "jp": 0x0203AA80},
    "src/sio_battle_options_state.o": {"us": 0x0203AA00, "jp": 0x0203A970, "eu": 0x0203B000},
    "src/sio_handshake_state.o": {"us": 0x0203A9EC, "jp": 0x0203A95C, "eu": 0x0203AFF8},
    "src/sio_runtime_state.o": {"us": 0x02039810, "jp": 0x02039780, "eu": 0x02039E20},
    "src/sio_callback_state.o": {"us": 0x020397F8, "jp": 0x02039768, "eu": 0x02039E08},
    "src/sio_link_header_state.o": {"us": 0x020397D0, "jp": 0x02039740, "eu": 0x02039DE0},
    "src/sram_state.o": {"us": 0x0203C7BC, "jp": 0x0203C72C, "eu": 0x0203CDAC},
    "src/allmap_cursor_state.o": {"us": 0x0203C538, "jp": 0x0203C4A8, "eu": 0x0203CB28},
    "src/battle_field_state.o": {"us": 0x02039B9C, "jp": 0x02039B0C, "eu": 0x0203A1AC},
    "src/chara_link_cursor.o": {"us": 0x0203BEB8, "jp": 0x0203BE28, "eu": 0x0203C488},
    "src/worldlogo_state.o": {"us": 0x0203AB3C, "jp": 0x0203AAAC, "eu": 0x0203B110},
    "src/sio_debug_state.o": {"us": 0x0203C3C4, "jp": 0x0203C334, "eu": 0x0203C9A0},
    "src/title_background_state.o": {"us": 0x0203C544, "jp": 0x0203C4B4, "eu": 0x0203CB34},
    "src/chara_link_buffers.o": {"us": 0x0203BD10, "jp": 0x0203BC80, "eu": 0x0203C2E0},
    "src/boss_tm_state.o": {"us": 0x0203AC60, "jp": 0x0203ABD0, "eu": 0x0203B230},
    "src/boss_status_state.o": {"us": 0x0203C554, "jp": 0x0203C4C4, "eu": 0x0203CB44},
    "src/pooh_state.o": {"us": 0x0203C3D8, "jp": 0x0203C348, "eu": 0x0203C9C8},
    "src/graphics_state.o": {"us": 0x030074CC, "jp": 0x030074CC, "eu": 0x030074D4},
    "src/chara_link_state.o": {"us": 0x0203BEC0, "jp": 0x0203BE30, "eu": 0x0203C490},
    "src/worldwarp_state.o": {"us": 0x020357C0, "jp": 0x02035720, "eu": 0x02035DD0},
    "src/mode_chkbtl.o": {"us": 0X02039B84, "jp": 0x02039af4, "eu": 0x0203a194},
    "src/mode_vsbattle.o": {"us": 0X02039B98, "jp": 0x02039b08, "eu": 0x0203a1a8},
    "src/evt.o": {"us": 0X02039DC8, "jp": 0x02039d38, "eu": 0x0203a3d8},
    "src/fld.o": {"us": 0X0203C7AC, "jp": 0x0203c71c, "eu": 0x0203cd9c},
    "src/player_progression.o": {"us": 0x02039BB0, "jp": 0x02039B20, "eu": 0x0203A1C0},
    "src/battle_runtime.o": {"us": 0X02039DC0, "jp": 0x02039d30, "eu": 0x0203a3d0},
    "src/taskpool.o": {"us": 0x03007488, "jp": 0x03007488, "eu": 0x0300748C},
    "src/malloc.o": {"us": 0x030074A8, "jp": 0x030074A8, "eu": 0x030074B0},
    "src/engine.o": 0x0203401C,
    "src/mode_ms.o": {"us": 0x020358C8, "jp": 0x02035828, "eu": 0x02035ED8},
    "src/card.o": {"us": 0x02034AA4, "jp": 0x02034A04, "eu": 0x02034AC0},
    "src/card_state.o": {"us": 0x02039DD8, "jp": 0x02039D48, "eu": 0x0203A3E8},
    "src/card_ui_state.o": {"us": 0x0203A860, "jp": 0x0203A7D0, "eu": 0x0203AE70},
    "src/util.o": 0x0203407C,
    "src/save.o": 0x02034088,
    "src/mode_debug.o": {"us": 0x02034898, "jp": 0x02034898, "eu": 0x020348A0},
    "src/mode_chksnd.o": {"us": 0x020348A0, "jp": 0x020348A0, "eu": 0x020348A8},
    "src/mode_chkeff.o": {"us": 0x020348B8, "jp": 0x020348B8, "eu": 0x020348C0},
    "src/movie_debug.o": {"eu": 0x020348C4},
    "src/mode_dummy.o": {"us": 0x020348BC, "jp": 0x020348BC, "eu": 0x020348C8},
    "src/mode_debflag.o": {"us": 0x020348C0, "jp": 0x020348C0, "eu": 0x020348CC},
    "src/field_transition.o": {"us": 0x020348C8, "jp": 0x020348C8, "eu": 0x020349CC},
    "src/btl_vs.o": {"us": 0x020348CC, "jp": 0x020348CC, "eu": 0x020349D0},
    "src/btl_collision.o": {"us": 0x020348E8, "jp": 0x020348E8, "eu": 0x020349E8},
    "src/btl_effect.o": {"us": 0x02034928, "jp": 0x02034928, "eu": 0x02034A28},
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
    "src/sroll.o": {"us": 0x02036028, "jp": 0x02035F98, "eu": 0x02036638},
    "src/audio_block_codec.o": {"us": 0x02038628, "jp": 0x02038598, "eu": 0x02038C38},
    "src/agb_sram.o": {"us": 0x02038698, "jp": 0x02038608, "eu": 0x02038CA8},
    "src/ms_charge.o": {"us": 0x02035C10, "jp": 0x02035B70, "eu": 0x02036220},
    "src/mode_ms2.o": {"us": 0x02035E28, "jp": 0x02035D88, "eu": 0x02036438},
    "src/mode_mapinspect.o": {"us": 0x02035FC4, "jp": 0x02035F30, "eu": 0x020365D4},
    "src/mode_test.o": {"us": 0x02034A08, "jp": 0x02034964, "eu": 0x02034A34},
    "src/main.o": 0x03006C00,
    "src/sprite.o": {"us": 0x030074C8, "jp": 0x030074C8, "eu": 0x030074D0},
    "src/pallet.o": {"us": 0x0300756C, "jp": 0x0300756C, "eu": 0x03007574},
    "src/mode_jiminy.o": {"us": 0x02034934, "jp": 0x02034934, "eu": 0x020349C8},
    "src/bos5.o": {"us": 0x02034FE8, "jp": 0x02034F48, "eu": 0x020351D8},
    "src/bos7.o": {"us": 0x02036014, "jp": 0x02035F84, "eu": 0x02036624},
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
parser.add_argument(
    "--asset-gfx-gap-195-mode",
    choices=("slice", "built"),
    default="slice",
    help="asset_gfx_gap_195 path: baserom slice (default) or leaf-patched built mega (gap_195 palettes via gbagfx)",
)
parser.add_argument(
    "--asset-gfx-gap-1-mode",
    choices=("slice", "built"),
    default="slice",
    help="asset_gfx_gap_1 path: baserom slice (default) or leaf-patched built mega (gUnk_08C6A88C tiles4 via gbagfx)",
)
parser.add_argument(
    "--asset-gfx-gap-43-mode",
    choices=("slice", "built"),
    default="slice",
    help="asset_gfx_gap_43 path: baserom slice (default) or leaf-patched built mega (gap_43 palettes via gbagfx)",
)
parser.add_argument(
    "--asset-gfx-gap-158-mode",
    choices=("slice", "built"),
    default="slice",
    help="asset_gfx_gap_158 path: baserom slice (default) or leaf-patched built mega (gap_158 title palettes via gbagfx)",
)
parser.add_argument(
    "--asset-gfx-gap-87-mode",
    choices=("slice", "built"),
    default="slice",
    help="asset_gfx_gap_87 path: baserom slice (default) or leaf-patched built mega (gap_87 palettes via gbagfx)",
)
args = parser.parse_args()

version = args.version
code, sha1 = VERSIONS[version]
prefix = args.binutils_prefix
asset_gfx_mode = args.asset_gfx_mode
asset_gfx_gap_195_mode = args.asset_gfx_gap_195_mode
asset_gfx_gap_1_mode = args.asset_gfx_gap_1_mode
asset_gfx_gap_43_mode = args.asset_gfx_gap_43_mode
asset_gfx_gap_158_mode = args.asset_gfx_gap_158_mode
asset_gfx_gap_87_mode = args.asset_gfx_gap_87_mode

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

regional_files = sorted(Path("config").glob("*_data.json"))
regional = load_sidecars("config")
regional_plan = regional["regions"][version]
symbols.extend(asset_symbols(regional_plan, symbols))
regional_sections = {(placement["unit"], placement["section"]): placement
                     for placement in regional_plan["placements"]}

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

asset_gfx_build = f"{build_dir}/assets/asset_gfx.bin"
asset_gfx_asm = f"{build_dir}/asm/asset_gfx.s"
asset_gfx_unit = "asset_gfx_at_084D4390.s" if version == "jp" else "asset_gfx.s"
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
asset_gfx_gap_195_build = f"{build_dir}/assets/asset_gfx_gap_195.bin"
asset_gfx_gap_195_asm = f"{build_dir}/asm/asset_gfx_gap_195.s"
asset_gfx_gap_195_unit = "asset_gfx_gap_195.s"
asset_gfx_gap_195_sym = {
    "us": "data_0999389C",
    "jp": "data_099483B0",
    "eu": "data_09999B58",
}[version]
asset_gfx_gap_195_extract = {
    "us": "assets/us/0999389C-09A3DF34.bin",
    "jp": "assets/jp/099483B0-099F29BC.bin",
    "eu": "assets/eu/09999B58-09A9B9F8.bin",
}[version]
asset_gfx_gap_195_manifest = f"config/asset_gfx_gap_195_{version}.yaml"
asset_gfx_gap_1_build = f"{build_dir}/assets/asset_gfx_gap_1.bin"
asset_gfx_gap_1_asm = f"{build_dir}/asm/asset_gfx_gap_1.s"
# EU leaf host is rodata_script_at_08896652.s; US/JP use asset_gfx_gap_1.s.
asset_gfx_gap_1_unit = {
    "us": "asset_gfx_gap_1.s",
    "jp": "asset_gfx_gap_1.s",
    "eu": "rodata_script_at_08896652.s",
}[version]
asset_gfx_gap_1_sym = {
    "us": "data_0886AD23",
    "jp": "data_0885E30B",
    "eu": "data_08896652",
}[version]
asset_gfx_gap_1_extract = {
    "us": "assets/us/0886AD23-08F6E184.bin",
    "jp": "assets/jp/0885E30B-08F6168C.bin",
    "eu": "assets/eu/08896652-08F7F15C.bin",
}[version]
asset_gfx_gap_1_manifest = f"config/asset_gfx_gap_1_{version}.yaml"
asset_gfx_gap_43_build = f"{build_dir}/assets/asset_gfx_gap_43.bin"
asset_gfx_gap_43_asm = f"{build_dir}/asm/asset_gfx_gap_43.s"
# EU leaf host is asset_gfx_gap_38_at_09041E7F.s; US/JP use asset_gfx_gap_43.s.
asset_gfx_gap_43_unit = {
    "us": "asset_gfx_gap_43.s",
    "jp": "asset_gfx_gap_43.s",
    "eu": "asset_gfx_gap_38_at_09041E7F.s",
}[version]
asset_gfx_gap_43_sym = {
    "us": "data_090451AB",
    "jp": "data_09012053",
    "eu": "data_090D76FB",
}[version]
asset_gfx_gap_43_extract = {
    "us": "assets/us/090451AB-096193B8.bin",
    "jp": "assets/jp/09012053-095D1E94.bin",
    "eu": "assets/eu/090D76FB-0954C2C9.bin",
}[version]
asset_gfx_gap_43_manifest = f"config/asset_gfx_gap_43_{version}.yaml"
asset_gfx_gap_158_build = f"{build_dir}/assets/asset_gfx_gap_158.bin"
asset_gfx_gap_158_asm = f"{build_dir}/asm/asset_gfx_gap_158.s"
asset_gfx_gap_158_unit = "asset_gfx_gap_158.s"
asset_gfx_gap_158_sym = {
    "us": "data_096FE36C",
    "jp": "data_096B6B48",
    "eu": "data_096CB6CC",
}[version]
asset_gfx_gap_158_extract = {
    "us": "assets/us/096FE36C-0984B838.bin",
    "jp": "assets/jp/096B6B48-0980034C.bin",
    "eu": "assets/eu/096CB6CC-0982820C.bin",
}[version]
asset_gfx_gap_158_manifest = f"config/asset_gfx_gap_158_{version}.yaml"
asset_gfx_gap_87_build = f"{build_dir}/assets/asset_gfx_gap_87.bin"
asset_gfx_gap_87_asm = f"{build_dir}/asm/asset_gfx_gap_87.s"
asset_gfx_gap_87_unit = "asset_gfx_gap_87_at_0961A9FD.s"
asset_gfx_gap_87_sym = {
    "us": "data_0961A9FD",
    "jp": "data_095D34D9",
    "eu": "data_095DBEDD",
}[version]
asset_gfx_gap_87_extract = {
    "us": "assets/us/0961A9FD-096FC004.bin",
    "jp": "assets/jp/095D34D9-096B47E0.bin",
    "eu": "assets/eu/095DBEDD-096C934C.bin",
}[version]
asset_gfx_gap_87_manifest = f"config/asset_gfx_gap_87_{version}.yaml"
if asset_gfx_mode == "built":
    Path(f"{build_dir}/asm").mkdir(parents=True, exist_ok=True)
    Path(asset_gfx_asm).write_text(
        "\t.section .rodata\n"
        f"\t.global {asset_gfx_sym}\n"
        f"{asset_gfx_sym}:\n"
        f'\t.incbin "{asset_gfx_build}"\n'
    )
    rewritten = []
    for src, obj, flags, section in units:
        if src is not None and src.name == asset_gfx_unit:
            rewritten.append((Path(asset_gfx_asm), obj, flags, section))
        else:
            rewritten.append((src, obj, flags, section))
    units = rewritten

if asset_gfx_gap_195_mode == "built":
    Path(f"{build_dir}/asm").mkdir(parents=True, exist_ok=True)
    Path(asset_gfx_gap_195_asm).write_text(
        "\t.section .rodata\n"
        f"\t.global {asset_gfx_gap_195_sym}\n"
        f"{asset_gfx_gap_195_sym}:\n"
        f'\t.incbin "{asset_gfx_gap_195_build}"\n'
    )
    rewritten = []
    for src, obj, flags, section in units:
        if src is not None and src.name == asset_gfx_gap_195_unit:
            rewritten.append((Path(asset_gfx_gap_195_asm), obj, flags, section))
        else:
            rewritten.append((src, obj, flags, section))
    units = rewritten

if asset_gfx_gap_1_mode == "built":
    Path(f"{build_dir}/asm").mkdir(parents=True, exist_ok=True)
    Path(asset_gfx_gap_1_asm).write_text(
        "\t.section .rodata\n"
        f"\t.global {asset_gfx_gap_1_sym}\n"
        f"{asset_gfx_gap_1_sym}:\n"
        f'\t.incbin "{asset_gfx_gap_1_build}"\n'
    )
    rewritten = []
    for src, obj, flags, section in units:
        if src is not None and src.name == asset_gfx_gap_1_unit:
            rewritten.append((Path(asset_gfx_gap_1_asm), obj, flags, section))
        else:
            rewritten.append((src, obj, flags, section))
    units = rewritten

if asset_gfx_gap_43_mode == "built":
    Path(f"{build_dir}/asm").mkdir(parents=True, exist_ok=True)
    Path(asset_gfx_gap_43_asm).write_text(
        "\t.section .rodata\n"
        f"\t.global {asset_gfx_gap_43_sym}\n"
        f"{asset_gfx_gap_43_sym}:\n"
        f'\t.incbin "{asset_gfx_gap_43_build}"\n'
    )
    rewritten = []
    for src, obj, flags, section in units:
        if src is not None and src.name == asset_gfx_gap_43_unit:
            rewritten.append((Path(asset_gfx_gap_43_asm), obj, flags, section))
        else:
            rewritten.append((src, obj, flags, section))
    units = rewritten

if asset_gfx_gap_158_mode == "built":
    Path(f"{build_dir}/asm").mkdir(parents=True, exist_ok=True)
    Path(asset_gfx_gap_158_asm).write_text(
        "\t.section .rodata\n"
        f"\t.global {asset_gfx_gap_158_sym}\n"
        f"{asset_gfx_gap_158_sym}:\n"
        f'\t.incbin "{asset_gfx_gap_158_build}"\n'
    )
    rewritten = []
    for src, obj, flags, section in units:
        if src is not None and src.name == asset_gfx_gap_158_unit:
            rewritten.append((Path(asset_gfx_gap_158_asm), obj, flags, section))
        else:
            rewritten.append((src, obj, flags, section))
    units = rewritten

if asset_gfx_gap_87_mode == "built":
    Path(f"{build_dir}/asm").mkdir(parents=True, exist_ok=True)
    Path(asset_gfx_gap_87_asm).write_text(
        "\t.section .rodata\n"
        f"\t.global {asset_gfx_gap_87_sym}\n"
        f"{asset_gfx_gap_87_sym}:\n"
        f'\t.incbin "{asset_gfx_gap_87_build}"\n'
    )
    rewritten = []
    for src, obj, flags, section in units:
        if src is not None and src.name == asset_gfx_gap_87_unit:
            rewritten.append((Path(asset_gfx_gap_87_asm), obj, flags, section))
        else:
            rewritten.append((src, obj, flags, section))
    units = rewritten

headers = sorted(str(p) for p in Path("include").glob("*.h"))
asm_includes = sorted(str(p) for p in Path("include").glob("*.inc"))
missing_assets = set()
edges = []
emitted = set()
for src, obj, flags, _section in units:
    if src is None or obj in emitted:
        continue
    emitted.add(obj)
    rule = "cc" if src.suffix == ".c" else "as"
    variables = {"cflags": f"-mthumb-interwork {flags}"} if flags else None
    deps = []
    if rule == "as":
        deps += asm_includes
        deps.extend(asm_file_deps(src, missing_assets))
    if rule == "cc":
        deps += headers
    if any(dep.startswith("assets/") for dep in deps):
        deps.append(assets_stamp)
    edges.append((obj, rule, src, deps, variables))
if asset_gfx_mode == "built":
    asset_gfx_obj_suffix = "/asset_gfx_at_084D4390.o" if version == "jp" else "/asset_gfx.o"
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
if asset_gfx_gap_195_mode == "built":
    patched = []
    for obj, rule, src, deps, variables in edges:
        if obj.endswith("/asset_gfx_gap_195.o"):
            deps = [d for d in deps if not d.startswith("assets/")]
            if asset_gfx_gap_195_build not in deps:
                deps.append(asset_gfx_gap_195_build)
            if asset_gfx_gap_195_asm not in deps:
                deps.append(asset_gfx_gap_195_asm)
        patched.append((obj, rule, src, deps, variables))
    edges = patched
    missing_assets.difference_update(
        p for p in list(missing_assets)
        if p.startswith("assets/") and Path(p).name == Path(asset_gfx_gap_195_extract).name
    )
if asset_gfx_gap_1_mode == "built":
    gap_1_obj_suffix = "/" + Path(asset_gfx_gap_1_unit).with_suffix(".o").name
    patched = []
    for obj, rule, src, deps, variables in edges:
        if obj.endswith(gap_1_obj_suffix):
            deps = [d for d in deps if not d.startswith("assets/")]
            if asset_gfx_gap_1_build not in deps:
                deps.append(asset_gfx_gap_1_build)
            if asset_gfx_gap_1_asm not in deps:
                deps.append(asset_gfx_gap_1_asm)
        patched.append((obj, rule, src, deps, variables))
    edges = patched
    missing_assets.difference_update(
        p for p in list(missing_assets)
        if p.startswith("assets/") and Path(p).name == Path(asset_gfx_gap_1_extract).name
    )

if asset_gfx_gap_43_mode == "built":
    gap_43_obj_suffix = "/" + Path(asset_gfx_gap_43_unit).with_suffix(".o").name
    patched = []
    for obj, rule, src, deps, variables in edges:
        if obj.endswith(gap_43_obj_suffix):
            deps = [d for d in deps if not d.startswith("assets/")]
            if asset_gfx_gap_43_build not in deps:
                deps.append(asset_gfx_gap_43_build)
            if asset_gfx_gap_43_asm not in deps:
                deps.append(asset_gfx_gap_43_asm)
        patched.append((obj, rule, src, deps, variables))
    edges = patched
    missing_assets.difference_update(
        p for p in list(missing_assets)
        if p.startswith("assets/") and Path(p).name == Path(asset_gfx_gap_43_extract).name
    )

if asset_gfx_gap_158_mode == "built":
    patched = []
    for obj, rule, src, deps, variables in edges:
        if obj.endswith("/asset_gfx_gap_158.o"):
            deps = [d for d in deps if not d.startswith("assets/")]
            if asset_gfx_gap_158_build not in deps:
                deps.append(asset_gfx_gap_158_build)
            if asset_gfx_gap_158_asm not in deps:
                deps.append(asset_gfx_gap_158_asm)
        patched.append((obj, rule, src, deps, variables))
    edges = patched
    missing_assets.difference_update(
        p for p in list(missing_assets)
        if p.startswith("assets/") and Path(p).name == Path(asset_gfx_gap_158_extract).name
    )

if asset_gfx_gap_87_mode == "built":
    gap_87_obj_suffix = "/" + Path(asset_gfx_gap_87_unit).with_suffix(".o").name
    patched = []
    for obj, rule, src, deps, variables in edges:
        if obj.endswith(gap_87_obj_suffix):
            deps = [d for d in deps if not d.startswith("assets/")]
            if asset_gfx_gap_87_build not in deps:
                deps.append(asset_gfx_gap_87_build)
            if asset_gfx_gap_87_asm not in deps:
                deps.append(asset_gfx_gap_87_asm)
        patched.append((obj, rule, src, deps, variables))
    edges = patched
    missing_assets.difference_update(
        p for p in list(missing_assets)
        if p.startswith("assets/") and Path(p).name == Path(asset_gfx_gap_87_extract).name
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
if asset_gfx_gap_195_mode == "built":
    allowed_build_assets.add(asset_gfx_gap_195_build)
if asset_gfx_gap_1_mode == "built":
    allowed_build_assets.add(asset_gfx_gap_1_build)
if asset_gfx_gap_43_mode == "built":
    allowed_build_assets.add(asset_gfx_gap_43_build)
if asset_gfx_gap_158_mode == "built":
    allowed_build_assets.add(asset_gfx_gap_158_build)
if asset_gfx_gap_87_mode == "built":
    allowed_build_assets.add(asset_gfx_gap_87_build)
pending_uncovered = [p for p in pending_build_assets if p not in allowed_build_assets]
if pending_uncovered:
    first = pending_uncovered[0]
    sys.exit(
        f"error: build asset {first} is missing; use --asset-gfx-mode=built "
        f"and/or --asset-gfx-gap-195-mode=built "
        f"and/or --asset-gfx-gap-1-mode=built "
        f"and/or --asset-gfx-gap-43-mode=built "
        f"and/or --asset-gfx-gap-158-mode=built "
        f"and/or --asset-gfx-gap-87-mode=built or extract slice assets"
    )

validate_active_sections(regional_plan,
                         [(src.name, section) for src, _obj, _flags, section in units if src is not None and src.suffix == ".c"],
                         managed_placements(regional))
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
        placement = regional_sections.get((Path(obj).stem + ".c", section)) if obj.startswith(f"{build_dir}/src/") else None
        if placement:
            for assertion in linker_assertions(placement):
                f.write(f"        {assertion}\n")
        f.write(f"        {obj}({section});\n")
        if placement:
            for assertion in linker_assertions(placement, after=True):
                f.write(f"        {assertion}\n")
    f.write("    }\n")
    if bss_members:
        f.write(f"\n    .bss {ARCHIVE_BSS[version]:#x} (NOLOAD) :\n    {{\n")
        for obj in bss_members:
            f.write(f"        {obj}(.bss);\n")
        f.write("    }\n")
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
        f"-mcpu=arm7tdmi -march=armv4t -mthumb-interwork -I . -I include",
    )
    n.variable("asdefines", f"--defsym VERSION_{version.upper()}=1")
    n.variable("cppflags", f"-nostdinc -undef -I include -I tools/agbcc/include -DVERSION_{version.upper()}")
    n.variable("cflags", "-mthumb-interwork -O2 -fprologue-bugfix")
    n.variable("pyreport", report_python)
    n.newline()

    n.rule(
        "as",
        command="$as $asflags $asdefines -o $out $in",
        description="AS $out",
    )
    n.rule(
        "cc",
        command="$cpp $cppflags -o $out.i $in && $agbcc $cflags -o $out.s $out.i && $as $asflags -o $out $out.s",
        description="CC $out",
    )
    n.rule(
        "ld",
        command="$ld -T $ldscript -Map $map -o $out $in" +
                (f" && {report_python} tools/regional_data.py {version} --binutils-prefix {prefix}" if regional_files else ""),
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
    if asset_gfx_gap_195_mode == "built":
        n.rule(
            "asset_gfx_gap_195_pack",
            command=f"python3 tools/gfx/asset_gfx_gap_195_pack.py --mode built --version {version} && test -f $out",
            description="ASSET_GFX_GAP_195 $out",
        )
    if asset_gfx_gap_1_mode == "built":
        n.rule(
            "asset_gfx_gap_1_pack",
            command=f"python3 tools/gfx/asset_gfx_gap_1_pack.py --mode built --version {version} && test -f $out",
            description="ASSET_GFX_GAP_1 $out",
        )
    if asset_gfx_gap_43_mode == "built":
        n.rule(
            "asset_gfx_gap_43_pack",
            command=f"python3 tools/gfx/asset_gfx_gap_43_pack.py --mode built --version {version} && test -f $out",
            description="ASSET_GFX_GAP_43 $out",
        )
    if asset_gfx_gap_158_mode == "built":
        n.rule(
            "asset_gfx_gap_158_pack",
            command=f"python3 tools/gfx/asset_gfx_gap_158_pack.py --mode built --version {version} && test -f $out",
            description="ASSET_GFX_GAP_158 $out",
        )
    if asset_gfx_gap_87_mode == "built":
        n.rule(
            "asset_gfx_gap_87_pack",
            command=f"python3 tools/gfx/asset_gfx_gap_87_pack.py --mode built --version {version} && test -f $out",
            description="ASSET_GFX_GAP_87 $out",
        )
    n.newline()

    objs = []
    for path, member, obj in archives:
        n.build(obj, "arx", implicit=[path],
                variables={"archive": path, "member": member})
        objs.append(obj)
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
    if asset_gfx_gap_195_mode == "built":
        n.build(
            asset_gfx_gap_195_build,
            "asset_gfx_gap_195_pack",
            implicit=[
                "tools/gfx/asset_gfx_gap_195_pack.py",
                "tools/gfx/asset_gfx_gap_195_layout.py",
                asset_gfx_gap_195_manifest,
                f"config/asset_inventory_{version}_gfx_gap_195.yaml",
                asset_gfx_gap_195_extract,
            ],
        )
    if asset_gfx_gap_1_mode == "built":
        n.build(
            asset_gfx_gap_1_build,
            "asset_gfx_gap_1_pack",
            implicit=[
                "tools/gfx/asset_gfx_gap_1_pack.py",
                "tools/gfx/asset_gfx_gap_1_layout.py",
                asset_gfx_gap_1_manifest,
                f"config/asset_inventory_{version}_gfx_gap_1.yaml",
                asset_gfx_gap_1_extract,
            ],
        )
    if asset_gfx_gap_43_mode == "built":
        n.build(
            asset_gfx_gap_43_build,
            "asset_gfx_gap_43_pack",
            implicit=[
                "tools/gfx/asset_gfx_gap_43_pack.py",
                "tools/gfx/asset_gfx_gap_43_layout.py",
                asset_gfx_gap_43_manifest,
                f"config/asset_inventory_{version}_gfx_gap_43.yaml",
                asset_gfx_gap_43_extract,
            ],
        )
    if asset_gfx_gap_158_mode == "built":
        n.build(
            asset_gfx_gap_158_build,
            "asset_gfx_gap_158_pack",
            implicit=[
                "tools/gfx/asset_gfx_gap_158_pack.py",
                "tools/gfx/asset_gfx_gap_158_layout.py",
                asset_gfx_gap_158_manifest,
                f"config/asset_inventory_{version}_gfx_gap_158.yaml",
                asset_gfx_gap_158_extract,
            ],
        )
    if asset_gfx_gap_87_mode == "built":
        n.build(
            asset_gfx_gap_87_build,
            "asset_gfx_gap_87_pack",
            implicit=[
                "tools/gfx/asset_gfx_gap_87_pack.py",
                "tools/gfx/asset_gfx_gap_87_layout.py",
                asset_gfx_gap_87_manifest,
                f"config/asset_inventory_{version}_gfx_gap_87.yaml",
                asset_gfx_gap_87_extract,
            ],
        )
    for obj, rule, src, deps, variables in edges:
        n.build(obj, rule, str(src), implicit=deps, variables=variables)
        objs.append(obj)
    n.newline()

    n.build(
        elf,
        "ld",
        objs,
        implicit=[ldscript] + (["tools/regional_data.py", "tools/rom_data_evidence.py"]
                              + [str(path) for path in regional_files] if regional_files else []),
        variables={"ldscript": ldscript, "map": mapfile},
    )
    n.build(rom, "rom", elf, implicit=["tools/gbafix.py"])
    n.build(f"{build_dir}/ok", "check", rom, implicit_outputs=[verified])
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
        (obj, src) for src, obj, _flags, _section in units
        if src is not None and src.suffix == ".c"
    ).items()
]
Path("compile_commands.json").write_text(json.dumps(compile_commands, indent=2) + "\n")

print(f"configured for {version} ({code}); run: ninja")
