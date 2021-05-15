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
    unsigned long long int totalSum = 0;
    unsigned long long int mod = pow(10, 9)+7;
    void getTotalSum(TreeNode* root){

        if(root==nullptr) return;
        totalSum += root->val;
        getTotalSum(root->left);
        getTotalSum(root->right);

    }
    unsigned long long int getSum(TreeNode* root, unsigned long long int& res){

        if(root==nullptr) return 0;

        unsigned long long int leftSum = getSum(root->left, res);
        unsigned long long int rightSum = getSum(root->right, res);

        unsigned long long int a = (totalSum-rightSum)*rightSum;
        unsigned long long int b = (totalSum-leftSum)*leftSum;
        unsigned long long int temp = max(a, b);
        res = max(temp, res);

        return root->val + leftSum + rightSum;

    }
    int maxProduct(TreeNode* root) {

        unsigned long long int res = 0;
        getTotalSum(root);
        getSum(root, res);

        return res%mod;
    }
};


typedef unsigned long long int lli;
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
    int getSum2(TreeNode* root, unordered_map<TreeNode*, int>& map){

        if(root == nullptr) return 0;
        if(map.find(root)!=map.end()) return map[root];

        return map[root] = getSum2(root->left, map)+getSum2(root->right, map)+root->val;

    }
    void getSum(TreeNode* root, lli& res, lli sum, unordered_map<TreeNode*, int>& map){

        if(root==nullptr) return;

        int l = map[root->left];
        int r = map[root->right];

        getSum(root->left, res, sum+root->val + r, map);
        getSum(root->right, res, sum+root->val + l, map);

        lli temp = max(l*(root->val + r + sum), r*(root->val + l + sum));
        res = max(res, temp);

    }
    int maxProduct(TreeNode* root) {

        lli res = 0;
        unordered_map<TreeNode*, int> map;
        getSum2(root, map);

        getSum(root, res, 0, map);

        int mod = pow(10,9)+7;
        return res%mod;
    }
};
