#include <bits/stdc++.h>
using namespace std;


using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);

    for(ll &p:a) cin>>p;

    //vector<ll> dp(n);
    ll prefix = max(0LL,a[0]);

    ll maxi = a[0];
    for(int i=1;i<n;i++){
        prefix += a[i];
        if(a[i] > prefix) prefix = a[i];
        maxi  = max(maxi,prefix);
    }

    cout << maxi << endl;
    
}

int main() {
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}