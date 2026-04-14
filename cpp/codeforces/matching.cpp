#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> nums(n);

    for(int &p:nums) cin>>p;
    
    map<int,vector<int>> groups;
    for(int i=0;i<n;i++){
        int id = i-nums[i];
        groups[id].push_back(nums[i]); 
    }

    long long ans = 0;
    
    for(auto &kv:groups){
        sort(kv.second.rbegin(),kv.second.rend());
        for(int i = 0;i+1<kv.second.size();i+=2){
            int total = kv.second[i] + kv.second[i+1];
            if(total > 0) ans+=total;
        }
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