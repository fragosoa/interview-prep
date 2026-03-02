from typing import List
def getMaxExpectedProfit(N: int, V: List[int], C: int, S: float) -> float:
    if S == 0.0:
        total = float(sum(V))
        return total - C if total > C else 0.0 
    if S == 1.0:
        return sum(max(0,0,float(x)-C) for x in V)
    
    survive = float(1-S)
    states = [(0.0,0.0)]
    best = 0.0

    for i in range(N):
        tmp_states = []
        for profit,stash in states:
            # Take the ith day
            take = profit + V[i] + stash - C
            if take > best:
                best = take
                # We take all and leave the stash empty
                tmp_states.append((take,0.0))
            # Calculate the expected value of not taking 
            next_stash = (stash + V[i]) * survive
            # If deciding to skip and accumulate leads to a better solution, then consider it
            if profit + next_stash >= best:
                tmp_states.append((profit,next_stash))
        states = tmp_states
    return best


N = 5
V = [10, 2, 8, 6, 4]
C = 3
S = 0.15
res = getMaxExpectedProfit(N=N,V=V,C=C,S=S)
print(res)