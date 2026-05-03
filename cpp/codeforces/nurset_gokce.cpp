#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    
    vector<int> nums(n);
    for(int &p:nums) cin>>p;

    for(int i=0;i<n-1;i++){
        nums[i+1] = max(nums[i+1],nums[i]-m);
    }
    for(int i=n-1;i>0;i--){
        nums[i-1] = max(nums[i-1],nums[i]-m);
    }

    for(int i=0;i<n;i++){
        cout << nums[i] << " ";
    }

    return 0; 
}