#include <bits/stdc++.h>
using namespace std;

vector<int> fA;
vector<int> fB;
vector<string> A;
vector<string> B;

bool check(){
    for(int i=0;i<4;i++){
        if(fA[i] != 0 && fB[i] !=0) return false;
    }
    return true;
}
int main(){
    freopen("cownomics.in","r",stdin);
    freopen("cownomics.out","w",stdout);

    int n,m;
    cin>>n>>m;


    A.resize(n);
    B.resize(n);

    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        cin>>B[i];
    }
    unordered_map<char,int> pos;
    pos['A'] = 0;
    pos['C'] = 1;
    pos['G'] = 2;
    pos['T'] = 3;
    
    
    int count = 0;
    for(int i=0;i<m;i++){
        fA.assign(4,0);
        fB.assign(4,0);

        for(int j = 0;j<n;j++){
            fA[pos[A[j][i]]]++;
            fB[pos[B[j][i]]]++;
        }
        if(check()){
            count++;
            
        } 
    }
    cout << count << endl;
    
    return 0; 
}