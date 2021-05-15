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
    int preIndex = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd){

        if(inStart>inEnd)
            return nullptr;

        int idx = -1;
        for(int i=inStart; i<=inEnd; i++){
            if(preorder[preIndex] == inorder[i]){
                idx = i; break;
            }
        }

        TreeNode* root = new TreeNode(inorder[idx]);
        preIndex++;

        if(inStart==inEnd)
            return root;

        root->left = buildTree(preorder, inorder, inStart, idx-1);
        root->right = buildTree(preorder, inorder, idx+1, inEnd);

        return root;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, inorder.size()-1);
    }
};
