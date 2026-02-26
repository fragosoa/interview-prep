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


struct compare{
        bool operator()(const int &a, const int &b){
            return a>b;
        }
    };
int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, compare> pq;
        for(int x:nums){
            pq.push(x);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
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

