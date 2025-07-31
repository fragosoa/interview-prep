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


vector<int> productExceptSelf(vector<int>& A) {
        int n = A.size();
        vector<int> left(n,1);

        left[n-1] = A[n-1];
        for(int i=n-2;i>=0;i--){
            left[i] = A[i] * left[i+1];
        }
        int acc = 1;

        for(int i=0;i<n;i++){
            left[i] = (acc) * (i+1<n ? left[i+1] : 1);
            acc *= A[i];
        }
        return left;
        
}

/**
 Leetcode 238: Product of Array except self
 */

int main(int argc, const char * argv[]) {
    vector<int> in = {1,2,3,4};
    vector<int> ans = productExceptSelf(in);
    for(auto x:ans) cout << x << " ";
    cout << endl;
    return 0;
}

