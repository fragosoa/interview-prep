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

struct Node {
    int val;
    vector<Node*> neighbors;
    Node() {
            val = 0;
            neighbors = vector<Node*>();
        }
        Node(int _val) {
            val = _val;
            neighbors = vector<Node*>();
        }
        Node(int _val, vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
};

unordered_map<Node*,Node*> visited;
Node* cloneGraph(Node* node) {
    if(!node) return nullptr;

    if(visited.count(node)>0) return visited[node];

    Node* clone = new Node(node->val);
    visited[node] = clone;

    for(Node *v:node->neighbors){
        clone->neighbors.push_back(cloneGraph(v));
    }

    return clone;
}

/**
 Leetcode 133: Clone Graph
 */

int main(int argc, const char * argv[]) {
    cout << "hello" << endl;
    
    
    return 0;
}

