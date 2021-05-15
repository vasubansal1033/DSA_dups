class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int k = 2;
        vector<int> dp(k+1);
        vector<int> mini(k+1, prices[0]);
        for(int j=1; j<prices.size(); j++){

            for(int i=1; i<=k; i++){

                // dp[i][j] = max(dp[i][j-1], dp[i-1][x-1]+prices[j]-prices[x]) x goes from 1 to j
                // prices[j] - (prices[x]-dp[i-1][x-1]) -> minimum 2nd term
                mini[i] = min(mini[i], prices[j]-dp[i-1]);
                dp[i] = max(dp[i], prices[j]-mini[i]);

            }

        }

        return dp[k];

    }
};




class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int k = 2;
        vector<vector<int> > dp(k+1, vector<int>(prices.size(), 0));

        for(int i=1; i<=k; i++){

            int mini = prices[0];
            for(int j=1; j<prices.size(); j++){

                mini = min(mini, prices[j]-dp[i-1][j-1]);

                dp[i][j] = max(dp[i][j-1], prices[j]-mini);

            }
        }

        return dp[k][prices.size()-1];

    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int k = 2;
        vector<vector<int> > dp(k+1, vector<int>(prices.size()));
        for(int i=0; i<dp.size(); i++)
            dp[i][0] = 0;
        for(int j=1; j<prices.size(); j++)
            dp[0][j] = 0;

        for(int i=1; i<=k; i++){
            for(int j=1; j<prices.size(); j++){

                // dp[i][j] = max(dp[i][j-1], dp[i-1][x-1]+prices[i]-prices[x]); x from 1...j
                // prices[i] - (prices[x]-dp[i-1][x-1]) -> 2nd term should be minimum
                int mini = prices[0];
                for(int x=1; x<=j; x++){
                    mini = min(prices[x]-dp[i-1][x-1], mini);
                }

                dp[i][j] = max(dp[i][j-1], prices[j]-mini);

            }
        }

        return dp[k][prices.size()-1];

    }
};
