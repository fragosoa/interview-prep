from collections import defaultdict

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def get_last(self):
        if self.tail:
            return self.tail
        return None
    
    def add_back(self, node):
        if not self.head:
            self.head = node
            self.tail = node 
            return
        self.tail.next = node
        node.prev = self.tail
        self.tail = node

    def remove_front(self):
        if self.head == None:
            return None
        evicted_key = self.head.key
        if self.head.next == None:
            self.head = None
            return evicted_key
        next = self.head.next
        self.head.next = None
        next.prev = None
        self.head = next

        return evicted_key
    def remove_back(self):
        if self.tail == None:
            return None
        if self.tail.prev == None:
            self.tail = None
            return
        prev = self.tail.prev
        self.tail.prev = None
        prev.next = None
        self.tail = prev
        return
    def remove_from_middle(self,node):
        if node.next and node.prev:
            node.prev.next = node.next
            node.next.prev = node.prev
            node.next = None
            node.prev = None
            return
        if node == self.head:
            self.remove_front()
            return
        if node == self.tail:
            self.remove_back()
            return


class ListNode:
    def __init__(self,key):
        self.key = key
        self.prev = None
        self.next = None

class LRUCache:
    def __init__(self, capacity: int) -> None:
        self.capacity = capacity
        self.size = 0
        self.eviction_list = LinkedList()
        self.keys = defaultdict(lambda : {
            "value": None,
            "eviction_node": None
        })
    
    def _evict_lru_node(self):
        evicted_key = self.eviction_list.remove_front()
        if evicted_key != None:
            del self.keys[evicted_key]
            self.size -= 1

    def get(self,key: int) -> int: 
        if not key in self.keys:
            return -1
        value = self.keys[key]["value"]
        node = self.keys[key]["eviction_node"]
        self.eviction_list.remove_from_middle(node)
        self.eviction_list.add_back(node)
        return value
        
    def put(self,key: int, value: int) -> None:
        if self.size == self.capacity:
            self._evict_lru_node()
        if not key in self.keys:
            self.keys[key] = {
                "value": value,
                "eviction_node": ListNode(key)
            }
        else:
            self.keys[key]["value"] = value
        newest_node = self.keys[key]["eviction_node"]
        self.eviction_list.add_back(newest_node)
        self.size += 1
