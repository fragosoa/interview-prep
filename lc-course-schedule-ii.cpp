//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 3/08/25.
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

int color[2002];
vector<int> adj[2002];
vector<int> ts;
    // has cycle?
bool dfs(int x) {
        if(color[x] == 1) return true;
        if(color[x] == 2) return false;

        color[x] = 1;
        for(int v:adj[x]){
            if(dfs(v)) return true;
        }

        color[x] = 2;
        ts.push_back(x);
        return false;
}
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto edge:prerequisites){
            int v = edge[0];
            int u = edge[1];

            adj[u].push_back(v);
        }
        for(int i=0;i<numCourses;i++){
            if(color[i] == 0){
                if(dfs(i)) return {};
            }
        }
        reverse(ts.begin(),ts.end());
        if(ts.size() == numCourses) return ts;
        return {};
}
/**
 Leetcode 210: Course-schedule-ii
 */

int main(int argc, const char * argv[]) {
    vector<vector<int>> in = {{1,0},{2,0},{3,1},{3,2}};
    vector<int> res = findOrder(4,in);
    for(auto x:res){
        cout << x << " , ";
        
    }
    return 0;
}

