import sys

NINTENDO_LOGO = bytes.fromhex(
    "24ffae51699aa2213d84820a84e409ad"
    "11248b98c0817f21a352be199309ce20"
    "10464a4af82731ec58c7e83382e3cebf"
    "85f4df94ce4b09c194568ac01372a7fc"
    "9f844d73a3ca9a615897a327fc039876"
    "231dc7610304ae56bf38840040a70efd"
    "ff52fe036f9530f197fbc08560d68025"
    "a963be03014e38e2f9a234ffbb3e0344"
    "780090cb88113a9465c07c6387f03caf"
    "d625e48b380aac7221d4f807"
)

HEADER_SIZE = 0xC0
LOGO_START = 0x04
TITLE_START = 0xA0
GAME_CODE_START = 0xAC
MAKER_CODE_START = 0xB0
MAGIC = 0xB2
CHECK_START = 0xA0
CHECK_END = 0xBD


def fix(path, title, game_code, maker_code):
    data = bytearray(open(path, "rb").read())
    if len(data) < HEADER_SIZE:
        sys.exit(f"error: {path} is shorter than a GBA header")
    data[LOGO_START:LOGO_START + len(NINTENDO_LOGO)] = NINTENDO_LOGO
    data[TITLE_START:TITLE_START + 12] = title.encode().ljust(12, b"\0")
    data[GAME_CODE_START:GAME_CODE_START + 4] = game_code.encode().ljust(4, b"\0")
    data[MAKER_CODE_START:MAKER_CODE_START + 2] = maker_code.encode().ljust(2, b"\0")
    data[MAGIC] = 0x96
    total = sum(data[CHECK_START:CHECK_END]) & 0xFF
    data[CHECK_END] = (-(0x19 + total)) & 0xFF
    open(path, "wb").write(data)


if __name__ == "__main__":
    if len(sys.argv) != 5:
        sys.exit("usage: gbafix.py <rom> <title> <game_code> <maker_code>")
    fix(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])
