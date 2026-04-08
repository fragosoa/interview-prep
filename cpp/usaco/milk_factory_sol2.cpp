#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> out(n,0);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        out[--u]++;
    }
    int found = -2;
    for(int i=0;i<n;i++){
        if(out[i] == 0){
            found = i;
        }
    }
    cout << found+1 << endl;
    
    return 0; 
}