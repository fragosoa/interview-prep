#include <bits/stdc++.h>
using namespace std;

string s;
bool choose[9];
vector<char> permutations;
int n;
set<string> perms;

string process(){
    string res = "";

    for(char c:permutations){
        res+=c;
    }
    return res;
}
void bt(){
    if(permutations.size() == n){
        perms.insert(process());
        return;
    }

    for(int i =0;i<n;i++){
        if(choose[i]) continue;
        choose[i] = true;
        permutations.push_back(s[i]);
        bt();
        choose[i] = false;
        permutations.pop_back();

    }
}
int main(){

    cin>>s;
    n = s.length();

    bt();

    cout << perms.size() << endl;
    for(string p:perms){
        cout << p << endl;
    }
    
    return 0; 
}