//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 28/08/25.
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
 Leetcode 918: Maximum Sum Circular Subarray
 */
int maxSubarraySumCircular(vector<int>& A) {
    int curMax = 0;
    int maxSum = INT_MIN;
    int sum = 0;
    int curMin = 0;
    int minSum = INT_MAX;
    
    for(int x:A){
        sum+=x;
        curMax = max(x,x+curMax);
        maxSum = max(maxSum,curMax);
        
        curMin = min(x,x+curMin);
        minSum = min(minSum,curMin);
    }
    
    if(maxSum < 0) return maxSum;
    
    return max(maxSum,sum-minSum);
}
int main(int argc, const char * argv[]) {
    vector<int> nums = {5,-3,5};
    int re = maxSubarraySumCircular(nums);
    cout << re << endl;
    return 0;
}

