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

    TreeNode* fun(TreeNode* root){

        // base cases
        if(root==nullptr) return nullptr;
        if(root->left==nullptr && root->right==nullptr) return root;

        // if only left is null, then recursively flatten right and return
        if(root->left==nullptr){

            TreeNode* rightFlatten = fun(root->right);
            root->right = rightFlatten;
            return root;

        }
        // if only right is null, then recursively flatten left
        if(root->right==nullptr){

            TreeNode* leftFlatten = fun(root->left);

            // make the left of tree null
            root->left = nullptr;
            // join the flattened tree on right
            root->right = leftFlatten;
            return root;

        }

        // flatten left and right subtrees
        TreeNode* leftFlatten = fun(root->left);
        TreeNode* rightFlatten = fun(root->right);

        // left will now be null
        root->left = nullptr;
        root->right = leftFlatten;

        auto temp = leftFlatten;

        // traverse to the end of left flatten subtree, at the end append the right flattened subtree
        while(temp->right!=nullptr)
            temp = temp->right;

        temp->right = rightFlatten;

        return root;

    }
    void flatten(TreeNode* root) {
        fun(root);
    }
};
