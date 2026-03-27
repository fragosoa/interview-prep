#include <bits/stdc++.h>
using namespace std;

void solve(){
    int k;
    cin>>k;
    int a1,b1;
    cin>>a1>>b1;
    int a2,b2;
    cin>>a2>>b2;
    int ca = 0;
    int cb = 0;
    if(a1 > b1) ca++;
    else cb++;
    if(a2 > b2) ca++;
    else cb++;

    int sa = a1+a2;
    int sb = b1+b2;

    if(ca > cb && sa -sb >=k) cout << "NO" << endl;
    else cout << "YES" << endl;

        
}
int main(){
    int q;
    cin>>q;
    while(q--){
        solve();
    }
    return 0;
}