from typing import List

def getMinCodeEntryTime(N: int, M: int, C: List[int]) -> int:
  start_1 = 1
  start_2 = 1
  count = 0
  for c in C:
    steps_1 = (min((c-start_1)%N, (start_1-c)%N))
    steps_2 = (min((c-start_2)%N, (start_2-c)%N))
    if steps_1 < steps_2:
      count += steps_1
      start_1 = c
    else:
      count += steps_2
      start_2 = c
  return count

N = 3
M = 3
C = [1, 2, 3]
res = getMinCodeEntryTime(N=N,M=M,C=C)
print(res)