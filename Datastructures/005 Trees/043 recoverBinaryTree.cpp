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

// Visit all nodes in inorder
// keep a firstNode, secondNode and prev
// Visualize the problem in sorted array. When discrepancy is found, Check if firstNode==nullptr before this
// If firstNode==nullptr means, this is the first discrepency. Thus firstNode==prev
// When second discrepancy is found firstNode!=nullptr. And secondNode==root
class Solution {
public:

    TreeNode* firstNode;
    TreeNode* secondNode;
    TreeNode* prev;
    void inorder(TreeNode* root){

        if(root==nullptr) return;

        inorder(root->left);

        // visit the node
        if(prev){

            if(prev->val>=root->val && firstNode==nullptr){
                firstNode = prev;
            }
            if(prev->val>=root->val && firstNode!=nullptr){
                secondNode = root;
            }

        }
        prev = root;

        inorder(root->right);

    }
    void recoverTree(TreeNode* root) {

        firstNode = nullptr;
        secondNode = nullptr;
        prev = nullptr;

        inorder(root);

        swap(firstNode->val, secondNode->val);

    }
};
