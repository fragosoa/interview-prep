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


/**
 Leetcode 75: Sort Colors
 */

void sortColors(vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        int right = n-1;
        int i = 0;

        while(i<n && i<=right){
            if(nums[i] == 0){
                swap(nums[i++],nums[left++]);
            }
            else if(nums[i] == 2){
                swap(nums[i],nums[right--]);
            }
            else i++;
        }
    }

int main(int argc, const char * argv[]) {
    vector<int> in = {2,0,2,1,1,0};
    sortColors(in);
    for(auto x:in){
        cout << x << " , ";
    }
    
    return 0;
}

