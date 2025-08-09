//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 5/08/25.
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


/**
 Leetcode 49: Group Anagrams
 */

unordered_map<string,vector<string>> anagrams;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for(string w:strs){
            string res = w;
            sort(w.begin(),w.end());
            anagrams[w].push_back(res);
        }
        vector<vector<string>> res;
        for(auto kv:anagrams){
            res.push_back(kv.second);
        }
        return res;
}

int main(int argc, const char * argv[]) {
    vector<string> in = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = groupAnagrams(in);
    
    for(auto v:ans){
        for(auto x:v){
            cout << x << " , ";
        }
        cout << endl;
    }
    
    return 0;
}

