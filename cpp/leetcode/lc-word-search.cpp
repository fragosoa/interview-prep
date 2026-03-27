//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 19/08/25.
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


/**
 Leetcode 79: Word Search
 */

int n,m;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    bool bt(int i,int x,int y,vector<vector<char>> &board, string &s){
        if(i == s.length()-1) return true;

        for(int k=0;k<4;k++){
            int nx = x+dx[k];
            int ny = y+dy[k];

            if(nx>=0 && nx<n && ny>=0 && ny<m && board[nx][ny] == s[i+1]){
                char c = board[nx][ny];
                board[nx][ny] = '*';
                if(bt(i+1,nx,ny,board,s)) return true;
                board[nx][ny] = c;
            }
        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    char c = board[i][j];
                    board[i][j] = '*';
                    if(bt(0,i,j,board,word)) return true;
                    board[i][j] = c;
                }
            }
        }

        return false;
    }
int main(int argc, const char * argv[]) {
    cout << "hee" << endl;
    return 0;
}

