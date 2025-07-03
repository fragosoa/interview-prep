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
 Leetcode 560. Subarray Sum Equals K
 */

int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freqs;
        freqs[0] = 1;
        int sum = 0;
        int total = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            total+=freqs[sum-k];
            freqs[sum]++;
        }
        return total;
}


int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,3};
    cout << subarraySum(nums,3) << endl;
    return 0;
}

