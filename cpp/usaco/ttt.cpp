#include <bits/stdc++.h>
using namespace std;


vector<string> ttt(3);
vector<int> abc(26,0);

int check(int k){
    int count = 0;
    for(char c ='A';c<='Z';c++){
        if (abc[c - 'A'] > 0) count++;
    }
    if(count == k) return 1;
    return 0;
    
}
int exactly_k(int k){
    int res = 0;
    abc.assign(26,0);
    //rows
    for(int i=0;i<3;i++) abc[(ttt[0][i]) - 'A']++;
    res+= check(k);

    abc.assign(26,0);

    for(int i=0;i<3;i++) abc[(ttt[1][i]) - 'A']++;
    res+= check(k);

    abc.assign(26,0);

    for(int i=0;i<3;i++) abc[(ttt[2][i]) - 'A']++;
    res+= check(k);

    // cols
   abc.assign(26,0);

   for(int i=0;i<3;i++) abc[(ttt[i][0]) - 'A']++;
   res+= check(k);

   abc.assign(26,0);

   for(int i=0;i<3;i++) abc[(ttt[i][1]) - 'A']++;
   res+= check(k);

   abc.assign(26,0);

   for(int i=0;i<3;i++) abc[(ttt[i][2]) - 'A']++;
   res+= check(k);

    // diag
   abc.assign(26,0);
   abc[(ttt[0][2]) - 'A']++;
   abc[(ttt[1][1]) - 'A']++;
   abc[(ttt[2][0]) - 'A']++;
   res+= check(k);

   abc.assign(26,0);
   abc[(ttt[0][0]) - 'A']++;
   abc[(ttt[1][1]) - 'A']++;
   abc[(ttt[2][2]) - 'A']++;
   res+= check(k);

   return res;
}
int main(){
    freopen("ttt.in","r",stdin);
    freopen("ttt.out","w",stdout);

    for(int i=0;i<3;i++){
        string w1;
        cin>>w1;
        ttt[i] = w1;
    }

    int res1 = exactly_k(1);
    int res2 = exactly_k(2);

    cout << res1 << endl;
    cout << res2 << endl;
    return 0; 
}