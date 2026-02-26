//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 06/07/25.
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


void bt(int n, int left, int right, string current,vector<string> &res){
    if(left == n && right == n){
        res.push_back(current);
        return;
    }

    if(left+1<=n){
        bt(n,left+1,right,current+"(",res);
    }
    if(right+1<=left){
        bt(n,left,right+1,current+")",res);
    }

    return;
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    bt(n,0,0,"",res);

    return res;
}


/**
 Leetcode 22: Generate Parentheses
 */

int main(int argc, const char * argv[]) {
    int n = 3;
    vector<string> res = generateParenthesis(n);
    
    for(auto x:res){
        cout << x << " , ";
    }
    cout << endl;
}

