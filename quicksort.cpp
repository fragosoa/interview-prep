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


// implement quick sort

int partition(int left,int right, vector<int> &nums){
    int pivot = nums[right];
    int i = left;
    for(int j=left;j<right;j++){
        if(nums[j] <= pivot){
            swap(nums[i++],nums[j]);
        }
    }
    swap(nums[i],nums[right]);
    return i;
}

void qsutil(int left,int right,vector<int> &nums){
    if(left >= right) return;
    
    int pivot = partition(left,right,nums);
    qsutil(left,pivot-1,nums);
    qsutil(pivot+1, right, nums);
    
}

void quicksort(vector<int>& nums) {
    qsutil(0,nums.size()-1,nums);
}


int main(int argc, const char * argv[]) {
    vector<int> in = {3,2,1,5,6,4};
    quicksort(in);
    
    for(auto x:in){
        cout << x << " , ";
    }
    cout << endl;
    return 0;
}

