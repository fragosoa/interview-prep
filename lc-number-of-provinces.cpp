//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 06/07/25.
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



bool visited[202];
int n;
void dfs(int city, vector<vector<int>> &isConnected){
    visited[city] = true;

    for(int j=0;j<n;j++){
        if(city == j) continue;
        if(!visited[j] && isConnected[city][j]){
            dfs(j,isConnected);
        }
    }
}
int findCircleNum(vector<vector<int>>& isConnected) {
    n = isConnected.size();
    int count = 0;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,isConnected);
            count++;
        }
    }

    return count;
}

/**
 Leetcode 547. Number of provinces
 */


int main(int argc, const char * argv[]) {
    vector<vector<int>> in = {{1,1,0},{1,1,0},{0,0,1}};
    int res =findCircleNum(in);
    cout << res << endl;
    
    return 0;
}

