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
    void fun(TreeNode* root, int sum, vector<vector<int> >& res, vector<int> currSet){

        if(root==nullptr) return;

        if(root->left==nullptr && root->right==nullptr){
            if(sum==root->val){
                currSet.push_back(root->val);
                res.push_back(currSet);
            }
            return;
        }

        currSet.push_back(root->val);
        fun(root->left, sum-root->val, res, currSet);
        fun(root->right, sum-root->val, res, currSet);

    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        vector<vector<int> > res;
        vector<int> currSet;

        fun(root, sum, res, currSet);

        return res;

    }
};
