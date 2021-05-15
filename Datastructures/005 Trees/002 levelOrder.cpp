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
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root==nullptr)
            return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int> > res;

        int level = 0;
        while(!q.empty()){

            res.push_back({});
            int sz = q.size();
            for(int i=0; i<sz; i++){
                TreeNode* front = q.front(); q.pop();

                res[level].push_back(front->val);
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);

            }
            level++;

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

    void fun(vector<vector<int>>& res, TreeNode* root, int level){

        if(root==nullptr)
            return;

        if(res.size()==level)
            res.push_back({});

        res[level].push_back(root->val);

        // call left child
        fun(res, root->left, level+1);
        // call right child
        fun(res, root->right, level+1);

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = 0;
        vector<vector<int> > res;
        fun(res, root, level);

        return res;
    }
};
