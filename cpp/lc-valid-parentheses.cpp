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

bool isOpen(char c){
    return (c == '(' || c == '{' || c == '[');
}
bool isClosing(char s,char t){
    if(s == '(' && t == ')') return true;
    if(s == '{' && t == '}') return true;
    if(s == '[' && t == ']') return true;
    return false;
}

bool isValid(string s) {
    stack<char> stack;
    for(char c:s){
        if(isOpen(c)){
            stack.push(c);
        }
        else{
            if(stack.empty()) return false;
            if(isClosing(stack.top(),c)){
                stack.pop();
            }
            else{
                return false;
            }
        }
    }
    return stack.empty();
}

/**
 Leetcode 20. Valid Parentheses
 */


int main(int argc, const char * argv[]) {
    string in = "()";
    bool res = isValid(in);
    cout << res << endl;
    return 0;
}

