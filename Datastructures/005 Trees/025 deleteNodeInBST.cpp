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
    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root==nullptr) return root;
        else if(root->val>key) root->left = deleteNode(root->left, key);
        else if(root->val<key) root->right = deleteNode(root->right, key);
        else{

            // leaf node
            if(root->left==nullptr && root->right==nullptr){
                delete root;
                root = nullptr;
            }else if(!root->right){

                auto temp = root;
                root = root->left;
                delete temp;

            }else if(!root->left){

                auto temp = root;
                root = root->right;
                delete temp;

            }else{
                // two children
                auto temp = root->left;
                while(temp->right)
                    temp = temp->right;

                root->val = temp->val;

                root->left = deleteNode(root->left, temp->val);

            }

        }
        return root;

    }
};
