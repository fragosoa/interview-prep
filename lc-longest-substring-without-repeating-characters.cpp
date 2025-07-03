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
using namespace std;

/**
 Leetcode 3. Longest Substring without repeating characters
 */

int chars[130];

    bool ok(){
        for(int i=0;i<130;i++){
            if(chars[i]>1) return false;
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int maxi = 0;
        for(int end=0;end<s.length();end++){
            chars[(int)s[end]]++;

            while(!ok()){
                chars[(int)s[start++]]--;
            }
            maxi = max(maxi,(end-start+1));
        }
        return maxi;
    }


int main(int argc, const char * argv[]) {
    string in = "abcabcbb";
    cout << lengthOfLongestSubstring(in) << endl;
    return 0;
}

