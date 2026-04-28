#include <bits/stdc++.h>
using namespace std;

vector<long long> arr;
int main(){
    int n,q;

    cin>>n>>q;
    arr.resize(n,0);
    for(long long &p:arr) cin>>p;
    
    for(int i=1;i<n;i++){
        arr[i] += arr[i-1];
    }
    while(q--){
        int r,l;
        cin>>l>>r;

        long long res = ((r-1>= 0 ? arr[r-1] : 0) - (l-1 >= 0? arr[l-1] : 0));
        cout << res << endl;
    }
    return 0;
}