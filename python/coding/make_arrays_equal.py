from collections import defaultdict
from typing import List

def is_permutation(target,arr):
    t = defaultdict(int)
    s = defaultdict(int)
    
    for c in target:
        t[c] += 1
        
    for c in arr:
        s[c] += 1
    if len(t.keys()) != len(s.keys()):
        return False

    for (key,value) in t.items():
        if key not in s:
            return False
        if s[key] != value:
            return False 

    return True  

def canBeEqual(target: List[int], arr: List[int]) -> bool:
    return is_permutation(target,arr)

if __name__ == '__main__':
    res = canBeEqual(target=[],arr=[])
    print(res)


