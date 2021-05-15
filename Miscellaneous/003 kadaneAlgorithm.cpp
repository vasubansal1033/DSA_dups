// maximum subarray sum

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // Kadane's algorithm
        int i = 0;
        int maxSum = nums[0];
        i++;
        int currSum = nums[0];
        while(i<nums.size()){

            if(currSum+nums[i]>nums[i]){
                currSum+=nums[i];
                i++;
            }else{
                currSum = nums[i];
                i++;
            }

            maxSum = max(maxSum, currSum);

        }

        return maxSum;

    }
};
