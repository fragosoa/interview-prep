#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin>>s>>t;
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i] == t[j]){
                dp[i][j] = 1+(i-1>=0 && j-1>=0 ? dp[i-1][j-1] : 0);
            }
            else{
                dp[i][j] = max((i-1>=0 ? dp[i-1][j] : 0),(j-1>=0 ? dp[i][j-1] : 0));
            }
        }
    }

    /*for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    int i= n-1;
    int j = m-1;

    string res = "";
    while(i >= 0 && j >= 0){
        if(s[i] == t[j]){
            res += s[i];
            i--;
            j--;
        }
        else{
            int up   = (i-1 >= 0) ? dp[i-1][j] : 0;
            int left = (j-1 >= 0) ? dp[i][j-1] : 0;
            if(up > left) i--;
            else j--;
        }
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;

}
