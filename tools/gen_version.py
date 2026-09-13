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
from function_pointer_evidence import literal_pointer_pairs, load_literal_loads, load_opaque_function_modes, trace_literal_loads
from regional_data import asset_symbols, load_sidecars, managed_placements, merge_placements, placement_overrides

ROM_BASE = 0x08000000
CODE_HI = 0x081213C4
ROM_END = 0x0A000000

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


def blob_source(code, lo, hi, data):
    head = f'\t.section .rodata\n\t.global data_{lo:08X}\ndata_{lo:08X}:\n'
    names = veneer_labels(data)

    if not names:
        return head + f'\t.incbin "roms/{code}.gba", {lo - ROM_BASE:#x}, {hi - lo:#x}\n'
    body = ""

    for i, name in enumerate(names):
        at = lo + i * VENEER_SIZE
        body += (f'\t.thumb_func\n\t.global {name}\n{name}:\n'
                 f'\t.incbin "roms/{code}.gba", {at - ROM_BASE:#x}, {VENEER_SIZE:#x}\n')
    return head + body

TRUSTED = ("named", "xref", "global", "body", "fill", "near", "match")

TARGET_ANCHORS = {
    "eu": {
        0x09ED9BA8: 0x09F57460,
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
        0x09992F70: 0x099991EC,
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
    },
    "jp": {
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
    },
}

TARGET_ABSENT_SYMBOLS = {
    "eu": {
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
    },
    "jp": {
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
    },
}

TARGET_ONLY_SYMBOLS = {
    "eu": {
        "gUnkEu_094E04E4": 0x094E04E4,
        "gUnkEu_09533324": 0x09533324,
        "gUnkEu_09F6FE04": 0x09F6FE04,
        "gUnkEu_09F72D08": 0x09F72D08,
        "gUnkEu_094C6C22": 0x094C6C22,
        "gUnkEu_094C789A": 0x094C789A,
        "gUnkEu_094C7472": 0x094C7472,
        "gUnkEu_094C704A": 0x094C704A,
        "gUnkEu_09F72A3C": 0x09F72A3C,
        "gUnkEu_09F72A50": 0x09F72A50,
        "gUnkEu_09F72A64": 0x09F72A64,
        "gModeLang": 0x09F3EA64,
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
        "gUnkEu_09F80124": 0x09F80124,
        "gUnkEu_09F80138": 0x09F80138,
        "gUnkEu_09F801D4": 0x09F801D4,
        "gUnkEu_09F80200": 0x09F80200,
        "gUnkEu_09F80214": 0x09F80214,
        "gUnkEu_09F81A80": 0x09F81A80,
        "gUnkEu_09F81A9C": 0x09F81A9C,
        "gUnkEu_09F81AF0": 0x09F81AF0,
        "gUnkEu_09F81AD4": 0x09F81AD4,
        "gUnkEu_09F81AB8": 0x09F81AB8,
        "gUnkEu_09F81B0C": 0x09F81B0C,
        "gUnkEu_0974E3CC": 0x0974E3CC,
        "gUnkEu_0974EC7C": 0x0974EC7C,
        "gUnkEu_0975038C": 0x0975038C,
        "gUnkEu_0974FBDC": 0x0974FBDC,
        "gUnkEu_0974F42C": 0x0974F42C,
        "gUnkEu_097462F2": 0x097462F2,
        "gUnkEu_09746CA4": 0x09746CA4,
        "gUnkEu_097483B4": 0x097483B4,
        "gUnkEu_09747C04": 0x09747C04,
        "gUnkEu_09747454": 0x09747454,
        "gUnkEu_09748BA6": 0x09748BA6,
        "gUnkEu_0974A284": 0x0974A284,
        "gUnkEu_0974D47A": 0x0974D47A,
        "gUnkEu_0974C504": 0x0974C504,
        "gUnkEu_0974B306": 0x0974B306,
        "gUnkEu_0973F058": 0x0973F058,
        "gUnkEu_09741E9A": 0x09741E9A,
        "gUnkEu_09742A74": 0x09742A74,
        "gUnkEu_0974507E": 0x0974507E,
        "gUnkEu_097445AC": 0x097445AC,
        "gUnkEu_09743812": 0x09743812,
        "gUnkEu_09745B92": 0x09745B92,
        "gUnkEu_09F81A04": 0x09F81A04,
        "gUnkEu_09F80228": 0x09F80228,
        "gUnkEu_09750AF8": 0x09750AF8,
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
        "gUnkEu_09750EE4": 0x09750EE4,
        "gUnkEu_09751ADE": 0x09751ADE,
        "gUnkEu_097516F8": 0x097516F8,
        "gUnkEu_097512CA": 0x097512CA,
        "gUnkEu_09F81C54": 0x09F81C54,
        "gUnkEu_09F81C5C": 0x09F81C5C,
        "gUnkEu_09F81C74": 0x09F81C74,
        "gUnkEu_09F81C6C": 0x09F81C6C,
        "gUnkEu_09F81C64": 0x09F81C64,
        "gUnkEu_0973F402": 0x0973F402,
        "gUnkEu_0973FC6A": 0x0973FC6A,
        "gUnkEu_097415E8": 0x097415E8,
        "gUnkEu_09740D62": 0x09740D62,
        "gUnkEu_09740536": 0x09740536,
        "gUnkEu_09F81A1C": 0x09F81A1C,
        "gUnkEu_09F81A08": 0x09F81A08,
        "gUnkEu_09F81A34": 0x09F81A34,
        "gUnkEu_09F81A20": 0x09F81A20,
        "gUnkEu_09F81A7C": 0x09F81A7C,
        "gUnkEu_09F81A68": 0x09F81A68,
        "gUnkEu_09F81A64": 0x09F81A64,
        "gUnkEu_09F81A50": 0x09F81A50,
        "gUnkEu_09F81A4C": 0x09F81A4C,
        "gUnkEu_09F81A38": 0x09F81A38,
        "gUnkEu_0973EEFE": 0x0973EEFE,
        "gUnkEu_09A86E60": 0x09A86E60,
        "gUnkEu_09F84EE8": 0x09F84EE8,
        "gUnkEu_09F84EFC": 0x09F84EFC,
        "gUnkEu_09F84F10": 0x09F84F10,
        "gUnkEu_09F84F24": 0x09F84F24,
        "gUnkEu_09F84F38": 0x09F84F38,
        "gUnkEu_09F84F5C": 0x09F84F5C,
        "gUnkEu_09A3D400": 0x09A3D400,
        "gUnkEu_09A3E800": 0x09A3E800,
        "gUnkEu_09A3FC00": 0x09A3FC00,
        "gUnkEu_09A41000": 0x09A41000,
        "gUnkEu_09F85058": 0x09F85058,
        "gUnkEu_09999A50": 0x09999A50,
        "gUnkEu_09F8506C": 0x09F8506C,
        "gUnkEu_09F85080": 0x09F85080,
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
        "gModeChkmov": 0x09F49A6C,
        "gUnkEu_08890EC0": 0x08890EC0,
        "gUnkEu_08895CF8": 0x08895CF8,
        "gUnkEu_08C9BD82": 0x08C9BD82,
        "gUnkEu_08C9BD8C": 0x08C9BD8C,
        "gUnkEu_08C9BD9C": 0x08C9BD9C,
        "gUnkEu_08C9BDAC": 0x08C9BDAC,
        "gUnkEu_08C9A538": 0x08C9A538,
        "gUnkEu_08C9A4CC": 0x08C9A4CC,
        "gUnkEu_08C9A564": 0x08C9A564,
        "gUnkEu_08C9A554": 0x08C9A554,
        "gUnkEu_08C9A590": 0x08C9A590,
        "gUnkEu_08C9A57A": 0x08C9A57A,
        "gUnkEu_08C9A5C2": 0x08C9A5C2,
        "gUnkEu_08C9A5A6": 0x08C9A5A6,
        "gUnkEu_08C9A4E2": 0x08C9A4E2,
        "gUnkEu_08C9A516": 0x08C9A516,
        "gUnkEu_08B51BA8": 0x08B51BA8,
        "gUnkEu_08B51D50": 0x08B51D50,
        "gUnkEu_08B51FB8": 0x08B51FB8,
        "gUnkEu_08B52220": 0x08B52220,
        "gUnkEu_08B52488": 0x08B52488,
        "gUnkEu_09F5C1FC": 0x09F5C1FC,
        "gUnkEu_08F6B5FC": 0x08F6B5FC,
        "gUnkEu_08F7913C": 0x08F7913C,
        "gUnkEu_09F5C20C": 0x09F5C20C,
        "gUnkEu_09F5C21C": 0x09F5C21C,
        "gUnkEu_09F5C22C": 0x09F5C22C,
        "gUnkEu_09F5C23C": 0x09F5C23C,
        "gUnkEu_096CB088": 0x096CB088,
        "gUnkEu_09F80288": 0x09F80288,
        "gUnkEu_096CB104": 0x096CB104,
        "gUnkEu_09F80350": 0x09F80350,
        "gUnkEu_09F80364": 0x09F80364,
        "gUnkEu_09F8029C": 0x09F8029C,
        "gUnkEu_09F802C8": 0x09F802C8,
        "gUnkEu_09F802DC": 0x09F802DC,
        "gUnkEu_09F84FBC": 0x09F84FBC,
        "gUnkEu_09F84FD0": 0x09F84FD0,
        "gUnkEu_09F84FE4": 0x09F84FE4,
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
        "gUnkEu_099991E0": 0x099991E0,
        "gUnkEu_09F847D4": 0x09F847D4,
        "gUnkEu_09F84810": 0x09F84810,
        "gUnkEu_09F65FDC": 0x09F65FDC,
        "gUnkEu_09F65FF0": 0x09F65FF0,
        "gUnkEu_09F66004": 0x09F66004,
        "gUnkEu_09F6FDB4": 0x09F6FDB4,
        "gUnkEu_09F6FDDC": 0x09F6FDDC,
        "gUnkEu_090CE9F4": 0x090CE9F4,
        "eu_080AB9FC": 0x080AB9FC,
        "eu_080ABA38": 0x080ABA38,
        "eu_080ABA7C": 0x080ABA7C,
        "gUnkEu_09F72BFC": 0x09F72BFC,
        "gUnkEu_09F7434C": 0x09F7434C,
        "gUnkEu_09F74360": 0x09F74360,
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
        "gUnkEu_09F843D8": 0x09F843D8,
        "gUnkEu_09F843E8": 0x09F843E8,
        "gUnkEu_09F843F8": 0x09F843F8,
        "gUnkEu_09F84408": 0x09F84408,
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
        "gUnkEu_095DA860": 0x095DA860,
        "gUnkEu_095DA867": 0x095DA867,
        "gUnkEu_08890EC0": 0x08890EC0,
        "gUnkEu_08895E94": 0x08895E94,
        "gUnkEu_08CB0D3C": 0x08CB0D3C,
        "gUnkEu_08F7ADFC": 0x08F7ADFC,
        "gUnkEu_09F72C10": 0x09F72C10,
        "gUnkEu_09F72D80": 0x09F72D80,
        "gUnkEu_09F72E10": 0x09F72E10,
        "gUnkEu_0916FDCA": 0x0916FDCA,
        "gUnkEu_09170202": 0x09170202,
        "gUnkEu_0917063A": 0x0917063A,
        "gUnkEu_0916F992": 0x0916F992,
        "gUnkEu_094DCCE4": 0x094DCCE4,
        "gUnkEu_094E20E4": 0x094E20E4,
        "gUnkEu_094E74E4": 0x094E74E4,
        "gUnkEu_094E58E4": 0x094E58E4,
        "gUnkEu_094E3CE4": 0x094E3CE4,
        "gUnkEu_09F74374": 0x09F74374,
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
        "gUnkEu_099AB990": 0x099AB990,
        "gUnkEu_099AB9A6": 0x099AB9A6,
        "gUnkEu_099AB9DA": 0x099AB9DA,
        "gUnkEu_099ABF18": 0x099ABF18,
        "gUnkEu_099ABF2E": 0x099ABF2E,
        "gUnkEu_099ABF62": 0x099ABF62,
        "gUnkEu_099AC3E0": 0x099AC3E0,
        "gUnkEu_099AC3F6": 0x099AC3F6,
        "gUnkEu_099AC42A": 0x099AC42A,
        "gUnkEu_099AC968": 0x099AC968,
        "gUnkEu_099AC97E": 0x099AC97E,
        "gUnkEu_099AC9B2": 0x099AC9B2,
        "gUnkEu_08896524": 0x08896524,
        "gUnkEu_09538324": 0x09538324,
        "gUnkEu_09538B24": 0x09538B24,
        "gUnkEu_09539324": 0x09539324,
        "gUnkEu_09F5D6EC": 0x09F5D6EC,
        "gUnkEu_098863B2": 0x098863B2,
        "gUnkEu_0988683C": 0x0988683C,
        "gUnkEu_09886C7E": 0x09886C7E,
        "gUnkEu_09886FC8": 0x09886FC8,
        "gUnkEu_09F8447C": 0x09F8447C,
        "gUnkEu_09F8444C": 0x09F8444C,
        "gUnkEu_09F8445C": 0x09F8445C,
        "gUnkEu_09F8446C": 0x09F8446C,
        "gUnkEu_09F84720": 0x09F84720,
        "gUnkEu_09F84718": 0x09F84718,
        "gUnkEu_09F84728": 0x09F84728,
        "gUnkEu_09F84738": 0x09F84738,
        "gUnkEu_09F84730": 0x09F84730,
        "gUnkEu_09F84560": 0x09F84560,
        "gUnkEu_09F84574": 0x09F84574,
        "gUnkEu_09F84588": 0x09F84588,
        "gUnkEu_09F8459C": 0x09F8459C,
        "gUnkEu_09F845B0": 0x09F845B0,
        "gUnkEu_09F844FC": 0x09F844FC,
        "gUnkEu_09F84510": 0x09F84510,
        "gUnkEu_09F84524": 0x09F84524,
        "gUnkEu_09F84538": 0x09F84538,
        "gUnkEu_09F8454C": 0x09F8454C,
        "gUnkEu_09F845C4": 0x09F845C4,
        "gUnkEu_09F84678": 0x09F84678,
        "gUnkEu_09F845E8": 0x09F845E8,
        "gUnkEu_09F84698": 0x09F84698,
        "gUnkEu_09F8460C": 0x09F8460C,
        "gUnkEu_09F846B8": 0x09F846B8,
        "gUnkEu_09F84630": 0x09F84630,
        "gUnkEu_09F846D8": 0x09F846D8,
        "gUnkEu_09F84654": 0x09F84654,
        "gUnkEu_09F846F8": 0x09F846F8,
        "gUnkEu_08895A00": 0x08895A00,
        "gUnkEu_08895C30": 0x08895C30,
        "gUnkEu_09F847FC": 0x09F847FC,
        "gUnkEu_099A421C": 0x099A421C,
        "gUnkEu_099A4238": 0x099A4238,
        "gUnkEu_099A426C": 0x099A426C,
        "gUnkEu_099A4C4C": 0x099A4C4C,
        "gUnkEu_099A4C68": 0x099A4C68,
        "gUnkEu_099A4C9C": 0x099A4C9C,
        "gUnkEu_099A511C": 0x099A511C,
        "gUnkEu_099A5138": 0x099A5138,
        "gUnkEu_099A516C": 0x099A516C,
        "gUnkEu_099A55AC": 0x099A55AC,
        "gUnkEu_099A55C8": 0x099A55C8,
        "gUnkEu_099A55FC": 0x099A55FC,
        "gUnkEu_099A5A3C": 0x099A5A3C,
        "gUnkEu_099A5A58": 0x099A5A58,
        "gUnkEu_099A5A8C": 0x099A5A8C,
        "gUnkEu_08C9CD3C": 0x08C9CD3C,
        "gUnkEu_08F79520": 0x08F79520,
        "gUnkEu_08F74484": 0x08F74484,
        "gUnkEu_08F7E498": 0x08F7E498,
        "gUnkEu_08F7042C": 0x08F7042C,
        "gUnkEu_08F7D724": 0x08F7D724,
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
        "gUnkEu_09F800A4": 0x09F800A4,
        "gUnkEu_09F800B8": 0x09F800B8,
        "gUnkEu_0919B63A": 0x0919B63A,
        "gUnkEu_09F5D7E4": 0x09F5D7E4,
        "gUnkEu_095A3D74": 0x095A3D74,
        "gUnkEu_09CEF9E8": 0x09CEF9E8,
        "gUnkEu_09F879D4": 0x09F879D4,
        "gUnkEu_09F8785C": 0x09F8785C,
        "gUnkEu_09CF1B7E": 0x09CF1B7E,
        "gUnkEu_09F87AF0": 0x09F87AF0,
        "gUnkEu_09F879E8": 0x09F879E8,
        "gUnkEu_09CF3FEE": 0x09CF3FEE,
        "gUnkEu_09F87C7C": 0x09F87C7C,
        "gUnkEu_09F87B04": 0x09F87B04,
        "gUnkEu_09CF6334": 0x09CF6334,
        "gUnkEu_09F87D98": 0x09F87D98,
        "gUnkEu_09F87C90": 0x09F87C90,
        "gUnkEu_09CF86A2": 0x09CF86A2,
        "gUnkEu_09F87F24": 0x09F87F24,
        "gUnkEu_09F87DAC": 0x09F87DAC,
        "gUnkEu_09CFA56C": 0x09CFA56C,
        "gUnkEu_09F88040": 0x09F88040,
        "gUnkEu_09F87F38": 0x09F87F38,
        "gUnkEu_09CFCB38": 0x09CFCB38,
        "gUnkEu_09F881CC": 0x09F881CC,
        "gUnkEu_09F88054": 0x09F88054,
        "gUnkEu_09CFEFA8": 0x09CFEFA8,
        "gUnkEu_09F882E8": 0x09F882E8,
        "gUnkEu_09F881E0": 0x09F881E0,
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
        "gUnkEu_095ECDD8": 0x095ECDD8,
        "gUnkEu_095ED472": 0x095ED472,
        "gUnkEu_09F7EB28": 0x09F7EB28,
        "gUnkEu_09F7EB30": 0x09F7EB30,
        "gUnkEu_095F5550": 0x095F5550,
        "gUnkEu_095F5BB0": 0x095F5BB0,
        "gUnkEu_09F7EBD8": 0x09F7EBD8,
        "gUnkEu_09F7EBE0": 0x09F7EBE0,
        "gUnkEu_095F6150": 0x095F6150,
        "gUnkEu_095F67B0": 0x095F67B0,
        "gUnkEu_09F7EBE8": 0x09F7EBE8,
        "gUnkEu_09F7EBF0": 0x09F7EBF0,
        "gUnkEu_095F6D50": 0x095F6D50,
        "gUnkEu_095F73AA": 0x095F73AA,
        "gUnkEu_09F7EBF8": 0x09F7EBF8,
        "gUnkEu_09F7EC00": 0x09F7EC00,
        "gUnkEu_095F79D2": 0x095F79D2,
        "gUnkEu_095F7FAE": 0x095F7FAE,
        "gUnkEu_09F7EC08": 0x09F7EC08,
        "gUnkEu_09F7EC10": 0x09F7EC10,
        "gUnkEu_08891670": 0x08891670,
        "gUnkEu_08891714": 0x08891714,
        "gUnkEu_09F72CC4": 0x09F72CC4,
        "gUnkEu_09F72CB0": 0x09F72CB0,
        "gUnkEu_08895EDC": 0x08895EDC,
        "gUnkEu_090D1DC0": 0x090D1DC0,
        "gUnkEu_0916292A": 0x0916292A,
        "gUnkEu_091633A4": 0x091633A4,
        "gUnkEu_09162FB8": 0x09162FB8,
        "gUnkEu_09162C8C": 0x09162C8C,
        "gUnkEu_09F6FF70": 0x09F6FF70,
        "gUnkEu_09F6FF30": 0x09F6FF30,
        "gUnkEu_090CED64": 0x090CED64,
        "gUnkEu_09F6FF44": 0x09F6FF44,
        "gUnkEu_090CEC30": 0x090CEC30,
        "gUnkEu_090CEC70": 0x090CEC70,
        "gUnkEu_09F6FE30": 0x09F6FE30,
        "gUnkEu_09F6FE58": 0x09F6FE58,
        "gUnkEu_09F6FE44": 0x09F6FE44,
        "gUnkEu_094F03A4": 0x094F03A4,
        "gUnkEu_094F1BA4": 0x094F1BA4,
        "gUnkEu_094F13A4": 0x094F13A4,
        "gUnkEu_094F0BA4": 0x094F0BA4,
        "gUnkEu_0953C324": 0x0953C324,
        "gUnkEu_090CECE8": 0x090CECE8,
        "gUnkEu_09F72D1C": 0x09F72D1C,
        "gUnkEu_090D1328": 0x090D1328,
        "gUnkEu_09F7626C": 0x09F7626C,
        "gUnkEu_09F762A4": 0x09F762A4,
        "gUnkEu_09172200": 0x09172200,
        "gUnkEu_091759BA": 0x091759BA,
        "gUnkEu_09F72D58": 0x09F72D58,
        "gUnkEu_09F72D44": 0x09F72D44,
        "gUnkEu_094D53C4": 0x094D53C4,
        "gUnkEu_094D6BC4": 0x094D6BC4,
        "gUnkEu_094D63C4": 0x094D63C4,
        "gUnkEu_094D5BC4": 0x094D5BC4,
        "gUnkEu_09F72D08": 0x09F72D08,
        "gUnkEu_09F6FDC8": 0x09F6FDC8,
        "gUnkEu_09F6FDF0": 0x09F6FDF0,
        "gUnkEu_0967CB6C": 0x0967CB6C,
        "gUnkEu_095F18BE": 0x095F18BE,
        "gUnkEu_095F3D12": 0x095F3D12,
        "gUnkEu_095F24DA": 0x095F24DA,
        "gUnkEu_095F30F6": 0x095F30F6,
        "gUnkEu_095F492E": 0x095F492E,
        "gUnkEu_09F7EBB0": 0x09F7EBB0,
        "gUnkEu_09F7EBC8": 0x09F7EBC8,
        "gUnkEu_09F7EBB8": 0x09F7EBB8,
        "gUnkEu_09F7EBC0": 0x09F7EBC0,
        "gUnkEu_09F7EBD0": 0x09F7EBD0,
        "gUnkEu_08891580": 0x08891580,
        "gUnkEu_095EC758": 0x095EC758,
        "gUnkEu_095EC898": 0x095EC898,
        "gUnkEu_095ECB38": 0x095ECB38,
        "gUnkEu_09F7EB08": 0x09F7EB08,
        "gUnkEu_09F7EB18": 0x09F7EB18,
        "gUnkEu_09F7EB20": 0x09F7EB20,
        "gUnk_09A53380": 0x09A53380,
        "gUnk_09A54080": 0x09A54080,
        "gUnk_09A54D80": 0x09A54D80,
        "gUnk_09A55A80": 0x09A55A80,
        "gUnk_09A59B80": 0x09A59B80,
        "gUnk_09A5A880": 0x09A5A880,
        "gUnk_09A5B580": 0x09A5B580,
        "gUnk_09A5C280": 0x09A5C280,
        "gUnkEu_09F85008": 0x09F85008,
        "gUnkEu_09F8501C": 0x09F8501C,
        "gUnkEu_09F85030": 0x09F85030,
        "gUnkEu_09F85044": 0x09F85044,
        "gUnkEu_09F84FA8": 0x09F84FA8,
        "gUnkEu_09A97520": 0x09A97520,
        "gUnkEu_099AEE98": 0x099AEE98,
        "gUnkEu_09F855A4": 0x09F855A4,
        "gUnkEu_09F85554": 0x09F85554,
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
        "gUnkEu_099A4CDA": 0x099A4CDA,
        "gUnkEu_099A51AA": 0x099A51AA,
        "gUnkEu_099A563A": 0x099A563A,
        "gUnkEu_099A5ACA": 0x099A5ACA,
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
        "gUnkEu_099ABA18": 0x099ABA18,
        "gUnkEu_099ABFA0": 0x099ABFA0,
        "gUnkEu_099AC468": 0x099AC468,
        "gUnkEu_099AC9F0": 0x099AC9F0,
        "gUnkEu_09A9A880": 0x09A9A880,
        "gUnkEu_09A9A8A0": 0x09A9A8A0,
        "gUnkEu_099FBE00": 0x099FBE00,
        "gUnkEu_08B54B7C": 0x08B54B7C,
        "gUnkEu_08B54B86": 0x08B54B86,
        "gUnkEu_08B54B96": 0x08B54B96,
        "gUnkEu_08B54BA6": 0x08B54BA6,
        "gUnkEu_08B54BB6": 0x08B54BB6,
        "gUnkEu_08B54BC6": 0x08B54BC6,
        "gUnkEu_08B54BDC": 0x08B54BDC,
        "gUnkEu_08B54BF2": 0x08B54BF2,
        "gUnkEu_08B54BFC": 0x08B54BFC,
        "gUnkEu_08B54C06": 0x08B54C06,
        "gUnkEu_08B54C10": 0x08B54C10,
        "gUnkEu_08B54C26": 0x08B54C26,
        "gUnkEu_08B54C3C": 0x08B54C3C,
        "gUnkEu_08B54C52": 0x08B54C52,
        "gUnkEu_08B54C5C": 0x08B54C5C,
        "gUnkEu_08B54C6C": 0x08B54C6C,
        "gUnkEu_08B54C7C": 0x08B54C7C,
        "gUnkEu_08B54C8C": 0x08B54C8C,
        "gUnkEu_08B54C9C": 0x08B54C9C,
        "gUnkEu_08B54CB2": 0x08B54CB2,
        "gUnkEu_08B54CC8": 0x08B54CC8,
        "gUnkEu_08B54CDE": 0x08B54CDE,
        "gUnkEu_08B54CF4": 0x08B54CF4,
        "gUnkEu_08B54D0A": 0x08B54D0A,
        "gUnkEu_08B54D1A": 0x08B54D1A,
        "gUnkEu_08B54D2A": 0x08B54D2A,
        "gUnkEu_08B54D3A": 0x08B54D3A,
        "gUnkEu_08B54D4A": 0x08B54D4A,
        "gUnkEu_08B54D60": 0x08B54D60,
        "gUnkEu_08B54D76": 0x08B54D76,
        "gUnkEu_08B54D8C": 0x08B54D8C,
        "gUnkEu_08B54DA2": 0x08B54DA2,
        "gUnkEu_08B54DB8": 0x08B54DB8,
        "gUnkEu_08B54DC8": 0x08B54DC8,
        "gUnkEu_08B54DD8": 0x08B54DD8,
        "gUnkEu_08B54DE8": 0x08B54DE8,
        "gUnkEu_08B54DF8": 0x08B54DF8,
        "gUnkEu_08B54E0E": 0x08B54E0E,
        "gUnkEu_08B54E24": 0x08B54E24,
        "gUnkEu_08B54E3A": 0x08B54E3A,
        "gUnkEu_08B54E50": 0x08B54E50,
        "gUnkEu_08B55C58": 0x08B55C58,
        "gUnkEu_08B55C6C": 0x08B55C6C,
        "gUnkEu_08B55C76": 0x08B55C76,
        "gUnkEu_08B55CFE": 0x08B55CFE,
        "gUnkEu_08B55D08": 0x08B55D08,
        "gUnkEu_08B55D18": 0x08B55D18,
        "gUnkEu_08B55D22": 0x08B55D22,
        "gUnkEu_08B55D32": 0x08B55D32,
        "gUnkEu_08B55D3C": 0x08B55D3C,
        "gUnkEu_08B55D4C": 0x08B55D4C,
        "gUnkEu_08B55D66": 0x08B55D66,
        "gUnkEu_08B55D70": 0x08B55D70,
        "gUnkEu_08B55D80": 0x08B55D80,
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
        "gUnkJp_09C68534": 0x09C68534,
        "gUnkJp_09C6854A": 0x09C6854A,
        "gUnkJp_09C68560": 0x09C68560,
        "gUnkJp_09C68576": 0x09C68576,
        "gUnkJp_09C6858C": 0x09C6858C,
        "gUnkJp_09C685A2": 0x09C685A2,
        "gUnkJp_09C685B8": 0x09C685B8,
        "gUnkJp_09C685D4": 0x09C685D4,
        "gUnkJp_09C685F0": 0x09C685F0,
        "gUnkJp_09C6860C": 0x09C6860C,
        "gUnkJp_09C68628": 0x09C68628,
        "gUnkJp_09C68644": 0x09C68644,
        "gUnkJp_09C68660": 0x09C68660,
        "gUnkJp_09C6867C": 0x09C6867C,
        "gUnkJp_09C68698": 0x09C68698,
        "gUnkJp_09C686B4": 0x09C686B4,
        "gUnkJp_09C686D0": 0x09C686D0,
        "gUnkJp_09C686EC": 0x09C686EC,
        "gUnkJp_09C68708": 0x09C68708,
        "gUnkJp_09C68724": 0x09C68724,
        "gUnkJp_09C68740": 0x09C68740,
        "gUnkJp_09C6875C": 0x09C6875C,
        "gUnkJp_09C68778": 0x09C68778,
        "gUnkJp_09C68794": 0x09C68794,
        "gUnkJp_09C687B0": 0x09C687B0,
        "gUnkJp_09C687CC": 0x09C687CC,
        "gUnkJp_09C687E8": 0x09C687E8,
        "gUnkJp_09C68804": 0x09C68804,
        "gUnkJp_09C68820": 0x09C68820,
        "gUnkJp_09C6883C": 0x09C6883C,
        "gUnkJp_09C68858": 0x09C68858,
        "gUnkJp_09C68874": 0x09C68874,
        "gUnkJp_09C6888A": 0x09C6888A,
        "gUnkJp_09C688A0": 0x09C688A0,
        "gUnkJp_09C688B6": 0x09C688B6,
        "gUnkJp_09C688CC": 0x09C688CC,
        "gUnkJp_09C688E2": 0x09C688E2,
        "gUnkJp_09C688F8": 0x09C688F8,
        "gUnkJp_09C6890E": 0x09C6890E,
        "gUnkJp_09C68924": 0x09C68924,
        "gUnkJp_09C6893A": 0x09C6893A,
        "gUnkJp_09C68950": 0x09C68950,
        "gUnkJp_09C68966": 0x09C68966,
        "gUnkJp_09C6897C": 0x09C6897C,
        "gUnkJp_09C68992": 0x09C68992,
        "gUnkJp_09C689A8": 0x09C689A8,
        "gUnkJp_09C689BE": 0x09C689BE,
        "gUnkJp_09C689D4": 0x09C689D4,
        "gUnkJp_09C689EA": 0x09C689EA,
        "gUnkJp_09C68A00": 0x09C68A00,
        "gUnkJp_09C68A16": 0x09C68A16,
        "gUnkJp_09C68A2C": 0x09C68A2C,
        "gUnkJp_09C68A42": 0x09C68A42,
        "gUnkJp_09C68A58": 0x09C68A58,
        "gUnkJp_09C68A6E": 0x09C68A6E,
        "gUnkJp_09C68A84": 0x09C68A84,
        "gUnkJp_09C68A9A": 0x09C68A9A,
        "gUnkJp_09C68ABC": 0x09C68ABC,
        "gUnkJp_09C68ADE": 0x09C68ADE,
        "gUnkJp_09C68B00": 0x09C68B00,
        "gUnkJp_09C68B22": 0x09C68B22,
        "gUnkJp_09C68B44": 0x09C68B44,
        "gUnkJp_09C68B66": 0x09C68B66,
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
        ("mode_chkobj_data.c", ".data"): 0x9A90,
        ("unk_0800c778_data.c", ".rodata"): 0x2928,
        ("unk_0800c778_data.c", ".data"): 0,
        ("mode_battle.c", ".rodata"): 0x914,
        ("formation_data.c", ".data"): 0x940,
        ("mode_debug.c", ".rodata"): 0x1F4,
        ("mode_chkobj.c", ".rodata"): 0x6350,
        ("mode_chksnd.c", ".rodata"): 0x20E8,
        ("mode_dummy.c", ".rodata"): 0x19C,
    },
}

TARGET_BLOB_REGIONS = {
    "jp": ((0x0813BA86, "rodata_tasknames_alignment"),),
    "eu": (
        (0x0812FB22, "rodata_tables3"),
        (0x08889EDE, "rodata_tasknames_alignment"),
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
\t.incbin "roms/{code}.gba", {off:#x}, {size:#x}
.syntax divided
"""

DATA = """.syntax unified
	.text
{align}\t.global {name}
{name}:
\t.incbin "roms/{code}.gba", {off:#x}, {size:#x}
.syntax divided
"""

PART = """{align}	.global {name}
	.thumb
	.thumb_func
	.type {name}, %function
{name}:
	.incbin "roms/{code}.gba", {off:#x}, {size:#x}
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
    for f in sorted(Path("src").glob("*.c")):
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


def symbol_map(rows, us, ot, literal_loads, opaque_modes=None):
    opaque_modes = opaque_modes or {}
    pairs = {}
    for nm, ua, sz, va, how, vsz in rows:
        if va is None or vsz != sz or sz == 0:
            continue
        a = us[ua - ROM_BASE:ua - ROM_BASE + sz]
        b = ot[va - ROM_BASE:va - ROM_BASE + sz]
        if len(b) != sz or not near_identical(mask(a), mask(b)):
            continue
        loads = literal_loads
        if ua in opaque_modes:
            loads = literal_loads | trace_literal_loads(us, ua, sz, opaque_modes[ua])
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
    ver, code = args.version, args.code

    us = Path("roms/B8CE.gba").read_bytes()
    ot = Path(f"roms/{code}.gba").read_bytes()
    regional = load_sidecars("config", {"us": us, ver: ot})
    regional_plan = regional["regions"][ver]
    regional_managed = managed_placements(regional)
    regional_overrides = placement_overrides(regional_plan)
    literal_loads = load_literal_loads("build/us/com_us.elf", ROM_BASE, CODE_HI)
    opaque_modes = load_opaque_function_modes("build/us/com_us.elf", ROM_BASE, CODE_HI)
    rows = load_rows(ver)

    owner = {}
    cur = None
    for line in Path("build/us/com_us.map").read_text().splitlines():
        m = re.match(r"^ \.text +0x08[0-9a-f]{6} +0x[0-9a-f]+ (\S+)$", line)
        if m:
            cur = m.group(1)
            continue
        if cur is None or "=" in line:
            continue
        m = re.match(r"^ +0x08[0-9a-f]{6} +(\S+)$", line)
        if m:
            owner.setdefault(m.group(1), cur)

    flexible = set()
    for f in sorted(Path("src").glob("*.c")):
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
    res = symbol_map(rows, us, ot, literal_loads, opaque_modes)
    res.update(anchors)
    tr = translator(res)

    code_end, how_end = tr(CODE_HI)
    if code_end != guess_end:
        rows = load_rows(ver)
        rows = complete(rows, code_end, flexible, owner, clean, fixed)
        res = symbol_map(rows, us, ot, literal_loads, opaque_modes)
        res.update(anchors)
        tr = translator(res)
    evidence = load_evidence("config/rom_data_evidence.json")
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
        TARGET_ONLY_SYMBOLS.get(ver, {}), TARGET_ABSENT_SYMBOLS.get(ver, ()))
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
    for src in sorted(Path("src").glob("*.c")):
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
                                    code=code, off=lo - ROM_BASE, size=hi - lo,
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
                    tmpl.format(name=name, code=code, off=r[3] - ROM_BASE, size=r[5],
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
                PART.format(name=f"{ver}_{lo:08X}", code=code, off=lo - ROM_BASE,
                            size=hi - lo,
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

    placed = re.compile(r"^ (\.[\w.]+) +0x(0[89][0-9a-f]{6}) +0x([0-9a-f]+) "
                        r"build/us/src/(\S+)\.o$")
    spans = {}
    for line in Path("build/us/com_us.map").read_text().splitlines():
        m = placed.match(line)
        if m:
            spans[(m.group(4) + ".c", m.group(1))] = (int(m.group(2), 16),
                                                      int(m.group(3), 16))

    head, body, cdata = [], [], []
    for line in Path("config/us/units.txt").read_text().splitlines():
        t = line.strip()
        if t.endswith(")"):
            nm, _, sec = t.partition("(")
            if nm.endswith(".s"):
                continue
            key = nm, sec[:-1]
            if key in regional_managed:
                if key not in regional_overrides:
                    continue
                here, size = regional_overrides[key]
            else:
                lo, size = spans[key]
                here, _ = tr(lo)
                size = TARGET_DATA_SIZE.get(ver, {}).get(key, size)
            cdata.append((here, size, line))
            continue
        if not t or t.startswith("#"):
            head.append(line)
            continue
        key = unit_key(t.split()[0])

        if key is None and t.endswith(".s"):
            head.append(line)
            continue
        body.append((key, line))
    cdata = merge_placements(cdata, regional_plan, code_end, min(ROM_END, ROM_BASE + len(ot)), regional_managed)
    dropped = [l for k, l in body if k == "absent"]
    for l in dropped:
        print(f"  unit dropped: {l}")
    body = [(k, l) for k, l in body if k != "absent"]
    body += [(at, nm) for at, nm in fillers]
    ordered = [l for k, l in sorted(body, key=lambda kl: (kl[0] is None, kl[0] or 0))]
    moved = [l for (k, l), l2 in zip(body, ordered) if l != l2]
    if moved:
        print(f"  units reordered: {len(moved)}")

    usrom = Path("roms/B8CE.gba").read_bytes()
    otrom = Path(f"roms/{code}.gba").read_bytes()
    pad = len(otrom)

    while pad > 0 and otrom[pad - 1] == 0xFF:
        pad -= 1
    found = []
    incbin = re.compile(r'\.incbin\s+"[^"]+",\s*(0x[0-9a-fA-F]+),\s*(0x[0-9a-fA-F]+)')
    for line in Path("config/us/units.txt").read_text().splitlines():
        t = line.strip()
        if not t.endswith(".s(.rodata)"):
            continue
        nm = t[:-len("(.rodata)")]
        src = Path("asm/us") / nm
        if not src.exists():
            continue
        m = incbin.search(src.read_text())
        if not m:
            continue
        off = int(m.group(1), 16)
        base = nm[:-2]

        if base == "padding":
            found.append((ROM_BASE + pad, base, "run"))
            continue
        pat = usrom[off:off + 64]
        i = otrom.find(pat)
        how = "content"

        if i < 0 or otrom.find(pat, i + 1) >= 0:
            i, how = tr(ROM_BASE + off)[0], "interp"

            if i is None:
                continue
            i -= ROM_BASE
        found.append((ROM_BASE + i, base, how))
    found.extend((address, name, "explicit")
                 for address, name in TARGET_BLOB_REGIONS.get(ver, ()))
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
        if lo > pos:
            for nm, a, b in blob(pos, lo):
                bounds.append((nm, a, b))
                tail.append(f"{nm}(.rodata)")
            pos = lo
        tail.append(line)
        pos += size
    for nm, a, b in blob(pos, ROM_END):
        bounds.append((nm, a, b))
        tail.append(f"{nm}(.rodata)")
    units = head + ordered + tail

    for nm, lo, hi in bounds:
        Path(f"asm/{ver}/{nm}").write_text(
            blob_source(code, lo, hi, otrom[lo - ROM_BASE:hi - ROM_BASE]))
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
