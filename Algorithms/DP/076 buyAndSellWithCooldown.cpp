class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size()<=1) return 0;
        if(prices.size()==2) return max(0, prices[1]-prices[0]);

        vector<int> dp(prices.size());
        dp[0] = 0;
        dp[1] = max(0, prices[1]-prices[0]);
        dp[2] = max(dp[1], max(prices[2]-prices[1], prices[2]-prices[0]));

        // int temp = max(dp[0]-prices[2], max(dp[0]-prices[0], dp[0]-prices[1]));
        int temp = dp[0]-min(prices[0], min(prices[1], prices[2]));

        for(int i=3; i<prices.size(); i++){

            dp[i] = max(dp[i-1], prices[i]+temp);
            temp = max(temp, dp[i-2]-prices[i]);
        }
        // for(int i=0; i<dp.size(); i++) cout<<dp[i]<<" ";

        return dp[prices.size()-1];

    }
};
