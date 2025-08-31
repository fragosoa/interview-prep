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
 Leetcode 150: Evaluate Reverse Polish Notation
 */
int operatee(int a,int b,string op){
        if(op == "+") return b+a;
        if(op == "-") return b-a;
        if(op == "*") return b*a;
        return b/a;
    }
    bool isOperator(string op){
        return (op == "+" || op == "-" || op == "*" || op == "/");
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string token:tokens){
            if(isOperator(token)){
                int a = s.top();s.pop();
                int b  = s.top();s.pop();

                int res = operatee(a,b,token);
                s.push(res);
            }
            else{
                int x = stoi(token);
                s.push(x);
            }
        }
        return s.top();
    }

int main(int argc, const char * argv[]) {
    vector<string> in = {"2","1","+","3","*"};
    int res = evalRPN(in);
    cout << res << endl;
    return 0;
}

