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

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

    //void dfs()
bool visited[52][52];
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    queue<pair<int,int>> q;
    int n = image.size();
    int m = image[0].size();

    int firstColor = image[sr][sc];

    q.push({sr,sc});
    image[sr][sc] = color;

    while(!q.empty()){
        pair<int,int> tp = q.front(); q.pop();
        int x = tp.first;
        int y = tp.second;
            
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny] && image[nx][ny] == firstColor){
                q.push({nx,ny});
                visited[nx][ny] = true;
                image[nx][ny] = color;
            }
        }
    }

    return image;
}


/**
 Leetcode 733: Flood Fill
 */

int main(int argc, const char * argv[]) {
    cout << " hello " << endl;
    return 0;
}

