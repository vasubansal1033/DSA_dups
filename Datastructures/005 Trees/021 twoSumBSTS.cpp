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

// Using moris inorder traversal to get sorted array. Then use 2pointers
class Solution {
public:
    TreeNode* getPred(TreeNode* curr){

        if(curr==nullptr || curr->left==nullptr) return nullptr;

        auto temp = curr->left;
        while(temp->right && temp->right!=curr)
            temp = temp->right;

        return temp;

    }
    void inorder(TreeNode* root, vector<int>& v){

        if(root==nullptr) return;

        TreeNode* curr = root;
        // morris inorder
        while(curr){

            if(!curr->left){
                // visit curr
                v.push_back(curr->val);
                curr = curr->right;
            }else{

                // inorder pred
                TreeNode* pred = getPred(curr);

                if(pred->right==nullptr){
                    pred->right = curr;
                    curr = curr->left;
                }else{
                    pred->right = nullptr;
                    // visit curr
                    v.push_back(curr->val);
                    curr = curr->right;
                }
            }

        }

    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {

        vector<int> v1, v2;

        inorder(root1, v1); inorder(root2, v2);

        int i(0), j(v2.size()-1);
        while(i<v1.size() && j>=0){

            if(v1[i]+v2[j]==target)
                return true;
            else if(v1[i]+v2[j]<target)
                i++;
            else
                j--;

        }

        return false;

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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {

        if(root1==nullptr || root2==nullptr) return false;

        if(root1->val+root2->val==target) return true;

        if(root1->val+root2->val<target){
            return twoSumBSTs(root1->right, root2, target)||twoSumBSTs(root1, root2->right, target);
        }else{
            return twoSumBSTs(root1->left, root2, target)||twoSumBSTs(root1, root2->left, target);
        }

    }
};
