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

unordered_map<char,int> w1;
unordered_map<char,int> w2;

bool ok(){
    for(auto kv:w1){
        char key = kv.first;
        int value = kv.second;
        if(w2[key] != value) return false;
    }
    return true;
}
bool checkInclusion(string s1, string s2) {
    if(s1.length() > s2.length()) return false;
    for(auto c:s1) w1[c]++;
    int k = s1.length();

    for(int i=0;i<k;i++) w2[s2[i]]++;

    for(int i=1;i<=(s2.length()-k);i++){
        if(ok()) return true;
        w2[s2[i+k-1]]++;
        w2[s2[i-1]]--;
    }
    return ok();
}
/**
 Leetcode 567.. Permutation in String
 */


int main(int argc, const char * argv[]) {
    string s = "ab";
    string t = "eidbaooo";
    bool res = checkInclusion(s,t);
    cout << res << endl;
    return 0;
}

