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
    TreeNode* fun(vector<int>& pre, vector<int>& post, int postLeft, int postRight){

        if(postLeft>postRight)
            return nullptr;

        int idx = -1;

        for(int i=postLeft; i<=postRight; i++){
            if(post[i]==pre[(preIndex+1)%pre.size()]){
                idx = i;
                break;
            }
        }

        TreeNode* root = new TreeNode(pre[preIndex++]);
        if(postLeft==postRight)
            return root;

        root->left = fun(pre, post, postLeft, idx);
        root->right = fun(pre, post, idx+1, postRight-1);

        return root;

    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if(pre.size()==1){
            TreeNode* root = new TreeNode(pre[0]);
            return root;
        }

        return fun(pre, post, 0, post.size()-1);
    }
};
