class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> res;

        // traverse array, if the current element is greater than all elements of res than push it in res
        // else find the smallest element greater than nums[i] in res and replace it.
        // This step does not change the shape of res, i.e. equivalent to the previous ans but helps us
        // incase we might find numbers that increase the length in further traversal


        for(int i=0; i<nums.size(); i++){

            auto it = lower_bound(res.begin(), res.end(), nums[i]);

            if(it==res.end())
                res.push_back(nums[i]);
            else{
                *it = nums[i];
            }

        }
        // res does not give the actual sequence though
        return res.size();

    }
};
