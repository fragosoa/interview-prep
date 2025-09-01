//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 31/08/25.
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
 Leetcode 676: Implement Magic Dictionary
 */

class MagicDictionary {
public:
    unordered_set<string> st;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(string word:dictionary){
            st.insert(word);
        }
    }
    
    bool search(string s) {
        for(int i=0;i<s.length();i++){
            char t = s[i];
            for(char c='a';c<='z';c++){
                if(t == c) continue;
                s[i] = c;
                //cout << s << endl;
                if(st.find(s) != st.end()) return true;
            }
            s[i] = t;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
int main(int argc, const char * argv[]) {
    cout << "hello" << endl;
    return 0;
}

