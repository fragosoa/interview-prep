from bisect import bisect_right, bisect_left, insort

def binary_search(arr,target):
    res = bisect_left(keys,target)
    return res if res < len(arr) and arr[res] == target else -1

keys = []
insort(keys,4)
insort(keys,2)
insort(keys,1)
insort(keys,3)
insort(keys,2)
insort(keys,2)
insort(keys,5)
insort(keys,1)
insort(keys,6)

print(keys)
print("----binary search ----")

index = binary_search(keys,-2)
print(index)
index = binary_search(keys,-1)
print(index)
index = binary_search(keys,1)
print(index)
index = binary_search(keys,2)
print(index)
index = binary_search(keys,3)
print(index)
index = binary_search(keys,4)
print(index)
index = binary_search(keys,5)
print(index)
index = binary_search(keys,6)
print(index)
index = binary_search(keys,7)
print(index)