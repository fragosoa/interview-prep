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

// nlogn divide and conquer
int findPivot(vector<int> &nums){
        int left = 0;
        int right = nums.size()-1;

        while(left<right){
            int m = (right-left)/2 + left;
            // pivot found
            if(nums[m] > nums[m+1]) return m+1;
            if(nums[m] > nums[right]){
                left = m;
            }
            else{
                right = m;
            }
        }
        return -1;
    }
    int binarySearch(int left,int right, vector<int> &nums, int target) {
        int l = left;
        int r = right;

        while(l<=r){
            int m = (r-l)/2 + l;
            if(nums[m] == target) return m;
            if(nums[m]>target){
                r = m-1;
            }
            else {
                l = m+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot;
        if(n == 1){
            if(nums[0] == target) return 0;
            return -1;
        }
        // check if no pivot
        if(nums[0] < nums[n-1]){
            return binarySearch(0,n-1,nums,target);
        }

        pivot = findPivot(nums);

        if(nums[0] <= target && target <= nums[pivot-1]){
            return binarySearch(0,pivot-1,nums,target);
        }
        return binarySearch(pivot,n-1,nums,target);
    }

/**
 Leetcode 33. Search in rotated Sorted Array
 */


int main(int argc, const char * argv[]) {
    vector<int> in = {4,5,6,7,0,1,2};
    int res = search(in,0);
    cout << res << endl;
    return 0;
}

