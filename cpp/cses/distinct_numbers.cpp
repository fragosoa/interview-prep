#include <bits/stdc++.h>
using namespace std;

int nxt(){
    int n;
    cin>>n;
    return n;
}

#define for(n) for(int i=0;i<n;i++)

int main() {
    int n = nxt();
    vector<int> nums(n); 

    for(n){
        cin>>nums[i];
    }
    set<int> S;
    for(n){
        int x = nums[i];
        S.insert(x);
    }

    cout << S.size() << endl;
	
}
