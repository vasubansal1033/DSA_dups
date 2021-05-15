class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        if(prices.size()==0 || k==0) return 0;
        if(k>=prices.size()/2){

            // Similar to infinite transactions as maxmimum transactions can be length/2
            int pprofit = 0;
            for(int i=1; i<prices.size(); i++){

                int cprofit = max(pprofit, pprofit+prices[i]-prices[i-1]);
                pprofit = cprofit;

            }
            return pprofit;
        }

        vector<int> dp(k+1, 0);

        vector<int> mini(k+1, prices[0]);
        for(int j=1; j<prices.size(); j++){

            for(int i=1; i<=k; i++){

                // dp[i][j] = max(dp[i][j-1], dp[i-1][x-1]+prices[j]-prices[x]) x from 1 to j
                mini[i] = min(mini[i], prices[j]-dp[i-1]);
                dp[i] = max(dp[i], prices[j]-mini[i]);

            }

        }

        return dp[k];

    }
};


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        if(prices.size()==0 || k==0) return 0;
        if(k>=prices.size()/2){

            // Similar to infinite transactions as maxmimum transactions can be length/2
            int pprofit = 0;
            for(int i=1; i<prices.size(); i++){

                int cprofit = max(pprofit, pprofit+prices[i]-prices[i-1]);
                pprofit = cprofit;

            }
            return pprofit;
        }

        vector<vector<int> > dp(k+1, vector<int>(prices.size()));

        // if k=0 or index = 0 -> profit = 0;
        for(int i=0; i<=k; i++)
            dp[i][0] = 0;
        for(int j=1; j<prices.size(); j++)
            dp[0][j] = 0;

        for(int i=1; i<=k; i++){

            int mini = prices[0];
            for(int j=1; j<prices.size(); j++){

                // dp[i][j] = max(dp[i][j-1], dp[i-1][x-1]+prices[j]-prices[x]) x from 1 to j
                mini = min(mini, prices[j]-dp[i-1][j-1]);
                dp[i][j] = max(dp[i][j-1], prices[j]-mini);

            }

        }

        return dp[k][prices.size()-1];

    }
};


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        if(prices.size()==0 || k==0) return 0;

        vector<vector<int> > dp(k+1, vector<int>(prices.size()));

        // if k=0 or index = 0 -> profit = 0;
        for(int i=0; i<=k; i++)
            dp[i][0] = 0;
        for(int j=1; j<prices.size(); j++)
            dp[0][j] = 0;

        for(int i=1; i<=k; i++){

            for(int j=1; j<prices.size(); j++){

                // dp[i][j] = max(dp[i][j-1], dp[i-1][x-1]+prices[j]-prices[x]) x from 1 to j
                int mini = prices[0];
                for(int x=1; x<=j; x++) mini = min(mini, prices[x]-dp[i-1][x-1]);
                dp[i][j] = max(dp[i][j-1], prices[j]-mini);

            }

        }

        return dp[k][prices.size()-1];

    }
};
