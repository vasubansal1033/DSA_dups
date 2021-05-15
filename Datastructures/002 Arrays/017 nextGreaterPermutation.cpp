class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        if(nums.size()<=1)
            return;

        // first find the number which is not in increasing order from left
        int i;
        for(i=nums.size()-2; i>=0; i--){
            if(nums[i]<nums[i+1])
                break;
        }

        // means list is sorted in reverse order, that is maximum possible configuration
        if(i<0){
            reverse(nums.begin(), nums.end());
            return;
        }

        // otherwise, find the first element from right > nums[i]
        int j;
        for(j=nums.size()-1; j>=0; j--)
            if(nums[j]>nums[i])
                break;

        // swap these numbers
        swap(nums[i], nums[j]);

        // reverse the numbers after i
        reverse(nums.begin()+i+1, nums.end());


    }
};
