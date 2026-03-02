from typing import List

from collections import deque
from collections import defaultdict

def getSecondsRequired(R: int, C: int, G: List[List[str]]) -> int:
    Q = deque()
    # (pos,steps)
    # Adjency list of portal positions.
    adj = defaultdict(list)
    portals = list("abcdefghijklmnopqrstuvwxyz")
    start_pos = []

    for i in range(R):
        for j in range(C):
            if G[i][j] == 'S':
                # Start position
                start_pos = (i,j)
                Q.append((start_pos,0))
            elif G[i][j] in list("abcdefghijklmnopqrstuvwxyz"):
                adj[G[i][j]].append((i,j))
    
    directions = [(-1,0),(0,1),(1,0),(0,-1)]
    visited = set()
    visited.add(start_pos)
    while Q:
        (x,y), steps = Q.popleft()
        #print(f"(x,y) = {x,y}")
        #print(y)
        if G[x][y] == 'E':
            return steps
        
        portal_positions = [
            pos 
            for pos in adj[G[x][y]]
            if pos != (x,y)
        ]
        next_positions = [
            (x+dx,y+dy)
            for dx,dy in directions
            if 0 <= x+dx < R and 0<= y+dy < C and G[x+dx][y+dy] != "#"
        ] + portal_positions

        for nx,ny in next_positions:
            if (nx,ny) not in visited:
                Q.append(((nx,ny),steps+1))
                visited.add((nx,ny)) 

    return -1

R = 1
C = 9
G = [
    ["x","S",".",".","x",".",".","E","x"],
]


res = getSecondsRequired(R=R,C=C,G=G)
print(res)