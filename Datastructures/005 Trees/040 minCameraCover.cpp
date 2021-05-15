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
    int util(TreeNode* root, bool hasCamera, bool isMonitored){

        if(root==nullptr) return 0;

        // if root has camera, then left and right nodes are monitored.
        // We may or maynot place cameras at left and right nodes
        if(hasCamera) return 1+util(root->left, false, true)+util(root->right, false, true);
        if(isMonitored){

            // If root is monitored, then we can place a camera here and child nodes will be monitored
            int yesCamera = 1+util(root->left, false, true)+util(root->right, false, true);
            // Or we can then "recurse" for child nodes. Child nodes won't be monitored.
            int noCamera = util(root->left, false, false)+util(root->right, false, false);

            return min(yesCamera, noCamera);
        }

        // If node is neither monitored nor has camera
        if(root->val!=0) return root->val;

        // we can place camera
        int yesCamera = 1+util(root->left, false, true)+util(root->right, false, true);

        // We don't place camera. We have to place camera on either left or child node so that root can be monitored from these.
        int leftCamera = (root->left==nullptr)?INT_MAX:(util(root->left, true, false)+util(root->right, false, false));
        int rightCamera = (root->right==nullptr)?INT_MAX:(util(root->left, false, false)+util(root->right, true, false));

        return root->val = min(yesCamera, min(leftCamera, rightCamera));


    }
    int minCameraCover(TreeNode* root) {
        return util(root, false, false);
    }
};
