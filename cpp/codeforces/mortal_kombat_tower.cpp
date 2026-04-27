#include <bits/stdc++.h>
using namespace std;


void gsolve(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
 
    for(int &p:nums) cin>>p;
    nums.push_back(0);
    int i = 0;
    int cnt = 0;
    bool turn = true;
    while(i<n){
        // A turn
        if(turn){
            if(nums[i] == 0){
                if(nums[i+1] == 0){
                    i+=2;
                }
                else{
                    i+=1;
                }
            }
            else{
                cnt++;
                if(nums[i+1] == 0){
                    i+=2;
                }
                else{
                    i+=1;
                }
            }
        }
        // B turn
        else{
            if(nums[i] == 0){
                if(nums[i+1] == 0){
                    i+=1;
                }
                else{
                    i+=2;
                }
            }
            else{
                if(nums[i+1] == 0){
                    i+=1;
                }
                else{
                    i+=2;
                }
            }
        }
        turn = !turn;
    }
    cout << cnt << endl;
}
int main(){
    int q;
    cin>>q;
    while(q--){
        gsolve();
    }
        
    return 0; 
}