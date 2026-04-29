#include <bits/stdc++.h>
using namespace std;

using ll = long long;



int main() {
    int n;
    cin>>n;
    vector<ll> nums(n+1,0);

    for(int i =1 ;i<=n;i++){
        cin>>nums[i];
    }

    for(int i=1;i<=n;i++){ nums[i] += nums[i-1];}

    map<int,ll> freqs;

    for(int i=0;i<=n;i++){
        freqs[((nums[i] % n) + n) % n]++;
    }

    ll ans = 0;

    for(auto kv:freqs){
        ll f = kv.second;

        ans += (f*(f-1)/2);
    }

    cout << ans << endl;

    
    return 0;
}