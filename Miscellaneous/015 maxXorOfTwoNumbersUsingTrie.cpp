class TrieNode{
public:
    TrieNode* next[2];
    int val;

    TrieNode(int val){
        next[0] = next[1] = nullptr;
        this->val = val;
    }

};
class trie{
public:
    TrieNode* root;

    trie(TrieNode* root){
        this->root = root;
    }
    void insert(int val){

        TrieNode* curr = root;
        for(int i=31; i>=0; i--){

            bool isBitSet = val & (1<<i);
            if(curr->next[isBitSet]){
                curr = curr->next[isBitSet];
            }else{

                curr->next[isBitSet] = new TrieNode(isBitSet);
                curr = curr->next[isBitSet];
            }
        }
        curr->val = val;
    }
    int maxXor(int val){

        TrieNode* curr = root;
        for(int i=31; i>=0; i--){

            bool isBitSet = val & (1<<i);
            if(curr->next[!isBitSet]){
                curr = curr->next[!isBitSet];
            }else{
                curr = curr->next[isBitSet];
            }

        }

        return val ^ curr->val;

    }

};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        TrieNode* root = new TrieNode(0);
        trie* dict = new trie(root);

        int res = INT_MIN;
        for(int i=0; i<nums.size(); i++){

            dict->insert(nums[i]);
            res = max(res, dict->maxXor(nums[i]));
        }

        return res;

    }
};
