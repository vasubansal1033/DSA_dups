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
    int postIndex;
    TreeNode* fun(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd){

        if(inStart>inEnd)
            return nullptr;

        int idx = -1;
        for(int i=inStart; i<=inEnd; i++){
            if(postorder[postIndex] == inorder[i]){
                idx = i; break;
            }
        }

        TreeNode* root = new TreeNode(postorder[postIndex]); postIndex--;

        if(inStart==inEnd) return root;

        root->right = fun(inorder, postorder, idx+1, inEnd);
        root->left = fun(inorder, postorder, inStart, idx-1);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        postIndex = postorder.size()-1;
        return fun(inorder, postorder, 0, inorder.size()-1);

    }
};
