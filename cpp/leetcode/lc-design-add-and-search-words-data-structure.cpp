//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 3/08/25.
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



class WordDictionary {
public:
    struct TrieNode{
        bool isWord = false;
        vector<TrieNode*> children;
        
        TrieNode(){
            this->isWord = false;
            children.resize(27,nullptr);
        }
    };
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word){
        TrieNode* iter = root;
        
        for(char c:word){
            if(!iter->children[c-'a']){
                iter->children[c-'a'] = new TrieNode();
            }
            iter = iter->children[c-'a'];
        }
        
        iter->isWord = true;
    }
    
    bool search(string word) {
        return dfs(root,word,0);
    }

    bool dfs(TrieNode* node, string word, int index){
        if(index == word.length()){
            return node->isWord;
        }

        char c = word[index];
        if(c == '.'){
            for(char t = 'a';t<='z';t++){
                if(node->children[t-'a'] && dfs(node->children[t-'a'], word, index+1)){
                    return true;
                }
            }
            return false;
        }
        else{
            if(!node->children[c-'a']) return false;
            return dfs(node->children[c-'a'],word,index+1);
        }
    }
};

/**
 Leetcode 211: Design Add and Search Words Data Structure
 */

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(int argc, const char * argv[]) {
    cout << "hello" << endl;
    return 0;
}

