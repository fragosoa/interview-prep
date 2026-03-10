class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
    
        dp1 = 0
        dp2 = -prices[0]

        for i in range(1,n):
            dp1_next = max(dp1,prices[i]+dp2)
            dp2_next = max(dp2,-prices[i] + dp1)
            dp1,dp2 = dp1_next,dp2_next
        return dp1
