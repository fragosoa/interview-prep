//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 29/07/25.
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

map<string,vector<int>> G2;
    unordered_map<int,vector<string>> G1;
    unordered_map<int,string> names;
    // refactor to use a set
    unordered_set<string> visited;
    int visitedgroups[1002];

    void dfs2(int group,vector<string> &emails){
        visitedgroups[group] = true;

        for(string email:G1[group]){
            if(visited.find(email) == visited.end()){
                dfs(email,emails);
            }
        }
    }
    void dfs(string email,vector<string> &emails){
        visited.insert(email);
        emails.push_back(email);

        for(int group:G2[email]){
            if(!visitedgroups[group]){
                dfs2(group,emails);
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        for(int group =0 ;group<accounts.size();group++){
            vector<string> account = accounts[group];
            names[group] = account[0];
            for(int j=1;j<account.size();j++){
                string email = account[j];
                G1[group].push_back(email);
                G2[email].push_back(group);
            }
        }
        vector<vector<string>> ans;
        for(auto kv:G2){
            string email = kv.first;
            string parent = names[G2[email][0]];
            // not present in visited
            if(visited.find(email) == visited.end()){
                vector<string> emails = {};
                dfs(email,emails);

                sort(emails.begin(),emails.end());
                vector<string> curr = {parent};
                for(auto x:emails){
                    curr.push_back(x);
                }
                ans.push_back(curr);
            }
        }
        return ans;
    }

/**
 Leetcode 721:  Accounts merge
 */

int main(int argc, const char * argv[]) {
    cout << "heelo" << endl;
    return 0;
}

