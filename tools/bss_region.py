import json, sys
d = json.load(open("/tmp/claude-1000/-home-pheenoh-git-c-khcom/a1bfa4de-60d5-4f26-80f7-ed193de463ed/scratchpad/work/data.json"))
syms, refs = d["syms"], d["refs"]
lo = int(sys.argv[1],16); hi = int(sys.argv[2],16)
rows = sorted(((v,k) for k,v in syms.items() if lo <= v <= hi))
prev=None
for a,n in rows:
    r = refs.get(n,[])
    gap = "" if prev is None else f"+{a-prev:#x}"
    print(f"{a:#010x} {gap:>8}  {n:<24} {','.join(r)}")
    prev=a
