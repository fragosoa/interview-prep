#include <bits/stdc++.h>
using namespace std;




void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &p:a) cin>>p;
    vector<int> pref(n);

    for(int i=0;i<n;i++){
        pref[i] = a[i] + i;
        if(i) pref[i] = max(pref[i],pref[i-1]);
    }

    vector<int> suf(n);
    for(int i=n-1;i>=0;i--){
        suf[i] = a[i]-i;
        if(i<n-1) suf[i] = max(suf[i],suf[i+1]);
    }

    int ans = 0;
    for(int i=1;i<n-1;i++){
        ans = max(ans,pref[i-1] + a[i] + suf[i+1]);
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}