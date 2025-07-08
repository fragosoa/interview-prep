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

vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> Q;
    
        if(root) Q.push(root);

        while(!Q.empty()){
            int size = Q.size();
            vector<int> current;

            for(int i=0;i<size;i++){
                TreeNode* tp = Q.front();
                Q.pop();

                current.push_back(tp->val);
                if(tp->left) Q.push(tp->left);
                if(tp->right) Q.push(tp->right);
            }
            res.push_back(current);
        }
        return res;
    }

/**
 Leetcode 102: Binary Tree Level Order Traversal
 */

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(1);
    /*root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(15);
    root->left->right = new TreeNode(7);*/
    
    vector<vector<int>> res = levelOrder(root);
    
    for(auto v:res){
        for(auto x:v){
            cout << x <<  " , ";
        }
        cout << endl;
    }
    //cout << res << endl;
}

