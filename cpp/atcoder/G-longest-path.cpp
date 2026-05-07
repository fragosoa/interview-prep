#include <bits/stdc++.h>
using namespace std;

int n,m;

int in[100002];
int dist[100002];
vector<int> adj[100002];

/*
if its a DAG we can maximize as dp[v] = max(dp[v],dp[u]+1) where u->v
and v is explored in topological order. 
For that, we can use Khan's algorithm

get the incidence degree, if there is any node with in degree = 0, we can process it next. 
We are sure we always have at least 1 node with in degree equals 0, because its a DAG.
*/

int main(){
    cin>>n>>m;

    while(m--){
        int u,v;
        cin>>u>>v;

        in[v]++;
        adj[u].push_back(v);
    }

    queue<int> q;
    for(int i=1;i<=n;i++){
        if(in[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u = q.front();q.pop();

        for(int v:adj[u]){
            dist[v] = max(dist[v],dist[u]+1);
            in[v]--;
            if(in[v] == 0) q.push(v);
        }
    }
    int maxi = 0;
    for(int i=1;i<=n;i++){
        maxi = max(maxi,dist[i]);
    }
    cout << maxi << endl;
    return 0;

}
