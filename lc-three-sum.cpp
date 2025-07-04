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

void next_(vector<int> &nums, int &i, int &j){
    int n = (int)nums.size();
    while(i<j && i<n && nums[i] == nums[i+1]) i++;
    i++;
}
void prev_(vector<int> &nums, int &i, int &j){
    while(i<j && j>0 && nums[j] == nums[j-1]) j--;
    j--;
}

vector<vector<int>> twoSum(vector<int> &nums, int i,int j, int target) {
    vector<vector<int>> ans = {};
    while(i<j){
        int sum = nums[i] + nums[j];
        if(sum == target){
            ans.push_back({-target, nums[i], nums[j]});
            // move i to avoid repeating tuples
            next_(nums,i,j);
            
            prev_(nums,i,j);
            //cout << " he " << endl;
            //cout << j << endl;
            continue;
        }
        if(sum > target){
            j--;
        }
        else{
            i++;
        }
    }
    return ans;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end(),[](const int &a, const int &b){
        return a<b;
    });
    //printV(nums);
    cout << endl;
    vector<vector<int>> res = {};
    int k = 0;
    int n = (int)nums.size();

    while(k<=n-3){
        //cout << "K: " << k << endl;
        vector<vector<int>> ans = twoSum(nums,k+1,n-1,-nums[k]);
        while(k+1<n && nums[k] == nums[k+1]) k++;
        k++;

        for(auto v:ans){
            
            //printV(v);
            res.push_back(v);
        }

    }
    return res;
}
/**
 Leetcode 15. Three Sum
 */


int main(int argc, const char * argv[]) {
    vector<int> in = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = threeSum(in);
    for(auto v:ans){
        for(auto x:v){
            cout << x << " , ";
        }
        cout << endl;
    }
    return 0;
}

