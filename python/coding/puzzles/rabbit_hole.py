from typing import List
from collections import defaultdict

def getMaxVisitableWebpages(N: int, L: List[int]) -> int:
    n = len(L)
    A = [a-1 for a in L]

    color = [0]*n
    dp = [0]*n

    def dfs(u):
        color[u] = 1
        

        v = A[u]

        if color[v] == 0:
            dfs(v)
        elif color[v] == 1:
            #cycle detected
            cycle_size = 1
            cur = v
            # Lo mismo que el stack, solo que iterando con punteros
            while A[cur] != v:
                cur = A[cur]
                cycle_size += 1
            
            # Asignar tamaño a todos
            cur = v
            dp[cur] = cycle_size
            color[cur] = 2

            cur = A[cur]
            while cur != v:
                dp[cur] = cycle_size
                color[cur] = 2
                cur = A[cur]
            

        if color[u] != 2:
            dp[u] = dp[v] + 1
            color[u] = 2
            
    
    for i in range(n):
        if color[i] == 0:
            dfs(i)
    return max(dp)

N = 4
L = [4, 1, 2, 1]

res = getMaxVisitableWebpages(N=N,L=L)
print(res)