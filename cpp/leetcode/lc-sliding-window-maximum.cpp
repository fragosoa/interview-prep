//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 5/08/25.
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


vector<int> tree;

void build(vector<int> &nums){
    int n = nums.size();
    tree.resize(2*n,INT_MIN);
    
    for(int i=0;i<n;i++){
        tree[i+n] = nums[i];
    }
    
    for(int i=n-1;i>0;i--){
        tree[i] = max(tree[2*i],tree[2*i+1]);
    }
}

int query(int l,int r, int n){
    
    int left = l+n;
    int right = r+n;
    int res = INT_MIN;
    
    while(left<right){
        if(left&1){
            res = max(res,tree[left++]);
        }
        if(right&1){
            res = max(res,tree[--right]);
        }
        left/=2;
        right/=2;
    }
    
    return res;
}

/**
 Leetcode 239: Sliding Window maximum
 */

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    build(nums);
    vector<int> ans;
    int n = nums.size();
    for(int i=0;i<=n-k;i++){
        int res = query(i,i+k,n);
        ans.push_back(res);
    }
    
    return ans;
    
}

int main(int argc, const char * argv[]) {
    vector<int> in = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = maxSlidingWindow(in,k);
    for(int x:ans){
        cout << x << endl;
    }
    
    return 0;
}

