#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    vector<int> b(n);

    for(int &p:a) cin>>p;
    for(int &p:b) cin>>p;

    vector<int> E(n);
    vector<int> M(n);

    E[0] = a[0];
    M[0] = b[0];
    for(int i=1;i<n;i++){
        E[i] = E[i-1]+a[i];
        M[i] = max(M[i-1],b[i]);
    }

    int l = min(n-1,k-1);
    int ans = 0;
    for(int i=l;i>=0;i--){
        int rem = (k-1-i);
        int sum = E[i];
        int ma = M[i];
        ans = max(ans,sum+rem*ma);
    }
    cout << ans << endl;
    
}
int main() {
    int q;
    cin>>q;
    while(q--){
        solve();
    }
}