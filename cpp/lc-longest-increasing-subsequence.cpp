//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 12/07/25.
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

int dp[2502];
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp[0] = 1;
        int lis = dp[0];
        for(int i=1;i<n;i++){
            int best = 0;
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    best = max(best,dp[j]);
                }
            }
            dp[i] = 1+best;
            lis = max(lis,dp[i]);
        }

        return lis;
}

/**
 Leetcode 300: Longest Increasing Subsequence
 */

int main(int argc, const char * argv[]) {
    vector<int> in = {10,9,2,5,3,7,101,18};
    int res = lengthOfLIS(in);
    cout << res << endl;
    return 0;
}

