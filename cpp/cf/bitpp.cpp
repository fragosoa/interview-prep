#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int val = 0;
    for(int i =0;i<n;i++){
        string w;
        cin>>w;
        if(w[0] == '+' || w[2] == '+') val++;
        if(w[0] == '-' || w[2] == '-') val--;
    }
    cout << val << endl;
    return 0;
}