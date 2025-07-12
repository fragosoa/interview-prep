//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 12/07/25.
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

bool adj[501][501];
int wordDistance(string s,string t){
    if(s.length() != t.length()) return -1;
    int count = 0;

    for(int i=0;i<s.length();i++){
        if(s[i] != t[i]) count++;
    }

    return count;
}
//debug
void printM(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

// maps distance: indexes (in word list)
vector<int> distances[1000];
bool visited[502];

int bfs(int src, int end, vector<string> &wordList){
    vector<int> dist(500,INT_MAX);
    dist[src] = 0;
    distances[0].push_back(src);
    int n = (int)wordList.size();
    
    queue<int> q;
    q.push(src);
    
    while(!q.empty()){
        int u = q.front(); q.pop();
        visited[u] = true;
        
        for(int j=0;j<n;j++){
            if(adj[u][j] == 1){
                if(dist[u]+1 < dist[j]){
                    dist[j] = dist[u] + 1;
                    distances[dist[j]].push_back(j);
                    q.push(j);
                }
            }
        }
        
    }
    
    return dist[end];
}
vector<vector<string>> res;
vector<int> path;

vector<string> convertToString(vector<string> &wordList){
    vector<string> ans = {};
    for(int i=(int)path.size()-1;i>=0;i--){
        int x = path[i];
        ans.push_back(wordList[x]);
    }
    
    return ans;
}

void bt(int shortest, int &start,int &end, int current, vector<string> &wordList){
    if(current == end){
        vector<string> strPath = convertToString(wordList);
        res.push_back(strPath);
        return;
    }
    
    for(int index:distances[shortest-1]){
        if(adj[current][index]){
            path.push_back(index);
            bt(shortest-1,start,end,index,wordList);
            path.pop_back();
        }
    }
    
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    
    wordList.push_back(beginWord); // should have index n-1
    
    int n = (int)wordList.size();
    int end = -1;
    int start = n-1;
    
    for(int i=0;i<n-1;i++){
        if(wordList[i] == endWord) end = i;
        for(int j=i+1;j<n;j++){
            if(wordDistance(wordList[i],wordList[j]) == 1){
                adj[i][j] = true;
                adj[j][i] = true;
            }
        }
    }
    
    if(end == -1) return {}; // end word not in word list

    int shortest = bfs(start, end, wordList);
    if(shortest == INT_MAX) {
        return {};
    }
    
    path.push_back(end);
    bt(shortest,end,start,end,wordList);
    
    return res;
}


/**
 Leetcode 126: Word Ladder II
 */

int main(int argc, const char * argv[]) {
    string beginWord = "hot";
    string endWord = "dog";
    
    vector<string> wordList = {"hot","dog"};
    vector<vector<string>> tst = findLadders(beginWord,endWord,wordList);
    
    for(auto v:tst){
        for(auto s:v){
            cout << s << " , ";
        }
        cout << endl;
    }
    return 0;
}

