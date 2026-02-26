from typing import List 
from collections import deque

def getMaximumEatenDishCount(N: int, D: List[int], K: int) -> int:
    count = 0
    eaten = set()
    Q = deque()

    for dish in D:
        if dish not in eaten:
            eaten.add(dish)
            if len(Q) >= K:
                top = Q.popleft()
                eaten.remove(dish)
            Q.append(dish)
            count += 1 

    return count

N = 7
D = [1, 2, 1, 2, 1, 2, 1]
K = 2
res = getMaximumEatenDishCount(N=N,D=D,K=K)
print(res)
