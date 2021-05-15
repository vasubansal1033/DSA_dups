class Solution {
public:

    int countVowelPermutation(int n) {

        vector<vector<long> > dp(5, vector<long>(3));
        int MOD = 1e9+7;

        for(int i=0; i<5; i++)
            dp[i][1%2+1] = 1;

        for(int j=2; j<=n; j++){

            dp[0][j%2+1] = (dp[1][(j-1)%2+1]+dp[2][(j-1)%2+1]+dp[4][(j-1)%2+1])%MOD;
            dp[1][j%2+1] = (dp[0][(j-1)%2+1]+dp[2][(j-1)%2+1])%MOD;
            dp[2][j%2+1] = (dp[1][(j-1)%2+1]+dp[3][(j-1)%2+1])%MOD;
            dp[3][j%2+1] = (dp[2][(j-1)%2+1])%MOD;
            dp[4][j%2+1] = (dp[2][(j-1)%2+1]+dp[3][(j-1)%2+1])%MOD;

        }

        int res = 0;
        for(int i=0; i<5; i++)
            res = (1LL*res+dp[i][n%2+1])%MOD;

        return res;

    }
};
