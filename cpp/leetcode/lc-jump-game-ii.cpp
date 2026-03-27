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
 Leetcode 45: Jump Game II
 */
int jump(vector<int>& nums) {
    int end = 0;
    int maxreach = 0;
    int n = nums.size();
    int count = 0;
    
    for(int i=0;i<n-1;i++){
        maxreach = max(maxreach,i+nums[i]);
        if(i == end){
            count++;
            end = maxreach;
        }
    }
    
    return count;
}

int main(int argc, const char * argv[]) {
    vector<int> in = {2,3,1,1,4};
    int res = jump(in);
    cout << res << endl;
    return 0;
}

