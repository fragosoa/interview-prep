import heapq

# min heap por default
minheap = []

heapq.heappush(minheap,1)
heapq.heappush(minheap,3)
heapq.heappush(minheap,2)
heapq.heappush(minheap,6)
heapq.heappush(minheap,0)

while len(minheap):
    x = heapq.heappop(minheap)
    print(x)

print("max heap")

maxheap = []
heapq.heappush(maxheap,-1)
heapq.heappush(maxheap,-3)
heapq.heappush(maxheap,-2)
heapq.heappush(maxheap,-6)
heapq.heappush(maxheap,-0)

print(maxheap[0])

while len(maxheap):
    x = -maxheap[0]
    heapq.heappop(maxheap)
    print(x)
