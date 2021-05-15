// Space optimized DP
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // calculate the maximum subarray sum ending at index j

        int a = nums[0];
        int res = nums[0];
        int temp;
        for(int i=1; i<nums.size(); i++){

            // maximum subarray sum ending at index i = element i or maximum subarray sum ending at j-1 + element i
            temp = max(a+nums[i], nums[i]);
            a = temp;
            res = max(res, temp);

        }

        return res;

    }
};

//  DP solution
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // calculate the maximum subarray sum ending at index j

        vector<int> dp(nums.size(), 0);

        dp[0] = nums[0];
        int res = nums[0];
        for(int i=1; i<nums.size(); i++){

            // maximum subarray sum ending at index i = element i or maximum subarray sum ending at j-1 + element i
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            res = max(res, dp[i]);
        }

        return res;

    }
};
