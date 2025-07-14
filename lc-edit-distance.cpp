//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 12/07/25.
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

int dp[502][502];
int minDistance(string s, string t) {
    int n = t.size();
    int m = s.size();

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                dp[i][j] = i+j;
                continue;
            }
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
    }


    return dp[m][n];
}

/**
 Leetcode 72: Edit Distance
 */

int main(int argc, const char * argv[]) {
    cout << "hello" << endl;
    return 0;
}

