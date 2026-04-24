#include <bits/stdc++.h>
using namespace std;

int n;
long long mod = 1e9 + 7;
void solve(){
    cin>>n;
    /*
    count(n) = count(n-1) + count(n-2) + ... count(n-6);
    count(0) = 0;
    */
    vector<long long> count(n+1,0);
    count[0] = 1;
    for(int i=1;i<=n;i++){
        if(i-1>=0) count[i] += (count[i-1])%mod;
        if(i-2>=0) count[i] += count[i-2]%mod;
        if(i-3>=0) count[i] += count[i-3]%mod;
        if(i-4>=0) count[i] += count[i-4]%mod;
        if(i-5>=0) count[i] += count[i-5]%mod;
        if(i-6>=0) count[i] += count[i-6]%mod;
    }

    cout << count[n]%mod << endl;
}
int main(){
    solve();    
    return 0; 
}