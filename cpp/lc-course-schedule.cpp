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
int color[2002];
    

bool dfs(int x){
        if(color[x] == 1) return true;
        if(color[x] == 2) return false;

        color[x] = 1;

        for(int v:adj[x]){
            if(dfs(v)) return true;
        }
        color[x] = 2;
        
        return false;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto edge:prerequisites){
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);
        }

        for(int i=0;i<numCourses;i++){
            if(color[i] == 0){
                if(dfs(i)) return false;
            }
        }

        return true;
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

