from typing import List

def getMinProblemCount(N: int, S: List[int]) -> int:
    max_s = max(S)
    k3 = max_s // 3
    remainder = max_s % 3

    if remainder == 0:
        k2 = 1 if any(s%3 == 2 for s in S) else 0
        k1 = 1 if any(s%3 == 1 for s in S) else 0
    
    elif remainder == 1:
        if 1 not in S and (max_s -1 ) not in S:
            k2 = 1
            k1 = 0
        else:
            k2 = 1 if any(s %3 == 2 for s in S) else 0
            k1 = 1  # No se cumple la condicion, necesitamos forzosamente un 1
    else:
        k2 = 1
        k1 = 1 if any( s %3 == 1 for s in S) else 0 
    return k3+k2+k1


N = 4
S = [4, 3, 3, 4]

res = getMinProblemCount(N=N,S=S)
print(res)