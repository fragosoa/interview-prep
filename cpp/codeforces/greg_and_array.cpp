#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,m,k;
    cin>>n>>m>>k;
    
    vector<long long> elems(n+1,0);
    vector<pair<int,pair<int,int>>> ops(m+1);
    for(int i=1;i<=n;i++) cin>>elems[i];

    for(int i=1;i<=m;i++){
        int l,r,v;
        cin>>l>>r>>v;
        ops[i] = make_pair(v,make_pair(l,r));
    }
    vector<pair<int,int>> gregs(n+1);
    vector<int> timesops(m+1,0);
    vector<int> diffops(m+2,0);

    // precalculate times each op is applied
    for(int i=1;i<=k;i++){
        int a,b;
        cin>>a>>b;
        //gregs[i] = make_pair(a,b);
        diffops[a] += 1;
        diffops[b+1] -=1;
    }

    for(int i=1;i<=m;i++){
        diffops[i] += diffops[i-1];
        timesops[i] += diffops[i];
    }

    vector<long long> difffinal(n+2,0);
    for(int i=1;i<=m;i++){
       auto opi = ops[i];
       long long value = (long long)opi.first * timesops[i];
       int l = opi.second.first;
       int r = opi.second.second;
       difffinal[l] += value;
       difffinal[r+1] -= value;
    }

    for(int i=1;i<=n;i++){
        difffinal[i] += difffinal[i-1];
        elems[i] += difffinal[i];
    }

    for(int i=1;i<=n;i++){
        cout << elems[i] << " ";
    }
    return 0; 
}
