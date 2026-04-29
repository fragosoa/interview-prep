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

    for(int i=1;i<=n;i++){
        nums[i] += nums[i-1];
    }

    map<ll,ll> freq;
    freq[0] = 1;

    ll ans = 0;

    for(int i=1;i<=n;i++){
        ans += freq[nums[i] - x];
        freq[nums[i]]++;
    }

    cout << ans << endl;

    
    return 0;
}