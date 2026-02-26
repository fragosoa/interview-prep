m = {
    "a": 1,
    "b": 2,
    "c": 3
}

for k in m.keys():
    print(k)

for v in m.values():
    print(v)

for (k,v) in m.items():
    print(k)

m["d"] = 1
print(m)

# usando defaultdict
from collections import defaultdict

mlist = defaultdict(int) # defaults missing to 0
graph = defaultdict(list) #defaults missing to []

mlist[1] = 1 # sets to 1
mlist[2] += 1 # defaults to 0 + 1

val = mlist.pop(2, None)
print(mlist)

# accessing creates a key CAUTION.