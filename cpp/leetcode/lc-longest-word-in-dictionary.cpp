//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 09/08/25.
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
 Leetcode 720: Longest Word in Dictionary
 */

struct TrieNode{
        bool isEnd;
        unordered_map<char,TrieNode*> children;

        TrieNode(): isEnd(false) {}
    };
    
    void insert(string word,TrieNode* root){
        TrieNode* iter = root;

        for(char c:word){
            if(!iter->children[c]) iter->children[c] = new TrieNode();
            iter = iter->children[c];
        }

        iter->isEnd = true;
    }
    bool isLeaf(unordered_map<char,TrieNode*> children){
        for(char c='a';c<='z';c++){
            if(children[c]) return false;
        }
        return true;
    }
    string dfs(TrieNode* root,string curr){
        string best = curr;

        for(auto kv:root->children){
            char c = kv.first;
            // exists the key
            string str = curr+c;
            if(root->children[c]->isEnd){
                string res= dfs(root->children[c],str);
                if(res.length() >= best.length()){
                    if(res.length() == best.length()){
                        if(res < best) best = res;
                    }
                    else best = res;
                }
            }
        }

        return best;
    }
    string longestWord(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(auto word:words){
            
            insert(word,root);
        }

        string res = dfs(root,"");
        return res;

    }
int main(int argc, const char * argv[]) {
    cout << "hello" << endl;
    
    return 0;
}

