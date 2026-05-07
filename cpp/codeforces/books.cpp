#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);

    for(int &p:a) cin>>p;

    int sum = 0;
    int start = 0;
    int maxi = 0;
    for(int end= 0;end<n;end++){
        sum+=a[end];

        while(sum>k){
            sum -= a[start++];
        }
        maxi = max(maxi,(end - start +1));
    }
    cout << maxi << endl;

    return 0;

}
