//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 19/08/25.
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
 Leetcode 56: Merge Intervals
 */

vector<vector<int>> merge(vector<vector<int>>& A) {
        sort(A.begin(),A.end());
        vector<int> iter = A[0];
        int n = A.size();
        vector<vector<int>> res;
        for(int i=1;i<n;i++){
            if(A[i][0]<= iter[1]){
                iter[1] = max(A[i][1],iter[1]);
            }
            else{
                res.push_back(iter);
                iter = A[i];
            }
        }
        res.push_back(iter);
        return res;
    }
int main(int argc, const char * argv[]) {
    vector<int> in = {2,3,1,1,4};
    bool res = canJump(in);
    cout << res << endl;
    return 0;
}

