//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 03/07/25.
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


string removeDuplicates(string s) {
        stack<char> stack;

        for(int i=0;i<s.length();i++){
            if(stack.empty() || stack.top() != s[i]) stack.push(s[i]);
            else{
                stack.pop();
            }
        }
        string res = "";
        while(!stack.empty()) {
            res+=stack.top();
            stack.pop();
        }
        reverse(res.begin(),res.end());
        return res;
}

/**
 Leetcode 1047. Remove All Adjacent Duplicates in String
 */


int main(int argc, const char * argv[]) {
    string s = "abbaca";
    string result = removeDuplicates(s);
    cout << result << endl;
    return 0;
}

