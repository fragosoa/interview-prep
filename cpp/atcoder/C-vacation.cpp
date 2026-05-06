#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> a(n+1,vector<int>(3));
   

    for(int i=1;i<=n;i++){
        cin>>a[i][0] >> a[i][1] >> a[i][2];
    }

    //vector<vector<int>> dp(n+1,vector<int> (3,0));
    int dpi0 = 0;
    int dpi1 = 0;
    int dpi2 = 0;

    for(int i=1;i<=n;i++){
        int ndpi0 = max(dpi1,dpi2) + a[i][0];
        int ndpi1 = max(dpi0,dpi2) + a[i][1];
        int ndpi2 = max(dpi1,dpi0) + a[i][2];

        dpi0 = ndpi0;
        dpi1 = ndpi1;
        dpi2 = ndpi2;
    }

    cout << max({dpi0,dpi1,dpi2}) << endl;

    return 0;
}
