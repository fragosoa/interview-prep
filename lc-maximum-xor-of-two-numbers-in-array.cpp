//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 14/07/25.
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

struct TrieNode{
        bool isEnd;
        vector<TrieNode*> children = {nullptr,nullptr};

        TrieNode(): isEnd(false) {}
    };
    TrieNode* root;
    void insert(int num){
        TrieNode* curr = root;
        int maxbits = 31;

        for(int i=31;i>=0;i--){
            int bit = (num >> i)& 1;
            if(!curr->children[bit]){
                curr->children[bit] = new TrieNode();
            }
            
            curr = curr->children[bit];
        }
        curr->isEnd = true;
    }
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();
        for(auto x:nums){
            insert(x);
        }

        
        int maxxor = 0;

        for(auto x:nums){
            TrieNode* curr = root;
            int xr = 0;
            for(int i=31;i>=0;i--){
                int bit = (x>>i) & 1;
                int target = 1-bit;


                // if exists the opposite bit
                if(curr->children[target]){
                    curr = curr->children[target];
                    xr |=  (1<<i);
                }
                else{
                    curr = curr->children[bit];
                }

            }
            maxxor = max(maxxor,xr);
        }
        return maxxor;
    }
/**
 Leetcode 421: Maximum XOR of Two numbers in an Array.
 */

int main(int argc, const char * argv[]) {
    vector<int> in = {3,10,5,25,2,8};
    int ans=findMaximumXOR(in);
    cout << ans << endl;
    
    return 0;
}

