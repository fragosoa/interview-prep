# Interview Prep Repository

A personal collection of solutions and reference material for software engineering interviews, covering competitive programming problems, classic LeetCode challenges, and object-oriented design exercises — all primarily implemented in Python.

---

## Repository Overview

The repository is organized into two top-level directories:

- **`python/`** — the main focus of this repo; contains reference cheat sheets, data structure implementations, LeetCode solutions, CodeSignal OOP design problems, and competitive programming puzzles.
- **`cpp/`** — miscellaneous C++ solutions from platforms like AlgoExpert, Codeforces, and Meta assessments.

---

## Problem Categories

### 1. Python Reference and Cheat Sheets (`python/`)

The root of the `python/` directory contains standalone scripts that serve as quick-reference material for core Python data structures and idioms used in interviews:

| File | What it covers |
|---|---|
| `cheat_sheet.py` | Lists, sets, dicts — operations, edge cases, and REPL transcripts |
| `heap.py` | `heapq` module usage — min-heap, max-heap patterns |
| `linked_list.py` | Singly linked list node and traversal patterns |
| `sorting.py` | Built-in sort, custom comparators, `functools.cmp_to_key` |
| `slicing.py` | Python slice notation and negative indexing |
| `subsets.py` | Generating subsets via backtracking |
| `dicts.py` | `defaultdict`, `Counter`, dict comprehensions |
| `strings.py` | String manipulation, `join`, `split`, formatting |
| `stacks_queues.py` | Stack and queue patterns using `list` and `deque` |
| `classes.py` | OOP basics — classes, implicit interfaces, duck typing |
| `classes_sort.py` | Sorting objects with custom `__lt__` and `key` functions |

---

### 2. LeetCode Problems (`python/leetcode/`)

Classic interview problems targeting array manipulation patterns:

- **Kadane's Algorithm** — maximum subarray sum
- **Best Time to Buy and Sell Stock** — single-transaction greedy
- **Merge Sorted Array** — in-place two-pointer merge
- **Remove Duplicates from Sorted Array** — two-pointer technique
- **Gas Station** — greedy circular array traversal

---

### 3. Competitive Programming Puzzles (`python/coding/`)

This section contains problems ranging from standard interview fare to harder algorithmic challenges targeting Meta and similar companies.

#### Standard Problems

Problems using two pointers, sliding window, and greedy approaches:

- **Jump Game I & II** — greedy reachability; optimal O(n) jump minimization
- **Container with Most Water** — two-pointer area maximization
- **Best Time to Buy and Sell Stock II** — unlimited-transaction greedy
- **Minimum Size Subarray Sum** — sliding window
- **Pair Sums** — hash map frequency counting
- **Matching Pairs** — frequency-based counting with edge cases
- **Contiguous Subarrays** — monotonic stack for nearest-greater-element
- **Minimum Length Substrings** — substring matching with character frequency maps
- **Make Arrays Equal** — sorting-based equalization

#### Advanced Data Structures

- **`segment_tree_fast.py`** — array-based segment tree with O(log n) range max queries and point updates, using bitwise indexing for cache efficiency.

#### Meta-Style Puzzle Problems (`python/coding/puzzles/`)

Harder multi-concept problems typical of Meta's coding assessments:

| Problem | Techniques Used |
|---|---|
| `director_of_photography.py` | Prefix sums, counting combinations |
| `missing_mail_dp.py` | Dynamic programming with expected value under probability |
| `portals.py` | BFS on a grid with teleportation edges |
| `kosaraju.py` | Kosaraju's SCC algorithm + DP on condensed DAG |
| `li_chao_tree.py` | Li Chao Tree (convex hull trick) — advanced geometry optimization |
| `rabbit_hole.py / rabbit_hole_2.py` | Graph DFS, cycle detection |
| `boss_fight.py / boss_fight_2.py` | Greedy/combinatorial optimization |
| `scoreboard*.py` | Constraint satisfaction and inference |
| `stack_stabilization.py` | Greedy with stacks |
| `rotary_lock.py` | DP on circular structures |
| `hops.py` | Jump/reach problems |
| `kaitenzushi.py` | Sliding window with sets |
| `tunnel_time.py` | Circular interval arithmetic |
| `uniform_integers.py` | Number theory, digit counting |
| `encrypted_words.py` | Recursive string transformation |
| `l1_cafeteria.py` | Interval/greedy seating |
| `score_board_inference.py` | Set-based inference |

---

### 4. CodeSignal OOP Design Problems (`python/codesignal/`)

This section focuses on **object-oriented design** — the ability to model a real-world problem using classes, encapsulation, and clean interfaces. These mirror the kind of system-design-lite problems seen in CodeSignal's "Industry Coding Framework."

#### LRU Cache (`lru_cache.py`)

A full LRU Cache implementation built from scratch using a **doubly linked list + hash map** — no use of `OrderedDict`. Demonstrates:

- Custom `LinkedList` class with `add_back`, `remove_front`, `remove_from_middle`
- `ListNode` class with `prev`/`next` pointers
- `LRUCache` class composing the two, with O(1) `get` and `put`

```python
class LRUCache:
    def __init__(self, capacity: int) -> None:
        self.eviction_list = LinkedList()
        self.keys = defaultdict(lambda: {"value": None, "eviction_node": None})
```

#### Trie (`trie_impl.py`)

A clean Trie implementation using `defaultdict(TrieNode)` for child management. Supports `insert`, `search`, and `startsWith` — a staple OOP design question.

#### Email Inbox Grouping (`group_emails_oop.py`)

Models an email inbox parser using OOP principles:

- `Email` class with `__eq__`, `__hash__`, `__lt__`, and `__repr__` — making objects sortable and usable as dict keys.
- `InboxParser` static class for preprocessing raw strings into `Email` objects.
- Demonstrates Python's **data model** (dunder methods) for custom object behavior.

#### Progressive Function (`progressive_function.py`)

A data structure supporting `ADD`, `REMOVE`, `EXISTS`, and `GET_NEXT` operations on a multiset. Uses `bisect` (binary search on a sorted list) and `insort` for O(log n) insertion — a practical combination of data structures.

#### Other CodeSignal Problems

| File | Topic |
|---|---|
| `parse_nested_string_to_json.py` | Recursive parsing / stack-based JSON construction |
| `bisect_notes.py` | Binary search patterns using Python's `bisect` module |
| `book_borrowings.py` | OOP modeling of a library borrowing system |
| `analyze_competition.py` | Data aggregation and ranking |
| `data_processing.py` | ETL-style data transformation |
| `cs_multidimensional_arrays.py` | 2D array manipulation |
| `group_emails.py` | Functional version of the email grouping problem |

---

### 5. gRPC Example (`python/grpc_example/`)

A minimal client-server example using **Protocol Buffers and gRPC** in Python — demonstrating familiarity with service definitions, stub generation, and RPC patterns. Includes:

- `greeter.proto` — protobuf service definition
- `server.py` — gRPC server implementation
- `client.py` — gRPC client calling the remote service
- `generate.sh` — script to generate Python stubs from the proto file

---

## Python for Competitive Programming

The codebase makes deliberate use of Python's standard library for competitive programming efficiency:

- **`collections.deque`** — O(1) BFS queues and sliding window deques
- **`collections.defaultdict`** — adjacency lists, frequency maps, memo tables
- **`collections.Counter`** — character and element frequency counting
- **`heapq`** — priority queues for Dijkstra, greedy, and scheduling
- **`bisect.bisect_right` / `insort`** — binary search and sorted insertion
- **Prefix sums** — O(1) range queries precomputed in O(n)
- **Monotonic stacks** — nearest-greater/smaller element patterns

Advanced algorithmic structures implemented directly in Python:

- **Segment Tree** — range max queries with bitwise array indexing
- **Li Chao Tree** — optimal line queries for convex hull trick problems
- **Kosaraju's Algorithm** — two-pass DFS for Strongly Connected Components
- **BFS with portals** — graph traversal on grids with non-local edges

---

## Python for OOP Design

The CodeSignal section demonstrates strong object-oriented design skills:

- **Encapsulation** — data and behavior bundled into classes (`LRUCache`, `Trie`, `InboxParser`)
- **Python data model** — custom `__eq__`, `__hash__`, `__lt__`, `__repr__` to make objects behave as first-class citizens in collections and sorting
- **Composition over inheritance** — `LRUCache` composes `LinkedList` and `defaultdict` rather than subclassing
- **Duck typing and implicit interfaces** — `classes.py` demonstrates how Python's structural typing allows `LinearStore` and `SetStore` to satisfy a `Store` interface without explicit `implements`
- **Static methods** — `InboxParser.preprocess_inbox` as a pure parsing utility
- **`defaultdict` with factory functions** — used to initialize complex nested structures lazily

---

## Topics Summary

| Category | Topics |
|---|---|
| Arrays | Two pointers, sliding window, prefix sums, Kadane's |
| Greedy | Jump game, gas station, stock trading, stack stabilization |
| Dynamic Programming | 1D DP, expected value DP, DP on DAGs |
| Graphs | BFS, DFS, Kosaraju SCC, BFS on grids with portals |
| Trees | Segment tree, Li Chao tree, Trie |
| Data Structures | LRU cache, monotonic stack, sorted list with `bisect` |
| OOP Design | LRU cache, Trie, Email parser, progressive multiset |
| Systems | gRPC client-server with protobuf |
