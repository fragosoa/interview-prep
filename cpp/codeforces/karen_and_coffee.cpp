#include <bits/stdc++.h>
using namespace std;

int greaterk[200002];
int diff[200002];

int main(){
    int n,k,q;
    cin>>n>>k>>q;

    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        diff[l]++;
        diff[r+1]--;
    }
    for(int i=1;i<200002;i++){
        diff[i] += diff[i-1];
        if(diff[i] >=k) greaterk[i] = 1;
    }
    for(int i=1;i<200002;i++){
        greaterk[i] += greaterk[i-1];
    }

    while(q--){
        int a,b;
        cin>>a>>b;
        int ans = greaterk[b] - greaterk[a-1];
        cout << ans << endl;
    }
    return 0;

}
