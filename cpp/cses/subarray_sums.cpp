#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n,x;
    cin>>n>>x;
    vector<ll> nums(n);

    for(ll &p:nums) cin>>p;

    int cnt = 0;
    int start =0 ;
    ll sum =0 ;
    for(int end = 0;end<n;end++){
        sum+=nums[end];

        while(sum > x){
            sum -= nums[start++];
        }
        if(sum == x) cnt++;
    }

    cout << cnt << endl;

    
    return 0;
}