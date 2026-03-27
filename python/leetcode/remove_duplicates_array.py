from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        top = 0
        for i in range(len(nums)):
            if nums[i] == val:
                continue
            nums[top] = nums[i]
            top += 1
        return top

sol = Solution()
nums = [3,2,2,3]
val = 3
res = sol.removeElement(nums=nums,val=val)
print(res)