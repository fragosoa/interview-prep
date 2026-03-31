#include <bits/stdc++.h>
using namespace std;
/*
2 4
1 5 2
7 9 3
2 9 2 3
1 6 2 8
1 2 4 2
6 9 1 5
*/
int n,d;
int intv[102];

int p[102];
int m[102];
int a[102];
int b[102];
int minsum = 100000000;

bool coverAll(vector<int> &inters){
    vector<int> nw(102,0);
    for(int x:inters){
        for(int j=a[x];j<=b[x];j++){
            nw[j] += p[x];
        }
    }
    // check temperature is reduced
    for(int j=0;j<=100;j++){
        if(intv[j] != 0){
            if(nw[j] < intv[j]) return false;
        }
    }
    return true;
}
int main(){
    cin>>n>>d;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        for(int j=a;j<=b;j++) intv[j] = c;
    }
    for(int i=0;i<d;i++){
        cin>>a[i]>>b[i]>>p[i]>>m[i];
    }

    for(int mask = 0;mask<(1<<d);mask++){
        vector<int> intervals;
        for(int i=0;i<d;i++){
            if(mask & (1<<i)) intervals.push_back(i);
        }
        if(coverAll(intervals)){
            int suminterval = 0;
            for(auto x:intervals){
                suminterval += m[x];
            }
            minsum = min(minsum,suminterval);
        }
    }
    cout << minsum << endl;
    return 0; 
}