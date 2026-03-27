def max_subarray_sum(A):
    prefix = 0
    min_prefix = 0
    max_sum = -10000000
    for x in A:
        prefix += x
        max_sum = max(max_sum,prefix-min_prefix)
        min_prefix = min(min_prefix,prefix)
    return max_sum

nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
res = max_subarray_sum(nums)
print(res)