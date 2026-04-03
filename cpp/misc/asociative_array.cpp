#include <bits/stdc++.h>
using namespace std;

// https://judge.yosupo.jp/problem/associative_array
map<long long,long long> M;
void read(){
    long long k,v;
    cin>>k>>v;
    M[k] = v;
}
void show(){
    long long k;
    cin>>k;
    cout << M[k] << endl;
}
int main(){
    int q;
    cin>>q;

    while(q--){
        int a;
        cin>>a;
        if(a == 0){
            read();
        }
        else if(a == 1){
            show();
        }
    }

    return 0;
}