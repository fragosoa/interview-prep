class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        min_size = 100000000
        cursum =0
        start =0 
        for end in range(n):
            cursum += nums[end]
            
            while cursum >= target:
                min_size = min(min_size,end-start+1)
                cursum -= nums[start]
                start +=1
        if min_size == 100000000:
            return 0
        return min_size
