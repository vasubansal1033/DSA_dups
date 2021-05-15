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

        if(root==nullptr) return 0;

        // calculate left ans and right ans
        int lAns = util(root->left, res);
        int rAns = util(root->right, res);

        // calculate temp ans
        int temp = max(lAns, rAns);
        // calculate if curr node is answer of final answer
        int ans = max(temp, lAns+rAns);

        // update res
        res = max(res, ans);

        // return temp ans
        return 1+temp;

    }
    int diameterOfBinaryTree(TreeNode* root) {

        int res = 0;
        util(root, res);

        return res;

    }
};s
