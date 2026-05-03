#include <bits/stdc++.h>
using namespace std;


using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<ll> prefix(n+1);

    /*
    sum over subarray [l,r] is 
    p[r] - p[l]. 
    separation variables method: 
    in order to get the largest sum, we can minimize p[l]. 
    So we can calculate max = p[r] - min p[l] for l<r. 
    We can track minimum 
    */
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        prefix[i] = prefix[i-1] +x;
    }
    ll max_sum = prefix[1];
    ll min_prefix = prefix[0];

    for(int i=1;i<=n;i++){
        max_sum = max(max_sum,prefix[i]-min_prefix);
        min_prefix = min(min_prefix,prefix[i]);
    }

    cout << max_sum << endl; 
}

int main() {
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}