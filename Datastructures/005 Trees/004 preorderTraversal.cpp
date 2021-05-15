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
    vector<int> preorderTraversal(TreeNode* root) {

        stack<TreeNode*> stk;
        vector<int> res;

        TreeNode* temp = root;

        while(!stk.empty() || temp!=nullptr){

            if(temp!=nullptr){
                res.push_back(temp->val);
                stk.push(temp);
                temp = temp->left;
            }else{
                temp = stk.top(); stk.pop();
                temp = temp->right;
            }

        }

        return res;

    }
};




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
    void fun(vector<int>& res, TreeNode* root){

        if(root==nullptr) return;

        res.push_back(root->val);
        fun(res, root->left);
        fun(res, root->right);

    }
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> res;
        fun(res, root);

        return res;

    }
};
