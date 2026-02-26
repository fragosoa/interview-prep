//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 31/08/25.
//

#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <string>
using namespace std;

/**
 Leetcode 980: Unique Paths III
 */

int n,m;
int xe,ye;
int finalState = 0;


int calcPos(int x,int y){
    return x*m + y;
}

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int solve(int x,int y,int state,vector<vector<vector<int>>> &dp){
    if(x == xe && y == ye && state == finalState){
        return 1;
    }
    
    if(dp[x][y][state] != -1) return dp[x][y][state];
    
    int sum = 0;
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        
        if(nx>=0 && nx<n && ny>=0 && ny<m){
            int pos = calcPos(nx, ny);
            
            if((state & (1<<pos)) == 0){
                if(nx == xe && ny == ye && ((state | (1<<pos)) == finalState) || !(nx == xe && ny==ye)){
                    sum+=(solve(nx,ny,state | (1<<pos),dp));
                }
            }
        }
    }
    
    return dp[x][y][state] = sum;
}
int uniquePathsIII(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();
    int initState = 0;
    
    int xs,ys;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int pos = calcPos(i,j);
            if(grid[i][j] == 1){
                xs = i;
                ys = j;
            }
            else if(grid[i][j] == 2){
                xe = i;
                ye = j;
            }
            else if(grid[i][j] == -1){
                initState = initState | (1<<pos);
            }
            finalState = finalState | (1<<pos);
        }
    }
    
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(finalState+1,-1)));
    initState = initState | (1<<(calcPos(xs, ys)));
    return solve(xs,ys,initState,dp);
    
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> in = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    cout << uniquePathsIII(in) << endl;
    return 0;
}

