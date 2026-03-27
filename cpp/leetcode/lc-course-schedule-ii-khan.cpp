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

int in[2002];
vector<int> adj[2002];
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int> ts;
        for(auto edge: prerequisites){
            int u = edge[1];
            int v = edge[0];
            adj[u].push_back(v);
            in[v]++;
        }

        for(int i=0;i<numCourses;i++){
            if(in[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int u = q.front();q.pop();
            ts.push_back(u);

            for(int v:adj[u]){
                in[v]--;
                if(in[v] == 0) q.push(v);
            }
        }

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

