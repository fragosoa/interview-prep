from typing import List

"""
use the 'start after minimum/maximum prefix trick'

When we have to take desicions across i,j for optimal value/position
we can iterate 1 pass and for every iteration, keep track of the optimal 
value, compare our ith element with the optimal value.

This same principle applies to 

Kadanes algorithm
Gas station.


The main idea is to realize:

--------*--------
        |
        m
Whatever we find the minimum at m, we can maximize starting 
at m+1 and comparing with the minimum everytime. 
"""
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_prefix = 100000000
        max_price_diff = 0
        for price in prices:
            min_prefix = min(min_prefix,price)
            max_price_diff = max(max_price_diff,price-min_prefix)
        return max_price_diff