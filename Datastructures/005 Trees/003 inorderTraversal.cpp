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

    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> res;
        stack<TreeNode* > stk;

        TreeNode* temp = root;
        while(!(stk.empty() && temp==nullptr)){

            if(temp!=nullptr){
                stk.push(temp);
                temp = temp->left;
            }else{
                temp = stk.top(); stk.pop();
                res.push_back(temp->val);
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

        if(root==nullptr)
            return;

        fun(res, root->left);
        res.push_back(root->val);
        fun(res, root->right);

    }
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> res;
        fun(res, root);

        return res;

    }
};
