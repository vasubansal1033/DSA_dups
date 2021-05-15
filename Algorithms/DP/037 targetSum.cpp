class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {

        // Make the choice on the first element
        // Then suffix array is subproblem
        // let dp[i][j] denote the number of ways in which suffix array starting from i
        // can have a target sum j
        // then dp[i][j] = dp[i+1][j-nums[i]] + dp[i+1][j+nums[i]]
        // That is for the next suffix subproblem, we want the number of ways
        // to get j-nums[i]. In this case, we will do +nums[i]
        // to get j+nums[i]. In this case, we will do -nums[i]
        // So the recurrence relation is dp[i][j] = dp[i+1][j-nums[i]] + dp[i+1][j+nums[i]]

        if(S>1000) return 0;

        vector<vector<int> > dp(nums.size(), vector<int>(4005, 0));

        dp[nums.size()-1][nums[nums.size()-1]+2000] = 1;
        dp[nums.size()-1][-nums[nums.size()-1]+2000] += 1; // if last number is 0, then it'll get 2. +0 and -0 are different

        for(int i=nums.size()-2; i>=0; i--){

            for(int j=-1000; j<=1000; j++){

                dp[i][j+2000] = dp[i+1][j+nums[i]+2000]+dp[i+1][j-nums[i]+2000];

            }

        }

        return dp[0][S+2000];

    }
};
