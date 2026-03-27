from typing import List


class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        result = [0] * (m+n)
        i = 0
        j = 0
        k = 0
        if m == 0:
            A = B
            #print(A)
            return
        if n == 0:
            #print(A)
            return
        while i < m and j < n:
            if A[i] < B[j]:
                result[k] = A[i]
                i += 1
            else:
                result[k] = B[j]
                j += 1
            k += 1
        while i < m:
            result[k] = A[i]
            i +=1
            k +=1
        while j < n:
            result[k] = B[j]
            j+=1
            k +=1
        A = result
        #print(A)
        
sol = Solution()
A = [1,2,3,0,0,0]
m = 3
B = [2,5,6]
n = 3

sol.merge(A=A,B=B,n=n,m=m)