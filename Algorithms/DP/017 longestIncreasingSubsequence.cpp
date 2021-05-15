class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        if(nums.size()==0)
            return 0;

        vector<int> dp(nums.size());
        dp[0] = 1;
        int ans = INT_MIN;
        for(int i=1; i<nums.size(); i++){

            int j=i-1;
            dp[i] = 1;

            while(j>=0){

                if(nums[i]>nums[j]){

                    dp[i] = max(dp[i], dp[j]+1);

                }
                j--;

            }
            ans = max(ans, dp[i-1]);
        }

        ans = max(ans, dp[nums.size()-1]);

        return ans;

    }
};
