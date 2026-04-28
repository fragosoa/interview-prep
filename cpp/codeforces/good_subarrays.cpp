#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> nums(n+1,0);

    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        nums[i] = c-'0';
    }

    for(int i=1;i<=n;i++){
        nums[i] += nums[i-1];
    }
    map<int,ll> freqs;
    for(int i=0;i<=n;i++){
        freqs[nums[i]-i]++;
    }


    ll ans =0;
    for(auto kv:freqs){
        ll fq = kv.second;
        ans += (fq*(fq-1)/2);
    }


    cout << ans << endl;

}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) { solve(); }
}