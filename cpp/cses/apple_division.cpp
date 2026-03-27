#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> w;
long long totalsum = 0;
long long mindiff = 1000000000000000;
int cnt = 0;
long long sum2 = 0;

void bt(int start,long long sum){
    sum2 = totalsum - sum;
    mindiff = min(mindiff,abs(sum2-sum));
    
    for(int i=start;i<n;i++){
        bt(i+1,sum+w[i]);
    }
}
int main(){

    cin>>n;
    w.resize(n);

    for(int i=0;i<n;i++) cin>>w[i],  totalsum += w[i];
    bt(0,0);

    cout << mindiff << endl;
    
    return 0; 
}