#include <bits/stdc++.h>
using namespace std;

vector<string> cownames = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
vector<pair<string,string>> reqs;
/*
3
Buttercup must be milked beside Bella
Blue must be milked beside Bella
Sue must be milked beside Beatrice
*/

bool check(){
    for(auto cond:reqs){

        auto it2 = find(cownames.begin(),cownames.end(),cond.second);
        auto it1 = find(cownames.begin(),cownames.end(),cond.first);
        int i1 = it1 - cownames.begin();
        int i2 = it2 - cownames.begin();

        if(abs(i1-i2) > 1) return false;
    }

    return true;
    
}
int main(){
    int n;
    cin>>n;
    cin.ignore();

    for(int i=0;i<n;i++){
        string constraint;
        getline(cin, constraint);

        int j = 0;
        string cow1="";
        while(constraint[j] != ' ') cow1 += constraint[j++];
        
        string cow2 = "";
        j = constraint.length()-1;
        while(constraint[j] != ' ') cow2 += constraint[j--];
        reverse(cow2.begin(),cow2.end());

        reqs.push_back({cow1,cow2});
    }

    sort(cownames.begin(),cownames.end());

    do{
        if(check()){
            for(string s:cownames) cout << s << endl;
            break;
        }
    }while(next_permutation(cownames.begin(),cownames.end()));

    return 0; 
}