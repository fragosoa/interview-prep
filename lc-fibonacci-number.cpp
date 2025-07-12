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

int dp[32];
int fib(int n) {
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    if(n<=2) return dp[n];

    for(int i=3;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

/**
 Leetcode 509: Fibonacci Number
 */

int main(int argc, const char * argv[]) {
    int n = 4;
    int res =fib(n);
    cout << res << endl;
    return 0;
}

