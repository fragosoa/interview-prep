#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<ll> nums;
int n,x;

// podemos contar el numero de subarrays que suman <= k. 
/*
podemos contarlos de esta forma cnt += (end-start+1); 
ya que el intervalo [start,end] contiene la suma <= k
Si tomamos subarrays individuales en este intervalo, todos ellos suman <= k. 
Ya que los numeros a_i >=1. Tenemos una propiedad monotonica. 

*/
int atmost(int k){
    int cnt = 0;
    int start =0 ;
    ll sum =0 ;
    for(int end = 0;end<n;end++){
        sum+=nums[end];

        while(sum > k){
            sum -= nums[start++];
        }
        cnt += (end-start+1);
    }

    return cnt;

}

int solveExactlyK(int k){
    int cnt = 0;
    int start =0 ;
    ll sum =0 ;
    for(int end = 0;end<n;end++){
        sum+=nums[end];

        while(sum > k){
            sum -= nums[start++];
        }
        if(sum == k) cnt++;
    }

    return cnt;
}
int main() {
    cin>>n>>x;
    nums.resize(n);

    for(ll &p:nums) cin>>p;

    int res = atmost(x) - atmost(x-1);
    cout << res << endl;
    
    
    return 0;
}