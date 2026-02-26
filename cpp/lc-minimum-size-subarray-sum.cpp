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


int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int start = 0;
        int mini = 1<<20;

        for(int end = 0;end<nums.size();end++){
            sum+=nums[end];

            while(sum>=target){
                mini = min(mini,(end-start+1));
                sum-=nums[start++];
            }
        }
        if(mini == 1<<20) return 0;
        return mini;
}

/**
 Leetcode 209: Minimum Size Subarray Sum
 */

int main(int argc, const char * argv[]) {
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    int res =minSubArrayLen(target,nums);
    cout << res << endl;
}

