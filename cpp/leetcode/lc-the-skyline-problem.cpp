//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 31/08/25.
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
#include <string>
using namespace std;

/**
 Leetcode 218: The skyline problem
 */

vector<vector<int>> merge_(vector<vector<int>> &A,vector<vector<int>> &B ){
    int i = 0;
    int j = 0;
    int h1 = 0;
    int h2 = 0;
    
    vector<vector<int>> ans;
    
    while(i<A.size() && j<B.size()){
        int x;
        // min x
        if(A[i][0] < B[j][0]){
            x = A[i][0];
            h1 = A[i][1];
            i++;
        }
        else if(B[j][0] < A[i][0]){
            x = B[j][0];
            h2 = B[j][1];
            j++;
        }
        else{
            // same x
            x = A[i][0];
            h1 = A[i][1];
            h2 = B[j][1];
            i++;
            j++;
        }
        int maxH = max(h1,h2);
        if(ans.size() == 0 || ans.back()[1] != maxH){
            ans.push_back({x,maxH});
        }
    }
    
    while(i<A.size()){
        if(ans.size() == 0 || ans.back()[1] != A[i][1]){
            ans.push_back(A[i]);
        }
        i++;
    }
    
    while(j<B.size()){
        if(ans.size() == 0 || ans.back()[1] != B[j][1]){
            ans.push_back(B[j]);
        }
        j++;
    }
    
    return ans;
}

vector<vector<int>> solve(int left,int right,vector<vector<int>> &A){
    if(left == right){
        int x1 = A[left][0];
        int x2 = A[left][1];
        int h = A[left][2];
        return {{x1,h},{x2,0}};
    }
    
    int m = (right-left)/2 + left;
    vector<vector<int>> leftHalf = solve(left,m,A);
    vector<vector<int>> rightHalf = solve(m+1,right,A);
    
    vector<vector<int>> merged = merge_(leftHalf,rightHalf);
    return merged;
    
}

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    return solve(0,buildings.size()-1,buildings);
}
int main(int argc, const char * argv[]) {
    // [[0,2,3],[2,5,3]]
    vector<vector<int>> in ={{0,2,3},{2,5,3}};
    vector<vector<int>> res = getSkyline(in);
    
    for(auto v:res){
        cout << "(" << v[0] << " , " << v[1] << ") ";
    }
    cout << endl;
    return 0;
}

