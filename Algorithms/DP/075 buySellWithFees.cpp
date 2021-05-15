class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        vector<int> dp(prices.size());
        dp[0] = 0;

        int max_profit = dp[0]-prices[0]-fee;
        for(int i=1; i<prices.size(); i++){
            dp[i] = max(dp[i-1], prices[i]+max_profit);
            max_profit = max(max_profit, dp[i]-prices[i]-fee);
        }

        return dp[dp.size()-1];

    }
};
