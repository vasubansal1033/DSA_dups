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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        // Using BFS find coordinates for all the nodes
        // Store them in a multimap s.t. they come in the order wanted
        // using this map construct the vector
        multimap<pair<pair<int, int>, int>, TreeNode* > coordinates;
        queue<pair<TreeNode*, pair<int, int> > > q;
        q.push({root, {0, 0}});

        while(!q.empty()){
            auto front = q.front(); q.pop();
            TreeNode* ptr = front.first;
            int x = front.second.first;
            int y = front.second.second;

            coordinates.insert({{{x,y}, ptr->val}, ptr});
            if(ptr->left){
                q.push({ptr->left, {x-1, y+1}});
            }
            if(ptr->right){
                q.push({ptr->right, {x+1, y+1}});
            }

        }

        vector<vector<int> > res;
        for(auto it = coordinates.begin(); it!=coordinates.end();){

            TreeNode* ptr = (it->second);
            int x = it->first.first.first;

            vector<int> temp;
            while(it!=coordinates.end() && it->first.first.first == x){
                temp.push_back((it->second)->val);
                it++;
            }
            // reverse(temp.begin(), temp.end());
            res.push_back(temp);

        }

        return res;


    }
};
