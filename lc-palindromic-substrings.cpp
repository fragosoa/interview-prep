//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 28/08/25.
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
 Leetcode 647: Palindromic Substrings
 */

bool dp[1001][1001];
int n;
void calc(string s) {
    for(int i=0;i<n;i++) dp[i][i] = true;
    
    for(int i=0;i<n-1;i++) dp[i][i+1] = (s[i] == s[i+1] ? true: false);
    
    for(int size=3;size<=n;size++){
        for(int i=0;i<=n-size;i++){
            int j = i+size-1;
            if(s[i] == s[j]){
                dp[i][j] = dp[i+1][j-1];
            }
            else{
                dp[i][j] = false;
            }
        }
    }
}
int countSubstrings(string s) {
    n = s.length();
    calc(s);
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(dp[i][j]) count++;
        }
       
    }
    return count;
}
int main(int argc, const char * argv[]) {
    string s = "aaa";
    cout << countSubstrings(s);
    return 0;
}

