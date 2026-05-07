#include <bits/stdc++.h>
using namespace std;

int n,m;
long long mod = 1000000007;

int main(){
    cin>>n>>m;
    vector<vector<char>> maze(n,vector<char>(m));
    vector<vector<long long>> dp(n,vector<long long>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
        }
    }
    dp[0][0] = 1;

    for(int i=1;i<n;i++){
        if(maze[i][0] == '#') dp[i][0] = 0;
        else dp[i][0] = dp[i-1][0];
    }
    for(int i=1;i<m;i++){
        if(maze[0][i] == '#') dp[0][i] = 0;
        else dp[0][i] = dp[0][i-1];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(maze[i][j] == '#'){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = ((dp[i-1][j]%mod) + (dp[i][j-1]%mod)) % mod;
            }
        }
    }


    cout << dp[n-1][m-1] << endl;

    return 0;

}
