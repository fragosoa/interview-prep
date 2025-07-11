//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 11/07/25.
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

class TrieNode{
public:
    bool isWord = false;
    unordered_map<char,TrieNode*> children;
    TrieNode() {}
};

class Trie{
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word){
        TrieNode *iter = root;
        
        for(char w:word){
            if(!iter->children[w]){
                iter->children[w] = new TrieNode();
            }
            iter = iter->children[w];
        }
        
        iter->isWord = true;
    }
    
    bool search(string word){
        TrieNode *iter = root;
        
        for(char w:word){
            if(!iter->children[w]){
                return false;
            }
            iter = iter->children[w];
        }
        
        return iter->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *iter = root;
        
        for(char w:prefix){
            if(!iter->children[w]){
                return false;
            }
            iter = iter->children[w];
        }
        
        return true;
    }
};


/**
 Leetcode 208: Implement Prefix Trie (Prefix Tree)
 */

int main(int argc, const char * argv[]) {
    Trie* obj = new Trie();
    obj->insert("hello");
    obj->insert("hell");
    obj->insert("he");
    
    cout << obj->search("hello");
    cout << obj->search("adolfo");
    cout << obj->search("hel");
    
    cout << "starts with" << endl;
    
    cout << obj->startsWith("hel");
    cout << obj->startsWith("hello");
    cout << obj->startsWith("a");
    
    return 0;
}

