from typing import List
from collections import defaultdict

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        top = 0
        i = 0
        n = len(nums)
        while i < n:
            cur = nums[i]
            nums[top] = cur
            top += 1
            while i+1 < n and cur == nums[i+1]:
                i +=1
            if i < n:
                i+=1
        return top

sol = Solution()
nums = [0,0,1,1,1,2,2,3,3,4]
res = sol.removeDuplicates(nums=nums)
print(res)