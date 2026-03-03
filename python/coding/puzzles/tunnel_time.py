from typing import List

def getSecondsElapsed(C: int, N: int, A: List[int], B: List[int], K: int) -> int:
    L = [
        (A[i],B[i])
        for i in range(N)
    ]
    L.sort(key=lambda x: x[1])
    s = sum([(end-start) for start,end in L])

    total = (K//s)*C
    rem = K%s

    if K%s == 0:
        total = ((K-1)//s)*C
        rem = ((K-1)%s) + 1
    
    last_end = 0
    for start,end in L:
        between = (last_end,start)
        total += (start-last_end)

        rem -= (end-start)
        total += (end-start)

        if rem <= 0:
            total += rem # if rem is negative, then we need to sum
            return total
        last_end = end

    return total

C = 50
N = 3
A = [39, 19, 28]
B = [49, 27, 35]
K = 15

res = getSecondsElapsed(C=C,N=N,A=A,B=B,K=K)
print(res)