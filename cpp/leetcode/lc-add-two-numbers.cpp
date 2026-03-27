//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 1/08/25.
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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> ans;
        int carry = 0;
        ListNode* result = new ListNode(0);
        ListNode* iter = result;
        while(l1 && l2){
            int sum = (l1->val + l2->val + carry);
            int res = sum%10;
            carry = sum/10;
            
            iter->next = new ListNode(res);
            iter = iter->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            int sum = (l1->val + carry);
            int res = sum%10;
            carry = sum/10;
            l1 = l1->next;
            iter->next = new ListNode(res);
            iter = iter->next;
        }
        while(l2){
            int sum = (l2->val + carry);
            int res = sum%10;
            carry = sum/10;
            l2 = l2->next;
            iter->next = new ListNode(res);
            iter = iter->next;
        }

        if(carry>0){
            iter->next = new ListNode(carry);
            iter = iter->next;
        }

        
        return result->next;
    }
/**
 Leetcode 2: Add two numbers
 */

int main(int argc, const char * argv[]) {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    
    ListNode* res = addTwoNumbers(l1,l2);
    
    ListNode* iter = res;
    while(iter){
        cout << iter->val << " , ";
        iter = iter->next;
    }
    return 0;
}

