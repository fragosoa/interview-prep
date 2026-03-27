//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 27/08/25.
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
 Leetcode 1319: Number of operations to make network connected
 */

vector<int> adj[100002];
    bool visited[100002];

    void dfs(int x){
        visited[x] = true;

        for(int v:adj[x]){
            if(!visited[v]){
                dfs(v);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        for(auto edge:connections){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int groups =0 ;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                groups++;
                dfs(i);
            }
        }

        int edges = connections.size();
        if(edges<n-1) return -1;
        return groups-1;
    }

int main(int argc, const char * argv[]) {
    vector<int> in = {2,3,1,1,4};
    int res = jump(in);
    //cout << res << endl;
    return 0;
}

