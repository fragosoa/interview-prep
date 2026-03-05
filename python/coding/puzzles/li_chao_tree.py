INF = 10**30

class Line:
    def __init__(self,m = 0, b = INF):
        self.m = m
        self.b = b
    
    def value(self,x):
        return self.m*x + self.b
    

class Node:
    def __init__(self, line = None):
        self.line = line if line else Line()
        self.right = None
        self.left = None


class LiChaoTree:
    def __init__(self,x_left,x_right):
        self.root = None
        self.x_left = x_left
        self.x_right = x_right
    
    def add_line(self,m,b):
        line = Line(m,b)
        self.root = self._add_line(self.root,self.x_left,self.x_right,line)

    def _add_line(self,node,l,r,new_line):
        if node is None:
            return Node(new_line)
        
        mid = (l + r ) // 2
        left_better = new_line.value(l) < node.line.value(l)
        mid_better = new_line.value(mid) < node.line.value(mid)

        # Swap lines
        if mid_better:
            node.line,new_line = new_line,node.line
        
        if r - l == 1:
            return None
        
        # They cross on the left
        if left_better != mid_better:
            node.left = self._add_line(node.left,l,mid,new_line)
        else: # They cross on the right
            node.right = self._add_line(node.right,mid,r,new_line)
        
        return node
    
    def query(self,x):
        return self._query(self.root,self.x_left,self.x_right,x)
    
    def _query(self,node,l,r,x):
        if node is None:
            return INF
        
        res = node.line.value(x)

        if r - l == 1:
            return res
        
        mid = (l + r) // 2

        if x < mid and node.left:
            res = min(res,self._query(node.left,l,mid,x))
        elif x >= mid and node.right:
            res = min(res,self._query(node.right,mid,r,x))

        return res


## Test
tree = LiChaoTree(-10**6,10**6)

"""
Track of the following lines:
y = 2x + 3
y = -x + 10
y = 5x - 2
"""

tree.add_line(2,3)
tree.add_line(-1,10)
tree.add_line(5,-2)

print(tree.query(1))
print(tree.query(5))
print(tree.query(-3))