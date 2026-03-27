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


int atMost(int k,const vector<int> &nums){
        int count = 0;
        // count the even, odd elements
        int res[2] = {0,0};
        int start = 0;

        for(int end = 0;end<nums.size();end++){
            res[nums[end]%2]++;

            while(res[1] > k){
                res[nums[start++]%2]--;
            }

            count+=(end-start+1);
        }
        return count;
}
int numberOfSubarrays(vector<int>& nums, int k) {
    return atMost(k,nums) - atMost(k-1,nums);
}

/**
 Leetcode 1248: Count number of Nice Subarrays
 */

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,1,2,1,1};
    int k = 3;
    int res =numberOfSubarrays(nums,k);
    cout << res << endl;
}

