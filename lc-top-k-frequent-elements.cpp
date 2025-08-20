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
 Leetcode 79: Word Search
 */

struct compare{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b){
        return a.second>b.second;
    }
};
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq; // min heap

        unordered_map<int,int> freq;

        for(auto x:nums){
            freq[x]++;
        }

        for(auto kv:freq) {
            if(pq.size()<k){
                pq.push(kv);
                continue;
            }
            if(pq.top().second < kv.second){
                pq.pop();
                pq.push(kv);
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }

int main(int argc, const char * argv[]) {
    vector<int> in = {1,1,1,2,2,3};
    
    int k = 2;
    
    vector<int> ans = topKFrequent(in,k);
    for(auto x:ans){
        cout << x << endl;
    }
    return 0;
}

