//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 06/07/25.
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

int n;
int m;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(vector<vector<char>> &grid, int x,int y){
    grid[x][y] = 'x';

    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] == '1'){
            dfs(grid,nx,ny);
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    n = grid.size();
    m = grid[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '1'){
                dfs(grid,i,j);
                count++;
            }
        }
    }

    return count;
}
/**
 Leetcode 200: Number of Islands
 */

int main(int argc, const char * argv[]) {
    cout << "hello " << endl;
    return 0;
}

