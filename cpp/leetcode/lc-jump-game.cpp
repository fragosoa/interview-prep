//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 19/08/25.
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
 Leetcode 55: Jump Game
 */

unordered_map<int, bool> dp;
    
    bool s(int x, vector<int> &nums) {
        if(x >= nums.size() - 1) return true;
        if(dp.find(x) != dp.end()) return dp[x];
        
        bool res = false;
        
        
        for(int i = x + 1; i <= min(x + nums[x], (int)nums.size() - 1); i++) {
            res = s(i, nums);
            if(res) break;
        }
        
        return dp[x] = res;
    }
    
    bool canJump(vector<int>& nums) {
        return s(0, nums);
    }
int main(int argc, const char * argv[]) {
    vector<int> in = {2,3,1,1,4};
    bool res = canJump(in);
    cout << res << endl;
    return 0;
}

