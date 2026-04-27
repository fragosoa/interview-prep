#include <bits/stdc++.h>
using namespace std;


long long dp[1000001];
long long mod = 1e9+7;
int main(){
    int n,x;
    cin>>n>>x;

    vector<int> coins(n,0);

    for(int &p:coins) cin>>p;
    sort(coins.begin(), coins.end());

    dp[0] = 1;
    for(int i=1;i<=x;i++){
        long long amount = 0;
        for(int c:coins){
            if(c > i) break;
            amount += dp[i-c];
        }
        dp[i] = amount%mod;
    }
    cout << dp[x] << endl;
    return 0; 
}