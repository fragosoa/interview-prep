#include <bits/stdc++.h>
using namespace std;

/*
Cambio de variable, en lugar de iterar por W y maximizar. Iteramos por V y minimizamos el peso.
*/
long long inf = 1e12;
int main(){
    int n,W;
    cin>>n>>W;
    vector<int> weight(n+1,0);
    vector<int> v(n+1,0);
    int V = 0;
    for(int i=1;i<=n;i++){
        cin>>weight[i] >> v[i];
        V += v[i];
    }

    vector<vector<long long>> dp(V+1,vector<long long> (n+1,inf));

    for(int i=0;i<=n;i++){
        dp[0][i] = 0;
    }

    int ans = 0;
    for(int vi=1;vi<=V;vi++){
        for(int i=1;i<=n;i++){
            
            long long take = dp[vi][i-1];
            long long notake = (vi-v[i] >= 0 ? (dp[vi-v[i]][i-1] != inf ? dp[vi-v[i]][i-1] + weight[i] : inf)  : inf );
            
            dp[vi][i] = min(take,notake);
            if(dp[vi][i] <= W){
                ans = vi;
            } 
        }
    }

    cout << ans << endl;

    return 0;
}
