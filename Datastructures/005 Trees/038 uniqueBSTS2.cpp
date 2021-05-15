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
    vector<TreeNode*> util(int start, int last){

        vector<TreeNode*> res;
        // base case
        if(start>last){
            res.push_back(nullptr);
            return res;
        }

        for(int i=start; i<=last; i++){

            vector<TreeNode*> leftSubtree = util(start, i-1);
            vector<TreeNode*> rightSubtree = util(i+1, last);

            for(auto l:leftSubtree){
                for(auto r:rightSubtree){

                    TreeNode* temp = new TreeNode(i);
                    temp->left = l;
                    temp->right = r;

                    res.push_back(temp);

                }
            }

        }

        return res;

    }
    vector<TreeNode*> generateTrees(int n) {

        if(n==0) return {};


        return util(1, n);

    }
};
