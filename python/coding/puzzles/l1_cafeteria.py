from typing import List

def getMaxAdditionalDinersCount(N: int, K: int, M: int, S: List[int]) -> int:
  # Write your code here
  intervals = set()
  for element in S:
    #interval = (element - K, element + K)
    elements_in_interval = [i for i in range(element-K,element+K+1)]
    for ac in elements_in_interval:
      intervals.add(ac)
  count = 0
  for i in range(1,N+1):
    #in_interval = False
    if not i in intervals:
      #print(i)
      count += 1
      elements_in_interval = [i for i in range(i-K,i+K+1)]
      for ac in elements_in_interval:
        intervals.add(ac)
  return count
'''
N = 10
K = 1
M = 2
S = [2, 6]
'''
res = getMaxAdditionalDinersCount(10,1,2,[2,6])
print(res)