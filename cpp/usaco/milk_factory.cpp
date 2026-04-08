#include <bits/stdc++.h>
using namespace std;


int adj[102][102];
int dist[102][102];
int inf = 1000000;
int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j) dist[i][j] = 1;
            else if(adj[i][j] == 0){
                dist[i][j] = inf;
            }
            else{
                dist[i][j] = adj[i][j];
            }
        }
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        bool found = true;
        for(int j=1;j<=n;j++){
            if(dist[j][i] >= inf){
                found = false;
                break;
            }
        }
        if(found){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0; 
}