from typing import List
from collections import defaultdict
from collections import deque

def getMaxVisitableWebpages(N: int, M: int, A: List[int], B: List[int]) -> int:
    g = defaultdict(list)
    color = [0] * (N+1)
    d = [0] * (N+1)
    stack = deque()

    def dfs(i):
        color[i] = 1
        stack.append(i)

        max_dist = 0
        for v in g[i]:
            if color[v] == 0:
                dfs(v)
                
            elif color[v] == 1:
                print("heee")
                # cycle detected
                latest = []
                while stack and stack[-1] != v:
                    latest.append(stack.pop())
                if stack and stack[-1] == v:
                    latest.append(stack[-1])
                
                cycle_distance = len(latest)
                for l in latest:
                    d[l] = cycle_distance
                    color[l] = 2

                return
            if color[v] == 2 and color[i] != 2:
                max_dist = max(max_dist,d[v])
        d[i] = max_dist + 1
        color[i] = 2
        stack.pop()

    for u,v in zip(A,B):
        if v not in g[u]:
            g[u].append(v)
    
    for i in range(1,N+1):
        #print(i)
        if color[i] == 0:
            dfs(i)
    print(d)
    return max(d)


N = 4
M = 4
A = [1, 2, 3, 4]
B = [4, 1, 2, 1]


res = getMaxVisitableWebpages(N=N,M=M,A=A,B=B)
print(res)