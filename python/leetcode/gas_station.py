from typing import List

def canCompleteCircuit(gas: List[int], cost: List[int]) -> int:
    # If total gas < total cost, no solution exists
    if sum(gas) < sum(cost):
        return -1

    # Find index of minimum prefix sum of (gas[i] - cost[i])
    # Starting right after that point maximizes our tank level when we arrive there
    min_prefix = float('inf')
    min_index = 0
    prefix = 0

    for i, (g, c) in enumerate(zip(gas, cost)):
        prefix += g - c
        if prefix < min_prefix:
            min_prefix = prefix
            min_index = i

    return (min_index + 1) % len(gas)

# Tests
print(canCompleteCircuit(gas=[1,2,3,4,5], cost=[3,4,5,1,2]))  # expected 3
print(canCompleteCircuit(gas=[2,3,4],     cost=[3,4,3]))       # expected 2
print(canCompleteCircuit(gas=[1,2,3],     cost=[4,5,6]))       # expected -1
print(canCompleteCircuit(gas=[5,1,2,3,4], cost=[4,4,1,5,1]))  # expected 4