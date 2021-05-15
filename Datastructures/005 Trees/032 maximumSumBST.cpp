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
    void maxSumBSTUtil(TreeNode* root, bool& isBST, int& smallest, int& largest, int& sum, int& maxSum){

        // base case
        if(root==nullptr){
            isBST = true;
            smallest = INT_MAX;
            largest = INT_MIN;
            sum = 0;
            return;
        }

        bool isBSTleft, isBSTright;
        int smallestLeft, smallestRight, largestLeft, largestRight, sumLeft, sumRight;

        // get answers for left subtree
        maxSumBSTUtil(root->left, isBSTleft, smallestLeft, largestLeft, sumLeft, maxSum);
        // get answers for right subtree
        maxSumBSTUtil(root->right, isBSTright, smallestRight, largestRight, sumRight, maxSum);

        isBST = (isBSTleft&&isBSTright)&&(root->val>largestLeft && root->val<smallestRight);
        smallest = min(smallestLeft, min(smallestRight, root->val));
        largest = max(largestLeft, max(largestRight, root->val));
        sum = sumLeft+sumRight+root->val;

        if(isBST)
            maxSum = max(sum, maxSum);


    }
    int maxSumBST(TreeNode* root) {

        // for each subtree, I need
        // if it is a bst
        // largest value in that subtree
        // smallest value in that subtree
        // sum of the subtree
        // maxSum for that subtree
        bool isBST = false;
        int largest = INT_MIN, smallest = INT_MAX, sum = 0, maxSum = INT_MIN;
        maxSumBSTUtil(root, isBST, smallest, largest, sum, maxSum);

        return maxSum<0?0:maxSum;

    }
};
