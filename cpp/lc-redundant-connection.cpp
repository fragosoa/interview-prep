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

class UnionFind{
private:
    vector<int> parent,rank;
public:
    UnionFind(int n){
        parent.resize(n+1);
        rank.resize(n+1,1);

        for(int i=1;i<=n;i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] == x) return parent[x];

        return parent[x] = find(parent[x]);
    }

    bool union_(int x,int y){
        int rx = find(x);
        int ry = find(y);

        if(rx == ry) return false; // same group

        if(rank[rx] > rank[ry]){
            parent[ry] = rx;
        }
        else if(rank[ry] > rank[rx]){
            parent[rx] = ry;
        }
        else{
            parent[ry] = rx;
            rank[rx]++;
        }

        return true;
    }
};

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind ds(edges.size());
        for(auto edge:edges){
            if(!ds.union_(edge[0],edge[1])) return edge;
        }
        return {};
    }

/**
 Leetcode 684:  Redundant Connection
 */

int main(int argc, const char * argv[]) {
    cout << "heelo" << endl;
    return 0;
}

