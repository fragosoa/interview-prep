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

struct TrieNode{
    bool isWord;
    vector<TrieNode*> children;

    TrieNode(): isWord(false) {
        children.resize(27,nullptr);
    }
};

vector<string> ans;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void insert(string word, TrieNode* root) {
    TrieNode* iter = root;
    for (char c : word) {
        if (!iter->children[c - 'a']) {
            iter->children[c - 'a'] = new TrieNode();
        }
        iter = iter->children[c - 'a'];
    }
    iter->isWord = true;
}


void dfs(TrieNode* root,int x,int y, vector<vector<char>> &board,string current,int &n, int &m){
    if(root->isWord){
        ans.push_back(current);
        root->isWord = false;
    }

    for(int i = 0;i<4;i++){
        int nx = dx[i]+x;
        int ny = dy[i]+y;
        if(nx>=0 && nx<n && ny>=0 && ny<m && board[nx][ny] != '*'){
            char c = board[nx][ny];
            if(root->children[c-'a']){
                board[nx][ny] = '*';
                dfs(root->children[c-'a'],nx,ny,board,current+c,n,m);
                board[nx][ny] = c;
            }
        }
    }
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    TrieNode* root = new TrieNode();
    int n = board.size();
    int m = board[0].size();

    for(string word:words){
        insert(word,root);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c = board[i][j];
            if(root->children[c-'a']){
                
                board[i][j] = '*';
                dfs(root->children[c-'a'],i,j,board,string(1,c),n,m);
                board[i][j] = c;
            }
        }
    }

    return ans;
}
/**
 Leetcode 212: Word Search II
 */


int main(int argc, const char * argv[]) {
    
    //[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
    vector<vector<char>> board = {{'o','a','a','n'}, {'e','t','a','e'}, {'i','h','k','r'}, {'i','f','l','v'}};
    vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<string> res = findWords(board,words);
    for(auto w:res){
        cout << w << endl;
    }
    return 0;
}

