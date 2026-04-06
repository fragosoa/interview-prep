#include <bits/stdc++.h>
using namespace std;


int main(){
    vector<int> a(3);
    for(int &x:a) cin>>x;
    sort(a.begin(),a.end());

    /*
    0 -- already placed
    1 -- two elements placed adyacent with a diff of 1, then we can 
            just move 1 cow and we are done
    2 -- we can always move 1 endpoint cow to 1 space separated and then
            go back to case 1.
    */
    if(a[0] == a[2]-2){
        cout << 0 << endl;
    }
    else if((a[1]==a[2]-2) || (a[0] == a[1] -2)){
        cout << 1 << endl;
    }
    else{
        cout << 2 << endl;
    }

    /*
    get the max dist (b-a or c-b) and calculate cows jumping each
       others 
    */      
    cout << max(a[2]-a[1],a[1]-a[0])-1 << endl;

    return 0;
}