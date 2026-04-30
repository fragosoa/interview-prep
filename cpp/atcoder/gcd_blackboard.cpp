#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll a,ll b){
    if(b == 0) return abs(max(a,b));
    return gcd(b,a%b);
}

int main() {
    int n;
    cin>>n;
    vector<ll> nums(n+1);


    for(int i=1;i<=n;i++) cin>>nums[i];
    nums.push_back(0);

    vector<ll> prefix(n+1,0);
    vector<ll> suffix(n+1,0);

    for(int i=1;i<=n;i++){
        prefix[i] = gcd(prefix[i-1],nums[i]);
    }

    for(int i=n-1;i>=0;i--){
        suffix[i] = gcd(suffix[i+1],nums[i+1]);
    }

    ll maxg = 0;
    for(int i=1;i<=n;i++){
        //cout << prefix[i];
        ll res = gcd(prefix[i-1],suffix[i]);
        maxg = max(maxg,res);
    }

    cout << maxg << endl;

    
    return 0;
}