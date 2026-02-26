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

int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;

        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        int count = 0;
        for (auto& kv : freq) {
            int x = kv.first;
            if ((k == 0 && kv.second > 1) || (k > 0 && freq.count(x + k))) {
                count++;
            }
        }

        return count;
}

/**
 Leetcode 532. K-diff Pairs in an Array
 */


int main(int argc, const char * argv[]) {
    vector<int> in = {3,1,4,1,5};
    int k = 2;
    int res = findPairs(in,k);
    cout << res << endl;
    return 0;
}

