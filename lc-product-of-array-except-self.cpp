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
        vector<int> right(n,1);
        vector<int> left(n,1);

        right[0] = A[0];
        for(int i=1;i<n;i++){
            right[i] = A[i] * right[i-1];
        }

        left[n-1] = A[n-1];
        for(int i=n-2;i>=0;i--){
            left[i] = A[i] * left[i+1];
        }

        vector<int> ans(n,1);

        for(int i=0;i<n;i++){
            ans[i] = (i-1>=0 ? right[i-1] : 1) * (i+1<n ? left[i+1] : 1);
        }
        return ans;
        
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

