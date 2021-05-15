class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {


        // dp[j] = 1+min(dp[j-coins[0]], dp[j-coins[1]],....)

        vector<int> dp(amount+1, INT_MAX-2);

        dp[0] = 0;
        for(int i=1; i<=amount; i++){

            for(int j=0; j<coins.size(); j++){

                if(i-coins[j]>=0)
                    dp[i] = min(dp[i], 1+dp[i-coins[j]]);

            }

        }

        return dp[amount]==(INT_MAX-2)?-1:dp[amount];

    }
};
