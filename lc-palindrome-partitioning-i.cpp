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

vector<vector<string>> res;
vector<string> curr;
bool isPalindrome[20][20];

void bt(int start, string &s){
    if(start == s.length()){
        res.push_back(curr);
        return;
    }

    for(int i=start;i<s.length();i++){
        if(isPalindrome[start][i]){
            curr.push_back(s.substr(start,i-start+1));
            bt(i+1,s);
            curr.pop_back();
        }
    }
}

void calculatePalindrome(int n, string &s){
    for(int i=0;i<n;i++) isPalindrome[i][i] = true;

    for(int i=0;i<n-1;i++) isPalindrome[i][i+1] = (s[i] == s[i+1]);

    for(int len = 3;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j= i+len-1;
            isPalindrome[i][j] = s[i] == s[j] && isPalindrome[i+1][j-1];
        }
    }
}

vector<vector<string>> partition(string s) {
    calculatePalindrome(s.length(),s);
    bt(0,s);
    return res;
}
/**
 Leetcode 131: Palindrome partitioning i
 */

int main(int argc, const char * argv[]) {
    vector<vector<string>> res = partition("aab");
    for(auto v:res){
        for(auto s:v){
            cout << s << " , ";
        }
        cout << endl;
    }
    
    return 0;
}

