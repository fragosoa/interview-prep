class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        count = 0
        max_dist = 0
        end = 0

        for i in range(n-1):
            max_dist = max(max_dist,i+nums[i])
            # track how many times we can reach the furthest
            if i == end:
                end = max_dist
                count += 1
        return count
