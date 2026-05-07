#include <bits/stdc++.h>
using namespace std;

int n,m;

int dist[100002];
bool visited[100002];

vector<int> adj[100002];
vector<int> topo;

void dfs(int u){
    visited[u] = true;

    for(int v:adj[u]){
        if(!visited[v]) dfs(v);
    }

    topo.push_back(u);
}
int main(){
    cin>>n>>m;

    while(m--){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }

    for(int i=1;i<=n;i++){
        if(!visited[i]) dfs(i);
    }

    reverse(topo.begin(),topo.end());

    for(int u:topo){
        for(int v:adj[u]){
            dist[v] = max(dist[v],dist[u]+1);
        }
    }

    int maxi = 0;
    for(int i=1;i<=n;i++) maxi = max(maxi,dist[i]);

    cout << maxi << endl;
    return 0;

}
