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
 Leetcode 1462: Course Schedule IV
 */

bool adj[102][102];
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        for(auto edge:prerequisites){
            adj[edge[0]][edge[1]] = true;
        }

        for(int k =0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    adj[i][j] |= (adj[i][k] && adj[k][j]);
                }
            }
        }
        vector<bool> ans;
        for(auto q:queries){
            ans.push_back(adj[q[0]][q[1]]);
        }

        return ans;
    }

int main(int argc, const char * argv[]) {
    cout << "heelo" << endl;
    return 0;
}

