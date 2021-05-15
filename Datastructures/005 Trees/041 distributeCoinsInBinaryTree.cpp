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
    // returns excess coins in this subree
    int util(TreeNode* root, int& moves){

        if(!root) return 0;
        // get excess coins from left and right subtree
        int left = util(root->left, moves);
        int right = util(root->right, moves);

        // these have to be moves, so sum them
        moves += abs(left)+abs(right);

        // add the root's coins to these excess coins and subtract 1 for root's coin.
        return root->val+left+right-1;

    }
    int distributeCoins(TreeNode* root) {

        int moves = 0;
        util(root, moves);

        return moves;
    }
};
