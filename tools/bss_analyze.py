import re, sys, os, json
from pathlib import Path
from collections import defaultdict

ROOT = Path(__file__).resolve().parent.parent

syms = {}
for line in (ROOT/"config/us/symbols.txt").read_text().splitlines():
    m = re.match(r"^(\S+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;?\s*$", line.strip())
    if m:
        syms[m.group(1)] = int(m.group(2), 16)

def is_ram(a):
    return 0x02000000 <= a < 0x02040000 or 0x03000000 <= a < 0x03008000

ram = {k:v for k,v in syms.items() if is_ram(v)}

# references from C sources
srcs = sorted((ROOT/"src").glob("*.c"))
hdrs = sorted((ROOT/"include").rglob("*.h"))
text = {}
for p in srcs:
    text[p.name] = p.read_text()

# also count asm references
asmref = defaultdict(set)

refs = defaultdict(set)   # sym -> set of c files
for name, t in text.items():
    words = set(re.findall(r"\b[A-Za-z_][A-Za-z0-9_]*\b", t))
    for s in ram:
        if s in words:
            refs[s].add(name)

# unit assignment from units.txt
units = []
for line in (ROOT/"config/us/units.txt").read_text().splitlines():
    line = line.strip()
    if not line or line.startswith("#"): continue
    f = line.split()[0]
    f = f.split("(")[0]
    units.append(f)

out = {"syms": ram, "refs": {k:sorted(v) for k,v in refs.items()}, "units": units}
json.dump(out, open("/tmp/claude-1000/-home-pheenoh-git-c-khcom/a1bfa4de-60d5-4f26-80f7-ed193de463ed/scratchpad/work/data.json","w"))
print("ram syms:", len(ram))
print("referenced by >=1 c file:", sum(1 for s in ram if refs[s]))
print("referenced by exactly 1:", sum(1 for s in ram if len(refs[s])==1))
print("referenced by 0:", sum(1 for s in ram if not refs[s]))
