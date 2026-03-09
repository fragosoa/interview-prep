class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_dist = 0

        for i,e in enumerate(nums[:-1]):
            if i == max_dist and e == 0:
                return False
            max_dist = max(max_dist,i+e)
        
        return (max_dist >= len(nums)-1)


sol = Solution()
nums = [1,2,3,4]
res = sol.canJump(nums=nums)
print(res)
