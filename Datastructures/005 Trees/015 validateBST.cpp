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

        if(root==nullptr || root->left==nullptr) return nullptr;

        auto temp = root->left;
        while(temp->right && temp->right!=root)
            temp = temp->right;

        return temp;

    }
    bool isValidBST(TreeNode* root) {

        // runtime error, if we break when we get false. Because we cannot change the tree

        TreeNode* curr = root;
        TreeNode* prev = nullptr;

        bool res = true;

        while(curr){

            if(curr->left==nullptr){

                // visit curr
                if(prev && prev->val>=curr->val){
                    res =  false;
                }


                prev = curr;
                curr = curr->right;

            }else{

                TreeNode* pred = getPred(curr);

                if(pred->right==nullptr){

                    pred->right = curr;
                    curr = curr->left;

                }else{

                    pred->right = nullptr;
                    // visit curr
                    if(prev && prev->val>=curr->val){
                        res = false;
                    }

                    prev = curr;
                    curr = curr->right;

                }

            }

        }

        return res;

    }
};



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
    bool isValidBST(TreeNode* root) {

        TreeNode* prev = nullptr;
        TreeNode* temp = root;
        stack<TreeNode*> stk;

        while(!(stk.empty() && temp==nullptr)){

            if(temp!=nullptr){
                stk.push(temp);
                temp = temp->left;
            }else{

                temp = stk.top(); stk.pop();

                // // visit curr
                // if(prev==nullptr){
                //     prev = temp;
                //     temp = temp->right;
                //     continue;
                // }

                if( prev!=nullptr && temp->val<=prev->val)
                    return false;
                prev = temp;
                temp = temp->right;
            }

        }

        return true;
    }
};
