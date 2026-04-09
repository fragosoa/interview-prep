#include <bits/stdc++.h>
using namespace std;

int calcint(int a,int b,int c,int d){
    return max(0,min(b,d)-max(a,c));
}

int main() {
    int x1,x2,x3,x4,x5,x6;
    int y1,y2,y3,y4,y5,y6;
    
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x5>>y5>>x6>>y6;

    int a1 = (x2-x1) * (y2-y1);
    int a2 = (x4-x3) * (y4-y3);

    int int_bat = calcint(x1,x2,x5,x6);
    int int_hat = calcint(y1,y2,y5,y6);
    int ai1 = int_bat*int_hat;
    a1 -=ai1;

    int int_bbt = calcint(x3,x4,x5,x6);
    int int_hbt = calcint(y3,y4,y5,y6);
    int ai2 = int_bbt*int_hbt;
    a2 -= ai2;

    int ans = a1+a2;
    cout << ans << endl;
    
    return 0;
}