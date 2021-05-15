/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // function returns null if it cannot find both pointers
    // if only one of p and q is present then it returns pointer of that node
    // otherwise it finds LCA
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root || root==p || root==q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // if one is in left and other is in right
        if(left && right) return root;

        // if both in right
        if(!left) return right;

        return left;

    }
};
