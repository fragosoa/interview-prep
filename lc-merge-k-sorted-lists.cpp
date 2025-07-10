//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 06/07/25.
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

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val): val(val), next(nullptr) {}
};

struct compare{
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0) return nullptr;
    
    vector<ListNode*> nums;

    for(int i=0;i<lists.size();i++){
        ListNode* iter = lists[i];
        while(iter){
            nums.push_back(iter);
            iter = iter->next;
        }
    }
    if(nums.size() == 0) return nullptr;
    priority_queue<ListNode*, vector<ListNode*>,compare> pq(nums.begin(),nums.end());

    ListNode* head = pq.top();
    
    ListNode* curr = head;
    
    pq.pop();

    while(!pq.empty()){
        ListNode* tp = pq.top();
        pq.pop();
        curr->next = tp;
        curr = curr->next;
    }
    curr->next = nullptr;

    return head;
}
/**
 Leetcode 23: Merge K sorted Lists
 */

int main(int argc, const char * argv[]) {
    cout << " hello " << endl;
    return 0;
}

