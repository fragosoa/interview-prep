import math
from collections import deque

'''
Brute force:
	for every i:
		  R = find the next greater element (NGE) position to the right (j)
			(j - i + 1)
		  L = find the next greater element position to the left (k)
			(i - k + 1)

		  count the number of subarrays = R U L - R intersect L : 
			((j - i + 1) + (i - k + 1) - 1 ) **dont count yourself twice. 

	--- Bottleneck here is how to get j,k efficiently. By iterating we have a O(n2) solution.
Optimal: 
	find the NGE by pre calculating them using stack, find NGE(right) and NGE(left). 
	Followup. 
		dont need to calculate NGE(left) we can calculate in place
'''
def count_subarrays(arr):
	print("heelo")
	n = len(arr)
	right = [n]*n
	left = [-1]*n

	stack = deque()

	for i in range(n-1, -1, -1):
		while stack and arr[stack[-1]] < arr[i]:
			stack.pop()
		if stack:
			right[i] = stack[-1]
		else:
			right[i] = n
		stack.append(i)

	while stack:
		stack.pop()

	for i in range(0, n):
		while stack and arr[stack[-1]] < arr[i]:
			stack.pop()
		if stack:
			left[i] = stack[-1]
		else:
			left[i] = -1
		stack.append(i)
	while stack:
		stack.pop()

	result = [0] * n
	for i in range(n):
		k = left[i] +1
		j = right[i] -1

		subarray_count = (j-i+1) + (i-k+1) - 1
		result[i] = subarray_count
	return result



if __name__ == "__main__":
	res = count_subarrays([3, 4, 1, 6, 2])
	print(res)
	# Add your own test cases here
