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


int minAddToMakeValid(string t) {
        if(t.length() == 0) return 0;

        stack<char> s;
        int countOpen = 0;
        for(char c:t){
            if(c == '('){
                s.push(c);
            }
            else{
                if(s.empty()) countOpen++;
                else s.pop();
            }
        }
        int countClose = s.size();
        return (countOpen + countClose);
}

/**
 Leetcode 921. Minimum Add to Make Parentheses valid.
 */


int main(int argc, const char * argv[]) {
    string in = "())";
    int res = minAddToMakeValid(in);
    cout << res << endl;
    return 0;
}

