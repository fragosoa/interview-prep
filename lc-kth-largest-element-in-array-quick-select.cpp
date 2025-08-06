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

// quick select

int partition(int left,int right, vector<int> &nums){
    int pivot = nums[right];
    int i = left;
    for(int j=left;j<right;j++){
        if(nums[j]>=pivot){
            swap(nums[i++],nums[j]);
        }
    }
    swap(nums[i],nums[right]);
    return i;
}
int quickselect(vector<int> &nums, int k){
    int left = 0;
    int right = nums.size()-1;
    
    while(1){
        int pivot = partition(left,right,nums);
        if(pivot == k-1) return nums[pivot];
        if(pivot<k-1) left = pivot+1;
        else right = pivot-1;
    }
}
int findKthLargest(vector<int>& nums, int k) {
    return quickselect(nums,k);
}

/**
 Leetcode 215: Kth largest element in an array
 */


int main(int argc, const char * argv[]) {
    vector<int> in = {3,2,1,5,6,4};
    int k = 2;
    int res = findKthLargest(in,k);
    cout << res << endl;
    return 0;
}

