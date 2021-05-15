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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums){

        stack<TreeNode*> stk;
        for (int num : nums) {
            TreeNode* node = new TreeNode(num);
            while (!stk.empty() && stk.top() -> val < node -> val) {
                node -> left = stk.top();
                stk.pop();
            }
            if (!stk.empty()) {
                stk.top() -> right = node;
            }
            stk.push(node);
        }
        while (stk.size() > 1) {
            stk.pop();
        }
        return stk.top();
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
    int sparseTable[1005][12];
    int log_[1005];

    void buildSparseTable(vector<int>& nums){

        for(int i=0; i<nums.size(); i++) sparseTable[i][0] = i;

        for(int j=1; j<11; j++){
            for(int i=0; i+(1<<j)<=nums.size(); i++){

                // sparseTable[i][j] = max(sparseTable[i][j-1], sparseTable[i+(1<<(j-1))][j-1]);
                int a = sparseTable[i][j-1];
                int b = sparseTable[i+(1<<(j-1))][j-1];
                if(nums[a]>nums[b]) sparseTable[i][j] = a;
                else sparseTable[i][j] = b;
            }
        }
    }
    int query(int l, int r, vector<int>& nums){

        int j = log_[r-l+1];

        int a = sparseTable[l][j];
        int b = sparseTable[r-(1<<j)+1][j];

        if(nums[a]>nums[b]) return a;
        else return b;

    }
    TreeNode* util(int start, int last, vector<int>& nums){

        if(start>last) return nullptr;
        if(start==last){
            return new TreeNode(nums[start]);
        }

        int maxIdx = query(start, last, nums);
        TreeNode* root = new TreeNode(nums[maxIdx]);

        root->left = util(start, maxIdx-1, nums);
        root->right = util(maxIdx+1, last, nums);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        ios_base::sync_with_stdio(0); cin.tie(0);

        buildSparseTable(nums);
        log_[0] = INT_MIN; log_[1] = 0;
        for(int i=2; i<=nums.size(); i++) log_[i] = log_[i/2]+1;

        TreeNode* root = nullptr;
        root = util(0, nums.size()-1, nums);

        return root;

    }
};
