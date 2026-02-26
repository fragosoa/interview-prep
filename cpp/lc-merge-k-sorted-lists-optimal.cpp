//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 27/08/25.
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
    
    ListNode(int val): val(val) {
        next = nullptr;
    }
};

/**
 Leetcode 23: Merge K sorted Lists
 */

struct compare{
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    for(ListNode* x:lists){
        if(x) pq.push(x);
    }
    
    ListNode* head = new ListNode(0); // dummy
    ListNode* curr = head;
    
    while(!pq.empty()){
        ListNode* top = pq.top();
        pq.pop();
        curr->next = top;
        curr = curr->next;
        
        if(top && top->next){
            pq.push(top->next);
        }
    }
    
    return head->next;
    
}
int main(int argc, const char * argv[]) {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(5);
    
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);
    
    ListNode* head3 = new ListNode(2);
    head3->next = new ListNode(6);
    
    vector<ListNode*> in = {head1,head2,head3};
    
    ListNode* res =mergeKLists(in);
    ListNode* iter = res;
    while(iter){
        cout << iter->val << " ";
        iter = iter->next;
    }
    
    return 0;
}

