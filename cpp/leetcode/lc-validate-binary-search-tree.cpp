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

bool isValid(TreeNode* root, long long low, long long high){
        if(!root) return true;

        bool validLeftBst = isValid(root->left, low, root->val);
        bool validRightBst = isValid(root->right, root->val, high);

        return validLeftBst && validRightBst && low < root->val && root->val < high;
}
bool isValidBST(TreeNode* root) {
    return isValid(root,(long long )INT_MIN-1,(long long)INT_MAX+1);
}

/**
 Leetcode 98: Validate Binary Search Tree
 */

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(2);
    root->left  = new TreeNode(1);
    root->right = new TreeNode(3);
    
    bool res = isValidBST(root);
    cout << res << endl;
    cout << endl;
}

