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

// Approach 1: sort + two pointers
vector<int> twoSum(vector<int>& nums, int target) {
    vector<pair<int,int>> extnums;
    for(int i=0;i<nums.size();i++){
        extnums.push_back({nums[i],i});
    }
    sort(extnums.begin(),extnums.end(),[](const pair<int,int> &a, pair<int,int>  &b){
        return a.first<b.first;
    });

    int left = 0;
    int right = (int)nums.size()-1;

    while(left<=right){
        int sum = extnums[left].first + extnums[right].first;
        if(sum == target){
            return {extnums[left].second,extnums[right].second};
        }
        if(sum>target) right--;
        else left++;
    }
    return {};
}

// Approach 2: Hashmap + linear scan
vector<int> twoSumHashmap(vector<int>& nums, int target) {
        unordered_map<int,int> numsindex;

        for(int i=0;i<nums.size();i++){
            numsindex[nums[i]] = i;
        }

        for(int i=0;i<nums.size();i++){
            int key = target-nums[i];
            if(numsindex.count(key)>0 && numsindex[key]!=i){
                return {i,numsindex[key]};
            }
        }
        return {};
}
/**
 Leetcode 1. Two sum
 */


int main(int argc, const char * argv[]) {
    vector<int> in = {3,2,4};
    vector<int> res = twoSum(in, 6);
    return 0;
}

