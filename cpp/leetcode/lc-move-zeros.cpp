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

void moveZeroes(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        int k = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0) count++;
            else{
                nums[k++] = nums[i];
            }
        }
        for(int i=n-1;i>=(n-count);i--) nums[i] = 0;
}

void printV(vector<int> &nums){
    for(auto x:nums) cout << x << " , ";
    cout << endl;
}


/**
 Leetcode 283. Move zeros
 */


int main(int argc, const char * argv[]) {
    vector<int> in = {0,1,0,3,12};
    moveZeroes(in);
    printV(in);
    return 0;
}

