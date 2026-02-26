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

vector<vector<int>> res;
vector<int> current;

void bt(int start,int sum,int &target, vector<int> &nums){
    if(sum == target){
        res.push_back(current);
        return;
    }

    for(int i=start;i<nums.size();i++){
        if(sum+nums[i]<=target){
            current.push_back(nums[i]);
            bt(i,sum+nums[i],target,nums);
            current.pop_back();
        }
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    bt(0,0,target,candidates);
    return res;
}
/**
 Leetcode 39. Combination Sum
 */


int main(int argc, const char * argv[]) {
    vector<int> in = {2,3,6,7};
    int k = 7;
    vector<vector<int>> res = combinationSum(in,k);
    for(auto v:res){
        for(auto x:v){
            cout << x << " , ";
        }
        cout << endl;
    }
    return 0;
}

