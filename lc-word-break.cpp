//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 3/08/25.
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

unordered_set<string> wordSet;
    vector<int> dp;

    bool solve(int start,string s){
        if(start == s.length()) return true;

        if(dp[start] != -1) return dp[start];

        for(int i=start;i<s.length();i++){
            string subs = s.substr(start,i-start+1);
            if(wordSet.find(subs) != wordSet.end() && solve(i+1,s)){
                return dp[start] = true;
            }
        }

        return dp[start] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        wordSet = unordered_set<string>(wordDict.begin(),wordDict.end());
        dp.resize(302,-1);
        return solve(0,s);
    }
/**
 Leetcode 139: Word Break
 */

int main(int argc, const char * argv[]) {
    vector<string> wordDict = {"leet","code"};
    string s = "leetcode";
    
    bool res = wordBreak(s, wordDict);
    cout << res << endl;
    return 0;
}

