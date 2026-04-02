#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> A(n);    
    vector<int> B(n);

    for(int i=0;i<n;i++){
        cin>>A[i];
    }

    for(int i=0;i<n;i++){
        cin>>B[i];
    }
    vector<long long> K(n);

    for(int i=0;i<n;i++){
        K[i] = (long long)(i+1)*(n-i);
    }

    vector<long long> A_final(n);
    for(int i=0;i<n;i++){
        A_final[i] = K[i]*A[i];
    }

    sort(A_final.begin(),A_final.end());
    sort(B.begin(),B.end(),[](int a,int b){
        return a>b;
    });

    long long sum = 0;
    for(int i=0;i<n;i++){
        sum+=(A_final[i]*B[i]);
    }
    cout << sum << endl;

    return 0;
}