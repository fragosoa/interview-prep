#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    string s;
    cin>>n>>k>>s;

    vector<int> freq(26,0);

    for(char c:s){
        freq[c-'a']++;
    }

    int numpairs = 0;
    int numodd = 0;

    for(int i=0;i<26;i++){
        numpairs += (freq[i]/2);
        numodd += (freq[i] %2 == 1);
    }

    int ans = 2*(numpairs/k);
    numodd += 2*(numpairs%k);

    ans += (numodd>=k);
    cout << ans << endl;
}
int main() {
    int q;
    cin>>q;
    while(q--){
        solve();
    }
}