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
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void union_(int x,int y){
        int xr = find(x);
        int yr = find(y);

        if(xr != yr){
            if(rank[xr] > rank[yr]){
                parent[yr] = xr;
            }
            else if(rank[yr] > rank[xr]){
                parent[xr] = yr;
            }
            else{
                parent[yr] = xr;
                rank[xr]++;
            }
        }
    }
};

int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind ds(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]) ds.union_(i,j);
            }
        }
        set<int> provinces;
        for(int i=0;i<n;i++){
            int root = ds.find(i);
            provinces.insert(root);
        }

        return provinces.size();
    }

/**
 Leetcode 547:  Number of Provinces
 */

int main(int argc, const char * argv[]) {
    vector<vector<int>> in = {{1,1,0},{1,1,0},{0,0,1}};
    int res = findCircleNum(in);
    cout << res << endl;
    return 0;
}

