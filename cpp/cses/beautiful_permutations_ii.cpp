#include <bits/stdc++.h>
using namespace std;

vector<int> res;
vector<int> ele;

void bt(){
    if(ele.empty()){
        for(int x:res) cout << x << " ";
        cout << endl;
        exit(0);
    }
    for(int i=ele.size()-1;i>=0;i--){
        int x = ele[i];
        if(res.empty() || abs(res.back()-x) != 1){
            ele.erase(ele.begin()+i); // make delete easier
            res.push_back(x);
            bt();
            res.pop_back();
            ele.insert(ele.begin()+i,x);
        }
    }
}
int main() {
	int n;
    cin>>n;

    if(n == 2 || n==3){
        cout << "NO SOLUTION" << '\n';
        return 0;
    }
    for(int i=n;i>=1;i--) ele.push_back(i);
    bt();
}
