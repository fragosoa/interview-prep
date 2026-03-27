#include <bits/stdc++.h>
using namespace std;
/*

*/
vector<vector<int>> grid;

int count_(int k,int n) {
    int count =0 ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j) continue;
            bool flag = false;
            for(int l=0;l<k;l++){
                int posi,posj;
                // search for i
                for(int m=0;m<n;m++){
                    if(grid[l][m] == i){
                        posi = m;
                    }
                }

                // search for j
                for(int m=0;m<n;m++){
                    if(grid[l][m] == j){
                        posj = m;
                    }
                }

                if(posi > posj){
                    flag = true;
                    break;
                }
            }
            if(!flag) count++;

        }
    }
    return count;
}
int main(){
    freopen("gymnastics.in","r",stdin);
    freopen("gymnastics.out","w",stdout);

    int k,n;
    cin>>k>>n;
    grid.assign(k,vector<int>(n,0));
    
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }

    int res = count_(k,n);
    cout << res << endl;
    return 0; 
}