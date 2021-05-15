class Solution {
public:
    int change(int amount, vector<int>& coins) {

        if(coins.size()==0) return amount==0?1:0;

        // Infinite coin case
        // Recurrence is
        // S(0..n-1, C) = sum over i( S(0...n-1, C-w[i]) )
        // dp[i][j] = dp[i][j-w[j]]+dp[i+1][j]
        vector<int> dp(amount+1, 0);

        // if I have only the last coin, how many ways is it possible to get
        // amount j (0....amount)
        for(int j=0; j<=amount; j++){

            if(j%coins[coins.size()-1]==0)
                dp[j] = 1;

        }

        for(int i=coins.size()-2; i>=0; i--){
            for(int j=0; j<=amount; j++){

                if(j-coins[i]>=0)
                    dp[j] = dp[j]+dp[j-coins[i]];
                else
                    dp[j] = dp[j];

            }
        }

        return dp[amount];

    }

};
