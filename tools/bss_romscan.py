import re, sys, json
from pathlib import Path
ROOT = Path(__file__).resolve().parent.parent
rom = (ROOT/"roms/B8CE.gba").read_bytes()
lo, hi = int(sys.argv[1],16), int(sys.argv[2],16)
CODE_END = 0x08121400
hits = {}
for off in range(0, min(len(rom), CODE_END-0x08000000), 4):
    w = int.from_bytes(rom[off:off+4], "little")
    if lo <= w <= hi:
        hits.setdefault(w, []).append(0x08000000+off)
syms = {}
for line in (ROOT/"config/us/symbols.txt").read_text().splitlines():
    m = re.match(r"^(\S+)\s*=\s*(0x[0-9A-Fa-f]+)", line.strip())
    if m: syms[int(m.group(2),16)] = m.group(1)
defined = {}
for c in (ROOT/"src").glob("*.c"):
    for m in re.finditer(r"^(?:\w[\w \*]*?)\b(gUnk_0([0-9A-F]{7}))\b\s*(\[[^\]]*\])?\s*;", c.read_text(), re.M):
        defined[int(m.group(1)[5:],16)] = (m.group(1), c.name)
for a in sorted(hits):
    tag = syms.get(a) or (defined.get(a) or ("",""))[0] or "*** UNNAMED ***"
    src = "" if a in syms or a in defined else "  refs@" + ",".join(hex(x) for x in hits[a][:4])
    print(f"{a:#010x}  {tag}{src}")
