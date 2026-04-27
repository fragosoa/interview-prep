#include <bits/stdc++.h>
using namespace std;


int dp[10000000];

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> coins(n,0);
    for(int &p:coins) cin>>p;

    dp[0] =0;
    for(int i=1;i<=x;i++){
        int mini = 10000000;
        for(int c:coins){
            int amount = i-c >= 0 ? dp[i-c] : 10000000;
            mini = min(mini,amount);
        }
        if(mini == 10000000) dp[i] = 10000000;
        else dp[i] = 1+mini;
    }

    //for(int i=0;i<=11;i++) cout << dp[i] << " "; 
    //cout << endl << endl;
    if(dp[x] == 10000000) cout << -1 << endl;
    else cout << dp[x] << endl;

        
    return 0; 
}