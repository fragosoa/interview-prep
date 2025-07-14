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

int dp[100002];
int maxSubArray(vector<int>& nums) {
    dp[0] = nums[0];
    int maxi = dp[0];

    for(int i=1;i<nums.size();i++){
        dp[i] = max(nums[i]+dp[i-1],nums[i]);
        maxi = max(maxi,dp[i]);
    }

    return maxi;
}

int sumCross(int left,int right, vector<int> &nums){
    int sum = 0;
    for(int i=left;i<=right;i++){
        sum+=nums[i];
    }
    
    return sum;
}

int util(int left,int right,vector<int> &nums){
    if(left == right) return nums[left];
    
    int m = (right-left)/2 + left;
    int sumLeft = util(left,m,nums);
    int sumRight = util(m+1,right,nums);
    int sumCrossing = sumCross(left,right,nums);
    
    return max(sumLeft,max(sumRight,sumCrossing));
}

int maxSubarrayDivideAndConquer(vector<int> &nums){
    return util(0,nums.size()-1,nums);
}

/**
 Leetcode 53: Maximum Subarray
 */

int main(int argc, const char * argv[]) {
    vector<int> in = {-2,1,-3,4,-1,2,1,-5,4};
    int res = maxSubArray(in);
    cout << res << endl;
    return 0;
}

