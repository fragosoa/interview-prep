//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 29/07/25.
//

#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <queue>
#include <stack>
#include <list>
using namespace std;


class LRUCache {
private:
    int capacity;
    // This is like unordered_map<int, ListNode* > cache
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    list<pair<int, int>> lruList;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        
        // Move the node to the head
        lruList.splice(lruList.begin(), lruList, cache[key]);
        return cache[key]->second;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // If we are updating move the node to the front
            cache[key]->second = value;
            lruList.splice(lruList.begin(), lruList, cache[key]);
            return;
        }

        // Check cache is full
        if (cache.size() >= capacity) {
            int lruKey = lruList.back().first;
            // remove the key and pop from the list
            cache.erase(lruKey);
            // this is like doing tail->next = nullptr
            lruList.pop_back();
        }

        // Create a new node at the head and point it to the cache key
        lruList.emplace_front(key, value);
        cache[key] = lruList.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


/**
 Leetcode 146: LRU Cache
 */

int main(int argc, const char * argv[]) {
    cout << "hee" << endl;
    return 0;
}

