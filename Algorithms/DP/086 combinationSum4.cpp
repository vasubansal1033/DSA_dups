class Solution {
public:

    int combinationSum4(vector<int>& nums, int target) {

        // if we have negative numbers, then there might be infinite cases
        // for eg [-1, 1] can solve any number in infinite ways
        // limitation -> one element can be taken only once

        unsigned int dp[target+1];
        memset(dp, 0, sizeof(dp));

        dp[0] = 1;

        for(int i=1; i<=target; i++){

            for(int j=0; j<nums.size(); j++){

                if(i>=nums[j])
                    dp[i] += dp[i-nums[j]];

            }

        }

        return dp[target];

    }
};

