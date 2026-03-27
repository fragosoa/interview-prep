//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 19/08/25.
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


/**
 Leetcode 146: LRU Cache LinkedList implementation
 */

class LRUCache {
private:
    struct tNode{
        int key;
        tNode* prev;
        tNode* next;

        tNode(int key): key(key) {
            prev = nullptr;
            next = nullptr;
        }
    };
    tNode* head;
    tNode* tail;
    unordered_map<int,pair<int,tNode*>> cache;
    int capacity;
    int size;

    void moveToFront(tNode* curr){
        if(curr == head) return; // already head
        if(curr->prev) curr->prev->next  = curr->next;
        if(curr->next) curr->next->prev = curr->prev;

        if(curr == tail){
            tail = curr->prev;
        }

        curr->next = head;
        curr->prev = nullptr;

        if(head){
            head->prev = curr;
        }
        head = curr;

        if(!tail) tail = head;
    }

    void addToFront(tNode* curr){
        curr->next = head;
        curr->prev = nullptr;

        if(head){
            head->prev = curr;
        }

        head = curr;

        if(!tail){
            tail = head;
        }
    }

    void removeTail(){
        if(!tail) return;

        tNode* toDelete = tail;
        tail = tail->prev;

        if(tail){
            tail->next = nullptr;
        }
        else{
            head = nullptr;
        }

        delete toDelete;
    }
public:

    LRUCache(int cap) {
        head = nullptr;
        tail = nullptr;
        capacity = cap;
        size = 0;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()) return -1;
        
        int val = cache[key].first;
        tNode* curr = cache[key].second;
        moveToFront(curr);

        return val;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            cache[key].first = value;
            tNode* curr = cache[key].second;
            moveToFront(curr);
            return;
        }
        tNode* newNode = new tNode(key);
        cache[key] = make_pair(value,newNode);
        addToFront(newNode);
        size++;
        
        //evict LRU key
        if(size>capacity){
            int keyToDelete = tail->key;
            cache.erase(keyToDelete);
            removeTail();
            size--;
        }
    }

    ~LRUCache() {
        tNode* curr = head;
        while(curr) {
            tNode* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

int main(int argc, const char * argv[]) {
    cout << "hee" << endl;
    return 0;
}

