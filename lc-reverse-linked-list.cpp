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

ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = head->next->next;
        prev->next = NULL;
        while(next){
            
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        curr->next = prev;
        return curr;
}
/**
 Leetcode 206: Reverse Linked List
 */

int main(int argc, const char * argv[]) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next  = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    ListNode* iter = reverseList(head);
    
    while(iter){
        cout << iter->val << " , ";
        iter = iter->next;
    }
    cout << endl;
    return 0;
}

