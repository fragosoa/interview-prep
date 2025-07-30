//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 29/07/25.
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


int bs(int x, vector<int> &lis, int tp){
    int left = 0;
    int right = tp;

    while(left < right){
        int m  = (right-left)/2 + left;
        if(x > lis[m]) left = m+1;
        else right = m;
    }
    return left;
    }

int lengthOfLIS(vector<int>& A) {
    int n = A.size();
    vector<int> lis(n,0);

    int tp = 0;

    for(auto x:A){
        // x needs to be added
        if(tp == 0 || x > lis[tp-1]){
            lis[tp++] = x;
            
            continue;
        }
        int index = bs(x,lis,tp-1);
        lis[index] = x;
        
    }
    return tp;
}


/**
 Leetcode 300: Longest Increasing subsequence
 */

int main(int argc, const char * argv[]) {
    cout << "hee" << endl;
    return 0;
}

