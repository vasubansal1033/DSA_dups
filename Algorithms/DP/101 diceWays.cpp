class Solution {
  public:
    long long noOfWays(int M , int N , int X) {
        // code here

        // dp[i][j] number of ways to get sum j from i dices
        // M=0, 0 faces, 0 ways
        // N=0, 0 dice, 0 ways
        // X=0, no way(starts from 1)
        // N=1 dice, X = 1 to M has 1 way
        long long int dp[N+1][X+1];
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=min(X, M); i++) dp[1][i] = 1;

        for(int i=2; i<=N; i++){
            for(int j=1; j<=X; j++){
                for(int k=1; k<=M && k<j; k++)
                    dp[i][j] += dp[i-1][j-k];
            }
        }

        return dp[N][X];

    }
};
