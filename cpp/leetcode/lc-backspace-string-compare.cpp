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


bool backspaceCompare(string s, string t) {
        int top1 = 0;
        int top2 = 0;

        // process string 1
        for(int i=0;i<s.length();i++){
            if(s[i] != '#'){
                s[top1++] = s[i];
            }
            else{
                if(top1>0) top1--;
            }
        }

        for(int i=0;i<t.length();i++){
            if(t[i] != '#'){
                t[top2++] = t[i];
            }
            else{
                if(top2>0) top2--;
            }
        }
        return (s.substr(0,top1) == t.substr(0,top2));
}

/**
 Leetcode 844. Backspace string compare
 */


int main(int argc, const char * argv[]) {
    string s = "ab#c";
    string t = "ad#c";
    bool result = backspaceCompare(s,t);
    cout << result << endl;
    return 0;
}

