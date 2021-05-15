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
    TreeNode* getPred(TreeNode* root){

        // if(root==nullptr || root->left==nullptr) return nullptr;

        auto temp = root->left;
        while(temp->right!=nullptr && temp->right!=root)
            temp = temp->right;

        return temp;

    }
    vector<int> inorderTraversal(TreeNode* root) {

        TreeNode* curr = root;
        vector<int> res;

        while(curr!=nullptr){

            if(curr->left==nullptr){

                // visit curr
                res.push_back(curr->val);
                curr = curr->right;

            }else{

                // find inorder predecessor of curr, so that we can go back to curr again
                TreeNode* pred = getPred(curr);

                if(pred->right==nullptr){
                    pred->right = curr;
                    curr = curr->left;
                }else{
                    pred->right = nullptr;
                    // visit curr
                    res.push_back(curr->val);
                    curr = curr->right;
                }

            }

        }

        return res;

    }
};
