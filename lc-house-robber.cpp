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

int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];

        for(int i=1;i<n;i++){
            dp[i] = max(nums[i]+(i-2>=0 ? dp[i-2] : 0), (i-1>=0 ? dp[i-1] : 0));
        }
        return dp[n-1];
}

/**
 Leetcode 198: House Robber
 */

int main(int argc, const char * argv[]) {
    vector<int> in = {1,2,3,1};
    int res = rob(in);
    cout << res << endl;
    return 0;
}

