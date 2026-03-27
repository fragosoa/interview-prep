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
 Leetcode 159: Longest Substring with at most K distinct Characters
 */

unordered_map<char, int> freq;

bool ok(int k){
    int count = 0;
    for(auto kv:freq){
        if(kv.second >= 1) count++;
    }

    return count<=k;
}
int lengthOfLongestSubstringKDistinct(string s,int k){
    int start = 0;
    int maxi = 0;
    
    for(int end = 0;end<s.length();end++){
        freq[s[end]]++;
        
        while(!ok(k)){
            freq[s[start++]]--;
        }

        maxi = max(maxi,(end-start+1));
    }
    
    return maxi;
}
int main(int argc, const char * argv[]) {
    string s = "aaabbccd";
    int k = 2;
    cout << solve(s,k) << endl;
    return 0;
}

