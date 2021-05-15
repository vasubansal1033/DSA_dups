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
    vector<int> rightSideView(TreeNode* root) {

        if(!root) return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<int> res;
        while(!q.empty()){

            int sz = q.size();
            for(int i=0; i<sz; i++){

                TreeNode* front = q.front(); q.pop();
                if(i==sz-1){
                    res.push_back(front->val);
                }

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);

            }

        }

        return res;

    }
};
