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
    int util(TreeNode* root, int& res){

        // base case
        if(root==nullptr) return 0;

        // calculate left and right answers
        int lAns = util(root->left, res);
        int rAns = util(root->right, res);

        // calculate temporary ans which will be passed to parent
        int temp = max(root->val, root->val+max(lAns, rAns));
        // calculate answer when the node will become part of answer
        int ans = max(temp, lAns+root->val+rAns);

        // update res
        res = max(res, ans);
        return temp;
    }
    int maxPathSum(TreeNode* root) {

        int res = INT_MIN;
        util(root, res);

        return res;
    }
};
