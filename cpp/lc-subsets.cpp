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
#include <list>
using namespace std;

vector<vector<int>> res;
vector<int> current;

void bt(int start,vector<int> &nums){
    res.push_back(current);

    for(int i=start;i<nums.size();i++){
        current.push_back(nums[i]);
        bt(i+1,nums);
        current.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    bt(0,nums);
    return res;
}
/**
 Leetcode 78. Subsets
 */


int main(int argc, const char * argv[]) {
    vector<int> in = {1,2,3};
    vector<vector<int>> res = subsets(in);
    for(auto v:res){
        for(auto x:v){
            cout << x << " , ";
        }
        cout << endl;
    }
    return 0;
}

