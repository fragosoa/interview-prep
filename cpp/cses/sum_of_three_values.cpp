#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<pair<long long,int>> a(n);

    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        a[i] = {val,i+1};
    }

    sort(a.begin(),a.end());

    for(int i=0;i<n-2;i++){
        long long target = k - a[i].first;

        int j = i+1;
        int k = n-1;

        while(j<k){
            long long sum = a[j].first + a[k].first;
            if(sum > target) k--;
            else if (sum < target) j++;
            else{
                cout << a[i].second << " " << a[j].second << " " << a[k].second << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    

    

    return 0;

}
