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

int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int prev = -200;
        int tp = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != prev){
                nums[tp++] = nums[i];
                k++;
            }
            prev = nums[i];
        }
        return k;
}

/**
 Leetcode 26.. Remove Duplicates from Sorted Array
 */


int main(int argc, const char * argv[]) {
    vector<int> in = {1,1,2};
    int res = removeDuplicates(in);
    cout << res << endl;
    return 0;
}

