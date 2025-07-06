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
void bt(int start, vector<int> &nums){
    if(start == nums.size()){
        res.push_back(nums);
        return;
    }

    for(int i=start;i<nums.size();i++){
        swap(nums[i],nums[start]);
        bt(start+1,nums);
        swap(nums[i],nums[start]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    bt(0,nums);
    return res;
}
/**
 Leetcode 46. Permutations
 */


int main(int argc, const char * argv[]) {
    vector<int> in = {1,2,3};
    vector<vector<int>> res = permute(in);
    for(auto v:res){
        for(auto x:v){
            cout << x << " , ";
        }
        cout << endl;
    }
    return 0;
}

