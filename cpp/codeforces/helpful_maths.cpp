#include <bits/stdc++.h>
using namespace std;

// 3+2+1
int main(){
    string s;
    cin>>s;
    int threes = 0;
    int twos = 0;
    int ones = 0;

    for(char c:s){
        if(c == '1') ones++;
        if(c == '2') twos++;
        if(c == '3') threes++;
    }

    for(int i=0;i<ones-1;i++){
        cout << "1+";
    }
    if(ones && !twos && ones && !threes ) cout << "1";
    else if(ones){
        cout << "1+";
        //cout << "hee";
    } 

    for(int i=0;i<twos-1;i++){
        cout << "2+";
    }
    if(twos && !threes) cout << "2";
    else if(twos) cout << "2+";

    for(int i=0;i<threes-1;i++){
        cout << "3+";
    }
    if(threes) cout << "3";
    
    return 0;
}