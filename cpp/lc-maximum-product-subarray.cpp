//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 27/08/25.
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
 Leetcode 152: Maximum product subarray
 */

int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp1(n+1,0);
        vector<int> dp2(n+1,0);

        dp1[0] = nums[0];
        dp2[0] = nums[0];

        int maxi = dp1[0];

        for(int i=1;i<n;i++){
            dp1[i] = max({nums[i],nums[i]*dp1[i-1],nums[i]*dp2[i-1]});
            dp2[i] = min({nums[i],nums[i]*dp1[i-1],nums[i]*dp2[i-1]});
            maxi = max({maxi,dp1[i],dp2[i]});
        }
        
        return maxi;
    }


int main(int argc, const char * argv[]) {
    vector<int> in = {2,3,-2,4};
    cout << maxProduct(in) << endl;
    return 0;
}

