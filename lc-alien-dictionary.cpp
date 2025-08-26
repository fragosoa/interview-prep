//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 23/08/25.
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
 Leetcode 269: Alien dictionary
 */

// using dfs + coloring for cycle detection
unordered_map<char,int> color;
unordered_map<char,unordered_set<char>> graph;
string result;

bool dfs(char c){
    color[c] = 1;
    
    for(char v:graph[c]){
        if(color[v] == 0){
            if(dfs(v)) return true;
        }
        else if(color[v] == 1){
            return true;
        }
    }
    
    color[c] = 2;
    result.push_back(c);
    return false;
}

string alienOrder(vector<string> &words){
    
    unordered_set<char> all_chars;
    
    for(string word:words){
        for(char c:word){
            all_chars.insert(c);
        }
    }
    
    for(int i=0;i<words.size()-1;i++){
        string word1 = words[i];
        string word2 = words[i+1];
        
        int min_len = (int) min(word1.length(),word2.length());
        bool found_difference = false;
        for(int j=0;j<min_len;j++){
            if(word1[j] != word2[j]){
                graph[word1[j]].insert(word2[j]);
                found_difference = true;
                break;
            }
        }
        
        if(!found_difference && word1.length() > word2.length()) return "";
    }
    for(char c:all_chars){
        color[c] = 0;
    }
    
    
    for(char c:all_chars){
        if(color[c] == 0){
            if(dfs(c)) return "";
        }
    }
    
    reverse(result.begin(),result.end());
    return result;
    
}

int main(int argc, const char * argv[]) {
    vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
    cout << alienOrder(words) << endl;
    
    return 0;
}

