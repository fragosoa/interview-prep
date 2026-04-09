#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
    vector<int> parent,rank;
    UnionFind(int n): parent(n), rank(n,0){
        iota(parent.begin(),parent.end(),0);
    }

    int find(int x){
        if(x == parent[x]) return parent[x];
        return parent[x] = find(parent[x]);
    }

    void _union(int a,int b){
        int x = find(a);
        int y = find(b);
        if(x != y){
            if(rank[x] > rank[y]){
                rank[x] += rank[y];
                parent[y] = x;
            }
            else{
                rank[y] += rank[x];
                parent[x] = y; 
            }
        }
    }
};

int min_changes(vector<int>& arr) {
    map<int, int> first_occ, last_occ, freq;

    for (int i = 0; i < (int)arr.size(); i++) {
        int v = arr[i];
        if (!first_occ.count(v)) first_occ[v] = i;
        last_occ[v] = i;
        freq[v]++;
    }

    vector<int> values;
    for (auto kv: first_occ) values.push_back(kv.first);
    int k = values.size();
    map<int,int> idx;
    for(int i=0;i<k;i++) idx[values[i]] = i;
    
    UnionFind uf(k);

    for(int i = 0;i<k;i++){
        for(int j=i+1;j<k;j++){
            int a = values[i];
            int b = values[j];
            if(first_occ[a] < last_occ[b] && first_occ[b] < last_occ[a]){
                uf._union(i,j);
            }
        }
    }

    map<int,pair<int,int>> comp;
    for(int i=0;i<k;i++){
        int root = uf.find(i);
        comp[root].first += freq[values[i]];
        comp[root].second = max(comp[root].second,freq[values[i]]);
    }

    int total_cost = 0;
    for(auto kv:comp){
        pair<int,int> value = kv.second;
        total_cost += value.first - value.second;
    }

    return total_cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;

    cout << min_changes(arr) << "\n";
    return 0;
}