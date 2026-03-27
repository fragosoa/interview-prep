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

int lessThanEqual(int target, vector<int> &nums){
        int count = 0;
        int start = 0;
        int sum = 0;

        for(int end = 0;end<nums.size();end++){
            sum+=nums[end];

            while(sum>target){
                sum-=nums[start++];
            }
            count+=(end-start+1);
        }

        return count;
}
int numSubarraysWithSum(vector<int>& nums, int goal) {
    return lessThanEqual(goal,nums) - (goal-1>=0 ? lessThanEqual(goal-1,nums) : 0);
}

/**
 Leetcode 930: Binary Subarrays with Sum
 */

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,0,1,0,1};
    int target = 2;
    int res =numSubarraysWithSum(nums,target);
    cout << res << endl;
}

