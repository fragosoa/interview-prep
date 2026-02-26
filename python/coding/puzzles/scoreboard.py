from typing import List

def getMinProblemCount(N: int, S: List[int]) -> int:
    max_odd = -1
    max_even = -1

    for ee in S:
        if ee%2 == 0:
            max_even = max(max_even,ee)
        else:
            max_odd = max(max_odd,ee)
    k2,k1 = 0,0
    k22,k11 = 0,0
    if max_even != -1:
        k2,k1 = max_even//2,max_even%2
    if max_odd != -1:
        k22,k11 = max_odd//2,max_odd%2
    return max(k2,k22) + max(k1,k11) 


N = 4
S = [1, 3, 5, 7]
res = getMinProblemCount(N=N,S=S)
print(res)