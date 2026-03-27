#include <bits/stdc++.h>
using namespace std;

/*3 3
40 75
50 35
10 45
40 76
20 30
40 40
*/
const int LEN = 100;
int main(){
    freopen("speeding.in","r",stdin);
    freopen("speeding.out","w",stdout);

    int n,m;
    cin>>n>>m;

    int start =0 ;
    vector<int> limit(LEN);
    vector<int> bessie(LEN);

    for(int i=0;i<n;i++){
        int length,speed;
        cin>>length>>speed;
        for(int j=start;j<start+length;j++) limit[j] = speed;
        start += length;
    }

    start = 0;
    for(int i=0;i<m;i++){
        int length,speed;
        cin>>length>>speed;
        for(int j=start;j<start+length;j++) bessie[j] = speed;
        start += length;
    }

    int max_speed = 0;
    for(int i=0;i<LEN;i++){
        max_speed = max(max_speed,bessie[i] - limit[i]);
    }
    cout << max_speed << endl;
    return 0; 
}