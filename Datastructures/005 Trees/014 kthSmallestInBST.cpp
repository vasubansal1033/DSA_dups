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
    int kthSmallest(TreeNode* root, int k) {

        stack<TreeNode*> stk;
        TreeNode* temp = root;

        while(!(stk.empty() && temp==nullptr)){

            if(temp!=nullptr){
                stk.push(temp);
                temp = temp->left;
            }else{
                temp = stk.top(); stk.pop();
                // visit it
                k--;
                if(k==0) return temp->val;
                temp = temp->right;
            }

        }

        return -1;

    }
};
