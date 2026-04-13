#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    
    for(int &p:a) cin>>p--;
    for(int &p:b) cin>>p--;

    vector<bool> moved(n+1,false);
    int ans = 0;
    int j =0 ;
    for (int i=0;i<n;i++){
        while(j<n && moved[a[j]]) j++;
        if(a[j] == b[i]){
            j++;
        }
        else{
            ans++;
            moved[b[i]] = true;
        }
    }
}