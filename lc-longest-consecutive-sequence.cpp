//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 03/07/25.
//

#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <queue>
#include <stack>
using namespace std;


/**
 Leetcode 128. Longest Consecutive Sequence
 */

unordered_map<int,int> exists;
unordered_map<int,int> cache;
bool visited[100002];

void chain(int x,vector<int> &nums){
    int acc = 0;
    int curr = x;
    while(exists[curr]){
        if(cache[curr]){
            acc+=cache[curr];
            break;
        }
        visited[curr] = true;
        acc++;
        curr++;
    }

    cache[x] = acc;
}
int longestConsecutive(vector<int>& nums) {
    for(auto x:nums){
        exists[x]++;
    }

    for(auto x:nums){
        if(!visited[x]){
            chain(x,nums);
        }
    }

    int maxi = 0;
    for(auto kv:cache){
        maxi = max(maxi, kv.second);
    }
    return maxi;
}

int main(int argc, const char * argv[]) {
    vector<int> in = {100,4,200,1,3,2};
    cout << longestConsecutive(in) << endl;
    return 0;
}

