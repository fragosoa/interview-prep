# Python Interview Prep Guide

A comprehensive guide covering essential Python data structures, syntax patterns, and algorithms for technical interviews.

## Table of Contents
1. [Lists (Arrays)](#lists-arrays)
2. [Sets](#sets)
3. [Dictionaries](#dictionaries)
4. [Strings](#strings)
5. [Slicing](#slicing)
6. [Sorting](#sorting)
7. [Stacks and Queues](#stacks-and-queues)
8. [Heaps (Priority Queues)](#heaps-priority-queues)
9. [Classes and OOP](#classes-and-oop)
10. [Time Complexity Reference](#time-complexity-reference)
11. [Common Patterns](#common-patterns)

---

## Lists (Arrays)

### Basic Operations

```python
arr = []
arr.append(1)           # Add single element: O(1)
arr.extend([1,2,3])     # Add multiple elements: O(k)
arr.pop()               # Remove last: O(1)
arr.pop(1)              # Remove by index: O(n) - all elements shift left
arr.remove(2)           # Remove first occurrence of value: O(n)
```

### Key Differences: append vs extend

```python
arr = []
arr.append([1,2,3])     # arr = [[1,2,3]] - adds the list as ONE element
arr.extend([1,2,3])     # arr = [[1,2,3], 1, 2, 3] - adds EACH element

# extend works with any iterable
arr = []
arr.extend("hello")     # arr = ['h', 'e', 'l', 'l', 'o']
```

### Concatenation

```python
l1 = [1,2,3]
l2 = [4,5,6]

# Creates new list
l3 = l1 + l2            # [1,2,3,4,5,6]

# Modifies in-place, returns None
l1.extend(l2)           # l1 is now [1,2,3,4,5,6]
```

### Common Operations

```python
# Length
len(arr)                # O(1)

# Insert at position
arr.insert(0, 'first')  # O(n) - shifts elements

# Check if element exists
if x in arr:            # O(n)
    pass

# Get index of element
idx = arr.index(x)      # O(n) - raises ValueError if not found

# Count occurrences
count = arr.count(x)    # O(n)

# Reverse in-place
arr.reverse()           # O(n)

# Clear all elements
arr.clear()             # O(n)
```

### Important Notes
- Lists are dynamic arrays (automatic resizing)
- Appending to end is amortized O(1)
- Inserting/deleting in middle is O(n)
- Access by index is O(1)

---

## Sets

### Basic Operations

```python
s = set()
s.add(1)                # Add element: O(1)
s.remove(1)             # Remove element: O(1) - raises KeyError if not found
s.discard(1)            # Remove element: O(1) - no error if not found (SAFER)

# Check membership
if 1 in s:              # O(1) - this is why sets are powerful!
    pass

# Size
len(s)                  # O(1)
```

### Set Operations

```python
s = {1, 2}
t = {2, 3}

s | t                   # Union: {1, 2, 3}
s & t                   # Intersection: {2}
s - t                   # Difference: {1}
s ^ t                   # Symmetric difference: {1, 3}

# Alternative methods
s.union(t)
s.intersection(t)
s.difference(t)
s.symmetric_difference(t)

# Check relationships
s.issubset(t)           # Is s subset of t?
s.issuperset(t)         # Is s superset of t?
s.isdisjoint(t)         # Do s and t have no elements in common?
```

### Converting Between Types

```python
# List to set (remove duplicates)
lst = [1, 2, 2, 3, 3, 3]
unique = set(lst)       # {1, 2, 3}

# Set to list
s = {3, 1, 2}
lst = list(s)           # Order not guaranteed: could be [1, 2, 3] or [3, 1, 2]
```

### Use Cases
- **Remove duplicates**: `unique_items = list(set(items))`
- **Fast membership testing**: Check if element exists in O(1)
- **Mathematical set operations**: Union, intersection, etc.
- **Track seen elements**: Commonly used in algorithms

---

## Dictionaries

### Basic Operations

```python
m = {"a": 1, "b": 2, "c": 3}

# Access
value = m["a"]          # 1 - raises KeyError if key doesn't exist
value = m.get("a")      # 1 - returns None if key doesn't exist
value = m.get("d", 0)   # 0 - custom default value

# Add or modify
m["d"] = 4              # O(1) average

# Delete
del m["a"]              # O(1) average
value = m.pop("b")      # Returns value and removes key
value = m.pop("z", None) # Returns None if key doesn't exist (no error)

# Check if key exists
if "a" in m:            # O(1)
    pass
```

### Iteration

```python
m = {"a": 1, "b": 2, "c": 3}

# Iterate over keys
for k in m.keys():
    print(k)

# Iterate over values
for v in m.values():
    print(v)

# Iterate over key-value pairs (most common)
for k, v in m.items():
    print(f"{k}: {v}")

# Note: Since Python 3.7+, dicts maintain insertion order
```

### defaultdict - Automatic Default Values

```python
from collections import defaultdict

# Integer counter
counter = defaultdict(int)      # Defaults to 0
counter['a'] += 1               # No KeyError! Starts at 0
counter['b'] += 5
# counter = {'a': 1, 'b': 5}

# List accumulator
graph = defaultdict(list)       # Defaults to []
graph[1].append(2)              # No KeyError!
graph[1].append(3)
# graph = {1: [2, 3]}

# Set accumulator
groups = defaultdict(set)       # Defaults to set()
groups['vowels'].add('a')
groups['vowels'].add('e')
```

### Counter - Frequency Counting

```python
from collections import Counter

# Count frequencies
arr = [1, 2, 2, 3, 3, 3]
count = Counter(arr)            # Counter({3: 3, 2: 2, 1: 1})

# Most common elements
count.most_common(2)            # [(3, 3), (2, 2)]

# Works with strings
text = "hello"
Counter(text)                   # Counter({'l': 2, 'h': 1, 'e': 1, 'o': 1})
```

### Important Notes
- **WARNING with defaultdict**: Accessing a missing key CREATES it
  ```python
  d = defaultdict(int)
  x = d[5]                # Now d = {5: 0} even if you just read it!
  ```
- Use regular dict with `.get()` if you don't want auto-creation
- Dict lookup/insertion/deletion: O(1) average case
- Perfect for frequency counting, memoization, graphs

---

## Strings

### Immutability

**Critical:** Strings are IMMUTABLE in Python. All operations return NEW strings.

```python
s = "hello"
s[0] = 'H'              # ERROR! Cannot modify
new_s = 'H' + s[1:]     # OK! Creates new string: "Hello"
```

### Whitespace Operations

```python
s = "    Hello World.  "

s.strip()               # "Hello World." - both sides
s.lstrip()              # "Hello World.  " - left side
s.rstrip()              # "    Hello World." - right side

# Strip specific characters
s = "###Hello###"
s.strip('#')            # "Hello"
```

### Case Conversion

```python
"abc".upper()           # "ABC"
"ABC".lower()           # "abc"
"hello world".title()   # "Hello World" - capitalize each word
"hello world".capitalize() # "Hello world" - capitalize first letter only
"HeLLo".swapcase()      # "hEllO" - swap case of each letter
```

### Searching

```python
s = "abcdeabcedf"

# Find substring (returns index or -1)
s.find("bc")            # 1 - first occurrence
s.find("xyz")           # -1 - not found (no error)

# Index (raises ValueError if not found)
s.index("bc")           # 1

# Check prefix/suffix
s.startswith("abc")     # True
s.endswith("edf")       # True

# Count occurrences
s.count("abc")          # 2
```

### Splitting and Joining

```python
# Split into list
s = "a,b,c,d"
lst = s.split(",")      # ['a', 'b', 'c', 'd']

# Split on whitespace (default)
s = "hello world  python"
lst = s.split()         # ['hello', 'world', 'python']

# Join list into string
lst = ["1", "2", "3"]
s = ",".join(lst)       # "1,2,3"
s = " ".join(lst)       # "1 2 3"
s = "".join(lst)        # "123"
```

### Character Operations

```python
# Check character type
"a".isalpha()           # True
"1".isdigit()           # True
"a1".isalnum()          # True
" ".isspace()           # True

# ASCII values
ord('a')                # 97
ord('A')                # 65
chr(97)                 # 'a'

# Character difference (useful for alphabets)
ord('c') - ord('a')     # 2
```

### String Building (Performance)

```python
# SLOW - creates new string each iteration: O(n²)
result = ""
for char in chars:
    result += char

# FAST - join at end: O(n)
result = "".join(chars)

# Alternative: use list then join
parts = []
for item in items:
    parts.append(str(item))
result = " ".join(parts)
```

---

## Slicing

### Basic Syntax: `[start:end:step]`

```python
lst = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

lst[2:5]                # [2, 3, 4] - from index 2 to 5 (excludes 5)
lst[2:]                 # [2, 3, 4, 5, 6, 7, 8, 9] - from 2 to end
lst[:6]                 # [0, 1, 2, 3, 4, 5] - from start to 6
lst[:]                  # [0, 1, ..., 9] - full copy
```

### Step Parameter

```python
lst = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

lst[2:9:2]              # [2, 4, 6, 8] - every 2nd element
lst[::2]                # [0, 2, 4, 6, 8] - every 2nd element (all)
lst[1::2]               # [1, 3, 5, 7, 9] - odd indices

# Reverse with negative step
lst[::-1]               # [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
lst[::-2]               # [9, 7, 5, 3, 1] - reverse, every 2nd
```

### Negative Indices

```python
lst = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

lst[-1]                 # 9 - last element
lst[-2]                 # 8 - second from last
lst[-3:]                # [7, 8, 9] - last 3 elements
lst[:-3]                # [0, 1, 2, 3, 4, 5, 6] - all except last 3
```

### String Slicing

```python
s = "hello"
s[1:4]                  # "ell"
s[::-1]                 # "olleh" - reverse string
s[::2]                  # "hlo" - every other character
```

### List Comprehensions

```python
# Filter elements
lst = [1, 2, 3, 2, 4]
filtered = [x for x in lst if x != 2]       # [1, 3, 4]

# Transform elements
squared = [x**2 for x in range(5)]          # [0, 1, 4, 9, 16]

# Conditional transformation
result = [x if x > 0 else 0 for x in lst]

# Nested loops
pairs = [(i, j) for i in range(3) for j in range(3)]
# [(0,0), (0,1), (0,2), (1,0), (1,1), (1,2), (2,0), (2,1), (2,2)]
```

### Important Notes
- Slicing creates a NEW list (doesn't modify original)
- `end` index is EXCLUSIVE
- Out of bounds indices don't raise errors in slicing
- `[::-1]` is idiomatic way to reverse

---

## Sorting

### Two Methods: sort() vs sorted()

```python
arr = [4, 3, 56, 6, 3]

# In-place sort (modifies original, returns None)
arr.sort()              # arr is now [3, 3, 4, 6, 56]

# Returns new sorted list (original unchanged)
arr = [4, 3, 56, 6, 3]
sorted_arr = sorted(arr) # sorted_arr = [3, 3, 4, 6, 56], arr unchanged

# Reverse order
arr.sort(reverse=True)  # Descending order
sorted_arr = sorted(arr, reverse=True)
```

### Custom Sorting with Key Functions

```python
# Sort by absolute value
arr = [-4, -1, 0, 3, 10]
arr.sort(key=abs)       # [0, -1, 3, -4, 10]

# Sort strings by length
words = ["apple", "pie", "a", "cherry"]
words.sort(key=len)     # ['a', 'pie', 'apple', 'cherry']

# Sort by last character
words.sort(key=lambda x: x[-1])
```

### Sorting Complex Data

```python
# Sorting dictionaries
employees = [
    {"name": "Adolfo", "age": 28},
    {"name": "Vanessa", "age": 29},
    {"name": "Raul", "age": 27}
]

# Sort by age
employees.sort(key=lambda x: x["age"])
# [{"name": "Raul", "age": 27}, {"name": "Adolfo", "age": 28}, ...]

# Sort by name (reverse)
employees.sort(key=lambda x: x["name"], reverse=True)
# [{"name": "Vanessa", ...}, {"name": "Raul", ...}, {"name": "Adolfo", ...}]
```

### Sorting Objects

```python
class User:
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def __repr__(self):
        return f"User({self.name}, {self.age})"

users = [User("Adolfo", 28), User("Vanessa", 27), User("Raul", 15)]

# Sort by age
users.sort(key=lambda x: x.age)

# Sort by name
users.sort(key=lambda x: x.name)

# Multiple criteria (age, then name)
users.sort(key=lambda x: (x.age, x.name))
```

### Stable Sorting

```python
# Stable sort maintains relative order of equal elements
data = [(1, 'b'), (1, 'a'), (2, 'c')]
data.sort(key=lambda x: x[0])
# Result: [(1, 'b'), (1, 'a'), (2, 'c')]
# Note: (1, 'b') still comes before (1, 'a')
```

### Important Notes
- Both `sort()` and `sorted()` use Timsort: O(n log n)
- Sorting is **stable** (preserves relative order)
- Can sort any iterable with `sorted()`, but only lists have `.sort()`
- For reverse order, `reverse=True` is faster than `[::-1]`

---

## Stacks and Queues

### Stack (LIFO - Last In First Out)

```python
# Using list (simple but OK for small stacks)
stack = []
stack.append(1)         # Push
stack.append(2)
top = stack[-1]         # Peek at top: O(1)
top = stack.pop()       # Pop: O(1) -> 2

# Using deque (better performance)
from collections import deque

stack = deque()
stack.append(1)         # Push: O(1)
stack.append(2)
top = stack[-1]         # Peek: O(1)
top = stack.pop()       # Pop: O(1)

# Check if empty
if stack:
    top = stack.pop()
```

### Queue (FIFO - First In First Out)

```python
from collections import deque

queue = deque()
queue.append(1)         # Enqueue: O(1)
queue.append(2)
queue.append(3)

front = queue[0]        # Peek at front: O(1)
front = queue.popleft() # Dequeue: O(1) -> 1

# DON'T use list for queue!
# queue.pop(0) is O(n) because all elements shift
```

### Priority Queue (Min Heap)

```python
import heapq

pq = []
heapq.heappush(pq, 3)   # O(log n)
heapq.heappush(pq, 1)
heapq.heappush(pq, 2)

# Peek at minimum
minimum = pq[0]         # O(1) -> 1

# Pop minimum
minimum = heapq.heappop(pq)  # O(log n) -> 1

while pq:
    smallest = heapq.heappop(pq)
    print(smallest)     # 2, 3
```

### Priority Queue with Custom Objects

```python
import heapq

class Task:
    def __init__(self, name, priority):
        self.name = name
        self.priority = priority
    def __repr__(self):
        return f"{self.name}"

tasks = [
    Task("Laundry", 0),
    Task("Dishes", 4),
    Task("Bed", 3),
    Task("Cook", 2)
]

# Method 1: Using tuples (priority, task)
minheap = [(t.priority, t) for t in tasks]
heapq.heapify(minheap)  # O(n) - convert list to heap

while minheap:
    priority, task = heapq.heappop(minheap)
    print(f"{task} (priority: {priority})")

# Method 2: Insert one by one
minheap = []
for task in tasks:
    heapq.heappush(minheap, (task.priority, task.name))

# Max heap: negate priorities
maxheap = []
for task in tasks:
    heapq.heappush(maxheap, (-task.priority, task.name))

while maxheap:
    neg_priority, name = heapq.heappop(maxheap)
    print(f"{name} (priority: {-neg_priority})")
```

### Important Notes
- **Use deque for queues**, not lists (popleft is O(1) vs O(n))
- **Use heapq for priority queues**
- Stack use cases: DFS, expression evaluation, backtracking
- Queue use cases: BFS, task scheduling
- Priority queue use cases: Dijkstra's, A*, top K problems

---

## Heaps (Priority Queues)

### Min Heap (Default)

```python
import heapq

minheap = []

# Push elements
heapq.heappush(minheap, 3)  # O(log n)
heapq.heappush(minheap, 1)
heapq.heappush(minheap, 2)
heapq.heappush(minheap, 6)
heapq.heappush(minheap, 0)

# Access minimum (don't remove)
minimum = minheap[0]        # O(1) -> 0

# Pop minimum
minimum = heapq.heappop(minheap)  # O(log n) -> 0

# Process all elements in order
while minheap:
    x = heapq.heappop(minheap)
    print(x)  # 1, 2, 3, 6
```

### Max Heap (Negate Values)

```python
import heapq

maxheap = []

# Negate values when pushing
heapq.heappush(maxheap, -3)
heapq.heappush(maxheap, -1)
heapq.heappush(maxheap, -2)
heapq.heappush(maxheap, -6)

# Access maximum (negate again)
maximum = -maxheap[0]       # O(1) -> 6

# Pop maximum (negate again)
maximum = -heapq.heappop(maxheap)  # O(log n) -> 6

while maxheap:
    x = -heapq.heappop(maxheap)
    print(x)  # 3, 2, 1
```

### Heapify - Convert List to Heap

```python
# Create heap from existing list
arr = [3, 1, 4, 1, 5, 9, 2, 6]
heapq.heapify(arr)          # O(n) - faster than n pushes!

# arr is now a valid min heap (but not fully sorted)
# arr[0] is guaranteed to be minimum
```

### Advanced Heap Operations

```python
import heapq

# Get n smallest elements
arr = [3, 1, 4, 1, 5, 9, 2, 6]
smallest_3 = heapq.nsmallest(3, arr)  # [1, 1, 2]

# Get n largest elements
largest_3 = heapq.nlargest(3, arr)    # [9, 6, 5]

# With key function
words = ["apple", "pie", "a", "cherry"]
longest_2 = heapq.nlargest(2, words, key=len)  # ['cherry', 'apple']
```

### Heap with Tuples (Multiple Criteria)

```python
import heapq

# Heap compares tuples element by element
pq = []
heapq.heappush(pq, (1, "task1"))     # Priority 1
heapq.heappush(pq, (1, "task2"))     # Same priority
heapq.heappush(pq, (0, "urgent"))    # Priority 0

while pq:
    priority, task = heapq.heappop(pq)
    print(f"{task}: {priority}")
# Output: urgent: 0, task1: 1, task2: 1
```

### Common Patterns

```python
# Pattern 1: Top K elements
def top_k_largest(arr, k):
    return heapq.nlargest(k, arr)

# Pattern 2: Merge K sorted lists
def merge_k_sorted(lists):
    heap = []
    result = []

    # Initialize heap with first element from each list
    for i, lst in enumerate(lists):
        if lst:
            heapq.heappush(heap, (lst[0], i, 0))  # (value, list_idx, elem_idx)

    while heap:
        val, list_idx, elem_idx = heapq.heappop(heap)
        result.append(val)

        # Add next element from same list
        if elem_idx + 1 < len(lists[list_idx]):
            next_val = lists[list_idx][elem_idx + 1]
            heapq.heappush(heap, (next_val, list_idx, elem_idx + 1))

    return result

# Pattern 3: Running median (use two heaps)
class MedianFinder:
    def __init__(self):
        self.small = []  # Max heap (negated)
        self.large = []  # Min heap

    def add(self, num):
        heapq.heappush(self.small, -num)
        heapq.heappush(self.large, -heapq.heappop(self.small))

        if len(self.large) > len(self.small):
            heapq.heappush(self.small, -heapq.heappop(self.large))

    def get_median(self):
        if len(self.small) > len(self.large):
            return -self.small[0]
        return (-self.small[0] + self.large[0]) / 2
```

### Important Notes
- Python only has min heap (use negation for max heap)
- `heapify()` is O(n), better than n pushes O(n log n)
- Heap is **not fully sorted**, only heap property guaranteed
- Top element access: O(1), push/pop: O(log n)
- Perfect for: Top K problems, merge operations, streaming data

---

## Classes and OOP

### Basic Class

```python
class Container:
    def __init__(self):
        self.data = []

    def add(self, x):
        self.data.append(x)

    def __repr__(self):
        return f"Container({self.data})"

    def __len__(self):
        return len(self.data)

# Usage
container = Container()
container.add(1)
container.add(2)
print(container)        # Container([1, 2])
print(len(container))   # 2
```

### Duck Typing (Implicit Interfaces)

Python doesn't require explicit interfaces. If it walks like a duck and quacks like a duck, it's a duck.

```python
class Store:
    """Base interface (optional, just for documentation)"""
    def add(self, x): pass
    def get_avg(self): pass

class LinearStore:
    def __init__(self):
        self.data = []

    def add(self, x):
        self.data.append(x)

    def get_avg(self):
        return sum(self.data) / len(self.data) if self.data else 0

class SetStore:
    def __init__(self):
        self.data = set()

    def add(self, x):
        self.data.add(x)

    def get_avg(self):
        return sum(self.data) / len(self.data) if self.data else 0

def process_store(store: Store):
    """Works with ANY object that has add() and get_avg()"""
    store.add(1)
    store.add(2)
    store.add(1)
    print(store.get_avg())

# Both work without inheritance!
linear_store = LinearStore()
set_store = SetStore()

process_store(linear_store)  # Output: 1.33 (allows duplicates)
process_store(set_store)      # Output: 1.5 (no duplicates)
```

### Special Methods (Dunder Methods)

```python
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __repr__(self):
        """String representation for debugging"""
        return f"Point({self.x}, {self.y})"

    def __str__(self):
        """User-friendly string"""
        return f"({self.x}, {self.y})"

    def __eq__(self, other):
        """Equality comparison: =="""
        return self.x == other.x and self.y == other.y

    def __lt__(self, other):
        """Less than comparison: <"""
        return (self.x, self.y) < (other.x, other.y)

    def __hash__(self):
        """Make hashable (can use in set/dict)"""
        return hash((self.x, self.y))

    def __add__(self, other):
        """Addition: +"""
        return Point(self.x + other.x, self.y + other.y)

# Usage
p1 = Point(1, 2)
p2 = Point(3, 4)
print(p1)               # (1, 2)
print(p1 == p2)         # False
print(p1 < p2)          # True
p3 = p1 + p2            # Point(4, 6)

# Can now use in sets/dicts
points = {p1, p2}
point_map = {p1: "origin"}
```

### Useful Patterns for Interviews

```python
# Pattern 1: TreeNode for binary trees
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Pattern 2: ListNode for linked lists
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# Pattern 3: Custom comparator for sorting
class Student:
    def __init__(self, name, grade):
        self.name = name
        self.grade = grade

    def __lt__(self, other):
        # Sort by grade descending, then name ascending
        if self.grade != other.grade:
            return self.grade > other.grade
        return self.name < other.name

students = [Student("Alice", 85), Student("Bob", 90), Student("Charlie", 85)]
students.sort()  # Uses __lt__
```

---

## Time Complexity Reference

### Lists
| Operation | Time Complexity |
|-----------|----------------|
| Access by index `arr[i]` | O(1) |
| Append `arr.append(x)` | O(1) amortized |
| Pop last `arr.pop()` | O(1) |
| Pop/insert at index `arr.pop(i)` | O(n) |
| Remove by value `arr.remove(x)` | O(n) |
| Search `x in arr` | O(n) |
| Slicing `arr[i:j]` | O(k) where k = j-i |
| Extend `arr.extend(lst)` | O(k) where k = len(lst) |
| Reverse `arr.reverse()` | O(n) |
| Sort `arr.sort()` | O(n log n) |

### Sets
| Operation | Time Complexity |
|-----------|----------------|
| Add `s.add(x)` | O(1) average |
| Remove `s.remove(x)` | O(1) average |
| Check membership `x in s` | O(1) average |
| Union `s \| t` | O(len(s) + len(t)) |
| Intersection `s & t` | O(min(len(s), len(t))) |

### Dictionaries
| Operation | Time Complexity |
|-----------|----------------|
| Get/Set `d[k]` | O(1) average |
| Delete `del d[k]` | O(1) average |
| Check key `k in d` | O(1) average |
| Iterate items | O(n) |

### Heaps
| Operation | Time Complexity |
|-----------|----------------|
| heappush | O(log n) |
| heappop | O(log n) |
| heapify | O(n) |
| Access min/max | O(1) |
| nsmallest/nlargest(k) | O(n log k) |

### Sorting
| Algorithm | Time Complexity |
|-----------|----------------|
| Timsort (Python's default) | O(n log n) |
| Best case (sorted) | O(n) |
| Worst case | O(n log n) |

### String Operations
| Operation | Time Complexity |
|-----------|----------------|
| Access by index `s[i]` | O(1) |
| Concatenation `s + t` | O(n + m) |
| Slicing `s[i:j]` | O(k) where k = j-i |
| `s.find(sub)` | O(n * m) worst case |
| `s.split()` | O(n) |
| `sep.join(lst)` | O(n) where n = total characters |

---

## Common Patterns

### Two Pointers

Used for: Sorted arrays, palindromes, removing duplicates

```python
# Example: Two sum on sorted array
def two_sum_sorted(arr, target):
    left, right = 0, len(arr) - 1

    while left < right:
        current = arr[left] + arr[right]
        if current == target:
            return [left, right]
        elif current < target:
            left += 1
        else:
            right -= 1
    return []

# Example: Remove duplicates from sorted array
def remove_duplicates(arr):
    if not arr:
        return 0

    write = 1
    for read in range(1, len(arr)):
        if arr[read] != arr[read - 1]:
            arr[write] = arr[read]
            write += 1
    return write
```

### Sliding Window

Used for: Subarray/substring problems, max/min in window

```python
# Example: Maximum sum subarray of size k
def max_sum_subarray(arr, k):
    window_sum = sum(arr[:k])
    max_sum = window_sum

    for i in range(k, len(arr)):
        window_sum = window_sum - arr[i - k] + arr[i]
        max_sum = max(max_sum, window_sum)

    return max_sum

# Example: Longest substring without repeating characters
def longest_unique_substring(s):
    seen = {}
    left = 0
    max_len = 0

    for right, char in enumerate(s):
        if char in seen and seen[char] >= left:
            left = seen[char] + 1
        seen[char] = right
        max_len = max(max_len, right - left + 1)

    return max_len
```

### Hash Map for Frequency/Lookup

Used for: Counting, finding pairs, checking existence

```python
# Example: Two sum (unsorted)
def two_sum(arr, target):
    seen = {}
    for i, num in enumerate(arr):
        complement = target - num
        if complement in seen:
            return [seen[complement], i]
        seen[num] = i
    return []

# Example: Group anagrams
def group_anagrams(strs):
    from collections import defaultdict
    groups = defaultdict(list)

    for s in strs:
        key = ''.join(sorted(s))
        groups[key].append(s)

    return list(groups.values())
```

### Stack for Matching/Nesting

Used for: Parentheses, nested structures, monotonic problems

```python
# Example: Valid parentheses
def is_valid(s):
    stack = []
    pairs = {'(': ')', '[': ']', '{': '}'}

    for char in s:
        if char in pairs:
            stack.append(char)
        elif not stack or pairs[stack.pop()] != char:
            return False

    return len(stack) == 0

# Example: Next greater element
def next_greater_elements(arr):
    result = [-1] * len(arr)
    stack = []  # Monotonic stack (indices)

    for i, num in enumerate(arr):
        while stack and arr[stack[-1]] < num:
            idx = stack.pop()
            result[idx] = num
        stack.append(i)

    return result
```

### BFS (Breadth-First Search)

Used for: Level-order traversal, shortest path, graphs

```python
from collections import deque

# Example: Level order traversal of binary tree
def level_order(root):
    if not root:
        return []

    result = []
    queue = deque([root])

    while queue:
        level_size = len(queue)
        level = []

        for _ in range(level_size):
            node = queue.popleft()
            level.append(node.val)

            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        result.append(level)

    return result

# Example: Shortest path in grid
def shortest_path(grid):
    rows, cols = len(grid), len(grid[0])
    queue = deque([(0, 0, 0)])  # (row, col, distance)
    visited = {(0, 0)}

    while queue:
        row, col, dist = queue.popleft()

        if row == rows - 1 and col == cols - 1:
            return dist

        for dr, dc in [(0,1), (1,0), (0,-1), (-1,0)]:
            r, c = row + dr, col + dc
            if (0 <= r < rows and 0 <= c < cols and
                grid[r][c] == 0 and (r, c) not in visited):
                visited.add((r, c))
                queue.append((r, c, dist + 1))

    return -1
```

### DFS (Depth-First Search)

Used for: Backtracking, exploring all paths, recursion

```python
# Example: DFS on binary tree
def dfs_tree(root):
    if not root:
        return

    print(root.val)
    dfs_tree(root.left)
    dfs_tree(root.right)

# Example: All paths from root to leaves
def all_paths(root):
    if not root:
        return []

    if not root.left and not root.right:
        return [[root.val]]

    paths = []
    for path in all_paths(root.left) + all_paths(root.right):
        paths.append([root.val] + path)

    return paths

# Example: Backtracking - generate all subsets
def subsets(nums):
    result = []

    def backtrack(start, current):
        result.append(current[:])  # Add copy of current

        for i in range(start, len(nums)):
            current.append(nums[i])
            backtrack(i + 1, current)
            current.pop()

    backtrack(0, [])
    return result
```

### Binary Search

Used for: Sorted arrays, finding boundaries, optimization problems

```python
# Example: Standard binary search
def binary_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1

# Example: Find first occurrence
def find_first(arr, target):
    left, right = 0, len(arr) - 1
    result = -1

    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            result = mid
            right = mid - 1  # Continue searching left
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return result

# Example: Search in rotated sorted array
def search_rotated(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = (left + right) // 2

        if arr[mid] == target:
            return mid

        # Determine which side is sorted
        if arr[left] <= arr[mid]:  # Left side is sorted
            if arr[left] <= target < arr[mid]:
                right = mid - 1
            else:
                left = mid + 1
        else:  # Right side is sorted
            if arr[mid] < target <= arr[right]:
                left = mid + 1
            else:
                right = mid - 1

    return -1
```

### Dynamic Programming

Used for: Optimization, counting, decision problems with overlapping subproblems

```python
# Example: Fibonacci with memoization
def fib(n, memo={}):
    if n in memo:
        return memo[n]
    if n <= 1:
        return n

    memo[n] = fib(n - 1, memo) + fib(n - 2, memo)
    return memo[n]

# Example: Coin change (min coins)
def coin_change(coins, amount):
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0

    for coin in coins:
        for i in range(coin, amount + 1):
            dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[amount] if dp[amount] != float('inf') else -1

# Example: Longest increasing subsequence
def longest_increasing_subsequence(arr):
    if not arr:
        return 0

    dp = [1] * len(arr)

    for i in range(1, len(arr)):
        for j in range(i):
            if arr[j] < arr[i]:
                dp[i] = max(dp[i], dp[j] + 1)

    return max(dp)
```

---

## Interview Tips

### Before You Code
1. **Clarify the problem**: Ask about input/output, constraints, edge cases
2. **Think out loud**: Explain your thought process
3. **Start with examples**: Walk through 2-3 examples (include edge cases)
4. **Discuss approach**: Explain your solution before coding
5. **Analyze complexity**: Mention time/space complexity of your approach

### While Coding
1. **Write clean code**: Use meaningful variable names
2. **Think about edge cases**: Empty input, single element, duplicates
3. **Test as you go**: Mentally verify correctness
4. **Don't optimize prematurely**: Get a working solution first

### After Coding
1. **Test with examples**: Walk through your code with test cases
2. **Check edge cases**: What if input is empty? What if n=1?
3. **Analyze complexity**: State time and space complexity
4. **Optimize if needed**: Discuss trade-offs

### Common Edge Cases
- Empty input: `[], "", {}, None`
- Single element: `[1]`
- All same elements: `[1,1,1,1]`
- Negative numbers: `[-1, -5, -3]`
- Duplicates: `[1,2,2,3]`
- Already sorted: `[1,2,3,4]`
- Reverse sorted: `[4,3,2,1]`

### Problem-Solving Framework
1. **Understand**: Restate the problem in your own words
2. **Examples**: Create 2-3 examples (normal + edge cases)
3. **Approach**: Choose appropriate data structure/algorithm
4. **Code**: Implement cleanly
5. **Test**: Verify with examples
6. **Optimize**: Improve if possible

### Common Mistakes to Avoid
- Off-by-one errors in loops/indices
- Not handling empty input
- Modifying input when not allowed
- Integer overflow (in other languages)
- Not considering negative numbers
- Forgetting to return a value
- Infinite loops

---

## Quick Reference

### Most Useful Imports
```python
from collections import deque, defaultdict, Counter
import heapq
```

### Common Initializations
```python
# Empty structures
arr = []
matrix = [[0] * cols for _ in rows]
hashmap = {}
hashmap = defaultdict(int)
hashset = set()
queue = deque()
heap = []

# Infinity
infinity = float('inf')
neg_infinity = float('-inf')

# Multi-dimensional visited
visited = set()
visited = [[False] * cols for _ in rows]
```

### Direction Vectors (Grid Problems)
```python
# 4 directions (up, right, down, left)
directions = [(0,1), (1,0), (0,-1), (-1,0)]

# 8 directions
directions = [(0,1), (1,0), (0,-1), (-1,0),
              (1,1), (1,-1), (-1,1), (-1,-1)]
```

### Built-in Functions
```python
min(arr)
max(arr)
sum(arr)
len(arr)
sorted(arr)
reversed(arr)
enumerate(arr)      # [(0, val1), (1, val2), ...]
zip(arr1, arr2)     # [(a1, b1), (a2, b2), ...]
all(booleans)       # True if all True
any(booleans)       # True if any True
```

---

**Good luck with your interviews!**
