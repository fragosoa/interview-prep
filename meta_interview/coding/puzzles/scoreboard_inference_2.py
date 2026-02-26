from typing import List

def getMinProblemCount(N: int, S: List[int]) -> int:
  max_r0 = -1
  max_r1 = -1
  max_r2 = -1
  
  for ee in S:
    if ee%3 == 0:
      max_r0 = max(max_r0,ee)
    elif ee%3 == 1:
      max_r1 = max(max_r1,ee)
    else:
      max_r2 = max(max_r2,ee)

  return 0