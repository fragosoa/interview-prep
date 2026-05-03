#include <bits/stdc++.h>
using namespace std;


using ll = long long;

char m[1002][1002];
int dp[1002][1002];

void solve(){

}

int main() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            m[i][j] = c;
        }
    }

    for(int i=1;i<=n;i++){
        if(m[i][1] == '*'){
            dp[i][1] = 1 + dp[i-1][1];
        }
    }
    for(int i=1;i<=n;i++){
        if(m[1][i] == '*'){
            dp[1][i] = 1 + dp[1][i-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int curr = m[i][j] == '*';
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + curr;
        }
    }
    /*cout << endl << endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << dp[i][j] << " ";
           
        }
        cout << endl;
    }*/

    while(q--){
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        
        int ans = dp[y2][x2] - dp[y2][x1-1] - dp[y1-1][x2] + dp[y1-1][x1-1];
        /*cout << "1: " << dp[y2][x2] << endl;
        cout << "2: " << dp[y2][x1-1] << endl;
        cout << "3: " << dp[y1-1][x2] << endl;
        cout << "4: " << dp[y1-1][x1-1] << endl;*/
        cout << ans << endl;
    }
    return 0;
}