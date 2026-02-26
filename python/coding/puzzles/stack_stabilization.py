from typing import List 

def getMinimumDeflatedDiscCount(N: int, R: List[int]) -> int:
    count = 0
    for i in range(N-2,-1,-1):
        if R[i] >= R[i+1]:
            count += 1
            R[i] = R[i+1] -1
            if R[i] <= 0:
                return -1
    return count

N = 4
R = [6, 5, 4, 3]
res = getMinimumDeflatedDiscCount(N=N,R=R)
print(res)