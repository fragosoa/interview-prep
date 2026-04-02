#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nums;

int main(){
    int q;
    cin>>q;

    while(q--){
        int n,m;
    cin>>n>>m;
    nums.assign(n,vector<int> (m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>nums[i][j];
        }
    }

    long long sum = 0;
    for(int j=0;j<m;j++){
        vector<int> curr(n,0);
        for(int i=0;i<n;i++){
            curr[i] = nums[i][j];
        }

        sort(curr.begin(),curr.end(),[](int a,int b){
            return a > b;
        });
        long long currsum = 0;
        for(int i=0;i<n;i++){
            currsum += (long long)(n-1-i)*(curr[i]-curr[n-1-i]);
        }
        sum += currsum;
    }
    cout << sum << endl;

    }
    return 0;
}