#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;


    vector<int> dp(n+1,INT_MAX);
    vector<int> a(n+1,0);

    dp[1] = 0;
    
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++){
        if(dp[i] == INT_MAX) continue;
        for(int j=1;j<=k;j++){
            if(i+j<=n) dp[i+j] = min(dp[i+j],dp[i] + abs(a[i] - a[i+j]));
        }
    }

    cout << dp[n] << endl;
    return 0;
}
