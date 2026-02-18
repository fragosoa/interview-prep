//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 31/08/25.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


string intToStr = "0123456789";
unordered_set<string> visited;

string encode(vector<int> &arr){
    string encoded_str = "";
    for(int x: arr){
        char str_num = (char)intToStr[x];
        encoded_str += str_num;
    }
    
    return encoded_str;
}

int minOperations(vector <int> arr) {
    // Store states and steps
    queue<pair<string,int>> Q;
    
    int n = arr.size();
    
    vector<int> res;
    for(int i=1;i<=n;i++){
        res.push_back(i);
    }
    
    string target = encode(res);
    
    string encoded = encode(arr);
    Q.push({encoded,0});
    
    visited.insert(encoded);
    
    while(!Q.empty()){
        auto top = Q.front();
        string element = top.first;
        Q.pop();
        int steps = top.second;
        
        if(element == target){
            return steps;
        }
        
        vector<int> current;
        for(char c : element){
            current.push_back(c - '0');
        }
        
        // list all possible states, iterating for all pairs in i,j
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                vector<int> next  = current;
                reverse(next.begin()+i,next.begin()+j+1);
                string encoded_arr = encode(next);
                
                if(visited.find(encoded_arr) == visited.end()){
                    visited.insert(encoded_arr);
                    Q.push({encoded_arr,steps+1});
                }
            }
        }
        
        
    }
    return 1;
}


int main(int argc, const char * argv[]) {
    int res = minOperations({1, 2, 5, 4, 3});
    cout << res << endl;
    return 0;
}

