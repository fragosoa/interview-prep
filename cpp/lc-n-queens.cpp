//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 3/08/25.
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
using namespace std;

bool inBounds(int i,int di,int j,int dj, int n, int m){
    return (0 <= i+di && i+di < n && 0<= j+dj && j+dj<m);
}

bool isSafe(vector<string> &board, int n, int m, int x,int y){
        // check horizontal
        int i = x;
        int j = y;
        int di = 0;
        int dj = -1;
    
        while(inBounds(i,di,j,dj,n,m)){
            if(board[i+di][j+dj] == 'Q') return false;
            dj--;
        }
        i = x;
        j = y;
        di = 0;
        dj = 1;
        while(inBounds(i,di,j,dj,n,m)){
            if(board[i+di][j+dj] == 'Q') return false;
            dj++;
        }

        i = x;
        j = y;
        di = -1;
        dj = 0;
        while(inBounds(i,di,j,dj,n,m) ){
            if(board[i+di][j+dj] == 'Q') return false;
            di--;
        }

        i = x;
        j = y;
        di = 1;
        dj = 0;
        while(inBounds(i,di,j,dj,n,m) ){
            if(board[i+di][j+dj] == 'Q') return false;
            di++;
        }

        i = x;
        j = y;
        di = -1;
        dj = -1;
        while(inBounds(i,di,j,dj,n,m)){
            if(board[i+di][j+dj] == 'Q') return false;
            di--;
            dj--;
        }

        i = x;
        j = y;
        di = 1;
        dj = 1;
        while(inBounds(i,di,j,dj,n,m)){
            if(board[i+di][j+dj] == 'Q') return false;
            di++;
            dj++;
        }

        i = x;
        j = y;
        di = -1;
        dj = 1;
        while(inBounds(i,di,j,dj,n,m)){
            if(board[i+di][j+dj] == 'Q') return false;
            di--;
            dj++;
        }

        i = x;
        j = y;
        di = 1;
        dj = -1;
        while(inBounds(i,di,j,dj,n,m)){
            if(board[i+di][j+dj] == 'Q') return false;
            di++;
            dj--;
        }

        return true;


        // vertical
}
vector<vector<string>> res;
vector<string> curr;
void bt(int i,int n){
    if(i == n){
        res.push_back(curr);
        return;
    }
    
    for(int j=0;j<n;j++){
        if(isSafe(curr, n, n, i, j)){
            curr[i][j] = 'Q';
            bt(i+1,n);
            curr[i][j] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    string row = "";
    for(int i=0;i<n;i++) row+=".";
    for(int i=0;i<n;i++) curr.push_back(row);
    
    
    bt(0,n);
    
    return res;
}

/**
 Leetcode 51: N-queens
 */

int main(int argc, const char * argv[]) {
    int n = 8;
    solveNQueens(n);
    return 0;
}

