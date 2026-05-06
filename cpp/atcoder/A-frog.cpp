#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> dp(n+1, INT_MAX);

    dp[1] = 0;
    for(int i=1;i<=n;i++){
        if(dp[i] == INT_MAX) continue;
        if(i+1 <= n) dp[i+1] = min(dp[i+1], dp[i] + abs(a[i]-a[i+1]));
        if(i+2 <= n) dp[i+2] = min(dp[i+2], dp[i] + abs(a[i]-a[i+2]));
    }
    cout << dp[n] << endl;
    return 0;
}
