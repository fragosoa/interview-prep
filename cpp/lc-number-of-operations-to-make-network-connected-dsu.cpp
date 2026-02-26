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

class UnionFind{
public:
vector<int> parent,rank;
    UnionFind(int n) {
        parent.resize(n,0);
        rank.resize(n,1);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] == x) return parent[x];
        return parent[x] = find(parent[x]);
    }

    void union_(int x,int y){
        int rx = find(x);
        int ry = find(y);

        if(rx!=ry){
            if(rank[rx] > rank[ry]){
                parent[ry] = rx;
                rank[rx]+=rank[ry];
            }
            else if(rank[ry] > rank[rx]){
                parent[rx] = ry;
                rank[ry]+=rank[rx];
            }
            else{
                parent[ry] = rx;
                rank[rx]+=rank[ry];
            }
        }
    }

    void printParent(){
        for(int i=0;i<parent.size();i++) cout << i << " , ";
        cout << endl;
        for(auto x:parent){
            cout << x << " , ";
        }
        cout << endl;
        for(auto x:rank){
            cout << x << " , ";
        }
    }
};

int makeConnected(int n, vector<vector<int>>& connections) {
        UnionFind ds(n);

        for(auto edge:connections){
            int u = edge[0];
            int v = edge[1];
            ds.union_(u,v);
        }
        //ds.printParent();

        unordered_set<int> groups;

        for(int i=0;i<n;i++){
            int root = ds.find(i);
            groups.insert(root);
        }

        int totalEdges = connections.size();
        
        if(totalEdges<n-1) return -1;

        return groups.size()-1;
    }
/**
 Leetcode 1319: Number of operations to make network connected
 */

int main(int argc, const char * argv[]) {
    cout << "hello" << endl;
    return 0;
}

