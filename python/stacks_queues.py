# TODO

stack = []

stack.append(1)
stack.append(2)

top = stack.pop()
print(top)
print(stack)

#usando deque
from collections import deque

stack = deque()
stack.append(1)
stack.append(2)
stack.append(3)
stack.append(4)
stack.append(5)

while stack:
    top = stack[-1]
    stack.pop()
    print(top)

queue = deque()

queue.append(1)
queue.append(2)
queue.append(3)
queue.append(4)
queue.append(5)

print("queue-----")
while queue:
    top = queue[0]
    queue.popleft()
    print(top)


# colas de prioridad
import heapq

pq = []
heapq.heappush(pq,1)
heapq.heappush(pq,2)
heapq.heappush(pq,3)
heapq.heappush(pq,4)

print("heap------")
while pq:
    top = pq[0]
    heapq.heappop(pq)
    print(top)

# Con heaps de objetos. 

class Task:
    def __init__(self,name,priority):
        self.name = name
        self.priority = priority
    def __repr__(self):
        return f"{self.name}"
    

tasks = [
    Task("Lavanderia",0),
    Task("Trastes",4),
    Task("Cama",3),
    Task("Cocina",2)
]

print("heap of objects")
minheap = [(t.priority,t) for t in tasks ]
heapq.heapify(minheap)

while minheap:
    prio,task = heapq.heappop(minheap)
    print((prio,task))


# Sin heapify
tasks = [
    Task("Lavanderia",0),
    Task("Trastes",4),
    Task("Cama",3),
    Task("Cocina",2)
]
print("max heap-----")
maxheap = []
for task in tasks:
    heapq.heappush(maxheap,(-task.priority,task.name))

while maxheap:
    prio,top = heapq.heappop(maxheap)
    print((-prio,top))