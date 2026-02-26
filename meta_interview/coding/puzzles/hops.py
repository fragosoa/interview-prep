from typing import List

def getSecondsRequired(N: int, F: int, P: List[int]) -> int:
    P.sort()
    target = N-1
    max_dist = -1
    for i in range(len(P)-1,-1,-1):
        curr_dist = target - P[i]
        max_dist = max(max_dist,curr_dist)
        target -= 1
    return max_dist + F


N = 11
F = 3
P = [4,2,8]
res = getSecondsRequired(N=N,F=F,P=P)
print(res)