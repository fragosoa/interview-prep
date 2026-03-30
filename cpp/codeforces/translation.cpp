#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin>>s>>t;

    if(s.length() != t.length()){
        cout << "NO" << endl;
        return 0; 
    }

    reverse(s.begin(),s.end());
    if(s == t) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}