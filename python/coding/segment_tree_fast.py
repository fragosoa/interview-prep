class SegmentTree:
    def __init__(self,nums):
        self.n = len(n)

        self.tree = [float('inf')] * (2*self.n)

        for i in range(self.n):
            self.tree[i + self.n] = nums[i]
        
        for i in range(self.n-1,0,-1):
            self.tree[i] = max(self.tree[2*i],self.tree[2*i+1])
    
    def query(self,l,r):
        left = l + self.n
        right = r + self.n

        res = float('inf')

        while left < right:
            # left is included in trees left child
            if left & 1:
                res = max(res,self.tree[left])
                left += 1
            # right is NOT included in trees left child
            if right & 1:
                right -= 1
                res = max(res,self.tree[right])
            left //=2
            right //=2
        return res

    def update(self,index,value):
        pos = index + self.n

        self.tree[pos] = value

        while pos>1:
            pos //=2
            self.tree[pos] = max(self.tree[2*pos],self.tree[2*pos+1])
