#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> cows(n);
    
    for(int &cow:cows)cin>>cow;

    vector<int> sortedCows(cows);

    sort(sortedCows.begin(),sortedCows.end());

    int diffs = 0;
    for(int i =0;i<n;i++){
        if(sortedCows[i] != cows[i]) diffs++;
    }
    cout << diffs-1 << endl;
    return 0; 

}