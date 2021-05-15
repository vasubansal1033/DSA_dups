class Solution {
public:
    /**
     * @param length: the length of the array
     * @param updates: update operations
     * @return: the modified array after all k operations were executed
     */
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        // Write your code here

        // Create array of 1 extra size. This will be removed later.
        vector<int> res(length+1, 0);
        for(auto update:updates){
            res[update[0]] += update[2];
            res[update[1]+1] -= update[2];
        }

        int sum = 0;
        for(int i=0; i<res.size(); i++){
            sum += res[i];
            res[i] = sum;
        }
        res.pop_back();
        return res;
    }
};
