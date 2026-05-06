#include <bits/stdc++.h>
using namespace std;

long long dp[101][100002];
int main(){
    int n,W;
    cin>>n>>W;
    vector<int> weight(n+1,0);
    vector<int> v(n+1,0);

    for(int i=1;i<=n;i++){
        cin>>weight[i] >> v[i];
    }

    for(int i=1;i<=n;i++){
        for(int w=0;w<=W;w++){
            long long notake = dp[i-1][w];
            long long take = (w-weight[i] >= 0 ? dp[i-1][w-weight[i]] + v[i] : 0) ;
            dp[i][w] = max(notake,take);

        }
    }

    cout << dp[n][W] << endl;

    

    return 0;
}
