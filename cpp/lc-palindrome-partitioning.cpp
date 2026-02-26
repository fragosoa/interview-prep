//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 14/07/25.
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

bool isPalindrome[2002][2002];
int dp[2002];

void initPalindrome(int n, string &s){
    for(int i=0;i<n;i++) isPalindrome[i][i] = true; // longitud 1
    
    for(int i=0;i<n-1;i++){
        isPalindrome[i][i+1] = (s[i] == s[i+1]); // longitud 2
    }
    
    for(int len=3; len<=n; len++){ // longitud >= 3
        for(int i=0; i+len-1<n; i++){
            int j = i + len - 1;
            isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i+1][j-1];
        }
    }
}

int minCut(string s) {
    initPalindrome(s.length(),s);
    dp[0] = 0;
    int n = s.length();

    for(int i=1;i<n;i++){
        if(isPalindrome[0][i]) dp[i] = 0;
        else {
            int best = INT_MAX;
            for(int j=0;j<i;j++){
                if(isPalindrome[j+1][i]){
                    best = min(best,dp[j]);
                }
            }
            dp[i] = best + 1;
        }
    }
    
    return dp[n-1];
}

/**
 Leetcode 132: Palindrome partitioning
 */

int main(int argc, const char * argv[]) {
    int res = minCut("abcbaef");
    cout << res << endl;
    
    return 0;
}

