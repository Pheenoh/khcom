#!/usr/bin/env python3
"""Generate a non-US version's build tree from the US one.

src/ is shared across versions, so every INCLUDE_ASM line in it has to
resolve for each version. This walks config/<version>/funcmap.txt (written
by tools/version_align.py) and emits, at that version's addresses:

  config/<version>/symbols.txt        globals, mapped through the pool words
                                      of instruction-identical function pairs
  asm/<version>/header.s, crt0.s      the pre-code region
  asm/<version>/nonmatchings/<tu>/    one incbin chunk per INCLUDE_ASM in src/
  asm/<version>/data.s, data2.s       the post-code region
  config/<version>/units.txt          the US link order

The chunks are incbins rather than disassembly: their job is to reproduce
the ROM's bytes at an address the link already fixes, and the readable
disassembly to decompile from lives on the US side. A chunk's extent comes
from the next function's address in this version, not from the US size, so
a function that is a different length here still tiles correctly.
"""

import argparse
import bisect
import re
import struct
from pathlib import Path

from rom_data_evidence import data_symbol_map, load_evidence
from movie_assets import apply_movie_regions, load_movie_assets
from function_pointer_evidence import literal_pointer_pairs, load_literal_loads, load_function_modes, trace_literal_loads
import assetgen
import baserom
from regional_data import asset_symbols, load_sidecars, managed_asset_names

ROM_BASE = 0x08000000
CODE_HI = 0x081213C4

VENEER_STUB = bytes((0x78, 0x47, 0xC0, 0x46))
VENEER_SIZE = 8
VENEER_NAMES = ("func_081213C4", "func_081213CC", "func_081213D4")


def veneer_labels(data):
    if len(data) != VENEER_SIZE * len(VENEER_NAMES):
        return None

    for i in range(len(VENEER_NAMES)):
        piece = data[i * VENEER_SIZE:(i + 1) * VENEER_SIZE]

        if piece[:4] != VENEER_STUB or piece[7] != 0xEA:
            return None
    return VENEER_NAMES


def validate_transform_veneers(rom, address, transform):
    size = VENEER_SIZE * len(VENEER_NAMES)
    if address < ROM_BASE or address + size > ROM_BASE + len(rom) or address % 4:
        raise ValueError('transform veneers are outside ROM or misaligned')
    data = rom[address - ROM_BASE:address - ROM_BASE + size]
    if veneer_labels(data) != VENEER_NAMES:
        raise ValueError('transform veneers have an unexpected instruction sequence')
    for index, offset in enumerate((0x134, 0, 0x1BC)):
        branch = struct.unpack_from('<I', data, index * VENEER_SIZE + 4)[0]
        displacement = branch & 0xFFFFFF
        if displacement & 0x800000:
            displacement -= 0x1000000
        target = address + index * VENEER_SIZE + 12 + displacement * 4
        if target != transform + offset:
            raise ValueError('transform veneer branch target differs from the native ARM entry')
    return size


def asset(ver, lo, hi):
    return f"assets/{ver}/{lo:08X}-{hi:08X}.bin"


def link_order(entries):
    order, position, anchor = [], {}, None
    for name, section in entries:
        if section == ".text":
            if name not in position:
                position[name] = len(order)
                order.append(name)
            continue
        if name in position:
            anchor = name
            continue
        index = len(order) if anchor is None else position[anchor] + 1
        order.insert(index, name)
        position = {o: i for i, o in enumerate(order)}
        anchor = name
    return order


def blob_source(ver, lo, hi, data):
    head = f'\t.section .rodata\n\t.global data_{lo:08X}\ndata_{lo:08X}:\n'
    names = veneer_labels(data)

    if not names:
        return head + f'\t.incbin "{asset(ver, lo, hi)}"\n'
    body = ""

    for i, name in enumerate(names):
        at = lo + i * VENEER_SIZE
        body += (f'\t.thumb_func\n\t.global {name}\n{name}:\n'
                 f'\t.incbin "{asset(ver, at, at + VENEER_SIZE)}"\n')
    return head + body

TRUSTED = ("named", "xref", "global", "body", "fill", "near", "match")

TARGET_ANCHORS = {
    "eu": {
        0x08f7f66c: 0x0905984c,
        0x08fbd378: 0x0908282c,
        0x09007134: 0x090b2510,
        0x0902fce8: 0x090c9044,
        0x09ED9BA8: 0x09F57460,
        0x09EE3844: 0x09F6EF64,
        0x09EE1520: 0x09F5C0EC,
        0x0813B67C: 0x08889B50,
        0x08135EFC: 0x088843D0,
        0x09A10A3C: 0x09A60380,
        0x099A2B62: 0x099AF866,
        0x099A36F8: 0x099B167C,
        0x09EF99D0: 0x09F8563C,
        0x09EF99A8: 0x09F85614,
        0x088C56C6: 0x088F0FEA,
        0x09A03CFC: 0x09A42400,
        0x0999E69E: 0x099A9E42,
        0x09EF9858: 0x09F85444,
        0x09EF9830: 0x09F8541C,
        0x0815C3EC: 0x0812FB24,
        0x084E0F34: 0x084B466C,
        0x084F4660: 0x084C7D98,
        0x0855CCB4: 0x085303EC,
        0x086FBA14: 0x086CF14C,
        0x0886AD10: 0x0883F2C8,
        0x08C6A6A4: 0x08C9BD78,
        0x08C6A69A: 0x08C9BD6E,
        0x08C6A878: 0x08C9C274,
        0x09A36EDC: 0x09A89EA0,
        0x09A373DC: 0x09A8A3A0,
        0x09402F78: 0x094DCCE4,
        0x09041E80: 0x090D1DC0,
        0x095152B8: 0x09537B24,
        0x0951534C: 0x09537BB8,
        0x095172B8: 0x09534324,
        0x09517AB8: 0x09534B24,
        0x09519AB8: 0x09538324,
        0x0951A2B8: 0x09538B24,
        0x0951AAB8: 0x09539324,
        0x02034890: 0x02034898,
        0x08C6A51C: 0x08C9C100,
        0x08C6A526: 0x08C9C10A,
        0x08F7CF18: 0x08F8DE14,
        0x0976DB68: 0x0973BA18,
        0x0976DB9C: 0x0973BA4C,
        0x09ED77D4: 0x09F476C8,
        0x09ED82D4: 0x09F481C8,
        0x08130E6C: 0x0887F340,
        0x0976D8A6: 0x097385B0,
        0x0976DBDA: 0x0973BA8A,
        0x092EB78A: 0x093BAE12,
        0x09958124: 0x0994AFB0,
        0x09EE1538: 0x09F5C140,
        0x0951B2B8: 0x09539B24,
        0x09512AB8: 0x09532B24,
        0x095192B8: 0x09537324,
        0x095182B8: 0x09535B24,
        0x09514AB8: 0x09536B24,
        0x090356EC: 0x090CE9FE,
        0x090356F2: 0x090CEA04,
        0x090A4664: 0x09193560,
        0x09EEB000: 0x09F77120,
        0x09EEB008: 0x09F77128,
        0x09D2B334: 0x09D9ABE0,
        0x09EEB03C: 0x09F7715C,
        0x09035730: 0x090CEA44,
        0x096B2664: 0x09677C0C,
        0x09C5CC7C: 0x09CE23B0,
        0x09EFAF60: 0x09F87494,
        0x09EFAF6C: 0x09F874A0,
        0x020354A8: 0x02035938,
        0x020354B0: 0x02035940,
        0x09A324DC: 0x09A854A0,
        0x097DB5F8: 0x097B1D00,
        0x09841798: 0x09815E40,
        0x09A123DC: 0x09A62840,
        0x09A18EBC: 0x09A69320,
        0x09ED9B88: 0x09F49A8C,
        0x09EE78A4: 0x09F72CD8,
        0x09EF4F08: 0x09F802B0,
        0x096AD744: 0x0967818C,
        0x097A28DA: 0x09780322,
        0x09EF6934: 0x09F81FB0,
        0x098A8C66: 0x0988740A,
        0x08B1EB1C: 0x08B4A42C,
        0x08F61B84: 0x08F5C0DC,
        0x08F60B84: 0x08F5B8DC,
        0x08C6A88C: 0x08C9C288,
        0x08C6A54E: 0x08C9C132,
        0x08C6A6B8: 0x08C9BDC0,
        0x08C6A958: 0x08C9C354,
        0x09EE2678: 0x09F5D4C0,
        0x09EE2668: 0x09F5D4B0,
        0x09EEA1EC: 0x09F76024,
        0x099930E8: 0x09999398,
        0x09A3641C: 0x09A88EE0,
        0x09A3691C: 0x09A893E0,
        0x0999FA20: 0x099AB1C4,
        0x099A012C: 0x099AB8D0,
        0x09EF9898: 0x09F85484,
        0x09EF9870: 0x09F8545C,
        0x09EF98B0: 0x09F8549C,
        0x09EF98A0: 0x09F8548C,
        0x091CF5D4: 0x0929EC5C,
        0x096B2124: 0x096776CC,
        0x096F8464: 0x096BF98C,
        0x096F8C64: 0x096C018C,
        0x09EE42C8: 0x09F6F57C,
        0x020354A0: 0x02035930,
        0x020352B8: 0x02035568,
        0x090A7D9A: 0x09198606,
        0x090A6B26: 0x09197392,
        0x09EEB108: 0x09F77298,
        0x09EEB0C4: 0x09F77254,
        0x09EEB14C: 0x09F772DC,
        0x09EEB11C: 0x09F772AC,
        0x090A7F0A: 0x09198776,
        0x090A8FC4: 0x09199830,
        0x09EEB180: 0x09F77310,
        0x09EEB150: 0x09F772E0,
        0x09ED9B78: 0x09F49A7C,
        0x0815A09A: 0x088912C8,
        0x0815A198: 0x088912F0,
        0x0815A0EE: 0x08891318,
        0x0815A152: 0x08891340,
        0x0815A0A0: 0x088912A0,
        0x09613E98: 0x09546D84,
        0x09EE7F60: 0x09F733BC,
        0x09EE7F90: 0x09F733EC,
        0x09035898: 0x090CEB78,
        0x090358D0: 0x090CEBB8,
        0x0951C2B8: 0x0953BB24,
        0x09035874: 0x090CEB3A,
        0x09EE7F48: 0x09F733A4,
        0x09EE7F30: 0x09F7338C,
        0x09EE790C: 0x09F72D6C,
        0x09037FB4: 0x090D1354,
        0x090950F4: 0x0916C228,
        0x09091D36: 0x09168E6A,
        0x095112B8: 0x09531224,
        0x09EE78D4: 0x09F72D58,
        0x09EE78F0: 0x09F72D58,
        0x09EE7914: 0x09F72D74,
        0x09613EB8: 0x09546DA4,
        0x09613ED8: 0x09546DC4,
        0x09613F18: 0x09546E04,
        0x09613F38: 0x09546E24,
        0x09EEA1BC: 0x09F72D30,
        0x0950F2B8: 0x09532624,
        0x099930BC: 0x0999936C,
        0x0999CFC6: 0x099A42AA,
        0x0999D41A: 0x099A46FE,
        0x0999D8A8: 0x099A4B8C,
        0x099FB53C: 0x09A24480,
        0x09A32EDC: 0x09A859A0,
        0x09A333DC: 0x09A85EA0,
        0x09A3399C: 0x09A86460,
        0x09A33E9C: 0x09A86960,
        0x09EF97B0: 0x09F8524C,
        0x09EF97C4: 0x09F85260,
        0x09EF97CC: 0x09F85268,
        0x09EF97DC: 0x09F85278,
        0x08155C54: 0x0887B6AC,
        0x0815600C: 0x0887BA20,
        0x0815631C: 0x0887BCF8,
        0x081564A4: 0x0887BE64,
        0x0815662C: 0x0887BFD0,
        0x081570E4: 0x0887C9C4,
        0x08157694: 0x0887CF0C,
        0x08157B9C: 0x0887D3B8,
        0x08158114: 0x0887D8CC,
        0x081589D4: 0x0887E0EC,
        0x08155B04: 0x0887B574,
        0x081576CC: 0x0887CF40,
        0x0815917C: 0x0887E808,
        0x0815948C: 0x0887EAE0,
        0x081595DC: 0x0887EC18,
        0x08F64384: 0x08F5A8DC,
        0x08F60384: 0x08F610DC,
        0x08F5EB84: 0x08F5E0DC,
        0x08F63384: 0x08F5F8DC,
        0x08F5FB84: 0x08F5F0DC,
        0x08F63B84: 0x08F600DC,
        0x08F64B84: 0x08F5B0DC,
        0x08EE78E4: 0x08EF7E3C,
        0x08C6A530: 0x08C9C114,
        0x08C6A53A: 0x08C9C11E,
        0x095142B8: 0x09535324,
        0x08B25ADE: 0x08B506CE,
        0x09041EB4: 0x090D1DFE,
        0x09041EBA: 0x090D1E04,
        0x09041EEE: 0x090D1E38,
        0x090A44C4: 0x091933C0,
        0x0961A9C8: 0x095DBEA8,
        0x0961A9CC: 0x095DBEAC,
        0x0961A9E8: 0x095DBEC8,
        0x09045188: 0x090D1F98,
        0x090352F4: 0x090CE5E8,
        0x090352FC: 0x090CE5F0,
        0x09511AB8: 0x09531724,
        0x095122B8: 0x09531C24,
        0x08F7DB10: 0x09057CF0,
        0x08F7DB40: 0x09057D20,
        0x08F7DC60: 0x09057E40,
        0x08F7DCF0: 0x09057ED0,
        0x08F7DD20: 0x09057F00,
        0x08F7DD50: 0x09057F30,
        0x08F7DD80: 0x09057F60,
        0x096194B0: 0x095DA8C4,
        0x096193B8: 0x095DA818,
        0x090451A0: 0x090D1FC0,
        0x09EE9190: 0x09F74610,
        0x09045158: 0x090D1F68,
        0x09EE9170: 0x09F745E0,
        0x09041F64: 0x090D1E4C,
        0x09EE8F20: 0x09F743A0,
        0x09041EF8: 0x090D1E40,
        0x09EE8EF0: 0x09F7434C,
        0x09041F48: 0x090D1E4C,
        0x09EE8F08: 0x09F743A0,
        0x09041EA4: 0x090D1DE4,
        0x09EE8E60: 0x09F742BC,
        0x09041E90: 0x090D1DD0,
        0x09EE8E30: 0x09F7428C,
        0x09041E78: 0x090D1DB8,
        0x09EE8008: 0x09F73478,
        0x0903C00C: 0x090D1888,
        0x09041E7F: 0x090D76FB,
        0x0903BFFC: 0x090D1878,
        0x0903BFEC: 0x090D1868,
        0x09EE7D84: 0x09F73238,
        0x09EE79EC: 0x09F72EC0,
        0x090381E8: 0x090D1588,
        0x09EE79B4: 0x09F72E88,
        0x09038024: 0x090D13C4,
        0x09EE7968: 0x09F72E3C,
        0x09037FE4: 0x090D1384,
        0x09EE78D4: 0x09F72D08,
        0x09037F90: 0x090D130C,
        0x09EE7894: 0x09F72CA0,
        0x090362D4: 0x090CF650,
        0x09EE7834: 0x09F72C40,
        0x09036294: 0x090CF638,
        0x09EE781C: 0x09F72C28,
        0x09036230: 0x090CF5D4,
        0x09EE778C: 0x09F72B84,
        0x090361C8: 0x090CF56C,
        0x09EE7698: 0x09F72A90,
        0x0903614C: 0x090CF4F0,
        0x09EE75F0: 0x09F729AC,
        0x090359F0: 0x090CED98,
        0x09EE75D8: 0x09F72994,
        0x090359BC: 0x090CED58,
        0x09EE4BA0: 0x09F6FF20,
        0x090359A0: 0x090CED3C,
        0x09EE4B40: 0x09F6FEC0,
        0x0903596C: 0x090CED08,
        0x09EE4B28: 0x09F6FEA8,
        0x09035738: 0x090CEA4C,
        0x09EE4A68: 0x09F6FD14,
        0x09035348: 0x090CE63C,
        0x09EE4A2C: 0x09F6FCD8,
        0x09035314: 0x090CE608,
        0x09EE49B4: 0x09F6FC60,
        0x09034060: 0x090CD354,
        0x09EE496C: 0x09F6FC18,
    },
    "jp": {
        0x08f7f66c: 0x08f72b74,
        0x08fbd378: 0x08fa6a14,
        0x09007134: 0x08fe380c,
        0x0902fce8: 0x09002fac,
        0x09079EB2: 0x09033FA2,
        0x09080074: 0x0903AE74,
        0x090822F2: 0x0903D494,
        0x09086C1C: 0x09042084,
        0x09087DD2: 0x09043374,
        0x09089C16: 0x090453C8,
        0x0908A958: 0x090461C8,
        0x0908AF32: 0x090467A2,
        0x0813B67C: 0x0813B6F8,
        0x08135EFC: 0x08135F78,
        0x0999E69E: 0x09953126,
        0x09C8D47A: 0x09C678B4,
        0x09C8F1FA: 0x09C68CC6,
        0x09EFBAD4: 0x09ED304C,
        0x0999D9C0: 0x0995248C,
        0x0999D9CA: 0x09952496,
        0x0999D9E6: 0x099524AC,
        0x0999DA1A: 0x099524E0,
        0x0999D41A: 0x09951EE6,
        0x0999D8A8: 0x09952374,
        0x0815A09A: 0x0814EF38,
        0x0815A198: 0x0814EF40,
        0x0815A0EE: 0x0814EF48,
        0x0815A152: 0x0814EF50,
        0x0815A0A0: 0x0814EF2C,
        0x09417438: 0x093CB694,
        0x09418438: 0x093CD694,
        0x09419438: 0x093CF694,
        0x09035808: 0x09008CA4,
        0x09035874: 0x09008D10,
        0x09035898: 0x09008D34,
        0x090358D0: 0x09008D6C,
        0x08EE78E4: 0x08EDADEC,
        0x095142B8: 0x094CBD94,
        0x090352F4: 0x090085B8,
        0x090352FC: 0x090085C0,
        0x0815A066: 0x0814EC80,
        0x0815A0BA: 0x0814EC8C,
        0x0815B1D2: 0x0814EC98,
        0x0815A078: 0x0814ECA4,
        0x0815A0CC: 0x0814ECC0,
        0x0815B1A8: 0x0814EF58,
        0x0815A116: 0x0814EEB8,
        0x0815A158: 0x0814EEC8,
        0x0815A0F4: 0x0814EED8,
        0x0815A130: 0x0814EEF4,
        0x0815A176: 0x0814EF10,
        0x090451A0: 0x09012048,
        0x09EE9190: 0x09EC07D4,
        0x09045158: 0x09012000,
        0x09EE9170: 0x09EC07B4,
        0x09041F64: 0x090105A4,
        0x09EE8F20: 0x09EC0564,
        0x09041F48: 0x09010588,
        0x09EE8F08: 0x09EC054C,
        0x09041EF8: 0x09010538,
        0x09EE8EF0: 0x09EC0534,
        0x09041EA4: 0x090104E4,
        0x09EE8E60: 0x09EC04A4,
        0x09041E90: 0x090104D0,
        0x09EE8E30: 0x09EC0474,
        0x09041E78: 0x090104B8,
        0x09EE8008: 0x09EBF64C,
        0x0903C00C: 0x0900D490,
        0x09EE7F60: 0x09EBF5A4,
        0x0903BFFC: 0x0900D480,
        0x09EE7F48: 0x09EBF58C,
        0x0903BFEC: 0x0900D474,
        0x09EE7D84: 0x09EBF3C8,
        0x09EE79EC: 0x09EBF044,
        0x090381E8: 0x0900B674,
        0x09EE79B4: 0x09EBF00C,
        0x09038024: 0x0900B4B0,
        0x09EE7968: 0x09EBEFC0,
        0x09037FE4: 0x0900B470,
        0x09EE78D4: 0x09EBEF2C,
        0x09037F90: 0x0900B41C,
        0x09EE7894: 0x09EBEEEC,
        0x090362D4: 0x09009760,
        0x09EE7834: 0x09EBEE8C,
        0x09036294: 0x09009738,
        0x09EE781C: 0x09EBEE74,
        0x09036230: 0x090096D4,
        0x09EE778C: 0x09EBEDE4,
        0x090361C8: 0x0900966C,
        0x09EE7698: 0x09EBECF0,
        0x0903614C: 0x090095F0,
        0x09EE75F0: 0x09EBEC48,
        0x090359F0: 0x09008E94,
        0x09EE75D8: 0x09EBEC30,
        0x090359BC: 0x09008E60,
        0x09EE4BA0: 0x09EBC1F8,
        0x090359A0: 0x09008E44,
        0x09EE4B40: 0x09EBC198,
        0x0903596C: 0x09008E10,
        0x09EE4B28: 0x09EBC180,
        0x09035738: 0x09008A20,
        0x09EE4A68: 0x09EBC088,
        0x09035348: 0x0900860C,
        0x09EE4A2C: 0x09EBC04C,
        0x09035314: 0x090085D8,
        0x09EE49B4: 0x09EBBFD4,
        0x09034060: 0x09007324,
        0x09EE496C: 0x09EBBF8C,
    },
}

TARGET_ABSENT_SYMBOLS = {
    "eu": {
        "gUnk_09C5D922",
        "gUnk_09C5DD46",
        "gUnk_09C5E15E",
        "gUnk_09C5E6E6",
        "gUnk_09C5EB5E",
        "gUnk_09C5F12C",
        "gUnk_09C5F678",
        "gUnk_09C5FC54",
        "gUnk_09C6000A",
        "gUnk_09C60662",
        "gUnk_09C60F20",
        "gUnk_09C61676",
        "gUnk_09C6259C",
        "gUnk_09C62CC8",
        "gUnk_09C63244",
        "gUnk_09C853DA",
        "gUnk_09C85EDE",
        "gUnk_09C865FC",
        "gUnk_09C86C68",
        "gUnk_09C872D4",
        "gUnk_099F4D3C",
        "gUnk_099F553C",
        "gUnk_099F5D3C",
        "gUnk_099F653C",
        "gUnk_099F6D3C",
        "gUnk_099F753C",
        "gUnk_099F7D3C",
        "gUnk_099F853C",
        "gUnk_099F8D3C",
        "gUnk_099F953C",
        "gUnk_099F9D3C",
        "gUnk_099FA53C",
        "gUnk_099FAD3C",
        "gUnk_09079EB2",
        "gUnk_09080074",
        "gUnk_090822F2",
        "gUnk_09086C1C",
        "gUnk_09087DD2",
        "gUnk_09089C16",
        "gUnk_0908A958",
        "gUnk_0908AF32",
        "gUnk_090AA3C4",
        "gUnk_090AA3CE",
        "gUnk_090AA3D8",
        "gUnk_090AA3E2",
        "gUnk_090AA3EC",
        "gUnk_090AA3F6",
        "gUnk_090AA400",
        "gUnk_090AA40A",
        "gUnk_090AA414",
        "gUnk_090AA41E",
        "gUnk_090AA428",
        "gUnk_090AA438",
        "gUnk_090AA442",
        "gUnk_090AA452",
        "gUnk_090AA45C",
        "gUnk_090AA466",
        "gUnk_090AA470",
        "gUnk_090AA47A",
        "gUnk_090AA484",
        "gUnk_090AA48E",
        "gUnk_090AA498",
        "gUnk_090AA4A2",
        "gUnk_090AA4AC",
        "gUnk_090AA4B6",
        "gUnk_090AA4C0",
        "gUnk_090AA4CA",
        "gUnk_090AA4D4",
        "gUnk_090AA4DE",
        "gUnk_090AA4E8",
        "gUnk_090AA4F2",
        "gUnk_090B35B4",
        "gUnk_090B35BE",
        "gUnk_090B35C8",
        "gUnk_090B35D2",
        "gUnk_090B35DC",
        "gUnk_090B35E6",
        "gUnk_090B35F0",
        "gUnk_090B35FA",
        "gUnk_090B3604",
        "gUnk_090B360E",
        "gUnk_090B3618",
        "gUnk_090B3622",
        "gUnk_090B362C",
        "gUnk_090B3636",
        "gUnk_090B3640",
        "gUnk_090B364A",
        "gUnk_090B3654",
        "gUnk_090B365E",
        "gUnk_090B3668",
        "gUnk_090B3672",
        "gUnk_090B367C",
        "gUnk_090B3686",
        "gUnk_090B3690",
        "gUnk_090B369A",
        "gUnk_090B36A4",
        "gUnk_090B36AE",
        "gUnk_090B36B8",
        "gUnk_090B36C2",
        "gUnk_090B36CC",
        "gUnk_090B36D6",
        "gUnk_090B36E0",
        "gUnk_090B36EA",
        "gUnk_090B36F4",
        "gUnk_090B36FE",
        "gUnk_090B3708",
        "gUnk_090B3712",
        "gUnk_090B371C",
        "gUnk_090B3726",
        "gUnk_090B3730",
        "gUnk_090B373A",
        "gUnk_090B3744",
        "gUnk_090B374E",
        "gUnk_090B3758",
        "gUnk_090B3762",
        "gUnk_090B376C",
        "gUnk_090B3776",
        "gUnk_090B3780",
        "gUnk_090B378A",
        "gUnk_090B3794",
        "gUnk_090B379E",
        "gUnk_090B37A8",
        "gUnk_090B37B2",
        "gUnk_090B37BC",
        "gUnk_090B37C6",
        "gUnk_090B37D0",
        "gUnk_090B37DA",
        "gUnk_090B37E4",
        "gUnk_090B37EE",
        "gUnk_090B37F8",
        "gUnk_090B3802",
        "gUnk_090B380C",
        "gUnk_090B3816",
        "gUnk_090B3820",
        "gUnk_090B382A",
        "gUnk_090B3834",
        "gUnk_090B383E",
        "gUnk_090B3848",
        "gUnk_090B3852",
        "gUnk_090B385C",
        "gUnk_090B3866",
        "gUnk_090B3870",
        "gUnk_090B387A",
        "gUnk_090B3884",
        "gUnk_090B388E",
        "gUnk_090B3898",
        "gUnk_090B38A2",
        "gUnk_090B38AC",
        "gUnk_090B38B6",
        "gUnk_090B38C0",
        "gUnk_090B38CA",
        "gUnk_090B38D4",
        "gUnk_090B38DE",
        "gUnk_090B38E8",
        "gUnk_090B38F2",
        "gUnk_090B38FC",
        "gUnk_090B3906",
        "gUnk_090B3910",
        "gUnk_090B391A",
        "gUnk_090B3924",
        "gUnk_090B392E",
        "gUnk_090B3938",
        "gUnk_090B3942",
        "gUnk_090B394C",
        "gUnk_090B3956",
        "gUnk_090B3960",
        "gUnk_090B396A",
        "gUnk_090B3974",
        "gUnk_090B397E",
        "gUnk_090B3988",
        "gUnk_090B3992",
        "gUnk_090B399C",
        "gUnk_090B39A6",
        "gUnk_090B39B0",
        "gUnk_090B39BA",
        "gUnk_090B39C4",
        "gUnk_090B39CE",
        "gUnk_090B39D8",
        "gUnk_090B39E2",
        "gUnk_090B39EC",
        "gUnk_090B39F6",
        "gUnk_090B3A00",
        "gUnk_090B3A0A",
        "gUnk_090B3A14",
        "gUnk_090B3A1E",
        "gUnk_090B3A28",
        "gUnk_090B3A32",
        "gUnk_090B3A3C",
        "gUnk_090B3A46",
        "gUnk_090B3A50",
        "gUnk_090B3A5A",
        "gUnk_090B3A64",
        "gUnk_090B3A6E",
        "gUnk_090B3A78",
        "gUnk_090B3A82",
        "gUnk_090B3A8C",
        "gUnk_090B3A96",
        "gUnk_090B3AA0",
        "gUnk_090B3AAA",
        "gUnk_090B3AB4",
        "gUnk_090B3ABE",
        "gUnk_090B3AC8",
        "gUnk_090B3AD2",
        "gUnk_090B3ADC",
        "gUnk_090B3AE6",
        "gUnk_090B3AF0",
        "gUnk_090B3AFA",
        "gUnk_090B3B04",
        "gUnk_090B3B0E",
        "gUnk_090B3B18",
        "gUnk_090B3B22",
        "gUnk_090B3B2C",
        "gUnk_090B3B36",
        "gUnk_090B3B40",
        "gUnk_090B3B4A",
        "gUnk_090B3B54",
        "gUnk_090B3B5E",
        "gUnk_090B3B68",
        "gUnk_090B3B72",
        "gUnk_090B3B7C",
        "gUnk_090B3B86",
        "gUnk_090B3B90",
        "gUnk_090B3B9A",
        "gUnk_090B3BA4",
        "gUnk_090B3BAE",
        "gUnk_090B3BB8",
        "gUnk_090B3BC2",
        "gUnk_090B3BCC",
        "gUnk_090B3BD6",
        "gUnk_090B3BE0",
        "gUnk_090B3BEA",
        "gUnk_090B3BF4",
        "gUnk_090B3BFE",
        "gUnk_090B3C08",
        "gUnk_090B3C12",
        "gUnk_090B3C1C",
        "gUnk_090B3C26",
        "gUnk_090B3C30",
        "gUnk_090B3C3A",
        "gUnk_090B3C44",
        "gUnk_090B3C4E",
        "gUnk_090B3C58",
        "gUnk_090B3C62",
        "gUnk_090B3C6C",
        "gUnk_090B3C76",
        "gUnk_090B3C80",
        "gUnk_090B3C8A",
        "gUnk_090B3C94",
        "gUnk_090B3C9E",
        "gUnk_090B3CA8",
        "gUnk_090B3CB2",
        "gUnk_090B3CBC",
        "gUnk_090B3CC6",
        "gUnk_090B3CD0",
        "gUnk_090B3CDA",
        "gUnk_090B3CE4",
        "gUnk_090B3CEE",
        "gUnk_090B3CF8",
        "gUnk_090B3D02",
        "gUnk_090B3D0C",
        "gUnk_090B3D16",
        "gUnk_090B3D20",
        "gUnk_090B3D2A",
        "gUnk_090B3D34",
        "gUnk_090B3D3E",
        "gUnk_090B3D48",
        "gUnk_090B3D52",
        "gUnk_090B3D5C",
        "gUnk_090B3D66",
        "gUnk_090B3D70",
        "gUnk_090B3D7A",
        "gUnk_090B3D84",
        "gUnk_090B3D8E",
        "gUnk_090B3D98",
        "gUnk_090B3DA2",
        "gUnk_090B3DAC",
        "gUnk_090B3DB6",
        "gUnk_090B3DC0",
        "gUnk_090B3DCA",
        "gUnk_090B3DD4",
        "gUnk_090B3DDE",
        "gUnk_090B3DE8",
        "gUnk_090B3DF2",
        "gUnk_090B3DFC",
        "gUnk_090B3E06",
        "gUnk_090B3E10",
        "gUnk_090B3E1A",
        "gUnk_090B3E24",
        "gUnk_090B3E2E",
        "gUnk_090B3E38",
        "gUnk_090B3E42",
        "gUnk_090B3E4C",
        "gUnk_090B3E56",
        "gUnk_090B3E60",
        "gUnk_090B3E6A",
        "gUnk_090B3E74",
        "gUnk_090B3E7E",
        "gUnk_090B3E88",
        "gUnk_090B3E92",
        "gUnk_090B3E9C",
        "gUnk_090B3EA6",
        "gUnk_090B3EB0",
        "gUnk_090B3EBA",
        "gUnk_090B3EC4",
        "gUnk_090B3ECE",
        "gUnk_090B3ED8",
        "gUnk_090B3EE2",
        "gUnk_090B3EEC",
        "gUnk_090B3EF6",
        "gUnk_090B3F00",
        "gUnk_090B3F0A",
        "gUnk_090B3F14",
        "gUnk_090B3F1E",
        "gUnk_090B3F28",
        "gUnk_090B3F32",
        "gUnk_090B3F3C",
        "gUnk_090B3F46",
        "gUnk_090B3F50",
        "gUnk_090B3F5A",
        "gUnk_090B3F64",
        "gUnk_090B3F6E",
        "gUnk_090B3F78",
        "gUnk_090B3F82",
        "gUnk_090B3F8C",
        "gUnk_090B3F96",
        "gUnk_090B3FA0",
        "gUnk_090B3FAA",
        "gUnk_090BBFC0",
        "gUnk_090BBFCA",
        "gUnk_090BBFD4",
        "gUnk_090BBFDE",
        "gUnk_090BBFE8",
        "gUnk_090BBFF2",
        "gUnk_090BBFFC",
        "gUnk_090BC006",
        "gUnk_090BC010",
        "gUnk_090BC01A",
        "gUnk_090BC024",
        "gUnk_090BC02E",
        "gUnk_090BC038",
        "gUnk_090BC042",
        "gUnk_090BC04C",
        "gUnk_090BC056",
        "gUnk_090BC060",
        "gUnk_090BC06A",
        "gUnk_090BC074",
        "gUnk_090BC07E",
        "gUnk_090BC088",
        "gUnk_090BC092",
        "gUnk_090BC09C",
        "gUnk_090BC0A6",
        "gUnk_090BC0B0",
        "gUnk_090BC0BA",
        "gUnk_090BC0C4",
        "gUnk_090BC0CE",
        "gUnk_090BC0D8",
        "gUnk_090BC0E2",
        "gUnk_090BC0EC",
        "gUnk_090BC0F6",
        "gUnk_090BC100",
        "gUnk_090BC10A",
        "gUnk_090BC114",
        "gUnk_090BC11E",
        "gUnk_090BC128",
        "gUnk_090BC132",
        "gUnk_090BC13C",
        "gUnk_090BC146",
        "gUnk_090BC150",
        "gUnk_090BC15A",
        "gUnk_090BC164",
        "gUnk_090BC16E",
        "gUnk_090BC178",
        "gUnk_090BC182",
        "gUnk_090BC18C",
        "gUnk_090BC196",
        "gUnk_090BC1A0",
        "gUnk_090BC1AA",
        "gUnk_090BC1B4",
        "gUnk_090BC1BE",
        "gUnk_090BC1C8",
        "gUnk_090BC1D2",
        "gUnk_090BC1DC",
        "gUnk_090BC1E6",
        "gUnk_090BC1F0",
        "gUnk_090BC1FA",
        "gUnk_090BC204",
        "gUnk_090BC20E",
        "gUnk_090BC218",
        "gUnk_090BC222",
        "gUnk_090BC22C",
        "gUnk_090BC236",
        "gUnk_090BC240",
        "gUnk_090BC24A",
        "gUnk_090BC254",
        "gUnk_090BC25E",
        "gUnk_090BC268",
        "gUnk_090BC272",
        "gUnk_090BC27C",
        "gUnk_090BC286",
        "gUnk_090BC290",
        "gUnk_090BC29A",
        "gUnk_090BC2A4",
        "gUnk_090BC2AE",
        "gUnk_090BC2B8",
        "gUnk_090BC2C2",
        "gUnk_090BC2CC",
        "gUnk_090BC2D6",
        "gUnk_090BC2E0",
        "gUnk_090BC2EA",
        "gUnk_090BC2F4",
        "gUnk_090BC2FE",
        "gUnk_090BC308",
        "gUnk_090BC312",
        "gUnk_090BC31C",
        "gUnk_090BC326",
        "gUnk_090BC330",
        "gUnk_090BC33A",
        "gUnk_090BC344",
        "gUnk_090BC34E",
        "gUnk_090BC358",
        "gUnk_090BC362",
        "gUnk_090BC36C",
        "gUnk_090BC376",
        "gUnk_090BC380",
        "gUnk_090BC38A",
        "gUnk_090BC394",
        "gUnk_090BC39E",
        "gUnk_090BC3A8",
        "gUnk_090BC3B2",
        "gUnk_090BC3BC",
        "gUnk_090BC3C6",
        "gUnk_090BC3D0",
        "gUnk_090BC3DA",
        "gUnk_090BC3E4",
        "gUnk_090BC3EE",
        "gUnk_090BC3F8",
        "gUnk_090BC402",
        "gUnk_090BC40C",
        "gUnk_090BC416",
        "gUnk_090BC420",
        "gUnk_090BC42A",
        "gUnk_090BC434",
        "gUnk_090BC43E",
        "gUnk_090BC448",
        "gUnk_090BC452",
        "gUnk_090BC45C",
        "gUnk_090BC466",
        "gUnk_090BC470",
        "gUnk_090BC47A",
        "gUnk_090BC484",
        "gUnk_090BC48E",
        "gUnk_090BC498",
        "gUnk_090BC4A2",
        "gUnk_090BC4AC",
        "gUnk_090BC4B6",
        "gUnk_090BC4C0",
        "gUnk_090BC4CA",
        "gUnk_090BC4D4",
        "gUnk_090BC4DE",
        "gUnk_090BC4E8",
        "gUnk_090BC4F2",
        "gUnk_090BC4FC",
        "gUnk_090BC506",
        "gUnk_090BC510",
        "gUnk_090BC51A",
        "gUnk_090BC524",
        "gUnk_090BC52E",
        "gUnk_090BC538",
        "gUnk_090BC542",
        "gUnk_090BC54C",
        "gUnk_090BC556",
        "gUnk_090BC560",
        "gUnk_090BC56A",
        "gUnk_090BC574",
        "gUnk_090BC57E",
        "gUnk_090BC588",
        "gUnk_090BC592",
        "gUnk_090BC59C",
        "gUnk_090BC5A6",
        "gUnk_090BC5B0",
        "gUnk_090BC5BA",
        "gUnk_090BC5C4",
        "gUnk_090BC5CE",
        "gUnk_090BC5D8",
        "gUnk_090BC5E2",
        "gUnk_090BC5EC",
        "gUnk_090BC5F6",
        "gUnk_090BC600",
        "gUnk_090BC60A",
        "gUnk_090BC614",
        "gUnk_090BC61E",
        "gUnk_090BC628",
        "gUnk_090BC632",
        "gUnk_090BC63C",
        "gUnk_090BC646",
        "gUnk_090BC650",
        "gUnk_090BC65A",
        "gUnk_090BC664",
        "gUnk_090BC66E",
        "gUnk_090BC678",
        "gUnk_090BC682",
        "gUnk_090BC68C",
        "gUnk_090BC696",
        "gUnk_090BC6A0",
        "gUnk_090BC6AA",
        "gUnk_090BC6B4",
        "gUnk_090BC6BE",
        "gUnk_090BC6C8",
        "gUnk_090BC6D2",
        "gUnk_090BC6DC",
        "gUnk_090BC6E6",
        "gUnk_090BC6F0",
        "gUnk_090BC6FA",
        "gUnk_090BC704",
        "gUnk_090BC70E",
        "gUnk_090BC718",
        "gUnk_090BC722",
        "gUnk_090BC72C",
        "gUnk_090BC736",
        "gUnk_090BC740",
        "gUnk_090BC74A",
        "gUnk_090BC754",
        "gUnk_090BC75E",
        "gUnk_090BC768",
        "gUnk_090BC772",
        "gUnk_090BC77C",
        "gUnk_090BC786",
        "gUnk_090BC790",
        "gUnk_090BC79A",
        "gUnk_090BC7A4",
        "gUnk_090BC7AE",
        "gUnk_090BC7B8",
        "gUnk_090BC7C2",
        "gUnk_090BC7CC",
        "gUnk_090BC7D6",
        "gUnk_090BC7E0",
        "gUnk_090BC7EA",
        "gUnk_090BC7F4",
        "gUnk_090BC7FE",
        "gUnk_090BC808",
        "gUnk_090BC812",
        "gUnk_090BC81C",
        "gUnk_090BC826",
        "gUnk_090BC830",
        "gUnk_090BC83A",
        "gUnk_090BC844",
        "gUnk_090BC84E",
        "gUnk_090BC858",
        "gUnk_090BC862",
        "gUnk_090BC86C",
        "gUnk_090BC876",
        "gUnk_090BC880",
        "gUnk_090BC88A",
        "gUnk_090BC894",
        "gUnk_090BC89E",
        "gUnk_090BC8A8",
        "gUnk_090BC8B2",
        "gUnk_090BC8BC",
        "gUnk_090BC8C6",
        "gUnk_090BC8D0",
        "gUnk_090BC8DA",
        "gUnk_090BC8E4",
        "gUnk_090BC8EE",
        "gUnk_090BC8F8",
        "gUnk_090BC902",
        "gUnk_090BC90C",
        "gUnk_090BC916",
        "gUnk_090BC920",
        "gUnk_090BC92A",
        "gUnk_090BC934",
        "gUnk_090BC93E",
        "gUnk_090BC948",
        "gUnk_090BC952",
        "gUnk_090BC95C",
        "gUnk_090BC966",
        "gUnk_090BC970",
        "gUnk_090BC97A",
        "gUnk_090BC984",
        "gUnk_090BC98E",
        "gUnk_090BC998",
        "gUnk_090BC9A2",
        "gUnk_090BC9AC",
        "gUnk_090BC9B6",
        "gUnk_090C49CC",
        "gUnk_090C49D6",
        "gUnk_090C49E0",
        "gUnk_090C49EA",
        "gUnk_090C49F4",
        "gUnk_090C49FE",
        "gUnk_090C4A08",
        "gUnk_090C4A12",
        "gUnk_090C4A1C",
        "gUnk_090C4A26",
        "gUnk_090C4A30",
        "gUnk_090C4A3A",
        "gUnk_090C4A44",
        "gUnk_090C4A4E",
        "gUnk_090C4A58",
        "gUnk_090C4A62",
        "gUnk_090C4A6C",
        "gUnk_090C4A76",
        "gUnk_090C4A80",
        "gUnk_090C4A8A",
        "gUnk_090C4A94",
        "gUnk_090C4A9E",
        "gUnk_090C4AA8",
        "gUnk_090C4AB2",
        "gUnk_090C4ABC",
        "gUnk_090C4AC6",
        "gUnk_090C4AD0",
        "gUnk_090C4ADA",
        "gUnk_090C4AE4",
        "gUnk_090C4AEE",
        "gUnk_090C4AF8",
        "gUnk_090C4B02",
        "gUnk_090C4B0C",
        "gUnk_090C4B16",
        "gUnk_090C4B20",
        "gUnk_090C4B2A",
        "gUnk_090C4B34",
        "gUnk_090C4B3E",
        "gUnk_090C4B48",
        "gUnk_090C4B52",
        "gUnk_090C4B5C",
        "gUnk_090C4B66",
        "gUnk_090C4B70",
        "gUnk_090C4B7A",
        "gUnk_090C4B84",
        "gUnk_090C4B8E",
        "gUnk_090C4B98",
        "gUnk_090C4BA2",
        "gUnk_090C4BAC",
        "gUnk_090C4BB6",
        "gUnk_090C4BC0",
        "gUnk_090C4BCA",
        "gUnk_090C4BD4",
        "gUnk_090C4BDE",
        "gUnk_090C4BE8",
        "gUnk_090C4BF2",
        "gUnk_090C4BFC",
        "gUnk_090C4C06",
        "gUnk_090C4C10",
        "gUnk_090C4C1A",
        "gUnk_090C4C24",
        "gUnk_090C4C2E",
        "gUnk_090C4C38",
        "gUnk_090C4C42",
        "gUnk_090C4C4C",
        "gUnk_090C4C56",
        "gUnk_090C4C60",
        "gUnk_090C4C6A",
        "gUnk_090C4C74",
        "gUnk_090C4C7E",
        "gUnk_090C4C88",
        "gUnk_090C4C92",
        "gUnk_090C4C9C",
        "gUnk_090C4CA6",
        "gUnk_090C4CB0",
        "gUnk_090C4CBA",
        "gUnk_090C4CC4",
        "gUnk_090C4CCE",
        "gUnk_090C4CD8",
        "gUnk_090C4CE2",
        "gUnk_090C4CEC",
        "gUnk_090C4CF6",
        "gUnk_090C4D00",
        "gUnk_090C4D0A",
        "gUnk_090C4D14",
        "gUnk_090C4D1E",
        "gUnk_090C4D28",
        "gUnk_090C4D32",
        "gUnk_090C4D3C",
        "gUnk_090C4D46",
        "gUnk_090C4D50",
        "gUnk_090C4D5A",
        "gUnk_090C4D64",
        "gUnk_090C4D6E",
        "gUnk_090C4D78",
        "gUnk_090C4D82",
        "gUnk_090C4D8C",
        "gUnk_090C4D96",
        "gUnk_090C4DA0",
        "gUnk_090C4DAA",
        "gUnk_090C4DB4",
        "gUnk_090C4DBE",
        "gUnk_090C4DC8",
        "gUnk_090C4DD2",
        "gUnk_090C4DDC",
        "gUnk_090C4DE6",
        "gUnk_090C4DF0",
        "gUnk_090C4DFA",
        "gUnk_090C4E04",
        "gUnk_090C4E0E",
        "gUnk_090C4E18",
        "gUnk_090C4E22",
        "gUnk_090C4E2C",
        "gUnk_090C4E36",
        "gUnk_090C4E40",
        "gUnk_090C4E4A",
        "gUnk_090C4E54",
        "gUnk_090C4E5E",
        "gUnk_090C4E68",
        "gUnk_090C4E72",
        "gUnk_090C4E7C",
        "gUnk_090C4E86",
        "gUnk_090C4E90",
        "gUnk_090C4E9A",
        "gUnk_090C4EA4",
        "gUnk_090C4EAE",
        "gUnk_090C4EB8",
        "gUnk_090C4EC2",
        "gUnk_090C4ECC",
        "gUnk_090C4ED6",
        "gUnk_090C4EE0",
        "gUnk_090C4EEA",
        "gUnk_090C4EF4",
        "gUnk_090C4EFE",
        "gUnk_090C4F08",
        "gUnk_090C4F12",
        "gUnk_090C4F1C",
        "gUnk_090C4F26",
        "gUnk_090C4F30",
        "gUnk_090C4F3A",
        "gUnk_090C4F44",
        "gUnk_090C4F4E",
        "gUnk_090C4F58",
        "gUnk_090C4F62",
        "gUnk_090C4F6C",
        "gUnk_090C4F76",
        "gUnk_090C4F80",
        "gUnk_090C4F8A",
        "gUnk_090C4F94",
        "gUnk_090C4F9E",
        "gUnk_090C4FA8",
        "gUnk_090C4FB2",
        "gUnk_090C4FBC",
        "gUnk_090C4FC6",
        "gUnk_090C4FD0",
        "gUnk_090C4FDA",
        "gUnk_090C4FE4",
        "gUnk_090C4FEE",
        "gUnk_090C4FF8",
        "gUnk_090C5002",
        "gUnk_090C500C",
        "gUnk_090C5016",
        "gUnk_090C5020",
        "gUnk_090C502A",
        "gUnk_090C5034",
        "gUnk_090C503E",
        "gUnk_090C5048",
        "gUnk_090C5052",
        "gUnk_090C505C",
        "gUnk_090C5066",
        "gUnk_090C5070",
        "gUnk_090C507A",
        "gUnk_090C5084",
        "gUnk_090C508E",
        "gUnk_090C5098",
        "gUnk_090C50A2",
        "gUnk_090C50AC",
        "gUnk_090C50B6",
        "gUnk_090C50C0",
        "gUnk_090C50CA",
        "gUnk_090C50D4",
        "gUnk_090C50DE",
        "gUnk_090C50E8",
        "gUnk_090C50F2",
        "gUnk_090C50FC",
        "gUnk_090C5106",
        "gUnk_090C5110",
        "gUnk_090C511A",
        "gUnk_090C5124",
        "gUnk_090C512E",
        "gUnk_090C5138",
        "gUnk_090C5142",
        "gUnk_090C514C",
        "gUnk_090C5156",
        "gUnk_090C5160",
        "gUnk_090C516A",
        "gUnk_090C5174",
        "gUnk_090C517E",
        "gUnk_090C5188",
        "gUnk_090C5192",
        "gUnk_090CB5A8",
        "gUnk_090CB5B2",
        "gUnk_090CB5BC",
        "gUnk_090CB5C6",
        "gUnk_090CB5D0",
        "gUnk_090CB5DA",
        "gUnk_090CB5E4",
        "gUnk_090CB5EE",
        "gUnk_090CB5F8",
        "gUnk_090CB602",
        "gUnk_090CB60C",
        "gUnk_090CB616",
        "gUnk_090CB620",
        "gUnk_090CB62A",
        "gUnk_090CB634",
        "gUnk_090CB63E",
        "gUnk_090CB648",
        "gUnk_090CB652",
        "gUnk_090CB65C",
        "gUnk_090CB666",
        "gUnk_090CB670",
        "gUnk_090CB67A",
        "gUnk_090CB684",
        "gUnk_090CB68E",
        "gUnk_090CB698",
        "gUnk_090CB6A2",
        "gUnk_090CB6AC",
        "gUnk_090CB6B6",
        "gUnk_090CB6C0",
        "gUnk_090CB6CA",
        "gUnk_090CB6D4",
        "gUnk_090CB6DE",
        "gUnk_090CB6E8",
        "gUnk_090CB6F2",
        "gUnk_090CB6FC",
        "gUnk_090CB706",
        "gUnk_090CB710",
        "gUnk_090CB71A",
        "gUnk_090CB724",
        "gUnk_090CB72E",
        "gUnk_090CB738",
        "gUnk_090CB742",
        "gUnk_090CB74C",
        "gUnk_090CB756",
        "gUnk_090CB760",
        "gUnk_090CB76A",
        "gUnk_090CB774",
        "gUnk_090CB77E",
        "gUnk_090CB788",
        "gUnk_090CB792",
        "gUnk_090CB79C",
        "gUnk_090CB7A6",
        "gUnk_090CB7B0",
        "gUnk_090CB7BA",
        "gUnk_090CB7C4",
        "gUnk_090CB7CE",
        "gUnk_090CB7D8",
        "gUnk_090CB7E2",
        "gUnk_090CB7EC",
        "gUnk_090CB7F6",
        "gUnk_090CB800",
        "gUnk_090CB80A",
        "gUnk_090CB814",
        "gUnk_090CB81E",
        "gUnk_090CB828",
        "gUnk_090CB832",
        "gUnk_090CB83C",
        "gUnk_090CB846",
        "gUnk_090CB850",
        "gUnk_090CB85A",
        "gUnk_090CB864",
        "gUnk_090CB86E",
        "gUnk_090CB878",
        "gUnk_090CB882",
        "gUnk_090CB88C",
        "gUnk_090CB896",
        "gUnk_090CB8A0",
        "gUnk_090CB8AA",
        "gUnk_090CB8B4",
        "gUnk_090CB8BE",
        "gUnk_090CB8C8",
        "gUnk_090CB8D2",
        "gUnk_090CB8DC",
        "gUnk_090CB8E6",
        "gUnk_090CB8F0",
        "gUnk_090CB8FA",
        "gUnk_090CB904",
        "gUnk_090CB90E",
        "gUnk_090CB918",
        "gUnk_090CB922",
        "gUnk_090CB92C",
        "gUnk_090CB936",
        "gUnk_090CB940",
        "gUnk_090CB94A",
        "gUnk_090CB954",
        "gUnk_090CB95E",
        "gUnk_090CB968",
        "gUnk_090CB972",
        "gUnk_090CB97C",
        "gUnk_090CB986",
        "gUnk_090CB990",
        "gUnk_090CB99A",
        "gUnk_090CB9A4",
        "gUnk_090CB9AE",
        "gUnk_090CB9B8",
        "gUnk_090CB9C2",
        "gUnk_090CB9CC",
        "gUnk_090CB9D6",
        "gUnk_090CB9E0",
        "gUnk_090CB9EA",
        "gUnk_090CB9F4",
        "gUnk_090CB9FE",
        "gUnk_090CBA08",
        "gUnk_090CBA12",
        "gUnk_090CBA1C",
        "gUnk_090CBA26",
        "gUnk_090CBA30",
        "gUnk_090CBA3A",
        "gUnk_090CBA44",
        "gUnk_090CBA4E",
        "gUnk_090CBA58",
        "gUnk_090CBA62",
        "gUnk_090CBA6C",
        "gUnk_090CBA76",
        "gUnk_090CBA80",
        "gUnk_090CBA8A",
        "gUnk_090CBA94",
        "gUnk_090CBA9E",
        "gUnk_090CBAA8",
        "gUnk_090CBAB2",
        "gUnk_090CBABC",
        "gUnk_090CBAC6",
        "gUnk_090CBAD0",
        "gUnk_090CBADA",
        "gUnk_090CBAE4",
        "gUnk_090CBAEE",
        "gUnk_090CBAF8",
        "gUnk_090CBB02",
        "gUnk_090CBB0C",
        "gUnk_090CBB16",
        "gUnk_090CBB20",
        "gUnk_090CBB2A",
        "gUnk_090CBB34",
        "gUnk_090CBB3E",
        "gUnk_090CBB48",
        "gUnk_090CBB52",
        "gUnk_090CBB5C",
        "gUnk_090CBB66",
        "gUnk_090CBB70",
        "gUnk_090CBB7A",
        "gUnk_090CBB84",
        "gUnk_090CBB8E",
        "gUnk_090CBB98",
        "gUnk_090CBBA2",
        "gUnk_090CBBAC",
        "gUnk_090CBBB6",
        "gUnk_090CBBC0",
        "gUnk_090CBBCA",
        "gUnk_090CBBD4",
        "gUnk_090CBBDE",
        "gUnk_090CBBE8",
        "gUnk_090CBBF2",
        "gUnk_090CBBFC",
        "gUnk_090CBC06",
        "gUnk_090CBC10",
        "gUnk_090CBC1A",
        "gUnk_090CBC24",
        "gUnk_090CBC2E",
        "gUnk_090CBC38",
        "gUnk_090CBC42",
        "gUnk_090CBC4C",
        "gUnk_090CBC56",
        "gUnk_090CBC60",
        "gUnk_090CBC6A",
        "gUnk_090CBC74",
        "gUnk_090CBC7E",
        "gUnk_090CBC88",
        "gUnk_090CBC92",
        "gUnk_090CBC9C",
        "gUnk_090CBCA6",
        "gUnk_090CBCB0",
        "gUnk_090CBCBA",
        "gUnk_090CBCC4",
        "gUnk_090CBCCE",
        "gUnk_090CBCD8",
        "gUnk_090CBCE2",
        "gUnk_090CBCEC",
        "gUnk_090CBCF6",
        "gUnk_090CBD00",
        "gUnk_090CBD0A",
        "gUnk_090CBD14",
        "gUnk_090CBD1E",
        "gUnk_090CBD28",
        "gUnk_090CBD32",
        "gUnk_090CBD3C",
        "gUnk_090CBD46",
        "gUnk_090CBD50",
        "gUnk_090CBD5A",
        "gUnk_090CBD64",
        "gUnk_090CBD6E",
        "gUnk_090CBD78",
        "gUnk_090CBD82",
        "gUnk_090CBD8C",
        "gUnk_090CBD96",
        "gUnk_090CBDA0",
        "gUnk_090CBDAA",
        "gUnk_090CBDB4",
        "gUnk_090CBDBE",
        "gUnk_090CBDC8",
        "gUnk_090CBDD2",
        "gUnk_090CBDDC",
        "gUnk_090CBDE6",
        "gUnk_090CBDF0",
        "gUnk_090CBDFA",
        "gUnk_090CBE04",
        "gUnk_090CBE0E",
        "gUnk_090CBE18",
        "gUnk_090CBE22",
        "gUnk_090CBE2C",
        "gUnk_090CBE36",
        "gUnk_090CBE40",
        "gUnk_090CBE4A",
        "gUnk_090CBE54",
        "gUnk_090CBE5E",
        "gUnk_090CBE68",
        "gUnk_090CBE72",
        "gUnk_090CBE7C",
        "gUnk_090CBE86",
        "gUnk_090CBE90",
        "gUnk_090CBE9A",
        "gUnk_090CBEA4",
        "gUnk_090CBEAE",
        "gUnk_090CBEB8",
        "gUnk_090CBEC2",
        "gUnk_090CBECC",
        "gUnk_090CBED6",
        "gUnk_090CBEE0",
        "gUnk_090CBEEA",
        "gUnk_090CBEF4",
        "gUnk_090CBEFE",
        "gUnk_090CBF08",
        "gUnk_090CBF12",
        "gUnk_090CBF1C",
        "gUnk_090CBF26",
        "gUnk_090CBF30",
        "gUnk_090CBF3A",
        "gUnk_090CBF44",
        "gUnk_090CBF4E",
        "gUnk_090CBF58",
        "gUnk_090CBF62",
        "gUnk_090CBF6C",
        "gUnk_090CBF76",
        "gUnk_090CBF80",
        "gUnk_090CBF8A",
        "gUnk_090CBF94",
        "gUnk_090CBF9E",
        "gUnk_09EE150C",
        "gWorldwarpAssetUs_099A2F84",
        "gWorldwarpAssetUs_099A32E4",
        "gWorldwarpAssetUs_09A3D81C",
        "gWorldwarpAssetUs_09A3D83C",
        "gMoogleAssetUs_00000001",
        "gMoogleAssetUs_00000002",
        "gMoogleAssetUs_00000003",
        "gMoogleAssetUs_00000004",
        "gMoogleAssetUs_00000005",
        "gMoogleAssetUs_00000006",
        "gMoogleAssetUs_00000007",
        "gMoogleAssetUs_00000008",
        "gMoogleAssetUs_00000009",
        "gMoogleAssetUs_0000000A",
        "gMoogleAssetUs_0000000B",
        "gMoogleAssetUs_0000000C",
        "gMoogleAssetUs_0000000D",
        "gMoogleAssetUs_0000000E",
        "gMoogleAssetUs_0000000F",
        "gMoogleAssetUs_00000010",
        "gMoogleAssetUs_00000011",
        "gMoogleAssetUs_00000012",
        "gMoogleAssetUs_00000013",
        "gMoogleAssetUs_00000014",
        "gMoogleAssetUs_00000015",
        "gMoogleAssetUs_00000016",
        "gMoogleAssetUs_00000017",
        "gMoogleAssetUs_00000018",
        "gMoogleAssetUs_00000019",
        "gMoogleAssetUs_0000001B",
        "gMoogleAssetUs_0000001C",
        "gMoogleAssetUs_0000001D",
        "gMoogleAssetUs_0000001E",
        "gMoogleAssetUs_0000001F",
        "gMoogleAssetUs_00000020",
        "gMoogleAssetUs_00000021",
        "gMoogleAssetUs_00000022",
        "gMoogleAssetUs_00000023",
        "gMoogleAssetUs_00000024",
        "gMoogleAssetUs_00000025",
        "gMoogleAssetUs_099A3EA4",
        "gMoogleAssetUs_099A3EC4",
        "gMoogleAssetUs_099A41E4",
        "gMoogleAssetUs_099A4204",
        "gMoogleAssetUs_099A4464",
        "gMoogleAssetUs_099A4484",
        "gMoogleAssetUs_099A46E4",
        "gMoogleAssetUs_099A4704",
        "gMoogleAssetUs_09A387DC",
        "gMoogleAssetUs_09A38CDC",
        "gMoogleAssetUs_09A391DC",
        "gMoogleAssetUs_09A396DC",
        "gMoogleAssetUs_09A39BDC",
        "gMoogleAssetUs_09A3A3DC",
        "gMoogleAssetUs_09A3DA9C",
        "gMoogleAssetUs_09A3DABC",
        "gMoogleAssetUs_09A3DADC",
        "gMoogleAssetUs_09A3DAFC",
        "gRoomAssetUs_099939FA",
        "gRoomAssetUs_09995E9C",
        "gRoomAssetUs_09996B82",
        "gRoomAssetUs_09997F64",
        "gRoomAssetUs_09999244",
        "gRoomAssetUs_099995FC",
        "gRoomAssetUs_099A899C",
        "gRoomAssetUs_09A1E0DC",
        "gRoomAssetUs_09A1E8DC",
        "gRoomAssetUs_09A1F0DC",
        "gRoomAssetUs_09A1F8DC",
        "gRoomAssetUs_09A3C75C",
        "gBossMapBlockUs_08125E24",
        "gBossMapBlockUs_096E2C64",
        "gBossMapBlockUs_096E3464",
        "gBossMapBlockUs_09845798",
        "gBossMapBlockUs_09845F98",
        "gBossMapBlockUs_09846798",
        "gBossMapBlockUs_09846F98",
        "gUnk_09037FAC",
        "gUnk_09041F58",
        "gUnk_0815A066",
        "gUnk_0815A0BA",
        "gUnk_0815B1D2",
        "gUnk_0815A078",
        "gUnk_0815A0CC",
        "gUnk_0815B1A8",
        "gUnk_0815A116",
        "gUnk_0815A158",
        "gUnk_0815A0F4",
        "gUnk_0815A130",
        "gUnk_0815A176",
    },
    "jp": {
        "gUnk_09C5D922",
        "gUnk_09C5DD46",
        "gUnk_09C5E15E",
        "gUnk_09C5E6E6",
        "gUnk_09C5EB5E",
        "gUnk_09C5F12C",
        "gUnk_09C5F678",
        "gUnk_09C5FC54",
        "gUnk_09C6000A",
        "gUnk_09C60662",
        "gUnk_09C60F20",
        "gUnk_09C61676",
        "gUnk_09C6259C",
        "gUnk_09C62CC8",
        "gUnk_09C63244",
        "gUnk_09C853DA",
        "gUnk_09C85EDE",
        "gUnk_09C865FC",
        "gUnk_09C86C68",
        "gUnk_09C872D4",
        "gUnk_09C8E7BC",
        "gUnk_09C8E7DE",
        "gUnk_09C8E800",
        "gUnk_09C8E822",
        "gUnk_09C8E844",
        "gUnk_09C8E866",
        "gUnk_09C8E888",
        "gUnk_09C8E8AA",
        "gUnk_09C8E8CC",
        "gUnk_09C8E8EE",
        "gUnk_09C8E910",
        "gUnk_09C8E932",
        "gUnk_09C8E954",
        "gUnk_09C8E976",
        "gUnk_09C8E998",
        "gUnk_09C8E9BA",
        "gUnk_09C8E9DC",
        "gUnk_09C8E9FE",
        "gUnk_09C8EA20",
        "gUnk_09C8EA42",
        "gUnk_09C8EA64",
        "gUnk_09C8EA86",
        "gUnk_09C8EAA8",
        "gUnk_09C8EACA",
        "gUnk_09C8EAEC",
        "gUnk_09C8EB0E",
        "gUnk_09C8EB2A",
        "gUnk_09C8EB46",
        "gUnk_09C8EB62",
        "gUnk_09C8EB7E",
        "gUnk_09C8EB9A",
        "gUnk_09C8EBB6",
        "gUnk_09C8EBD2",
        "gUnk_09C8EBEE",
        "gUnk_09C8EC0A",
        "gUnk_09C8EC26",
        "gUnk_09C8EC42",
        "gUnk_09C8EC5E",
        "gUnk_09C8EC7A",
        "gUnk_09C8EC96",
        "gUnk_09C8ECB2",
        "gUnk_09C8ECCE",
        "gUnk_09C8ECEA",
        "gUnk_09C8ED06",
        "gUnk_09C8ED22",
        "gUnk_09C8ED3E",
        "gUnk_09C8ED5A",
        "gUnk_09C8ED76",
        "gUnk_09C8ED92",
        "gUnk_09C8EDAE",
        "gUnk_09C8EDCA",
        "gUnk_09C8EDE6",
        "gUnk_09C8EE02",
        "gUnk_09C8EE1E",
        "gUnk_09C8EE58",
        "gUnk_09C8EE92",
        "gUnk_09C8EECC",
        "gUnk_09C8EF06",
        "gUnk_09C8EF40",
        "gUnk_09C8EF7A",
        "gUnk_09C8EFA8",
        "gUnk_09C8EFD6",
        "gUnk_09C8F004",
        "gUnk_09C8F032",
        "gUnk_09C8F060",
        "gUnk_09C8F08E",
        "gWorldwarpAssetUs_099A2F84",
        "gWorldwarpAssetUs_099A32E4",
        "gWorldwarpAssetUs_09A3D81C",
        "gWorldwarpAssetUs_09A3D83C",
        "gMoogleAssetUs_00000001",
        "gMoogleAssetUs_00000002",
        "gMoogleAssetUs_00000003",
        "gMoogleAssetUs_00000004",
        "gMoogleAssetUs_00000005",
        "gMoogleAssetUs_00000006",
        "gMoogleAssetUs_00000007",
        "gMoogleAssetUs_00000008",
        "gMoogleAssetUs_00000009",
        "gMoogleAssetUs_0000000A",
        "gMoogleAssetUs_0000000B",
        "gMoogleAssetUs_0000000C",
        "gMoogleAssetUs_0000000D",
        "gMoogleAssetUs_0000000E",
        "gMoogleAssetUs_0000000F",
        "gMoogleAssetUs_00000010",
        "gMoogleAssetUs_00000011",
        "gMoogleAssetUs_00000012",
        "gMoogleAssetUs_00000013",
        "gMoogleAssetUs_00000014",
        "gMoogleAssetUs_00000015",
        "gMoogleAssetUs_00000016",
        "gMoogleAssetUs_00000017",
        "gMoogleAssetUs_00000018",
        "gMoogleAssetUs_00000019",
        "gMoogleAssetUs_0000001B",
        "gMoogleAssetUs_0000001C",
        "gMoogleAssetUs_0000001D",
        "gMoogleAssetUs_0000001E",
        "gMoogleAssetUs_0000001F",
        "gMoogleAssetUs_00000020",
        "gMoogleAssetUs_00000021",
        "gMoogleAssetUs_00000022",
        "gMoogleAssetUs_00000023",
        "gMoogleAssetUs_00000024",
        "gMoogleAssetUs_00000025",
        "gMoogleAssetUs_099A3EA4",
        "gMoogleAssetUs_099A3EC4",
        "gMoogleAssetUs_099A41E4",
        "gMoogleAssetUs_099A4204",
        "gMoogleAssetUs_099A4464",
        "gMoogleAssetUs_099A4484",
        "gMoogleAssetUs_099A46E4",
        "gMoogleAssetUs_099A4704",
        "gMoogleAssetUs_09A387DC",
        "gMoogleAssetUs_09A38CDC",
        "gMoogleAssetUs_09A391DC",
        "gMoogleAssetUs_09A396DC",
        "gMoogleAssetUs_09A39BDC",
        "gMoogleAssetUs_09A3A3DC",
        "gMoogleAssetUs_09A3DA9C",
        "gMoogleAssetUs_09A3DABC",
        "gMoogleAssetUs_09A3DADC",
        "gMoogleAssetUs_09A3DAFC",
        "gRoomAssetUs_099939FA",
        "gRoomAssetUs_09995E9C",
        "gRoomAssetUs_09996B82",
        "gRoomAssetUs_09997F64",
        "gRoomAssetUs_09999244",
        "gRoomAssetUs_099995FC",
        "gRoomAssetUs_099A899C",
        "gRoomAssetUs_09A1E0DC",
        "gRoomAssetUs_09A1E8DC",
        "gRoomAssetUs_09A1F0DC",
        "gRoomAssetUs_09A1F8DC",
        "gRoomAssetUs_09A3C75C",
        "gBossMapBlockUs_08125E24",
        "gBossMapBlockUs_096E2C64",
        "gBossMapBlockUs_096E3464",
        "gBossMapBlockUs_09845798",
        "gBossMapBlockUs_09845F98",
        "gBossMapBlockUs_09846798",
        "gBossMapBlockUs_09846F98",
    },
}

TARGET_ONLY_SYMBOLS = {
    "eu": {
        "gUnkEu_0954C284": 0x0954C284,
        "gUnkEu_0954C7B4": 0x0954C7B4,
        "gUnkEu_0954CD1C": 0x0954CD1C,
        "gUnkEu_0954D238": 0x0954D238,
        "gUnkEu_0954D7A0": 0x0954D7A0,
        "gUnkEu_094C9860": 0x094C9860,
        "gUnkEu_094C9C20": 0x094C9C20,
        "gUnkEu_0988519C": 0x0988519C,
        "gUnkEu_0988551E": 0x0988551E,
        "gUnkEu_09885862": 0x09885862,
        "gUnkEu_09885BA6": 0x09885BA6,
        "gUnkEu_09885EEA": 0x09885EEA,
        "gUnkEu_094E04E4": 0x094E04E4,
        "gUnkEu_09533324": 0x09533324,
        "gUnkEu_094C6C22": 0x094C6C22,
        "gUnkEu_094C789A": 0x094C789A,
        "gUnkEu_094C7472": 0x094C7472,
        "gUnkEu_094C704A": 0x094C704A,
        "gUnkEu_08F6A73C": 0x08F6A73C,
        "gUnkEu_09529A04": 0x09529A04,
        "gUnkEu_0952DDE4": 0x0952DDE4,
        "gUnkEu_0952E0E4": 0x0952E0E4,
        "gUnkEu_0952DFE4": 0x0952DFE4,
        "gUnkEu_0952DEE4": 0x0952DEE4,
        "gUnkEu_09543324": 0x09543324,
        "gUnkEu_08F79038": 0x08F79038,
        "gUnkEu_09814E40": 0x09814E40,
        "gUnkEu_09815640": 0x09815640,
        "gUnkEu_09A2B040": 0x09A2B040,
        "gUnkEu_09A2BE40": 0x09A2BE40,
        "gUnkEu_09A30C00": 0x09A30C00,
        "gUnkEu_09A34400": 0x09A34400,
        "gUnkEu_09A31A00": 0x09A31A00,
        "gUnkEu_09A35200": 0x09A35200,
        "gUnkEu_09A32800": 0x09A32800,
        "gUnkEu_09A38C00": 0x09A38C00,
        "gUnkEu_09A33600": 0x09A33600,
        "gUnkEu_09A39A00": 0x09A39A00,
        "gUnkEu_09A86E60": 0x09A86E60,
        "gUnkEu_09A3D400": 0x09A3D400,
        "gUnkEu_09A3E800": 0x09A3E800,
        "gUnkEu_09A3FC00": 0x09A3FC00,
        "gUnkEu_09A41000": 0x09A41000,
        "gUnkEu_0883E040": 0x0883E040,
        "gUnkEu_0883E454": 0x0883E454,
        "gUnkEu_0883E8D4": 0x0883E8D4,
        "gUnkEu_0883ECE8": 0x0883ECE8,
        "gUnkEu_0883F0F8": 0x0883F0F8,
        "gUnkEu_0883E070": 0x0883E070,
        "gUnkEu_0883E494": 0x0883E494,
        "gUnkEu_0883E914": 0x0883E914,
        "gUnkEu_0883ED28": 0x0883ED28,
        "gUnkEu_0883F138": 0x0883F138,
        "gUnkEu_0883E150": 0x0883E150,
        "gUnkEu_0883E574": 0x0883E574,
        "gUnkEu_0883E9F4": 0x0883E9F4,
        "gUnkEu_0883EE08": 0x0883EE08,
        "gUnkEu_0883F218": 0x0883F218,
        "gUnkEu_08890EC0": 0x08890EC0,
        "gUnkEu_08895CF8": 0x08895CF8,
        "gUnkEu_08B51BA8": 0x08B51BA8,
        "gUnkEu_08B51D50": 0x08B51D50,
        "gUnkEu_08B51FB8": 0x08B51FB8,
        "gUnkEu_08B52220": 0x08B52220,
        "gUnkEu_08B52488": 0x08B52488,
        "gUnkEu_08F6B5FC": 0x08F6B5FC,
        "gUnkEu_08F7913C": 0x08F7913C,
        "gUnkEu_08890E1C": 0x08890E1C,
        "gUnkEu_08890E44": 0x08890E44,
        "gUnkEu_08895AF4": 0x08895AF4,
        "gUnkEu_08895CF8": 0x08895CF8,
        "gUnkEu_08895DBC": 0x08895DBC,
        "gUnkEu_08891508": 0x08891508,
        "gUnkEu_088927F4": 0x088927F4,
        "gUnkEu_088928E4": 0x088928E4,
        "gUnkEu_090CE9EA": 0x090CE9EA,
        "gUnkEu_090D1DF4": 0x090D1DF4,
        "gUnkEu_097D8300": 0x097D8300,
        "gUnkEu_097D8F00": 0x097D8F00,
        "gUnkEu_097D9B00": 0x097D9B00,
        "gUnkEu_097DA700": 0x097DA700,
        "gUnkEu_090CE9F4": 0x090CE9F4,
        "gUnkEu_09955250": 0x09955250,
        "gUnkEu_09957550": 0x09957550,
        "gUnkEu_09959850": 0x09959850,
        "gUnkEu_0995BB50": 0x0995BB50,
        "gUnkEu_0995DE50": 0x0995DE50,
        "gUnkEu_09960150": 0x09960150,
        "gUnkEu_09962450": 0x09962450,
        "gUnkEu_09964750": 0x09964750,
        "gUnkEu_09966A50": 0x09966A50,
        "gUnkEu_09968D50": 0x09968D50,
        "gUnkEu_099563D0": 0x099563D0,
        "gUnkEu_099586D0": 0x099586D0,
        "gUnkEu_0995A9D0": 0x0995A9D0,
        "gUnkEu_0995CCD0": 0x0995CCD0,
        "gUnkEu_0995EFD0": 0x0995EFD0,
        "gUnkEu_099612D0": 0x099612D0,
        "gUnkEu_099635D0": 0x099635D0,
        "gUnkEu_099658D0": 0x099658D0,
        "gUnkEu_09967BD0": 0x09967BD0,
        "gUnkEu_09969ED0": 0x09969ED0,
        "gUnkEu_08892780": 0x08892780,
        "gUnkEu_08892864": 0x08892864,
        "gUnkEu_0996D130": 0x0996D130,
        "gUnkEu_0996D930": 0x0996D930,
        "gUnkEu_0996E130": 0x0996E130,
        "gUnkEu_0996E930": 0x0996E930,
        "gUnkEu_09953BF0": 0x09953BF0,
        "gUnkEu_099543F0": 0x099543F0,
        "gUnkEu_09954BF0": 0x09954BF0,
        "gUnkEu_09938170": 0x09938170,
        "gUnkEu_09939D30": 0x09939D30,
        "gUnkEu_0993B8F0": 0x0993B8F0,
        "gUnkEu_0993D4B0": 0x0993D4B0,
        "gUnkEu_0993E9B0": 0x0993E9B0,
        "gUnkEu_0993FEB0": 0x0993FEB0,
        "gUnkEu_099413B0": 0x099413B0,
        "gUnkEu_099428B0": 0x099428B0,
        "gUnkEu_09943DB0": 0x09943DB0,
        "gUnkEu_099452B0": 0x099452B0,
        "gUnkEu_099467B0": 0x099467B0,
        "gUnkEu_09947CB0": 0x09947CB0,
        "gUnkEu_099491B0": 0x099491B0,
        "gUnkEu_0994A6B0": 0x0994A6B0,
        "gUnkEu_0994A8B0": 0x0994A8B0,
        "gUnkEu_0994AAB0": 0x0994AAB0,
        "gUnkEu_0994ACB0": 0x0994ACB0,
        "gUnkEu_09827920": 0x09827920,
        "gUnkEu_098272D0": 0x098272D0,
        "gUnkEu_09823D9C": 0x09823D9C,
        "gUnkEu_09827C34": 0x09827C34,
        "gUnkEu_0981F960": 0x0981F960,
        "gUnkEu_0982761C": 0x0982761C,
        "gUnkEu_097ADE00": 0x097ADE00,
        "gUnkEu_0981ECC0": 0x0981ECC0,
        "gUnkEu_09814A40": 0x09814A40,
        "gUnkEu_09DD51A0": 0x09DD51A0,
        "gUnkEu_09DD59A0": 0x09DD59A0,
        "gUnkEu_09DD61A0": 0x09DD61A0,
        "gUnkEu_09DD69A0": 0x09DD69A0,
        "gUnkEu_09DD71A0": 0x09DD71A0,
        "gUnkEu_09DD79A0": 0x09DD79A0,
        "gUnkEu_09DD81A0": 0x09DD81A0,
        "gUnkEu_09DD89A0": 0x09DD89A0,
        "gUnkEu_08890EC0": 0x08890EC0,
        "gUnkEu_08895E94": 0x08895E94,
        "gUnkEu_08CB0D3C": 0x08CB0D3C,
        "gUnkEu_08F7ADFC": 0x08F7ADFC,
        "gUnkEu_09F72C10": 0x09F72C10,
        "gUnkEu_09F72D80": 0x09F72D80,
        "gUnkEu_094DCCE4": 0x094DCCE4,
        "gUnkEu_094E20E4": 0x094E20E4,
        "gUnkEu_094E74E4": 0x094E74E4,
        "gUnkEu_094E58E4": 0x094E58E4,
        "gUnkEu_094E3CE4": 0x094E3CE4,
        "gUnkEu_09534324": 0x09534324,
        "gUnkEu_090D1DFE": 0x090D1DFE,
        "gUnkEu_090D1E04": 0x090D1E04,
        "gUnkEu_08C9A5E2": 0x08C9A5E2,
        "gUnkEu_08892334": 0x08892334,
        "gUnkEu_088920BC": 0x088920BC,
        "gUnkEu_096C798C": 0x096C798C,
        "gUnkEu_08EF3EDC": 0x08EF3EDC,
        "gUnkEu_08EF4EDC": 0x08EF4EDC,
        "gUnkEu_08EF5EDC": 0x08EF5EDC,
        "gUnkEu_08EF6EDC": 0x08EF6EDC,
        "gUnkEu_099AABA4": 0x099AABA4,
        "gUnkEu_099AABBA": 0x099AABBA,
        "gUnkEu_099AABEE": 0x099AABEE,
        "gUnkEu_08896524": 0x08896524,
        "gUnkEu_09538324": 0x09538324,
        "gUnkEu_09538B24": 0x09538B24,
        "gUnkEu_09539324": 0x09539324,
        "gUnkEu_09F5D6EC": 0x09F5D6EC,
        "gUnkEu_098863B2": 0x098863B2,
        "gUnkEu_0988683C": 0x0988683C,
        "gUnkEu_09886C7E": 0x09886C7E,
        "gUnkEu_09886FC8": 0x09886FC8,
        "gUnkEu_08895A00": 0x08895A00,
        "gUnkEu_08895C30": 0x08895C30,
        "gUnkEu_099A421C": 0x099A421C,
        "gUnkEu_099A4238": 0x099A4238,
        "gUnkEu_099A426C": 0x099A426C,
        "gUnkEu_08C9CD3C": 0x08C9CD3C,
        "gUnkEu_08F79520": 0x08F79520,
        "gUnkEu_08F74484": 0x08F74484,
        "gUnkEu_08F7E498": 0x08F7E498,
        "gUnkEu_08F6EF3C": 0x08F6EF3C,
        "gUnkEu_08F7D318": 0x08F7D318,
        "gUnkEu_08CA0D3C": 0x08CA0D3C,
        "gUnkEu_08F79960": 0x08F79960,
        "gUnkEu_08F728C0": 0x08F728C0,
        "gUnkEu_08F7DED0": 0x08F7DED0,
        "gUnkEu_08F756FC": 0x08F756FC,
        "gUnkEu_08F7E83C": 0x08F7E83C,
        "gUnkEu_08F71C40": 0x08F71C40,
        "gUnkEu_08F7DB78": 0x08F7DB78,
        "gUnkEu_08CA4D3C": 0x08CA4D3C,
        "gUnkEu_08F79DEC": 0x08F79DEC,
        "gUnkEu_08CA8D3C": 0x08CA8D3C,
        "gUnkEu_08F7A224": 0x08F7A224,
        "gUnkEu_08CB4D3C": 0x08CB4D3C,
        "gUnkEu_08F7B498": 0x08F7B498,
        "gUnkEu_08CACD3C": 0x08CACD3C,
        "gUnkEu_08F7A7A8": 0x08F7A7A8,
        "gUnkEu_08CB8D3C": 0x08CB8D3C,
        "gUnkEu_08F7B958": 0x08F7B958,
        "gUnkEu_08CBCD3C": 0x08CBCD3C,
        "gUnkEu_08F7BE78": 0x08F7BE78,
        "gUnkEu_08CC0BFC": 0x08CC0BFC,
        "gUnkEu_08F7C274": 0x08F7C274,
        "gUnkEu_08CC4BFC": 0x08CC4BFC,
        "gUnkEu_08F7C6CC": 0x08F7C6CC,
        "gUnkEu_08CCCBFC": 0x08CCCBFC,
        "gUnkEu_08F7CFB4": 0x08F7CFB4,
        "gUnkEu_08CC8BFC": 0x08CC8BFC,
        "gUnkEu_08F7CB08": 0x08F7CB08,
        "gUnkEu_0919B63A": 0x0919B63A,
        "gUnkEu_095A3D74": 0x095A3D74,
        "gUnkEu_096BF18C": 0x096BF18C,
        "gUnkEu_096C698C": 0x096C698C,
        "gUnkEu_096C598C": 0x096C598C,
        "gUnkEu_096C618C": 0x096C618C,
        "gUnkEu_096C718C": 0x096C718C,
        "gUnkEu_096C118C": 0x096C118C,
        "gUnkEu_096BE98C": 0x096BE98C,
        "gUnkEu_096C298C": 0x096C298C,
        "gUnkEu_096C498C": 0x096C498C,
        "gUnkEu_096C198C": 0x096C198C,
        "gUnkEu_096C398C": 0x096C398C,
        "gUnkEu_096C218C": 0x096C218C,
        "gUnkEu_096C418C": 0x096C418C,
        "gUnkEu_096C318C": 0x096C318C,
        "gUnkEu_096C518C": 0x096C518C,
        "gUnkEu_08891670": 0x08891670,
        "gUnkEu_08891714": 0x08891714,
        "gUnkEu_08895EDC": 0x08895EDC,
        "gUnkEu_090D1DC0": 0x090D1DC0,
        "gUnkEu_090CEC30": 0x090CEC30,
        "gUnkEu_090CEC70": 0x090CEC70,
        "gUnkEu_094F03A4": 0x094F03A4,
        "gUnkEu_094F1BA4": 0x094F1BA4,
        "gUnkEu_094F13A4": 0x094F13A4,
        "gUnkEu_094F0BA4": 0x094F0BA4,
        "gUnkEu_0953C324": 0x0953C324,
        "gUnkEu_090CECE8": 0x090CECE8,
        "gUnkEu_090D1328": 0x090D1328,
        "gUnkEu_094D53C4": 0x094D53C4,
        "gUnkEu_094D6BC4": 0x094D6BC4,
        "gUnkEu_094D63C4": 0x094D63C4,
        "gUnkEu_094D5BC4": 0x094D5BC4,
        "gUnkEu_0967CB6C": 0x0967CB6C,
        "gUnkEu_08891580": 0x08891580,
        "gUnk_09A53380": 0x09A53380,
        "gUnk_09A54080": 0x09A54080,
        "gUnk_09A54D80": 0x09A54D80,
        "gUnk_09A55A80": 0x09A55A80,
        "gUnk_09A59B80": 0x09A59B80,
        "gUnk_09A5A880": 0x09A5A880,
        "gUnk_09A5B580": 0x09A5B580,
        "gUnk_09A5C280": 0x09A5C280,
        "gUnkEu_09A97520": 0x09A97520,
        "gUnkEu_099AEE98": 0x099AEE98,
        "gUnkEu_092D1F74": 0x092D1F74,
        "gUnkEu_08890F40": 0x08890F40,
        "gUnkEu_08895960": 0x08895960,
        "gUnkEu_09A2D440": 0x09A2D440,
        "gUnkEu_09A2E440": 0x09A2E440,
        "gUnkEu_09A2F440": 0x09A2F440,
        "gUnkEu_09A30440": 0x09A30440,
        "gUnkEu_09A2CC40": 0x09A2CC40,
        "gUnkEu_09A2DC40": 0x09A2DC40,
        "gUnkEu_09A2EC40": 0x09A2EC40,
        "gUnkEu_09A2FC40": 0x09A2FC40,
        "gUnkEu_09A4FBC0": 0x09A4FBC0,
        "gUnkEu_09A50BC0": 0x09A50BC0,
        "gUnkEu_09A51BC0": 0x09A51BC0,
        "gUnkEu_09A52BC0": 0x09A52BC0,
        "gUnkEu_09A4F3C0": 0x09A4F3C0,
        "gUnkEu_09A503C0": 0x09A503C0,
        "gUnkEu_09A513C0": 0x09A513C0,
        "gUnkEu_09A523C0": 0x09A523C0,
        "gUnkEu_09A4CCC0": 0x09A4CCC0,
        "gUnkEu_09A4BFC0": 0x09A4BFC0,
        "gUnkEu_09A4E6C0": 0x09A4E6C0,
        "gUnkEu_09A4D9C0": 0x09A4D9C0,
        "gUnkEu_09A56780": 0x09A56780,
        "gUnkEu_09A53380": 0x09A53380,
        "gUnkEu_09A5CF80": 0x09A5CF80,
        "gUnkEu_09A59B80": 0x09A59B80,
        "gUnkEu_09A57480": 0x09A57480,
        "gUnkEu_09A54080": 0x09A54080,
        "gUnkEu_09A5DC80": 0x09A5DC80,
        "gUnkEu_09A5A880": 0x09A5A880,
        "gUnkEu_09A58180": 0x09A58180,
        "gUnkEu_09A54D80": 0x09A54D80,
        "gUnkEu_09A5E980": 0x09A5E980,
        "gUnkEu_09A5B580": 0x09A5B580,
        "gUnkEu_09A58E80": 0x09A58E80,
        "gUnkEu_09A55A80": 0x09A55A80,
        "gUnkEu_09A5F680": 0x09A5F680,
        "gUnkEu_09A5C280": 0x09A5C280,
        "gUnkEu_099AAC2C": 0x099AAC2C,
        "gUnkEu_09A9A880": 0x09A9A880,
        "gUnkEu_09A9A8A0": 0x09A9A8A0,
        "gUnkEu_099FBE00": 0x099FBE00,
        "gUnkEu_094C6BFC": 0x094C6BFC,
        "gUnkEu_094C6C18": 0x094C6C18,
        "gUnkEu_094C7024": 0x094C7024,
        "gUnkEu_094C7040": 0x094C7040,
        "gUnkEu_094C744C": 0x094C744C,
        "gUnkEu_094C7468": 0x094C7468,
        "gUnkEu_094C7874": 0x094C7874,
        "gUnkEu_094C7890": 0x094C7890,
        "gUnkEu_094C7C9C": 0x094C7C9C,
        "gUnkEu_094C7CC4": 0x094C7CC4,
        "gUnkEu_094C8250": 0x094C8250,
        "gUnkEu_094C827E": 0x094C827E,
        "gUnkEu_094C8908": 0x094C8908,
        "gUnkEu_094C893C": 0x094C893C,
        "gUnkEu_094C9148": 0x094C9148,
        "gUnkEu_094C9176": 0x094C9176,
        "gUnkEu_094C9800": 0x094C9800,
        "gUnkEu_094C980A": 0x094C980A,
        "gUnkEu_094C9814": 0x094C9814,
        "gUnkEu_094C981E": 0x094C981E,
        "gUnkEu_094C9828": 0x094C9828,
        "gUnkEu_094C9832": 0x094C9832,
        "gUnkEu_094C983C": 0x094C983C,
        "gUnkEu_094C9846": 0x094C9846,
        "gUnkEu_094C9850": 0x094C9850,
        "gUnkEu_094C985A": 0x094C985A,
        "gUnkEu_094C9BC0": 0x094C9BC0,
        "gUnkEu_094C9BCA": 0x094C9BCA,
        "gUnkEu_094C9BD4": 0x094C9BD4,
        "gUnkEu_094C9BDE": 0x094C9BDE,
        "gUnkEu_094C9BE8": 0x094C9BE8,
        "gUnkEu_094C9BF2": 0x094C9BF2,
        "gUnkEu_094C9BFC": 0x094C9BFC,
        "gUnkEu_094C9C06": 0x094C9C06,
        "gUnkEu_094C9C10": 0x094C9C10,
        "gUnkEu_094C9C1A": 0x094C9C1A,
        "gUnkEu_094CE440": 0x094CE440,
        "gUnkEu_094CE44A": 0x094CE44A,
        "gUnkEu_094CE454": 0x094CE454,
        "gUnkEu_094CE45E": 0x094CE45E,
        "gUnkEu_094CE468": 0x094CE468,
        "gUnkEu_094CE472": 0x094CE472,
        "gUnkEu_094CE47C": 0x094CE47C,
        "gUnkEu_094CE486": 0x094CE486,
        "gUnkEu_094CE570": 0x094CE570,
        "gUnkEu_094CE57A": 0x094CE57A,
        "gUnkEu_094CE584": 0x094CE584,
        "gUnkEu_094CE58E": 0x094CE58E,
        "gUnkEu_094CE598": 0x094CE598,
        "gUnkEu_094CE5A2": 0x094CE5A2,
        "gUnkEu_094CE5AC": 0x094CE5AC,
        "gUnkEu_094CE5B6": 0x094CE5B6,
        "gUnkEu_094CE6A0": 0x094CE6A0,
        "gUnkEu_094CE6AA": 0x094CE6AA,
        "gUnkEu_094CE6B4": 0x094CE6B4,
        "gUnkEu_094CE6BE": 0x094CE6BE,
        "gUnkEu_094CE6C8": 0x094CE6C8,
        "gUnkEu_094CE6D2": 0x094CE6D2,
        "gUnkEu_094CE6DC": 0x094CE6DC,
        "gUnkEu_094CE6E6": 0x094CE6E6,
        "gUnkEu_094CE7D0": 0x094CE7D0,
        "gUnkEu_094CE7DA": 0x094CE7DA,
        "gUnkEu_094CE7E4": 0x094CE7E4,
        "gUnkEu_094CE7EE": 0x094CE7EE,
        "gUnkEu_094CE7F8": 0x094CE7F8,
        "gUnkEu_094CE802": 0x094CE802,
        "gUnkEu_094CE80C": 0x094CE80C,
        "gUnkEu_094CE816": 0x094CE816,
        "gUnkEu_090F1EE8": 0x90f1ee8,
        "gUnkEu_090F1FFC": 0x90f1ffc,
        "gUnkEu_090F2224": 0x90f2224,
        "gUnkEu_090F2338": 0x90f2338,
        "gUnkEu_090F244C": 0x90f244c,
        "gUnkEu_090F2560": 0x90f2560,
        "gUnkEu_090F2788": 0x90f2788,
        "gUnkEu_090F289C": 0x90f289c,
        "gUnkEu_090F2AC4": 0x90f2ac4,
        "gUnkEu_090F2BD8": 0x90f2bd8,
        "gUnkEu_090F2CEC": 0x90f2cec,
        "gUnk_09059EAE": 0x90e6cce,
        "gUnk_0905A14A": 0x90e6f6a,
        "gUnk_0905A3E6": 0x90e7206,
        "gUnk_0905A682": 0x90e74a2,
        "gUnk_0905A91E": 0x90e773e,
        "gUnk_0905BA76": 0x90e8896,
        "gUnk_0905F0D0": 0x90ebef0,
        "gUnk_0905F1E4": 0x90ec004,
        "gUnk_0905F2F8": 0x90ec118,
        "gUnk_0905F40C": 0x90ec22c,
        "gUnk_0905F520": 0x90ec340,
        "gUnk_0905F634": 0x90ec454,
        "gUnk_0905F748": 0x90ec568,
        "gUnk_0905F85C": 0x90ec67c,
        "gUnk_0905F970": 0x90ec790,
        "gUnk_0905FA84": 0x90ec8a4,
        "gUnk_0905FB98": 0x90ec9b8,
        "gUnk_0905FCAC": 0x90ecacc,
        "gUnk_0905FDC0": 0x90ecbe0,
        "gUnk_0905FED4": 0x90eccf4,
        "gUnk_0905FFE8": 0x90ece08,
        "gUnk_090600FC": 0x90ecf1c,
        "gUnk_09060210": 0x90ed030,
        "gUnk_09060324": 0x90ed144,
        "gUnk_09060438": 0x90ed258,
        "gUnk_0906054C": 0x90ed36c,
        "gUnk_09060660": 0x90ed480,
        "gUnk_09060774": 0x90ed594,
        "gUnk_09060888": 0x90ed6a8,
        "gUnk_0906099C": 0x90ed7bc,
        "gUnk_09060AB0": 0x90ed8d0,
        "gUnk_09060BC4": 0x90ed9e4,
        "gUnk_09060CD8": 0x90edaf8,
        "gUnk_09060DEC": 0x90edc0c,
        "gUnk_09060F00": 0x90edd20,
        "gUnk_09061014": 0x90ede34,
        "gUnk_09061128": 0x90edf48,
        "gUnk_0906123C": 0x90ee05c,
        "gUnk_09061350": 0x90ee170,
        "gUnk_09061464": 0x90ee284,
        "gUnk_09061578": 0x90ee398,
        "gUnk_0906168C": 0x90ee4ac,
        "gUnk_090617A0": 0x90ee5c0,
        "gUnk_090618B4": 0x90ee6d4,
        "gUnk_090619C8": 0x90ee7e8,
        "gUnk_09061ADC": 0x90ee8fc,
        "gUnk_09061BF2": 0x90eea12,
        "gUnk_09061D08": 0x90eeb28,
        "gUnk_09061E1C": 0x90eec3c,
        "gUnk_09061F30": 0x90eed50,
        "gUnk_09062044": 0x90eee64,
        "gUnk_09062158": 0x90eef78,
        "gUnk_0906226C": 0x90ef08c,
        "gUnk_09062380": 0x90ef1a0,
        "gUnk_09062494": 0x90ef2b4,
        "gUnk_090625A8": 0x90ef3c8,
        "gUnk_090626BC": 0x90ef4dc,
        "gUnk_090627D0": 0x90ef5f0,
        "gUnk_090628E4": 0x90ef704,
        "gUnk_090629F8": 0x90ef818,
        "gUnk_09062B0C": 0x90ef92c,
        "gUnk_09062C20": 0x90efa40,
        "gUnk_09062D34": 0x90efb54,
        "gUnk_09062E48": 0x90efc68,
        "gUnk_09062F5C": 0x90efd7c,
        "gUnk_09063070": 0x90efe90,
        "gUnk_09063184": 0x90effa4,
        "gUnk_09063298": 0x90f00b8,
        "gUnk_090633AC": 0x90f01cc,
        "gUnk_090634C0": 0x90f02e0,
        "gUnk_090635D4": 0x90f03f4,
        "gUnk_090636E8": 0x90f0508,
        "gUnk_090637FC": 0x90f061c,
        "gUnk_09063910": 0x90f0730,
        "gUnk_09063A24": 0x90f0844,
        "gUnk_09063B38": 0x90f0958,
        "gUnk_09063C4C": 0x90f0a6c,
        "gUnk_09063D60": 0x90f0b80,
        "gUnk_09063E74": 0x90f0c94,
        "gUnk_09063F88": 0x90f0da8,
        "gUnk_0906409C": 0x90f0ebc,
        "gUnk_090641B0": 0x90f0fd0,
        "gUnk_090642C4": 0x90f10e4,
        "gUnk_090643D8": 0x90f11f8,
        "gUnk_090644EC": 0x90f130c,
        "gUnk_09064600": 0x90f1420,
        "gUnk_09064714": 0x90f1534,
        "gUnk_09064828": 0x90f1648,
        "gUnk_0906493C": 0x90f175c,
        "gUnk_09064A50": 0x90f1870,
        "gUnk_09064B64": 0x90f1984,
        "gUnk_09064C78": 0x90f1a98,
        "gUnk_09064D8C": 0x90f1bac,
        "gUnk_09064EA0": 0x90f1cc0,
        "gUnk_09064FB4": 0x90f1dd4,
        "gUnk_090650C8": 0x90f2110,
        "gUnk_090651DC": 0x90f2674,
        "gUnk_090652F0": 0x90f29b0,
        "gUnk_09065404": 0x90f2e00,
        "gUnk_09065518": 0x90f2f14,
        "gUnk_0906562C": 0x90f3028,
        "gUnk_09065740": 0x90f313c,
        "gUnk_09065854": 0x90f3250,
        "gUnk_09065968": 0x90f3364,
        "gUnk_09065A7C": 0x90f3478,
        "gUnk_09065B90": 0x90f358c,
        "gUnk_09065CA4": 0x90f36a0,
        "gUnk_09065DB8": 0x90f37b4,
        "gUnk_09065ECC": 0x90f38c8,
        "gUnk_09065FE0": 0x90f39dc,
        "gUnk_090660F4": 0x90f3af0,
        "gUnk_09066430": 0x90f3e2c,
        "gUnk_09066544": 0x90f3f40,
        "gUnk_09612C38": 0x9545ca4,
        "gUnk_09612C58": 0x9545cc4,
        "gUnk_09612C78": 0x9545ce4,
        "gUnk_09612C98": 0x9545d04,
        "gUnk_09612CB8": 0x9545d24,
        "gUnk_09612CD8": 0x9545d44,
        "gUnk_09612CF8": 0x9545d64,
        "gUnk_09612D18": 0x9545d84,
        "gUnk_09612D38": 0x9545da4,
        "gUnk_09612D58": 0x9545dc4,
        "gUnk_09612D78": 0x9545de4,
        "gUnk_09612D98": 0x9545e04,
        "gUnk_09612DB8": 0x9545e24,
        "gUnk_09612DD8": 0x9545e44,
        "gUnk_09612DF8": 0x9545e64,
        "gUnk_09612E18": 0x9545e84,
        "gUnk_09612E38": 0x9545ea4,
        "gUnk_09612E58": 0x9545ec4,
        "gUnk_09612E78": 0x9545ee4,
        "gUnk_09612E98": 0x9545f04,
        "gUnk_09612EB8": 0x9545f24,
        "gUnk_09612ED8": 0x9545f44,
        "gUnk_09612EF8": 0x9545f64,
        "gUnk_09612F18": 0x9545f84,
        "gUnk_09612F38": 0x9545fa4,
        "gUnk_09612F58": 0x9545fc4,
        "gUnk_09612F78": 0x9545fe4,
        "gUnk_09612F98": 0x9546004,
        "gUnk_09612FB8": 0x9546024,
        "gUnk_09612FD8": 0x9546044,
        "gUnk_09612FF8": 0x9546064,
        "gUnk_09613018": 0x9546084,
        "gUnk_09613038": 0x95460a4,
        "gUnk_09613058": 0x95460c4,
        "gUnk_09613078": 0x95460e4,
        "gUnk_09613098": 0x9546104,
        "gUnk_096130B8": 0x9546124,
        "gUnk_096130D8": 0x9546144,
        "gUnk_096130F8": 0x9546164,
        "gUnk_09613118": 0x9546184,
        "gUnk_09613138": 0x95461a4,
        "gUnk_09613158": 0x95461c4,
        "gUnk_09613178": 0x95461e4,
        "gUnk_096131F8": 0x9546264,
        "gUnk_09613218": 0x9546284,
        "gUnk_09613238": 0x95462a4,
        "gUnk_09613258": 0x95462c4,
        "gUnk_09613278": 0x95462e4,
        "gUnk_09613298": 0x9546304,
        "gUnk_096132B8": 0x9546324,
        "gUnk_096132D8": 0x9546344,
        "gUnk_096132F8": 0x9546364,
        "gUnk_09613318": 0x9546384,
        "gUnk_09613338": 0x95463a4,
        "gUnk_09613358": 0x95463c4,
        "gUnk_09613378": 0x95463e4,
        "gUnk_09613398": 0x9546404,
        "gUnk_096133B8": 0x9546424,
        "gUnk_096133D8": 0x9546444,
        "gUnk_096133F8": 0x9546464,
        "gUnk_09613418": 0x9546484,
        "gUnk_09613438": 0x95464a4,
        "gUnk_09613458": 0x95464c4,
        "gUnk_09613478": 0x95464e4,
        "gUnk_09613498": 0x9546504,
        "gUnk_096134B8": 0x9546524,
        "gUnk_096134D8": 0x9546544,
        "gUnk_096134F8": 0x9546564,
        "gUnk_09613518": 0x9546584,
        "gUnk_09613538": 0x95465a4,
        "gUnk_09613558": 0x95465c4,
        "gUnk_09613578": 0x95465e4,
        "gUnk_09613598": 0x9546604,
        "gUnk_096135B8": 0x9546624,
        "gUnk_096135D8": 0x9546644,
        "gUnk_096135F8": 0x9546664,
        "gUnk_09613618": 0x9546684,
        "gUnk_09613638": 0x95466a4,
        "gUnk_09613658": 0x95466c4,
        "gUnk_09613678": 0x95466e4,
        "gUnk_09613698": 0x9546704,
        "gUnk_096136B8": 0x9546724,
        "gUnk_096136D8": 0x9546744,
        "gUnk_096136F8": 0x9546764,
        "gUnk_09613718": 0x9546784,
        "gUnk_09613738": 0x95467a4,
        "gUnk_09613758": 0x95467c4,
        "gUnk_09613778": 0x95467e4,
        "gUnk_09613798": 0x9546804,
        "gUnk_096137B8": 0x9546824,
        "gUnk_096137D8": 0x9546844,
        "gUnk_09613858": 0x95468c4,
        "gUnk_09613878": 0x95468e4,
        "gUnk_09613898": 0x95468e4,
        "gUnk_096138F8": 0x9546904,
        "gUnk_09613918": 0x9546924,
        "gUnk_09613938": 0x9546924,
        "gUnk_09613958": 0x9546924,
        "gUnk_09613978": 0x9546924,
        "gUnk_09613998": 0x9546944,
        "gUnk_096139B8": 0x9546964,
        "gUnk_096139D8": 0x9546964,
        "gUnk_09613A38": 0x9546984,
        "gUnk_09613A58": 0x95469a4,
        "gUnk_09613A78": 0x95469a4,
        "gUnk_09613A98": 0x95469a4,
        "gUnk_09613AD8": 0x95469c4,
        "gUnk_09613AF8": 0x95469e4,
        "gUnk_09613B78": 0x9546a64,
        "gUnk_09613B98": 0x9546a84,
        "gUnk_09613C18": 0x9546b04,
        "gUnk_09613C38": 0x9546b24,
        "gUnk_09613C78": 0x9546b64,
        "gUnk_09613CB8": 0x9546ba4,
        "gUnk_09613CD8": 0x9546bc4,
        "gUnk_09613D98": 0x9546c84,
        "gUnk_09613DB8": 0x9546ca4,
        "gUnkEu_091078AE": 0x91078ae,
        "gUnkEu_0910DD2E": 0x910dd2e,
        "gUnkEu_09121002": 0x9121002,
        "gUnkEu_0911AB16": 0x911ab16,
        "gUnkEu_09114860": 0x9114860,
        "gUnkEu_09127204": 0x9127204,
        "gUnkEu_091292D6": 0x91292d6,
        "gUnkEu_0912F83E": 0x912f83e,
        "gUnkEu_0912D736": 0x912d736,
        "gUnkEu_0912B47C": 0x912b47c,
        "gUnkEu_09131BFE": 0x9131bfe,
        "gUnkEu_091367CC": 0x91367cc,
        "gUnkEu_0914583A": 0x914583a,
        "gUnkEu_091407A2": 0x91407a2,
        "gUnkEu_0913B7F4": 0x913b7f4,
        "gUnkEu_0914A2E4": 0x914a2e4,
        "gUnkEu_0914B41E": 0x914b41e,
        "gUnkEu_0914E89E": 0x914e89e,
        "gUnkEu_0914D7B0": 0x914d7b0,
        "gUnkEu_0914C648": 0x914c648,
        "gUnkEu_09160A0E": 0x9160a0e,
        "gUnkEu_09160C2A": 0x9160c2a,
        "gUnkEu_091611C8": 0x91611c8,
        "gUnkEu_09160FE8": 0x9160fe8,
        "gUnkEu_09160E46": 0x9160e46,
        "gUnkEu_0915E7D4": 0x915e7d4,
        "gUnkEu_0915EDDA": 0x915edda,
        "gUnkEu_091602F4": 0x91602f4,
        "gUnkEu_0915FC28": 0x915fc28,
        "gUnkEu_0915F468": 0x915f468,
        "gUnkEu_0914FAD6": 0x914fad6,
        "gUnkEu_091519CE": 0x91519ce,
        "gUnkEu_091581F6": 0x91581f6,
        "gUnkEu_09155EFE": 0x9155efe,
        "gUnkEu_09153BC6": 0x9153bc6,
        "gUnkEu_0915A27A": 0x915a27a,
        "gUnkEu_0915B004": 0x915b004,
        "gUnkEu_0915DAD4": 0x915dad4,
        "gUnkEu_0915CC96": 0x915cc96,
        "gUnkEu_0915BE46": 0x915be46,
        "gWorldwarpAssetEu_09A9B2E0": 0x9a9b2e0,
        "gWorldwarpAssetEu_09A9B300": 0x9a9b300,
        "gMoogleAssetEu_00000001": 0x1,
        "gMoogleAssetEu_00000002": 0x2,
        "gMoogleAssetEu_00000003": 0x3,
        "gMoogleAssetEu_00000004": 0x4,
        "gMoogleAssetEu_00000005": 0x5,
        "gMoogleAssetEu_00000006": 0x6,
        "gMoogleAssetEu_00000007": 0x7,
        "gMoogleAssetEu_00000008": 0x8,
        "gMoogleAssetEu_00000009": 0x9,
        "gMoogleAssetEu_0000000A": 0xa,
        "gMoogleAssetEu_0000000B": 0xb,
        "gMoogleAssetEu_0000000C": 0xc,
        "gMoogleAssetEu_0000000D": 0xd,
        "gMoogleAssetEu_0000000E": 0xe,
        "gMoogleAssetEu_0000000F": 0xf,
        "gMoogleAssetEu_00000010": 0x10,
        "gMoogleAssetEu_00000011": 0x11,
        "gMoogleAssetEu_00000012": 0x12,
        "gMoogleAssetEu_00000013": 0x13,
        "gMoogleAssetEu_00000014": 0x14,
        "gMoogleAssetEu_00000015": 0x15,
        "gMoogleAssetEu_00000016": 0x16,
        "gMoogleAssetEu_00000017": 0x17,
        "gMoogleAssetEu_00000018": 0x18,
        "gMoogleAssetEu_00000019": 0x19,
        "gMoogleAssetEu_0000001B": 0x1b,
        "gMoogleAssetEu_0000001C": 0x1c,
        "gMoogleAssetEu_0000001D": 0x1d,
        "gMoogleAssetEu_0000001E": 0x1e,
        "gMoogleAssetEu_0000001F": 0x1f,
        "gMoogleAssetEu_00000020": 0x20,
        "gMoogleAssetEu_00000021": 0x21,
        "gMoogleAssetEu_00000022": 0x22,
        "gMoogleAssetEu_00000023": 0x23,
        "gMoogleAssetEu_00000024": 0x24,
        "gMoogleAssetEu_00000025": 0x25,
        "gMoogleAssetEu_099B1E28": 0x99b1e28,
        "gMoogleAssetEu_099B2168": 0x99b2168,
        "gMoogleAssetEu_099B23E8": 0x99b23e8,
        "gMoogleAssetEu_099B2668": 0x99b2668,
        "gMoogleAssetEu_09A8DFA0": 0x9a8dfa0,
        "gMoogleAssetEu_09A8E4A0": 0x9a8e4a0,
        "gMoogleAssetEu_09A8E9A0": 0x9a8e9a0,
        "gMoogleAssetEu_09A8EEA0": 0x9a8eea0,
        "gMoogleAssetEu_09A8F3A0": 0x9a8f3a0,
        "gMoogleAssetEu_09A8FBA0": 0x9a8fba0,
        "gMoogleAssetEu_09A91E20": 0x9a91e20,
        "gMoogleAssetEu_09A92620": 0x9a92620,
        "gMoogleAssetEu_09A92E20": 0x9a92e20,
        "gMoogleAssetEu_09A93620": 0x9a93620,
        "gMoogleAssetEu_09A93E20": 0x9a93e20,
        "gMoogleAssetEu_09A94620": 0x9a94620,
        "gMoogleAssetEu_09A9B560": 0x9a9b560,
        "gMoogleAssetEu_09A9B580": 0x9a9b580,
        "gMoogleAssetEu_09A9B5A0": 0x9a9b5a0,
        "gMoogleAssetEu_09A9B5C0": 0x9a9b5c0,
        "gRoomAssetEu_09A6FCA0": 0x9a6fca0,
        "gRoomAssetEu_09A704A0": 0x9a704a0,
        "gRoomAssetEu_09A70CA0": 0x9a70ca0,
        "gRoomAssetEu_09A714A0": 0x9a714a0,
        "gRoomAssetEu_09A9A220": 0x9a9a220,
        "gWorldIntroAssetEu_08CA0D3C": 0x8ca0d3c,
        "gWorldIntroAssetEu_08CB4D3C": 0x8cb4d3c,
        "gWorldIntroAssetEu_08CB8D3C": 0x8cb8d3c,
        "gWorldIntroAssetEu_08CC0BFC": 0x8cc0bfc,
        "gWorldIntroAssetEu_08CC4BFC": 0x8cc4bfc,
        "gWorldIntroAssetEu_08CC8BFC": 0x8cc8bfc,
        "gWorldIntroAssetEu_08CCCBFC": 0x8cccbfc,
        "gWorldIntroAssetEu_08F79520": 0x8f79520,
        "gWorldIntroAssetEu_08F79960": 0x8f79960,
        "gWorldIntroAssetEu_08F7B498": 0x8f7b498,
        "gWorldIntroAssetEu_08F7B958": 0x8f7b958,
        "gWorldIntroAssetEu_08F7C274": 0x8f7c274,
        "gWorldIntroAssetEu_08F7C6CC": 0x8f7c6cc,
        "gWorldIntroAssetEu_08F7CB08": 0x8f7cb08,
        "gWorldIntroAssetEu_08F7CFB4": 0x8f7cfb4,
        "gBossMapBlockEu_08124944": 0x8124944,
        "gBossMapBlockEu_096AA98C": 0x96aa98c,
        "gBossMapBlockEu_096AB18C": 0x96ab18c,
        "gBossMapBlockEu_09819E40": 0x9819e40,
        "gBossMapBlockEu_0981A640": 0x981a640,
        "gBossMapBlockEu_0981AE40": 0x981ae40,
        "gBossMapBlockEu_0981B640": 0x981b640,
        "gUnkEu_09795660": 0x9795660,
        "gUnkEu_097966A0": 0x97966a0,
        "gUnkEu_09799760": 0x9799760,
        "gUnkEu_09798720": 0x9798720,
        "gUnkEu_097976E0": 0x97976e0,
        "gUnkEu_0979A7A0": 0x979a7a0,
        "gUnkEu_0979B7E0": 0x979b7e0,
        "gUnkEu_0979E8A0": 0x979e8a0,
        "gUnkEu_0979D860": 0x979d860,
        "gUnkEu_0979C820": 0x979c820,
        "gUnkEu_0980F840": 0x980f840,
        "gUnkEu_0980FD40": 0x980fd40,
        "gUnkEu_09810C40": 0x9810c40,
        "gUnkEu_09810740": 0x9810740,
        "gUnkEu_09810240": 0x9810240,
        "gUnkEu_09A8C1A0": 0x9a8c1a0,
        "gUnkEu_09A8BCA0": 0x9a8bca0,
        "gUnkEu_09A8B7A0": 0x9a8b7a0,
        "gUnkEu_09A8C6A0": 0x9a8c6a0,
        "gUnkEu_09A8D5A0": 0x9a8d5a0,
        "gUnkEu_09A8D0A0": 0x9a8d0a0,
        "gUnkEu_09A8CBA0": 0x9a8cba0,
        "gUnkEu_09A8DAA0": 0x9a8daa0,
        "gUnkEu_09A91920": 0x9a91920,
        "gUnkEu_09A91420": 0x9a91420,
        "gUnkEu_09A94E20": 0x9a94e20,
        "gUnkEu_09A95320": 0x9a95320,
        "gUnkEu_09A96220": 0x9a96220,
        "gUnkEu_09A95D20": 0x9a95d20,
        "gUnkEu_09A95820": 0x9a95820,
        "gUnkEu_09A96720": 0x9a96720,
        "gUnkEu_09A96820": 0x9a96820,
        "gUnkEu_09A96920": 0x9a96920,
        "gUnkEu_09A96A20": 0x9a96a20,
        "gUnkEu_09A96B20": 0x9a96b20,
        "gUnkEu_09A97A20": 0x9a97a20,
        "gUnkEu_09A98920": 0x9a98920,
        "gUnkEu_09A98420": 0x9a98420,
        "gUnkEu_09A97F20": 0x9a97f20,
        "gUnkEu_09A97020": 0x9a97020,
        "gUnkEu_09A98E20": 0x9a98e20,
        "gUnkEu_09A99D20": 0x9a99d20,
        "gUnkEu_09A99820": 0x9a99820,
        "gUnkEu_09A99320": 0x9a99320,
        "gUnkEu_090CF64D": 0x090CF64D,
        "gUnkEu_08B50A4A": 0x08B50A4A,
        "gUnkEu_08B50BE6": 0x08B50BE6,
        "gUnkEu_08B50D82": 0x08B50D82,
        "gUnkEu_08B50F18": 0x08B50F18,
        "gUnkEu_08B5102C": 0x08B5102C,
        "gUnkEu_08B51140": 0x08B51140,
        "gUnkEu_08B51254": 0x08B51254,
        "gUnkEu_08B51368": 0x08B51368,
        "gUnkEu_08B5147C": 0x08B5147C,
        "gUnkEu_08B51590": 0x08B51590,
        "gUnkEu_08B516A4": 0x08B516A4,
        "gUnkEu_08B517B8": 0x08B517B8,
        "gUnkEu_08B518CC": 0x08B518CC,
        "gUnkEu_08B519E0": 0x08B519E0,
        "gUnkEu_08B51A74": 0x08B51A74,
        "gUnkEu_08B52782": 0x08B52782,
        "gUnkEu_08B533BE": 0x08B533BE,
        "gUnkEu_08B53FFA": 0x08B53FFA,
        "gUnkEu_090CE9E0": 0x090CE9E0,
        "gUnkEu_08B4FBC0": 0x08B4FBC0,
        "gUnkEu_08F6A6FC": 0x08F6A6FC,
        "gUnkEu_08F77180": 0x08F77180,
        "gUnkEu_08F7EBF8": 0x08F7EBF8,
        "gUnkEu_08F7EFB0": 0x08F7EFB0,
        "gUnkEu_08C9CA58": 0x08C9CA58,
        "gUnkEu_090D1FB0": 0x090D1FB0,
        "gUnkEu_090D1DA5": 0x090D1DA5,
        "gUnkEu_091926B2": 0x091926B2,
        "gUnkEu_0919308A": 0x0919308A,
        "gUnkEu_09192D42": 0x09192D42,
        "gUnkEu_091929FA": 0x091929FA,
        "gUnkEu_094CE490": 0x094CE490,
        "gUnkEu_094CE820": 0x094CE820,
        "gUnkEu_094CE6F0": 0x094CE6F0,
        "gUnkEu_094CE5C0": 0x094CE5C0,
        "gUnkEu_094CF704": 0x094CF704,
        "gUnkEu_094D72E4": 0x094D72E4,
        "gUnkEu_094DB664": 0x094DB664,
        "gUnkEu_094D9FE4": 0x094D9FE4,
        "gUnkEu_094D8964": 0x094D8964,
        "gUnkEu_09187A0E": 0x09187A0E,
        "gUnkEu_09189F36": 0x09189F36,
        "gUnkEu_0918A73A": 0x0918A73A,
        "gUnkEu_0918A48E": 0x0918A48E,
        "gUnkEu_0918A1E2": 0x0918A1E2,
        "gUnkEu_0918B8F2": 0x0918B8F2,
        "gUnkEu_0919016A": 0x0919016A,
        "gUnkEu_0918E942": 0x0918E942,
        "gUnkEu_0918D11A": 0x0918D11A,
        "gUnkEu_09191992": 0x09191992,
        "gUnkEu_0919236A": 0x0919236A,
        "gUnkEu_09192022": 0x09192022,
        "gUnkEu_09191CDA": 0x09191CDA,
        "gUnkEu_094EAD64": 0x094EAD64,
        "gUnkEu_094E90E4": 0x094E90E4,
        "gUnkEu_094EA2E4": 0x094EA2E4,
        "gUnkEu_094E9CE4": 0x094E9CE4,
        "gUnkEu_094E96E4": 0x094E96E4,
        "gUnk_08B1ED76": 0x08b4a686,
        "gUnk_08B1EF0C": 0x08b4a81c,
        "gUnk_08B1F020": 0x08b4a930,
        "gUnk_08B1F2D6": 0x08b4abe6,
        "gUnk_08B1F472": 0x08b4ad82,
        "gUnk_08B1F60E": 0x08b4af1e,
        "gUnk_08B1F7AC": 0x08b4b0bc,
        "gUnk_08B1FCBC": 0x08b4b5cc,
        "gUnk_08B1FCCC": 0x08b4b5dc,
        "gUnk_08B1FCDC": 0x08b4b5ec,
        "gUnk_08B1FCEC": 0x08b4b5fc,
        "gUnk_08B1FCFC": 0x08b4b60c,
        "gUnk_08B1FD0C": 0x08b4b61c,
        "gUnk_08B1FD1C": 0x08b4b62c,
        "gUnk_08B1FD2C": 0x08b4b63c,
        "gUnk_08B1FD3C": 0x08b4b64c,
        "gUnk_08B1FD4C": 0x08b4b65c,
        "gUnk_08B1FD66": 0x08b4b676,
        "gUnk_08B24C98": 0x08b4fb78,
        "gUnk_08B24CA2": 0x08b4fb82,
        "gUnk_08B24CB2": 0x08b4fb92,
        "gUnk_08B24CC2": 0x08b4fba2,
        "gUnk_08B24CD2": 0x08b4fbb2,
        "gUnk_08B24CE2": 0x08b4fbc2,
        "gUnk_08B24CF8": 0x08b4fbd8,
        "gUnk_08B24D0E": 0x08b4fbee,
        "gUnk_08B24D18": 0x08b4fbf8,
        "gUnk_08B24D22": 0x08b4fc02,
        "gUnk_08B24D2C": 0x08b4fc0c,
        "gUnk_08B24D42": 0x08b4fc22,
        "gUnk_08B24D58": 0x08b4fc38,
        "gUnk_08B24D6E": 0x08b4fc4e,
        "gUnk_08B24D78": 0x08b4fc58,
        "gUnk_08B24D82": 0x08b4fc62,
        "gUnk_08B24D8C": 0x08b4fc6c,
        "gUnk_08B24D96": 0x08b4fc76,
        "gUnk_08B24DA0": 0x08b4fc80,
        "gUnk_08B24DAA": 0x08b54e98,
        "gUnk_0962B286": 0x095ec766,
        "gUnk_0962B8BE": 0x095ecd9e,
        "gUnk_0962BEDA": 0x095ed3ba,
        "gUnk_0962CAFC": 0x095edfdc,
        "gUnk_0962D196": 0x095ee676,
        "gUnk_0962D7C0": 0x095eeca0,
        "gUnk_0962D900": 0x095eede0,
        "gUnk_0962DBA0": 0x095ef080,
        "gUnk_0962DEA8": 0x095ef388,
        "gUnk_096FBE24": 0x096c934c,
        "gUnk_096FBF04": 0x096c942c,
        "gUnk_097A24A6": 0x09780322,
        "gUnk_097A2DF8": 0x09780840,
        "gUnk_097A2E16": 0x0978085e,
    },
    "jp": {
        "gUnk_0814F180": 0x0814F180,
        "gUnk_0814FBB0": 0x0814FBB0,
        "gUnk_0814FBBC": 0x0814FBBC,
        "gUnk_0814FBD4": 0x0814FBD4,
        "gUnkJp_093D1694": 0x093D1694,
        "gUnkJp_09008DEC": 0x09008DEC,
        "gUnkJp_094D4594": 0x094D4594,
        "gUnkJp_094D4D94": 0x094D4D94,
        "gUnk_09059EAE": 0x9026d56,
        "gUnk_0905A14A": 0x9026ff2,
        "gUnk_0905A3E6": 0x902728e,
        "gUnk_0905A682": 0x902752a,
        "gUnk_0905A91E": 0x90277c6,
        "gUnk_0905BA76": 0x902891e,
        "gUnk_0905F0D0": 0x902bf78,
        "gUnk_0905F1E4": 0x902c08c,
        "gUnk_0905F2F8": 0x902c1a0,
        "gUnk_0905F40C": 0x902c2b4,
        "gUnk_0905F520": 0x902c3c8,
        "gUnk_0905F634": 0x902c4dc,
        "gUnk_0905F748": 0x902c5f0,
        "gUnk_0905F85C": 0x902c704,
        "gUnk_0905F970": 0x902c818,
        "gUnk_0905FA84": 0x902c92c,
        "gUnk_0905FB98": 0x902ca40,
        "gUnk_0905FCAC": 0x902cb54,
        "gUnk_0905FDC0": 0x902cc68,
        "gUnk_0905FED4": 0x902cd7c,
        "gUnk_0905FFE8": 0x902ce90,
        "gUnk_090600FC": 0x902cfa4,
        "gUnk_09060210": 0x902d0b8,
        "gUnk_09060324": 0x902d1cc,
        "gUnk_09060438": 0x902d2e0,
        "gUnk_0906054C": 0x902d3f4,
        "gUnk_09060660": 0x902d508,
        "gUnk_09060774": 0x902d61c,
        "gUnk_09060888": 0x902d730,
        "gUnk_0906099C": 0x902d844,
        "gUnk_09060AB0": 0x902d958,
        "gUnk_09060BC4": 0x902da6c,
        "gUnk_09060CD8": 0x902db80,
        "gUnk_09060DEC": 0x902dc94,
        "gUnk_09060F00": 0x902dda8,
        "gUnk_09061014": 0x902debc,
        "gUnk_09061128": 0x902dfd0,
        "gUnk_0906123C": 0x902e0e4,
        "gUnk_09061350": 0x902e1f8,
        "gUnk_09061464": 0x902e30c,
        "gUnk_09061578": 0x902e420,
        "gUnk_0906168C": 0x902e534,
        "gUnk_090617A0": 0x902e648,
        "gUnk_090618B4": 0x902e75c,
        "gUnk_090619C8": 0x902e870,
        "gUnk_09061ADC": 0x902e984,
        "gUnk_09061BF2": 0x902ea9a,
        "gUnk_09061D08": 0x902ebb0,
        "gUnk_09061E1C": 0x902ecc4,
        "gUnk_09061F30": 0x902edd8,
        "gUnk_09062044": 0x902eeec,
        "gUnk_09062158": 0x902f000,
        "gUnk_0906226C": 0x902f114,
        "gUnk_09062380": 0x902f228,
        "gUnk_09062494": 0x902f33c,
        "gUnk_090625A8": 0x902f450,
        "gUnk_090626BC": 0x902f564,
        "gUnk_090627D0": 0x902f678,
        "gUnk_090628E4": 0x902f78c,
        "gUnk_090629F8": 0x902f8a0,
        "gUnk_09062B0C": 0x902f9b4,
        "gUnk_09062C20": 0x902fac8,
        "gUnk_09062D34": 0x902fbdc,
        "gUnk_09062E48": 0x902fcf0,
        "gUnk_09062F5C": 0x902fe04,
        "gUnk_09063070": 0x902ff18,
        "gUnk_09063184": 0x903002c,
        "gUnk_09063298": 0x9030140,
        "gUnk_090633AC": 0x9030254,
        "gUnk_090634C0": 0x9030368,
        "gUnk_090635D4": 0x903047c,
        "gUnk_090636E8": 0x9030590,
        "gUnk_090637FC": 0x90306a4,
        "gUnk_09063910": 0x90307b8,
        "gUnk_09063A24": 0x90308cc,
        "gUnk_09063B38": 0x90309e0,
        "gUnk_09063C4C": 0x9030af4,
        "gUnk_09063D60": 0x9030c08,
        "gUnk_09063E74": 0x9030d1c,
        "gUnk_09063F88": 0x9030e30,
        "gUnk_0906409C": 0x9030f44,
        "gUnk_090641B0": 0x9031058,
        "gUnk_090642C4": 0x903116c,
        "gUnk_090643D8": 0x9031280,
        "gUnk_090644EC": 0x9031394,
        "gUnk_09064600": 0x90314a8,
        "gUnk_09064714": 0x90315bc,
        "gUnk_09064828": 0x90316d0,
        "gUnk_0906493C": 0x90317e4,
        "gUnk_09064A50": 0x90318f8,
        "gUnk_09064B64": 0x9031a0c,
        "gUnk_09064C78": 0x9031b20,
        "gUnk_09064D8C": 0x9031c34,
        "gUnk_09064EA0": 0x9031d48,
        "gUnk_09064FB4": 0x9031e5c,
        "gUnk_090650C8": 0x9031f70,
        "gUnk_090651DC": 0x9032084,
        "gUnk_090652F0": 0x9032198,
        "gUnk_09065404": 0x90322ac,
        "gUnk_09065518": 0x90323c0,
        "gUnk_0906562C": 0x90324d4,
        "gUnk_09065740": 0x90325e8,
        "gUnk_09065854": 0x90326fc,
        "gUnk_09065968": 0x9032810,
        "gUnk_09065A7C": 0x9032924,
        "gUnk_09065B90": 0x9032a38,
        "gUnk_09065CA4": 0x9032b4c,
        "gUnk_09065DB8": 0x9032c60,
        "gUnk_09065ECC": 0x9032d74,
        "gUnk_09065FE0": 0x9032e88,
        "gUnk_090660F4": 0x9032f9c,
        "gUnk_09066430": 0x90332d8,
        "gUnk_09066544": 0x90333ec,
        "gUnk_09612C38": 0x95cb714,
        "gUnk_09612C58": 0x95cb734,
        "gUnk_09612C78": 0x95cb754,
        "gUnk_09612C98": 0x95cb774,
        "gUnk_09612CB8": 0x95cb794,
        "gUnk_09612CD8": 0x95cb7b4,
        "gUnk_09612CF8": 0x95cb7d4,
        "gUnk_09612D18": 0x95cb7f4,
        "gUnk_09612D38": 0x95cb814,
        "gUnk_09612D58": 0x95cb834,
        "gUnk_09612D78": 0x95cb854,
        "gUnk_09612D98": 0x95cb874,
        "gUnk_09612DB8": 0x95cb894,
        "gUnk_09612DD8": 0x95cb8b4,
        "gUnk_09612DF8": 0x95cb8d4,
        "gUnk_09612E18": 0x95cb8f4,
        "gUnk_09612E38": 0x95cb914,
        "gUnk_09612E58": 0x95cb934,
        "gUnk_09612E78": 0x95cb954,
        "gUnk_09612E98": 0x95cb974,
        "gUnk_09612EB8": 0x95cb994,
        "gUnk_09612ED8": 0x95cb9b4,
        "gUnk_09612EF8": 0x95cb9d4,
        "gUnk_09612F18": 0x95cb9f4,
        "gUnk_09612F38": 0x95cba14,
        "gUnk_09612F58": 0x95cba34,
        "gUnk_09612F78": 0x95cba54,
        "gUnk_09612F98": 0x95cba74,
        "gUnk_09612FB8": 0x95cba94,
        "gUnk_09612FD8": 0x95cbab4,
        "gUnk_09612FF8": 0x95cbad4,
        "gUnk_09613018": 0x95cbaf4,
        "gUnk_09613038": 0x95cbb14,
        "gUnk_09613058": 0x95cbb34,
        "gUnk_09613078": 0x95cbb54,
        "gUnk_09613098": 0x95cbb74,
        "gUnk_096130B8": 0x95cbb94,
        "gUnk_096130D8": 0x95cbbb4,
        "gUnk_096130F8": 0x95cbbd4,
        "gUnk_09613118": 0x95cbbf4,
        "gUnk_09613138": 0x95cbc14,
        "gUnk_09613158": 0x95cbc34,
        "gUnk_09613178": 0x95cbc54,
        "gUnk_096131F8": 0x95cbcd4,
        "gUnk_09613218": 0x95cbcf4,
        "gUnk_09613238": 0x95cbd14,
        "gUnk_09613258": 0x95cbd34,
        "gUnk_09613278": 0x95cbd54,
        "gUnk_09613298": 0x95cbd74,
        "gUnk_096132B8": 0x95cbd94,
        "gUnk_096132D8": 0x95cbdb4,
        "gUnk_096132F8": 0x95cbdd4,
        "gUnk_09613318": 0x95cbdf4,
        "gUnk_09613338": 0x95cbe14,
        "gUnk_09613358": 0x95cbe34,
        "gUnk_09613378": 0x95cbe54,
        "gUnk_09613398": 0x95cbe74,
        "gUnk_096133B8": 0x95cbe94,
        "gUnk_096133D8": 0x95cbeb4,
        "gUnk_096133F8": 0x95cbed4,
        "gUnk_09613418": 0x95cbef4,
        "gUnk_09613438": 0x95cbf14,
        "gUnk_09613458": 0x95cbf34,
        "gUnk_09613478": 0x95cbf54,
        "gUnk_09613498": 0x95cbf74,
        "gUnk_096134B8": 0x95cbf94,
        "gUnk_096134D8": 0x95cbfb4,
        "gUnk_096134F8": 0x95cbfd4,
        "gUnk_09613518": 0x95cbff4,
        "gUnk_09613538": 0x95cc014,
        "gUnk_09613558": 0x95cc034,
        "gUnk_09613578": 0x95cc054,
        "gUnk_09613598": 0x95cc074,
        "gUnk_096135B8": 0x95cc094,
        "gUnk_096135D8": 0x95cc0b4,
        "gUnk_096135F8": 0x95cc0d4,
        "gUnk_09613618": 0x95cc0f4,
        "gUnk_09613638": 0x95cc114,
        "gUnk_09613658": 0x95cc134,
        "gUnk_09613678": 0x95cc154,
        "gUnk_09613698": 0x95cc174,
        "gUnk_096136B8": 0x95cc194,
        "gUnk_096136D8": 0x95cc1b4,
        "gUnk_096136F8": 0x95cc1d4,
        "gUnk_09613718": 0x95cc1f4,
        "gUnk_09613738": 0x95cc214,
        "gUnk_09613758": 0x95cc234,
        "gUnk_09613778": 0x95cc254,
        "gUnk_09613798": 0x95cc274,
        "gUnk_096137B8": 0x95cc294,
        "gUnk_096137D8": 0x95cc2b4,
        "gUnk_09613858": 0x95cc334,
        "gUnk_09613878": 0x95cc354,
        "gUnk_09613898": 0x95cc374,
        "gUnk_096138F8": 0x95cc3d4,
        "gUnk_09613918": 0x95cc3f4,
        "gUnk_09613938": 0x95cc414,
        "gUnk_09613958": 0x95cc434,
        "gUnk_09613978": 0x95cc454,
        "gUnk_09613998": 0x95cc474,
        "gUnk_096139B8": 0x95cc494,
        "gUnk_096139D8": 0x95cc4b4,
        "gUnk_09613A38": 0x95cc514,
        "gUnk_09613A58": 0x95cc534,
        "gUnk_09613A78": 0x95cc554,
        "gUnk_09613A98": 0x95cc574,
        "gUnk_09613AD8": 0x95cc5b4,
        "gUnk_09613AF8": 0x95cc5d4,
        "gUnk_09613B78": 0x95cc654,
        "gUnk_09613B98": 0x95cc674,
        "gUnk_09613C18": 0x95cc6f4,
        "gUnk_09613C38": 0x95cc714,
        "gUnk_09613C78": 0x95cc754,
        "gUnk_09613CB8": 0x95cc794,
        "gUnk_09613CD8": 0x95cc7b4,
        "gUnk_09613D98": 0x95cc874,
        "gUnk_09613DB8": 0x95cc894,
        "gWorldwarpAssetJp_099F22A4": 0x99f22a4,
        "gWorldwarpAssetJp_099F22C4": 0x99f22c4,
        "gMoogleAssetJp_00000001": 0x1,
        "gMoogleAssetJp_00000002": 0x2,
        "gMoogleAssetJp_00000003": 0x3,
        "gMoogleAssetJp_00000004": 0x4,
        "gMoogleAssetJp_00000005": 0x5,
        "gMoogleAssetJp_00000006": 0x6,
        "gMoogleAssetJp_00000007": 0x7,
        "gMoogleAssetJp_00000008": 0x8,
        "gMoogleAssetJp_00000009": 0x9,
        "gMoogleAssetJp_0000000A": 0xa,
        "gMoogleAssetJp_0000000B": 0xb,
        "gMoogleAssetJp_0000000C": 0xc,
        "gMoogleAssetJp_0000000D": 0xd,
        "gMoogleAssetJp_0000000E": 0xe,
        "gMoogleAssetJp_0000000F": 0xf,
        "gMoogleAssetJp_00000010": 0x10,
        "gMoogleAssetJp_00000011": 0x11,
        "gMoogleAssetJp_00000012": 0x12,
        "gMoogleAssetJp_00000013": 0x13,
        "gMoogleAssetJp_00000014": 0x14,
        "gMoogleAssetJp_00000015": 0x15,
        "gMoogleAssetJp_00000016": 0x16,
        "gMoogleAssetJp_00000017": 0x17,
        "gMoogleAssetJp_00000018": 0x18,
        "gMoogleAssetJp_00000019": 0x19,
        "gMoogleAssetJp_0000001B": 0x1b,
        "gMoogleAssetJp_0000001C": 0x1c,
        "gMoogleAssetJp_0000001D": 0x1d,
        "gMoogleAssetJp_0000001E": 0x1e,
        "gMoogleAssetJp_0000001F": 0x1f,
        "gMoogleAssetJp_00000020": 0x20,
        "gMoogleAssetJp_00000021": 0x21,
        "gMoogleAssetJp_00000022": 0x22,
        "gMoogleAssetJp_00000023": 0x23,
        "gMoogleAssetJp_00000024": 0x24,
        "gMoogleAssetJp_00000025": 0x25,
        "gMoogleAssetJp_0995892C": 0x995892c,
        "gMoogleAssetJp_09958C6C": 0x9958c6c,
        "gMoogleAssetJp_09958EEC": 0x9958eec,
        "gMoogleAssetJp_0995916C": 0x995916c,
        "gMoogleAssetJp_099ED264": 0x99ed264,
        "gMoogleAssetJp_099ED764": 0x99ed764,
        "gMoogleAssetJp_099EDC64": 0x99edc64,
        "gMoogleAssetJp_099EE164": 0x99ee164,
        "gMoogleAssetJp_099EE664": 0x99ee664,
        "gMoogleAssetJp_099EEE64": 0x99eee64,
        "gMoogleAssetJp_099F2524": 0x99f2524,
        "gMoogleAssetJp_099F2544": 0x99f2544,
        "gMoogleAssetJp_099F2564": 0x99f2564,
        "gMoogleAssetJp_099F2584": 0x99f2584,
        "gRoomAssetJp_099D2B64": 0x99d2b64,
        "gRoomAssetJp_099D3364": 0x99d3364,
        "gRoomAssetJp_099D3B64": 0x99d3b64,
        "gRoomAssetJp_099D4364": 0x99d4364,
        "gRoomAssetJp_099F11E4": 0x99f11e4,
        "gBossMapBlockJp_08125EA0": 0x8125ea0,
        "gBossMapBlockJp_0969B440": 0x969b440,
        "gBossMapBlockJp_0969BC40": 0x969bc40,
        "gBossMapBlockJp_097FAC6C": 0x97fac6c,
        "gBossMapBlockJp_097FB46C": 0x97fb46c,
        "gBossMapBlockJp_097FBC6C": 0x97fbc6c,
        "gBossMapBlockJp_097FC46C": 0x97fc46c,
        "gUnkJp_09009748": 0x09009748,
        "gUnkJp_0900974C": 0x0900974C,
    },
}

TARGET_EXTRA_LABELS = {
    "eu": [0x080059F4, 0x08005A1C, 0x08005ADC, 0x0805E968, 0x0805E9AC, 0x080C2740, 0x080DA830,
           0x080DA848, 0x080DA860, 0x080ABA38, 0x080ABA7C,
           0x0805E9F0, 0x0805EA44, 0x0805EC60, 0x0805ECE4],
}

TARGET_FUNC_SIZE = {
    "jp": {
        "func_0808B238": 0xbc,
        "mode_sioError_0": 0x10c,
        "func_08066588": 156,
        "func_080A2980": 260,
        "task_title_logo_2": 196,
    },
    "eu": {
        "func_080892E8": 632,
        "func_08089EC0": 596,
        "func_0805E89C": 32,
        "func_0801CB44": 60,
        "task_btl_escape_0": 224,
        "event_seq_3": 76,
        "func_08060F1C": 68,
        "func_080A2980": 260,
        "func_08088EB4": 136,
        "func_0808CA78": 228,
        "func_0808CB60": 88,
        "func_0808CD48": 164,
        "func_0808D73C": 180,
        "func_0808D7EC": 76,
        "func_0808DB50": 468,
        "func_0808E3E0": 152,
        "func_0808E474": 276,
        "func_0808E890": 92,
        "func_0808E8E8": 80,
        "func_0808E934": 220,
        "func_0809B76C": 252,
        "func_0809B920": 252,
        "func_080A5C60": 76,
        "func_080B0754": 308,
        "mode_sio_btl_option_0": 0x1c4,
        "Deck_Yes_No_0": 0x178,
        "Deck_Clear_0": 0x174,
        "WORLDSELECT_0": 0x94,
        "Mode_Premire_0": 0x9c,
        "LVUP_EFFECT_2": 0x80,
        "LVUP_EFFECT_0": 0x1cc,
        "func_080A5C9C": 0x104,
        "func_080A5D3C": 0x174,
        "func_0808FA0C": 0x8c,
        "func_0808D0A4": 0xe0,
        "func_0808D258": 0x1fc,
        "func_080A6C50": 0xc8,
        "func_0808686C": 0x11c,
        "func_0808A650": 0x194,
        "func_0808A7E4": 0x130,
        "func_0808B068": 0x1a0,
        "func_0808C2F0": 0xe8,
        "func_0808B208": 0x30,
        "func_0808B30C": 0x8c,
        "func_0808B398": 0x44,
        "func_0808B3DC": 0x290,
        "func_0808B238": 0xd4,
        "func_080AE28C": 0x2e0,
        "mode_sioError_0": 0x15c,
        "mode_jiminy_0": 0x4a8,
        "func_08064EF4": 0x174,
        "func_08065170": 0x150,
        "mode_sio_btl_option_2": 0x14c,
        "func_080B0874": 0x164,
        "func_080B06D4": 0x90,
        "func_080B4154": 192,
        "func_080EC04C": 148,
        "func_080ED250": 208,
        "func_080EEB00": 352,
        "func_080F7AB4": 52,
        "func_08100608": 56,
        "func_081017A0": 492,
        "func_08101970": 760,
        "mode_worldinspect_1": 388,
        "func_08100980": 0x390,
        "func_080D6C54": 232,
        "func_080D6D2C": 148,
        "task_title_lumichange_2": 152,
        "func_080D6A64": 288,
        "func_080D6B7C": 232,
        "task_title_menu_2": 232,
        "task_title_lumichange_0": 264,
        "task_title_menu_0": 672,
        "task_title_obj_0": 700,
        "ModeUpdate": 328,
        "task_bos_lst_0": 1044,
    },
}

TARGET_FUNC_ADDR = {
    "eu": {
        "func_08005458": 0x08005600,
        "func_08005474": 0x08005620,
    },
}

TARGET_DATA_SIZE = {
    "eu": {
        ("mode_sio.c", ".rodata"): 0x92,
        ("sroll.c", ".rodata"): 0x257,
        ("bos5.c", ".rodata"): 0x102D,
        ("battle_localized_09EE1520_data.c", ".data"): 0x31C,
        ("battle_localized_09EE25D0_data.c", ".data"): 0x124,
        ("card_localized_09EE9C90_data.c", ".data"): 0xE74,
        ("jiminy_records_data.c", ".rodata"): 0x42C4,
        ("mode_chkobj.c", ".data"): 0x9A90,
        ("mode_sio.c", ".data"): 0x214,
        ("mode_battle.c", ".rodata"): 0x914,
        ("formation_data.c", ".data"): 0x940,
        ("mode_debug.c", ".rodata"): 0x1F4,
        ("mode_chkobj.c", ".rodata"): 0x6350,
        ("mode_chksnd.c", ".rodata"): 0x20E8,
        ("mode_dummy.c", ".rodata"): 0x19C,
        ("event_index_data.c", ".data"): 0x924,
        ("events_074_133.c", ".rodata"): 0x28fe0,
        ("events_000_073.c", ".rodata"): 0x2fce4,
        ("events_134_196.c", ".rodata"): 0x16b34,
        ("card_riku_tutorial.c", ".data"): 0x30,
        ("card_mode_deck.c", ".data"): 0x240,
        ("card_deckexchange.c", ".rodata"): 0,
        ("card_deckexchange.c", ".data"): 0,
        ("card_deckmenu2_2.c", ".data"): 0x54,
        ("card_msgwin.c", ".data"): 0xE14,
        ("card_deck_equip.c", ".data"): 0xBC,
        ("card_stock_info.c", ".data"): 0x16C,
        ("card_help_data.c", ".data"): 0x378,
        ("card_level_up.c", ".data"): 0x134,
        ("card_mode_premire.c", ".data"): 0x68,
        ("card_friend_card.c", ".data"): 0xA4,
        ("card_prize_card_init.c", ".data"): 0xE4,
        ("card_worldselect.c", ".rodata"): 0x38,
        ("card_worldselect.c", ".data"): 0x2A74,
        ("card_deckmenu2.c", ".data"): 0x194,
        ("mode_battle.c", ".data"): 0x20,
        ("jiminy_data.c", ".data"): 0xd994,
        ("mode_test.c", ".rodata"): 0xe,
        ("mode_test.c", ".data"): 0x18,
        ("card_label_data.c", ".rodata"): 0x78c,
        ("continue_ui.c", ".data"): 0x44,
        ("card_help_data.c", ".rodata"): 0x298,
        ("card_localized_deck_labels_data.c", ".data"): 0xe4,
        ("msg_font_data.c", ".data"): 0x4bc,
        ("card_sprite_data.c", ".data"): 0x2b8,
        ("mode_sio_dbg.c", ".data"): 0x40,
        ("poo.c", ".data"): 0xc00,
        ("allmap.c", ".data"): 0xb8,
        ("title.c", ".data"): 0x9c,
        ("status.c", ".rodata"): 0x137,
        ("status.c", ".data"): 0x198,
        ("map_ui_data.c", ".data"): 0x36c,
        ("bos5.c", ".data"): 0x168,
        ("mode_ms_top.c", ".data"): 0x74,
        ("mode_ms.c", ".data"): 0x4c,
        ("ms_charge.c", ".data"): 0x60,
        ("mode_mapinspect.c", ".rodata"): 0x24,
        ("mode_mapinspect.c", ".data"): 0xc4,
        ("staff_roll_script_data.c", ".data"): 0xb50,
        ("mode_chkmov.c", ".rodata"): 0x84,
        ("jiminy_eu_localized_text_data.c", ".rodata"): 0x3ba89,
        ("jiminy_inline_text_data.c", ".rodata"): 0x1c4,
        ("jiminy_eu_localized_name_data.c", ".rodata"): 0x4150,
        ("map_text_eu_castle_oblivion_hall_name.c", ".rodata"): 0x14,
        ("jiminy_eu_room_name_data.c", ".rodata"): 0xc14,
        ("map_text_eu_unknown_place_name.c", ".rodata"): 0x14,
        ("map_text_eu_hidden_room_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_1f_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_2f_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_3f_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_4f_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_5f_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_6f_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_7f_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_8f_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_9f_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_10f_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_11f_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_12f_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_13f_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_b12_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_b11_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_b10_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_b9_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_b8_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_b7_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_b6_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_b5_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_b4_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_b3_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_b2_name.c", ".rodata"): 0x14,
        ("map_text_eu_castle_oblivion_b1_name.c", ".rodata"): 0x14,
        ("jiminy_eu_epilogue_name_data.c", ".rodata"): 0x1034,
        ("mode_chkmov.c", ".data"): 0x10,
        ("mode_test_data.c", ".data"): 0x140,
        ("msg_localized_data.c", ".data"): 0x1075c,
    },
    "jp": {
        ("sroll.c", ".rodata"): 0x287,
        ("events_074_133.c", ".rodata"): 0x33ea0,
        ("events_000_073.c", ".rodata"): 0x3cdf8,
        ("events_134_196.c", ".rodata"): 0x1f7a0,
        ("event_index_data.c", ".data"): 0x93C,
        ("card_localized_09EE9C90_data.c", ".data"): 0x28C,
        ("card_help_data.c", ".data"): 0x384,
        ("card_deckmenu2.c", ".data"): 0xF8,
        ("jiminy_data.c", ".data"): 0x23d4,
        ("card_help_data.c", ".rodata"): 0x1a28,
        ("card_localized_deck_labels_data.c", ".data"): 0x2c,
        ("staff_roll_script_data.c", ".data"): 0xb90,
        ("jiminy_inline_text_data.c", ".rodata"): 0x1c9,
    },
}

TARGET_DATA_ADDR = {
    "jp": {
        ("jiminy_inline_text_data.c", ".rodata"): 0x0813feb8,
        ("mode_jiminy.c", ".rodata"): 0x0814e570,
        ("monsgage.c", ".rodata"): 0x0814fc14,
        ("btl4.c", ".rodata"): 0x0814fc24,
        ("tutorial.c", ".rodata"): 0x0814fc68,
        ("card_help_data.c", ".rodata"): 0x0900ba1c,
        ("staff_roll_script_data.c", ".rodata"): 0x09a06558,
    },
    "eu": {
        ("mode_chkmov.c", ".rodata"): 0x0812f680,
        ("jiminy_eu_localized_text_data.c", ".rodata"): 0x0883f2db,
        ("mode_jiminy.c", ".rodata"): 0x0887f334,
        ("jiminy_inline_text_data.c", ".rodata"): 0x0888e310,
        ("jiminy_eu_localized_name_data.c", ".rodata"): 0x0888e530,
        ("map_text_eu_castle_oblivion_hall_name.c", ".rodata"): 0x088926fc,
        ("jiminy_eu_room_name_data.c", ".rodata"): 0x08892710,
        ("map_text_eu_unknown_place_name.c", ".rodata"): 0x08893370,
        ("map_text_eu_hidden_room_name.c", ".rodata"): 0x088933d4,
        ("map_text_eu_castle_oblivion_1f_name.c", ".rodata"): 0x08893480,
        ("map_text_eu_castle_oblivion_2f_name.c", ".rodata"): 0x0889352c,
        ("map_text_eu_castle_oblivion_3f_name.c", ".rodata"): 0x088935d8,
        ("map_text_eu_castle_oblivion_4f_name.c", ".rodata"): 0x08893684,
        ("map_text_eu_castle_oblivion_5f_name.c", ".rodata"): 0x08893730,
        ("map_text_eu_castle_oblivion_6f_name.c", ".rodata"): 0x088937dc,
        ("map_text_eu_castle_oblivion_7f_name.c", ".rodata"): 0x0889388c,
        ("map_text_eu_castle_oblivion_8f_name.c", ".rodata"): 0x08893938,
        ("map_text_eu_castle_oblivion_9f_name.c", ".rodata"): 0x088939e4,
        ("map_text_eu_castle_oblivion_10f_name.c", ".rodata"): 0x08893a94,
        ("map_text_eu_castle_oblivion_11f_name.c", ".rodata"): 0x08893b48,
        ("map_text_eu_castle_oblivion_12f_name.c", ".rodata"): 0x08893bfc,
        ("map_text_eu_castle_oblivion_13f_name.c", ".rodata"): 0x08893cb8,
        ("map_text_eu_castle_oblivion_b12_name.c", ".rodata"): 0x08893d78,
        ("map_text_eu_castle_oblivion_b11_name.c", ".rodata"): 0x08893e38,
        ("map_text_eu_castle_oblivion_b10_name.c", ".rodata"): 0x08893ef4,
        ("map_text_eu_castle_oblivion_b9_name.c", ".rodata"): 0x08893fac,
        ("map_text_eu_castle_oblivion_b8_name.c", ".rodata"): 0x08894068,
        ("map_text_eu_castle_oblivion_b7_name.c", ".rodata"): 0x08894124,
        ("map_text_eu_castle_oblivion_b6_name.c", ".rodata"): 0x088941dc,
        ("map_text_eu_castle_oblivion_b5_name.c", ".rodata"): 0x08894294,
        ("map_text_eu_castle_oblivion_b4_name.c", ".rodata"): 0x0889434c,
        ("map_text_eu_castle_oblivion_b3_name.c", ".rodata"): 0x08894408,
        ("map_text_eu_castle_oblivion_b2_name.c", ".rodata"): 0x088944c0,
        ("map_text_eu_castle_oblivion_b1_name.c", ".rodata"): 0x08894578,
        ("jiminy_eu_epilogue_name_data.c", ".rodata"): 0x0889548c,
        ("monsgage.c", ".rodata"): 0x088964c0,
        ("btl4.c", ".rodata"): 0x088964d0,
        ("tutorial.c", ".rodata"): 0x08896514,
        ("mode_test.c", ".rodata"): 0x08896644,
        ("mode_test_support.c", ".rodata"): 0x08f7f15c,
        ("msg_portrait_data.c", ".rodata"): 0x090cb778,
        ("card_help_data.c", ".rodata"): 0x090d15a0,
        ("mode_wlogo.c", ".rodata"): 0x095da8ac,
        ("mode_pooh.c", ".rodata"): 0x096c934c,
        ("mode_mapinspect.c", ".rodata"): 0x09999a50,
        ("ms.c", ".rodata"): 0x09999a74,
        ("mode_backupstat.c", ".rodata"): 0x09999a88,
        ("staff_roll_script_data.c", ".rodata"): 0x09aaf400,
        ("mode_battle.c", ".data"): 0x09f3ea64,
        ("mode_chkmov.c", ".data"): 0x09f49a6c,
        ("jiminy_data.c", ".data"): 0x09f49abc,
        ("mode_test.c", ".data"): 0x09f59130,
        ("mode_test_data.c", ".data"): 0x09f5d574,
        ("continue_ui.c", ".data"): 0x09f5d7e4,
        ("msg_localized_data.c", ".data"): 0x09f5d828,
        ("event_background_data.c", ".data"): 0x09f6df84,
        ("map_ui_data.c", ".data"): 0x09f843d8,
        ("mode_ms_top.c", ".data"): 0x09f84ee8,
        ("ms_charge.c", ".data"): 0x09f84fa8,
        ("mode_mapinspect.c", ".data"): 0x09f85008,
    },
}

TARGET_BLOB_REGIONS = {
    "jp": ((0x0814FC76, "rodata_movie_alignment"), (0x090089B0, "rodata_regtables3_gap_10")),
    "eu": (
        (0x0812FB22, "rodata_movie_alignment"),
        (0x09F49910, "rodata_registrations"),
    ),
}

INCLUDE_ASM_RE = re.compile(r'INCLUDE_ASM\("([^"]+)/([^"/]+)\.s"\)')

THUMB = """.syntax unified
	.text
{align}\t.global {name}
\t.thumb
\t.thumb_func
\t.type {name}, %function
{name}:
\t.incbin "{asset}"
.syntax divided
"""

DATA = """.syntax unified
	.text
{align}\t.global {name}
{name}:
\t.incbin "{asset}"
.syntax divided
"""

PART = """{align}	.global {name}
	.thumb
	.thumb_func
	.type {name}, %function
{name}:
	.incbin "{asset}"
"""

EMPTY = """.syntax unified
	.text
\t.global {name}
\t.thumb
\t.thumb_func
\t.type {name}, %function
{name}:
.syntax divided
"""


def mask(b):
    out = bytearray(b)
    for k in range(0, len(b) - 1, 2):
        h = struct.unpack_from("<H", b, k)[0]
        if 0xF000 <= h <= 0xFFFF:
            struct.pack_into("<H", out, k, 0)
    for k in range(0, len(b) - 3, 4):
        w = struct.unpack_from("<I", b, k)[0]
        if (w >> 24) in (0x08, 0x09, 0x02, 0x03):
            struct.pack_into("<I", out, k, 0)
    return bytes(out)


def near_identical(a, b):
    diff = sum(1 for k in range(0, len(a) - 1, 2) if a[k:k + 2] != b[k:k + 2])
    return diff <= 8 and diff * 64 <= len(a)


VERSION_IF_RE = re.compile(r"#\s*(ifdef|ifndef|if|else|elif|endif)\b(.*)")


def version_cond(rest, ver):
    tag = f"VERSION_{ver.upper()}"
    expr = re.sub(r"defined\s*\(\s*(\w+)\s*\)", r"\1", rest)
    expr = re.sub(r"defined\s+(\w+)", r"\1", expr)
    expr = expr.replace("||", " or ").replace("&&", " and ")
    expr = re.sub(r"!(?!=)", " not ", expr)
    expr = re.sub(r"\b[A-Za-z_]\w*\b",
                  lambda m: "True" if m.group(0) == tag else
                  m.group(0) if m.group(0) in ("and", "or", "not", "True", "False") else "False",
                  expr)
    try:
        return bool(eval(expr, {"__builtins__": {}}, {}))
    except Exception:
        return tag in rest


def active_lines(path, ver):
    """Source lines this version actually compiles.

    A function that only diverges in one version is guarded against that
    version alone, so the same line is C for one build and asm for another.
    Only VERSION_* conditions are interpreted; anything else stays active.
    """
    tag = f"VERSION_{ver.upper()}"
    stack = []
    for line in Path(path).read_text().splitlines():
        m = VERSION_IF_RE.match(line.strip())
        if m:
            kind, rest = m.group(1), m.group(2)
            if kind in ("ifdef", "ifndef", "if", "elif"):
                versioned = "VERSION_" in rest
                if not versioned:
                    frame = (False, True)
                elif kind == "ifndef":
                    frame = (True, tag not in rest)
                elif kind == "ifdef":
                    frame = (True, tag in rest)
                else:
                    frame = (True, version_cond(rest, ver))
                if kind == "elif" and stack:
                    stack[-1] = frame
                else:
                    stack.append(frame)
            elif kind == "else":
                if stack:
                    versioned, state = stack[-1]
                    stack[-1] = (versioned, not state if versioned else True)
            elif kind == "endif":
                if stack:
                    stack.pop()
            continue
        if all(state for _versioned, state in stack):
            yield line


def active_includes(path, ver):
    out = []
    for line in active_lines(path, ver):
        m = INCLUDE_ASM_RE.search(line)
        if m:
            out.append((m.group(1), m.group(2)))
    return out


def active_definitions(path, ver):
    pat = re.compile(r"^[A-Za-z_][A-Za-z0-9_* ]*\b((?:func_)?" + ver + r"_([0-9A-Fa-f]{8}))\(.*\)\s*\{")
    out = []
    for line in active_lines(path, ver):
        m = pat.match(line)
        if m:
            out.append((m.group(1), int(m.group(2), 16)))
    return out


def load_rows(ver):
    rows = load_funcmap(f"config/{ver}/funcmap.txt")
    for r in rows:
        at = TARGET_FUNC_ADDR.get(ver, {}).get(r[0])
        if at is not None:
            r[3] = at
            if r[4] == "absent":
                r[4] = "entry"
    for f in sorted(Path("src").rglob("*.c"), key=lambda path: path.name):
        for name, at in active_definitions(f, ver):
            rows.append([name, 0, 0, at, "named"])
    return rows


def load_funcmap(path):
    rows = []
    for line in Path(path).read_text().splitlines():
        nm, ua, sz, va, how = line.split("\t")
        rows.append([nm, int(ua, 16), int(sz), None if va == "-" else int(va, 16), how])
    return rows


def complete(rows, code_end, flexible, unit_of=None, clean=None, fixed=None):
    unit_of = unit_of or {}
    clean = clean or (lambda r: True)
    fixed = fixed or {}
    n = len(rows)
    i = 0
    while i < n:
        if rows[i][3] is not None or rows[i][4] == "absent":
            i += 1
            continue
        j = i
        while j < n and rows[j][3] is None and rows[j][4] != "absent":
            j += 1
        prev = next((rows[k] for k in range(i - 1, -1, -1)
                     if rows[k][3] is not None), None)
        nxt = next((rows[k] for k in range(j, n) if rows[k][3] is not None), None)
        if prev is None:
            i = j
            continue
        begin = prev[3] + fixed.get(prev[0], prev[2])
        stop = nxt[3] if nxt is not None else code_end
        want = sum(rows[k][2] for k in range(i, j))
        span = max(0, stop - begin)
        if span == 0:
            for k in range(i, j):
                rows[k][4] = "absent"
            i = j
            continue
        for k in range(i, j):
            rows[k][3] = begin
            share = rows[k][2] if want == 0 else round(span * rows[k][2] / want / 4) * 4
            begin = min(begin + max(0, share), stop)
        i = j

    present = sorted((r for r in rows if r[3] is not None and r[4] != "absent"),
                     key=lambda r: r[3])
    size, start = {}, {}
    pos = present[0][3] if present else 0
    for k, r in enumerate(present):
        nxt = present[k + 1][3] if k + 1 < len(present) else code_end
        if r[0] in flexible:
            if r[4] in TRUSTED or (k and r[3] > pos and clean(present[k - 1])
                                   and r[4] != "-" and unit_of.get(r[0])
                                   != unit_of.get(present[k - 1][0])):
                pos = r[3]
            start[id(r)] = pos
            size[id(r)] = max(0, nxt - pos)
            pos = nxt
        elif r[2] == 0:
            start[id(r)] = r[3]
            size[id(r)] = max(0, nxt - r[3])
            pos = nxt
        else:
            nk = present[k + 1][4] if k + 1 < len(present) else None
            tsz = fixed.get(r[0], r[2])

            if (r[0] not in fixed
                    and nxt > r[3] and nk in TRUSTED
                    and r[4] in TRUSTED
                    and not clean(r)):
                tsz = nxt - r[3]
            start[id(r)] = r[3]
            size[id(r)] = tsz
            pos = r[3] + tsz
    for r in rows:
        r[3] = start.get(id(r), r[3] if r[3] is not None else 0)
        r.append(size.get(id(r), 0))
    return rows


def symbol_map(rows, us, ot, literal_loads, function_modes=None):
    function_modes = function_modes or {}
    pairs = {}
    for nm, ua, sz, va, how, vsz in rows:
        if va is None or vsz != sz or sz == 0:
            continue
        a = us[ua - ROM_BASE:ua - ROM_BASE + sz]
        b = ot[va - ROM_BASE:va - ROM_BASE + sz]
        if len(b) != sz or not near_identical(mask(a), mask(b)):
            continue
        loads = literal_loads
        if ua in function_modes:
            loads = literal_loads | trace_literal_loads(us, ua, sz, function_modes[ua])
        for w1, w2 in literal_pointer_pairs(us, ot, ua, va, sz, loads):
            pairs.setdefault(w1, {})
            pairs[w1][w2] = pairs[w1].get(w2, 0) + 1
    res = {}
    tied = {}
    for k, v in pairs.items():
        best = sorted(v.items(), key=lambda x: -x[1])
        if len(best) == 1 or best[0][1] > 2 * best[1][1]:
            res[k] = best[0][0]
        else:
            tied[k] = [w for w, _n in best]
    keys = sorted(res)
    for k, cands in tied.items():
        i = bisect.bisect_left(keys, k)
        near = [keys[j] for j in (i - 1, i) if 0 <= j < len(keys)]
        if not near:
            continue
        deltas = {res[n] - n for n in near}
        pick = [w for w in cands if w - k in deltas]
        if len(pick) == 1:
            res[k] = pick[0]
    return res


def translator(res, provenance=None):
    keys = sorted(res)
    provenance = provenance or {}

    def tr(a):
        if a < 0x02000000 or a >= 0x0E000000:
            return a, "const"
        if a in res:
            return res[a], "data" if a in provenance else "exact"
        i = bisect.bisect_left(keys, a)
        lo = keys[i - 1] if i > 0 else None
        hi = keys[i] if i < len(keys) else None
        if lo is None and hi is None:
            return None, "unknown"
        if lo is None:
            return a + res[hi] - hi, "interp"
        if hi is None or (res[lo] - lo) == (res[hi] - hi):
            return a + res[lo] - lo, "interp"
        return a + res[lo] - lo, "interp?"

    return tr


def regional_symbols(lines, tr, target_only=None, absent=()):
    target_only = target_only or {}
    absent = set(absent)
    if absent & target_only.keys():
        raise ValueError('a regional symbol cannot be both present and absent')
    out, uncertain = [], []
    for line in lines:
        stripped = line.split("#")[0].strip()
        if not stripped:
            out.append(line)
            continue
        nm, a = (x.strip() for x in stripped.split("="))
        if nm in absent:
            continue
        b, how = tr(int(a, 16))
        if b is None:
            b, how = int(a, 16), "unknown"
        if how in ("interp?", "unknown"):
            uncertain.append((nm, how))
        out.append(f"{nm} = {b:#010x}")
    for nm, a in target_only.items():
        out.append(f"{nm} = {a:#010x}")
    return out, uncertain


def main():
    p = argparse.ArgumentParser()
    p.add_argument("version")
    p.add_argument("code")
    p.add_argument("-q", "--quiet", action="store_true")
    args = p.parse_args()
    ver = args.version

    us = baserom.read("us", purpose="gen_version.py")
    ot = baserom.read(ver, purpose="gen_version.py")
    regional = load_sidecars("config", {"us": us, ver: ot})
    regional_plan = regional["regions"][ver]
    literal_loads = load_literal_loads("build/us/com_us.elf", ROM_BASE, CODE_HI)
    function_modes = load_function_modes("build/us/com_us.elf", ROM_BASE, CODE_HI)
    rows = load_rows(ver)

    owner = {}
    cur = None
    for line in Path("build/us/com_us.map").read_text().splitlines():
        m = re.match(r"^ \.text +0x0*8[0-9a-f]{6} +0x[0-9a-f]+ (\S+)$", line)
        if m:
            cur = m.group(1)
            continue
        if cur is None or "=" in line:
            continue
        m = re.match(r"^ +0x0*8[0-9a-f]{6} +(\S+)$", line)
        if m:
            owner.setdefault(m.group(1), cur)

    flexible = set()
    for f in sorted(Path("src").rglob("*.c"), key=lambda path: path.name):
        for tu, name in active_includes(f, ver):
            flexible.add(name)
        for name, at in active_definitions(f, ver):
            owner[name] = f"build/us/src/{f.stem}.o"

    def identical(r):
        a = us[r[1] - ROM_BASE:r[1] - ROM_BASE + r[2]]
        b = ot[r[3] - ROM_BASE:r[3] - ROM_BASE + r[2]]
        return mask(a) == mask(b)

    def clean(r):
        return r[0] in flexible or identical(r)

    anchors = TARGET_ANCHORS.get(ver, {})
    fixed = TARGET_FUNC_SIZE.get(ver, {})

    provisional = [r for r in rows if r[3] is not None]
    guess_end = provisional[-1][3] + (CODE_HI - provisional[-1][1])
    rows = complete(rows, guess_end, flexible, owner, clean, fixed)
    res = symbol_map(rows, us, ot, literal_loads, function_modes)
    res.update(anchors)
    tr = translator(res)

    code_end, how_end = tr(CODE_HI)
    if code_end != guess_end:
        rows = load_rows(ver)
        rows = complete(rows, code_end, flexible, owner, clean, fixed)
        res = symbol_map(rows, us, ot, literal_loads, function_modes)
        res.update(anchors)
        tr = translator(res)
    evidence = load_evidence("config/rom_data_evidence.yaml")
    data, provenance = data_symbol_map(evidence, ver, us, ot, res, CODE_HI, code_end)
    res.update(data)
    tr = translator(res, provenance)
    print(f"{ver}: code region {rows[0][3]:#x} .. {code_end:#x} ({how_end})")
    if data:
        print(f"  data pointer evidence: {len(data)} directly derived targets")

    present = sorted((r for r in rows if r[5]), key=lambda r: r[3])
    gaps = {}
    for a, b in zip(present, present[1:]):
        end = a[3] + a[5]
        if b[3] <= end:
            continue
        kind = "boundary" if owner.get(a[0]) != owner.get(b[0]) else "inside"
        word = struct.unpack_from("<I", ot, end - ROM_BASE)[0]
        if b[3] - end == 4 and (word >> 24) in (0x02, 0x03, 0x08, 0x09):
            kind = "pool"
        gaps[end] = (b[3] - end, kind, a, b, clean(a))

    out, uncertain = regional_symbols(
        Path("config/us/symbols.txt").read_text().splitlines(), tr,
        TARGET_ONLY_SYMBOLS.get(ver, {}), set(TARGET_ABSENT_SYMBOLS.get(ver, ())) | managed_asset_names(regional))
    regional_ledger = []
    for line in out:
        stripped = line.split("#", 1)[0].strip()
        if stripped:
            name, address = stripped.split("=")
            regional_ledger.append((name.strip(), int(address.strip(), 16)))
    asset_symbols(regional_plan, regional_ledger)
    Path(f"config/{ver}/symbols.txt").write_text("\n".join(out) + "\n")
    print(f"  symbols.txt: {len(out)} lines, {len(uncertain)} uncertain")

    byname = {r[0]: r for r in rows}
    asm_root = Path(f"asm/{ver}/nonmatchings")
    wrote = missing = absent = 0
    kept = set()
    filled = set()
    for src in sorted(Path("src").rglob("*.c"), key=lambda path: path.name):
        for tu, name in active_includes(src, ver):
            m = re.fullmatch(f"{ver}_([0-9A-Fa-f]{{8}})", name)
            if m:
                at = int(m.group(1), 16)
                gap = gaps.get(at)
                d = asm_root / tu
                d.mkdir(parents=True, exist_ok=True)
                if gap is None:
                    (d / f"{name}.s").write_text(EMPTY.format(name=name))
                else:
                    filled.add(at)
                    cuts = ([at]
                            + [x for x in TARGET_EXTRA_LABELS.get(ver, [])
                               if at < x < at + gap[0]]
                            + [at + gap[0]])
                    body = "".join(
                        PART.format(name=name if lo == at else f"{ver}_{lo:08X}",
                                    asset=asset(ver, lo, hi),
                                    align="\t.align 2, 0\n" if lo % 4 == 0 else "")
                        for lo, hi in zip(cuts, cuts[1:]) if hi > lo)
                    (d / f"{name}.s").write_text(
                        ".syntax unified\n\t.text\n" + body + ".syntax divided\n")
                kept.add(d / f"{name}.s")
                wrote += 1
                continue
            r = byname.get(name)
            if r is None:
                missing += 1
                print(f"  missing layout for {tu}/{name}")
                continue
            if r[5] == 0:
                absent += 1
            usasm = Path(f"asm/us/nonmatchings/{tu}/{name}.s")
            d = asm_root / tu
            d.mkdir(parents=True, exist_ok=True)
            if (usasm.exists() and r[5] != 0
                    and ".include \"asm/" in usasm.read_text()):
                (d / f"{name}.s").write_text(usasm.read_text())
            else:
                tmpl = DATA if usasm.exists() and ".thumb_func" not in usasm.read_text() else THUMB
                if r[5] == 0:
                    tmpl = EMPTY
                (d / f"{name}.s").write_text(
                    tmpl.format(name=name, asset=asset(ver, r[3], r[3] + r[5]),
                                align="\t.align 2, 0\n" if r[3] % 4 == 0 and r[5] else ""))
            kept.add(d / f"{name}.s")
            wrote += 1
    stale = 0
    for old in asm_root.glob("*/*.s"):
        if old not in kept:
            old.unlink()
            stale += 1
    for d in asm_root.glob("*"):
        if d.is_dir() and not any(d.iterdir()):
            d.rmdir()
    print(f"  chunks: {wrote} written ({absent} empty), {missing} missing"
          + (f", {stale} stale removed" if stale else ""))

    Path(f"asm/{ver}").mkdir(parents=True, exist_ok=True)

    fillers = []
    extra_labels = TARGET_EXTRA_LABELS.get(ver, [])
    slack = 0
    for at, (size, kind, a, b, clean) in sorted(gaps.items()):
        unit = owner.get(a[0], "?").rsplit("/", 1)[-1][:-2]
        if kind == "boundary" and clean:
            nm = f"{ver}_{at:08X}.s"
            cuts = [at] + [x for x in extra_labels if at < x < at + size] + [at + size]
            body = "".join(
                PART.format(name=f"{ver}_{lo:08X}", asset=asset(ver, lo, hi),
                            align="\t.align 2, 0\n" if lo % 4 == 0 else "")
                for lo, hi in zip(cuts, cuts[1:]) if hi > lo)
            Path(f"asm/{ver}/{nm}").write_text(
                ".syntax unified\n\t.text\n" + body + ".syntax divided\n")
            fillers.append((at, nm))
            print(f"  filler {nm}: {size:#x} bytes after {a[0]} ({unit})")
        elif at in filled:
            pass
        elif kind == "pool":
            print(f"  gap {size:#x} at {at:#x} inside {unit} after {a[0]}: a pool word,"
                  f" so {a[0]} is longer in {ver}")
        elif clean:
            print(f"  gap {size:#x} at {at:#x} inside {unit} after {a[0]} before {b[0]}:"
                  f" needs INCLUDE_ASM(\"{unit}/{ver}_{at:08X}.s\")")
        else:
            slack += size
    if slack:
        print(f"  slack after divergent functions: {slack:#x} bytes")
    fresh = {nm for _at, nm in fillers}
    for old in Path(f"asm/{ver}").glob(f"{ver}_*.s"):
        if old.name not in fresh:
            old.unlink()

    def unit_key(name):
        if name.startswith("@"):
            arch, member = name[1:].split(":")
            obj = f"build/us/lib/{arch}/{member}"
        elif name.endswith(".c"):
            obj = f"build/us/src/{name[:-2]}.o"
        elif name.endswith(".s"):
            obj = f"build/us/asm/{name[:-2]}.o"
        else:
            return None
        named = sorted(r[3] for r in rows
                       if owner.get(r[0]) == obj and r[5] and r[4] == "named")
        addrs = named or sorted(r[3] for r in rows
                                if owner.get(r[0]) == obj and r[5])
        if not addrs and any(owner.get(r[0]) == obj for r in rows):
            return "absent"
        return addrs[len(addrs) // 2] if addrs else None

    placed = re.compile(r"^ (\.[\w.]+)? +0x([0-9a-f]+) +0x([0-9a-f]+) build/us/src/(\S+)\.o$")
    spans, sections = {}, {}
    pending = None
    for line in Path("build/us/com_us.map").read_text().splitlines():
        m = re.fullmatch(r" (\.[\w.]+)", line)
        if m:
            pending = m.group(1)
            continue
        m = placed.match(line)
        if not m or not int(m.group(3), 16):
            continue
        section = m.group(1) or pending
        pending = None
        unit = m.group(4) + ".c"
        sections.setdefault(unit, set()).add(section)
        if section in (".rodata", ".data"):
            spans[(unit, section)] = (int(m.group(2), 16), int(m.group(3), 16))

    def data_only(nm):
        placed_in = sections.get(nm, set())
        return bool(placed_in) and placed_in <= {".rodata", ".data"}

    us_units = [line.split()[0] for line in Path("config/us/units.txt").read_text().splitlines()
                if line.strip() and not line.startswith("#")]
    manifests = [manifest for manifest in assetgen.load_manifests()
                 if any(obj["name"] in us_units for obj in manifest.objects.get("us", []))]
    generated = {obj["name"] for manifest in manifests for objects in manifest.objects.values() for obj in objects}
    head, body, cdata, blobs, placed = [], [], [], [], set()
    for manifest in manifests:
        for obj in manifest.objects.get(ver, []):
            cdata.append((obj["start"], obj["end"] - obj["start"], f"{obj['name']}(.rodata)"))
    for line in Path("config/us/units.txt").read_text().splitlines():
        t = line.strip()
        if not t or t.startswith("#"):
            head.append(line)
            continue
        nm = t.split()[0]
        if nm in generated:
            continue
        if nm == "transform_veneers.s":
            size = validate_transform_veneers(ot, code_end, byname["func_08109AAC"][3])
            cdata.append((code_end, size, "transform_veneers.s(.text)"))
            continue
        if nm.endswith(".s") and (Path("asm/us") / nm).exists():
            blobs.append(nm)
            continue
        if nm.endswith(".c"):
            for sec in (".rodata", ".data"):
                key = nm, sec
                if key not in spans:
                    continue
                lo, size = spans[key]
                here = TARGET_DATA_ADDR.get(ver, {}).get(key)
                if here is None:
                    here, _ = tr(lo)
                size = TARGET_DATA_SIZE.get(ver, {}).get(key, size)
                cdata.append((here, size, f"{nm}({sec})"))
                placed.add(key)
            if data_only(nm):
                continue
        key = unit_key(nm)
        if key is None and nm.endswith(".s"):
            head.append(line)
            continue
        body.append((key, line))
    for key, here in TARGET_DATA_ADDR.get(ver, {}).items():
        if key not in placed:
            cdata.append((here, TARGET_DATA_SIZE.get(ver, {})[key], f"{key[0]}({key[1]})"))
    dropped = [l for k, l in body if k == "absent"]
    for l in dropped:
        print(f"  unit dropped: {l}")
    body = [(k, l) for k, l in body if k != "absent"]
    body += [(at, nm) for at, nm in fillers]
    ordered = [l for k, l in sorted(body, key=lambda kl: (kl[0] is None, kl[0] or 0))]
    moved = [l for (k, l), l2 in zip(body, ordered) if l != l2]
    if moved:
        print(f"  units reordered: {len(moved)}")

    pad = len(ot)

    while pad > 0 and ot[pad - 1] == 0xFF:
        pad -= 1
    found = []
    incbin = re.compile(r'\.incbin\s+"assets/us/([0-9A-F]{8})-([0-9A-F]{8})\.bin"')
    for nm in blobs:
        src = Path("asm/us") / nm
        m = incbin.search(src.read_text())
        if not m:
            raise SystemExit(f"error: {src} is a US data unit with no assets/us incbin to anchor its offset")
        off = int(m.group(1), 16) - ROM_BASE
        base = nm[:-2]

        if base.startswith(("asset_us_", "padding_us_")):
            continue
        pat = us[off:off + 64]
        i = ot.find(pat)
        how = "content"

        if i < 0 or ot.find(pat, i + 1) >= 0:
            i, how = tr(ROM_BASE + off)[0], "interp"

            if i is None:
                continue
            i -= ROM_BASE
        found.append((ROM_BASE + i, base, how))
    found.extend((address, name, "explicit")
                 for address, name in TARGET_BLOB_REGIONS.get(ver, ()))
    found = apply_movie_regions(found, cdata, load_movie_assets("config/movie_assets.yaml", ver, ot))
    regions = []

    for here, base, how in sorted(found, key=lambda item: (item[0], item[2] != "explicit", item[1])):
        if regions and here <= regions[-1][0]:
            print(f"  data region {base} dropped, not monotone ({how})")
            continue
        regions.append((here, base))

    used = {}
    blob_names = set()

    def blob(lo, hi):
        out = []
        cuts = [a for a, _n in regions if lo < a < hi]
        for a, b in zip([lo] + cuts, cuts + [hi]):
            if a >= b:
                continue
            k = bisect.bisect_right([x[0] for x in regions], a) - 1
            base = regions[k][1] if k >= 0 else "data"
            used[base] = used.get(base, 0) + 1
            nm = f"{base}.s" if used[base] == 1 else f"{base}_at_{a:08X}.s"
            if nm in blob_names:
                raise ValueError(f"duplicate regional blob filename: {nm}")
            blob_names.add(nm)
            out.append((nm, a, b))
        return out

    tail, bounds = [], []
    pos = code_end
    for lo, size, line in sorted(cdata):
        if pos < lo < pos + 4 and lo % 4 == 0 and not any(ot[pos - ROM_BASE:lo - ROM_BASE]):
            pos = lo
        if lo > pos:
            for nm, a, b in blob(pos, lo):
                bounds.append((nm, a, b))
                tail.append(f"{nm}(.rodata)")
            pos = lo
        tail.append(line)
        pos += size
    for nm, a, b in blob(pos, ROM_BASE + pad):
        bounds.append((nm, a, b))
        tail.append(f"{nm}(.rodata)")
    entries, line_of = [], {}
    for line in head + ordered + tail:
        t = line.strip()
        if not t or t.startswith("#"):
            continue
        nm, section = t.split()[0], ".text"
        if nm.endswith(")"):
            nm, _, spec = nm.partition("(")
            section = spec[:-1]
        else:
            line_of[nm] = t
        entries.append((nm, section))
    units = [line_of.get(nm, nm) for nm in link_order(entries)]

    for nm, lo, hi in bounds:
        Path(f"asm/{ver}/{nm}").write_text(
            blob_source(ver, lo, hi, ot[lo - ROM_BASE:hi - ROM_BASE]))
    fresh = {nm for nm, _lo, _hi in bounds}
    for old in Path(f"asm/{ver}").glob("*.s"):
        if old.name not in fresh and ".global data_" in old.read_text():
            old.unlink()
    print("  " + "  ".join(f"{nm} {lo:#x}..{hi:#x}" for nm, lo, hi in bounds))

    Path(f"config/{ver}/units.txt").write_text("\n".join(units) + "\n")
    print(f"  units.txt: {len(units)} entries")
    if not args.quiet:
        for nm, how in uncertain:
            print(f"    {how:9s} {nm}")


if __name__ == "__main__":
    main()
