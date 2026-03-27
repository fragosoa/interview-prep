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

vector<int> adj[2002];
int in[2002];

// Khan Algorithm
bool ts(int numCourses) {
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(in[i] == 0) q.push(i);
        }
        int nodes = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            nodes++;
            for(int v:adj[u]){
                in[v]--;
                if(in[v] == 0) q.push(v);
            }
        }

        return nodes == numCourses;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto edge:prerequisites){
            int v = edge[0];
            int u = edge[1];

            adj[u].push_back(v);
            in[v]++;
        }

        return ts(numCourses);
}
/**
 Leetcode 207: Course Schedule
 */

int main(int argc, const char * argv[]) {
    vector<vector<int>> in = {{1,0},{0,1}};
    bool res = canFinish(2,in);
    
    cout << res << endl;
    return 0;
}

