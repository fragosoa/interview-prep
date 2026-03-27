#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;

int t;
int main()
{
    cin >> t;
    
    while( t -- )
    {
        ll n;
        cin>>n;
        vector<ll> A(n,0);
        vector<ll> B(n,0);

        for(ll i=0;i<n;i++) cin>>A[i];
        for(ll i=0;i<n;i++) cin>>B[i];

        sort(A.begin(),A.end(),[](ll a,ll b){ return a>b;});
        ll res = 0;
        ll levels = 0;
        ll sum = 0;

        for(ll i=1;i<=n;i++){
            ll streng = A[i-1];
            while(levels < n && sum+B[levels] <= i) sum+=B[levels++];
            res = max(res,levels*streng);
            
        }
        cout << res << endl;
    }

    return 0;
}