#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    string fences; 
    cin>>n;
    cin>>fences;
    vector<int> L(n);
    vector<int> R(n);


    for(int i=0;i<n;i++){
        if(fences[i] == '1') L[i] = i;
        else{
            L[i] = (i-1) >= 0 ? L[i-1] : 100000000;
        }
    }

    for(int i=n-1;i>=0;i--){
        if(fences[i] == '1') R[i] = i;
        else{
            R[i] = (i+1) < n ? R[i+1] : 100000000;
        }
    }
    unordered_map<int,pair<int,int>> dists;
    for(int i=0;i<n;i++){
        if(fences[i] == '0'){
            int dist = min(i-L[i],R[i]-i);
            if(dists.find(dist) == dists.end()){
                dists[dist] = make_pair(i,-1);
            }
            else{
                dists[dist].second = i;
            }
        }
    }
    
    int ans = 0;
    for(auto kv:dists){
        int left = kv.second.first;
        int right  =  kv.second.second;
        if(right - left > kv.first){
            ans = max(ans,kv.first);
        }
    }
    cout << ans << endl;
    

    return 0;
}