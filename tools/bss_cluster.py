import json, sys
from collections import defaultdict
W="/tmp/claude-1000/-home-pheenoh-git-c-khcom/a1bfa4de-60d5-4f26-80f7-ed193de463ed/scratchpad/work/"
d=json.load(open(W+"data.json"))
syms,refs,units=d["syms"],d["refs"],d["units"]
order={u:i for i,u in enumerate(units)}
lo=int(sys.argv[1],16) if len(sys.argv)>1 else 0
hi=int(sys.argv[2],16) if len(sys.argv)>2 else 0xffffffff
rows=sorted((v,k) for k,v in syms.items() if lo<=v<=hi)

# assign each symbol to the EARLIEST-linked referencing unit (a plausible definer)
def owner(n):
    r=[x for x in refs.get(n,[]) if x in order]
    if not r: return None
    return min(r,key=lambda x:order[x])

# print runs: group consecutive symbols by owner
cur=None; start=None; prev=None; cnt=0; excl=0
runs=[]
for a,n in rows:
    o=owner(n)
    if o!=cur:
        if cur is not None: runs.append((start,prev,cur,cnt,excl))
        cur=o; start=a; cnt=0; excl=0
    cnt+=1
    if len(refs.get(n,[]))==1: excl+=1
    prev=a
if cur is not None: runs.append((start,prev,cur,cnt,excl))
for s,e,o,c,x in runs:
    print(f"{s:#010x}..{e:#010x} n={c:<4} excl={x:<4} {o}  (link#{order.get(o,-1)})")
