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

    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> res;
        TreeNode* temp = root;
        stack<TreeNode*> stk;

        while(!(stk.empty() && temp==nullptr)){

            if(temp!=nullptr){
                stk.push(temp);
                temp = temp->left;
            }else{

                TreeNode* temp2 = stk.top()->right;
                // if current node has right subtree, then print it
                if(temp2!=nullptr)
                    temp = temp2;
                else{

                    temp2 = stk.top(); stk.pop();
                    // we have visited left subtree, right subtree not present. so push it
                    res.push_back(temp2->val);

                    while(!stk.empty() && stk.top()->right==temp2){
                        temp2 = stk.top(); stk.pop();
                        res.push_back(temp2->val);
                    }

                }

            }

        }

        return res;


    }
};
