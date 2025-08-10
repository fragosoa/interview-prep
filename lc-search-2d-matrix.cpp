//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 09/08/25.
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
 Leetcode 74: Search 2D matrix
 */

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0;
        int col = m-1;

        while(row>=0 && col>=0 && row < n && col < m){
            if(matrix[row][col] == target){
                return true;
            }
            if(target>matrix[row][col]) row++;
            else col--;
        }
        return false;
    }
int main(int argc, const char * argv[]) {
    cout << "heelo" << endl;
    return 0;
}

