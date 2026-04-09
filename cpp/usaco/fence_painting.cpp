#include <bits/stdc++.h>
using namespace std;



int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int d1 = (b-a);
    int d2 = (d-c);
    
    int intersect = max(0,min(b,d)-max(a,c));
    int ans = d1+d2-intersect;
    cout << ans << endl;
    return 0;
}