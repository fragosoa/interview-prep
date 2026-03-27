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
 Leetcode 127: Word Ladder
 */

unordered_map<string,int> wordToIndex;
vector<int> adj[5002];
bool visited[5002];

int wordDist(string s,string t){
    if(s.length() != t.length()) return -1;
    
    int count = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] != t[i])count++;
    }
    
    return count;
}

int bfs(int start,int end){
    
    queue<pair<int,int>> q;
    
    q.push({start,1});
    
    while(!q.empty()){
        int curr = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if(curr == end) return dist;
        
        for(auto v:adj[curr]){
            if(!visited[v]){
                visited[v] = true;
                q.push({v,dist+1});
            }
        }
    }
    return -1;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    wordList.push_back(beginWord);
    if(beginWord.length() != endWord.length()) return -1;
    
    for(int i = 0;i<wordList.size();i++){
        wordToIndex[wordList[i]] = i;
    }
    
    int n = wordList.size();
    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(wordDist(wordList[i],wordList[j]) == 1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    
    int startIndex = wordToIndex[beginWord];
    if(wordToIndex.find(endWord) == wordToIndex.end()) return 0;
    int endIndex = wordToIndex[endWord];
    
    int res = bfs(startIndex,endIndex);
    
    return res;
}
int main(int argc, const char * argv[]) {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log"};
    int res = ladderLength(beginWord,endWord,wordList);
    cout << res << endl;
    
    return 0;
}

