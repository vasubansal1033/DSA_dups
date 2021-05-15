// LCA in BST and Binary Tree is different
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        TreeNode* curr = root;

        while(true){

            if(p->val<curr->val && q->val<curr->val) curr = curr->left;
            else if(p->val>curr->val && q->val>curr->val) curr = curr->right;

            // now it can be that root is between p and q
            // that is p and q are in different subtrees or one of them is curr
            // thus the answer will be root
            else break;

        }

        return curr;

    }
};



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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root==nullptr) return nullptr;

        // case 1: p and q in left subtree
        if((root->val)>p->val && (root->val)>q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        // case 2: p and q both in right subtree
        if((root->val)<p->val && (root->val)<q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        // case 3: one of p or q is root
        // if(root==p || root==q)
        //     return root;
        // case 4: p and q in different subtrees
        return root;




    }
};
