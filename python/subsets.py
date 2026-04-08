subsets = []
def find_all_subsets(nums, i=0, current=[]):
    if i == len(nums):          # 2^n leaf nodes reached
        subsets.append(current[:])
        return
    # exclude nums[i]
    
    # include nums[i]
    find_all_subsets(nums, i + 1, current)
    find_all_subsets(nums, i + 1, current + [nums[i]])
    

nums = [1,2,3]
find_all_subsets(nums)
print(subsets)