#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nums;

int main(){
    int n;
    cin>>n;

    vector<int> nums(2*n);

    for(int i=0;i<2*n;i++){
        cin>>nums[i];
    }

    sort(nums.begin(),nums.end());
    int mindiff = 10000000;
    for(int i=0;i<nums.size()-1;i++){
        
        for(int j=i+1;j<nums.size();j++){
            vector<bool> present(2*n,true);
        vector<int> tmp;
            present[i] = false;
            present[j] = false;
            for(int k=0;k<nums.size();k++){
                if(present[k]) tmp.push_back(nums[k]);
            }
            
            int diffs = 0;
            bool dcalc = false;
            for(int k=0;k<tmp.size()-1;k+=2){
                diffs += abs(tmp[k]-tmp[k+1]);
                dcalc = true;
            }
            int diffs2 = 0;
            bool dcalc2 = false;
            for(int k=1;k<tmp.size()-2;k+=2){
                diffs2 += abs(tmp[k]-tmp[k+1]);
                dcalc2 = true;
            }
            if(!dcalc) diffs = 10000000;
            if(!dcalc2) diffs2 = 10000000;

            diffs2 += abs(tmp[0]-tmp[tmp.size()-1]);
            mindiff = min({mindiff,diffs,diffs2});
        }
    }
    cout << mindiff << endl;
    return 0;
}