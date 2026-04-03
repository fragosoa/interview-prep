#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,x;
    cin>>n>>x;
    vector<int> nums(n);
    map<int,int> s;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        s[nums[i]] = i;
    }

    for(int i=0;i<n;i++){
        int t = nums[i];
        if(s.find(x-t) != s.end()){
            int posxt = s[x-t];
            int posx = i;
            if(posxt  != posx){
                cout << s[x-t]+1 << " " <<i+1 << endl;
                return 0;
            }
            
        }
    }
    cout << "IMPOSSIBLE" << endl;
    
    return 0;
}