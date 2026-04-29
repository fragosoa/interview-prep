#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n,x;
    cin>>n>>x;
    vector<ll> nums(n+1,0);
    
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }

    map<ll,ll> freq;
    freq[0] = 1;

    ll ans = 0;
    int pref =0 ;
    for(int i=0;i<n;i++){
        pref += nums[i]; 
        ans += freq[pref - x];
        freq[pref]++;
    }

    cout << ans << endl;

    
    return 0;
}