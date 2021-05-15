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
class Solution {
public:
    void fun(TreeNode* root, int& sum, int curr){

        if(root==nullptr) return;
        if(root->left==nullptr && root->right==nullptr){
            sum = sum + (10*curr+root->val);
            return;
        }

        fun(root->left, sum, 10*curr+root->val);
        fun(root->right, sum, 10*curr+root->val);

    }
    int sumNumbers(TreeNode* root) {

        int sum = 0;
        int curr = 0;
        fun(root, sum, curr);

        return sum;

    }
};
