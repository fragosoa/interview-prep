class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        min_steps = [1000000000] * (n+1)
        min_steps[0] = 0
        for i,step in enumerate(nums):
            for j in range(1,step+1):
                if i+j < n:
                    min_steps[i+j] = min(min_steps[i+j],1+min_steps[i])

        return min_steps[n-1]


sol = Solution()
nums = [1,2,3,4]
res = sol.jump(nums=nums)
print(res)
