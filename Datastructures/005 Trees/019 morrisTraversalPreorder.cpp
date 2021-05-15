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
    vector<int> preorderTraversal(TreeNode* root) {

        TreeNode* curr = root;
        vector<int> res;

        while(curr){

            if(curr->left==nullptr){

                // visit curr
                res.push_back(curr->val);
                curr = curr->right;

            }else{

                // get inorder predecessor
                TreeNode* pred = getPred(curr);

                if(pred->right==nullptr){
                    pred->right = curr;
                    res.push_back(curr->val);
                    curr = curr->left;
                }else{
                    pred->right = nullptr;

                    curr = curr->right;
                }

            }

        }

        return res;

    }
};
