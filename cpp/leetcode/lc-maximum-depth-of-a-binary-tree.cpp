//
//  main.cpp
//  interviewprep
//
//  Created by Adolfo Fragoso on 06/07/25.
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

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

/**
 Leetcode 104: Maximum Depth of a Binary Tree
 */

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(15);
    root->left->right = new TreeNode(7);
    
    int res = maxDepth(root);
    cout << res << endl;
}

