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


unordered_map<char,int> freqt;
unordered_map<char,int> freqs;

bool ok(){
    for(auto kv:freqt){
        char key = kv.first;
        int value = kv.second;
        if((freqs[key] < value)) return false;
    }
    return true;
}
string minWindow(string s, string t) {
    for(auto c:t) freqt[c]++;
    
    int start = 0;
    int mini = 1<<20;
    
    list<char> current;
    int bestStart = 0;

    for(int end = 0;end<s.length();end++){
        freqs[s[end]]++;
        current.push_back(s[end]);
        
        while(ok()){
            if((int)current.size() < mini){
                mini = (int)current.size();
                bestStart = start;
            }
            
            current.pop_front();
            freqs[s[start++]]--;
        }
    }
    
    if(mini == (1<<20)) return "";
    return s.substr(bestStart,mini);
}
/**
 Leetcode 76.. Minimum Window Substring
 */


int main(int argc, const char * argv[]) {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string res = minWindow(s,t);
    cout << res << endl;
    return 0;
}

