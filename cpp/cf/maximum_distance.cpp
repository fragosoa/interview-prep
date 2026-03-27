#include <bits/stdc++.h>
using namespace std;

/*
3
321 -15 -525
404 373 990
*/

int dst(int x1,int y1,int x2,int y2) {
    return (y2-y1)*(y2-y1) + (x2-x1)*(x2-x1); 
}
int main(){
    int n;
    
    cin>>n;
    vector<int> x(n);
    vector<int> y(n);

    for(int i=0;i<n;i++){
        cin>>x[i];
    }

    for(int i=0;i<n;i++){
        cin>>y[i];
    }
    int res = 0;
    int max_res = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            res = dst(x[i],y[i],x[j],y[j]);
            max_res = max(max_res,res);
        }
    }
    cout << max_res << endl;
    return 0;
}