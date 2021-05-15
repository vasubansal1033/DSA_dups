/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// recursive
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if(root==nullptr)
            return root;

        TreeNode* lchild = root->left;
        TreeNode* rchild = root->right;

        root->left = rchild;
        root->right = lchild;
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);

        return root;

    }
};

// iterative
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<bits/stdc++.h>

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if(root==nullptr)
            return nullptr;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            TreeNode* front = q.front(); q.pop();

            TreeNode* lchild = front->left;
            TreeNode* rchild = front->right;
            front->left = rchild;
            front->right = lchild;

            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }

        }

        return root;


    }
};
