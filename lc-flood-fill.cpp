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
bool visited[52][52];

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int prevColor = image[sr][sc];
    visited[sr][sc] = true;
    image[sr][sc] = color;

    for(int k=0;k<4;k++){
        int nx = sr+dx[k];
        int ny = sc+dy[k];

        if(nx>=0 && nx < image.size() && ny>=0 && ny<image[0].size() && !visited[nx][ny] && image[nx][ny] == prevColor){
            floodFill(image,nx,ny,color);
        }
    }

    return image;
}

/**
 Leetcode 733: Flood Fill
 */

int main(int argc, const char * argv[]) {
    vector<vector<int>> nums = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1;
    int sc = 1;
    int color = 2;
    
    vector<vector<int>> res =floodFill(nums, sr,sc, color);
    for(auto v:res){
        for(auto x:v){
            cout << x << " , ";
        }
        cout << endl;
    }
    return 0;
}

