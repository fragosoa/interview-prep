#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k;
    cin>>k>>n;

    vector<int> guesses(n);
    vector<int> points(k+1);

    /*
    to get the sum up to i
    this helps to simulate the vlaues
    */ 
    for(int i=1;i<= k;i++){
        cin>>points[i];
        points[i] += points[i-1];
    }
    for(int &p:guesses){
        cin>>p;
    }

    set<int> candidate_starts;
    for(int m=1;m<=k;m++){
        candidate_starts.insert(guesses.front()-points[m]);
    }

    // filter all invalid candidates

    int ans =0 ;
    for(int s:candidate_starts){
        set<int> pts;
        for(int i=1;i<=k;i++){
            pts.insert(s+points[i]);
        }

        bool valid = true;
        // if all guesses appear after simulating candiadates path
        for(int p:guesses){
            valid &= pts.count(p);
        }
        ans+=valid;
    }
    cout << ans << endl;

}