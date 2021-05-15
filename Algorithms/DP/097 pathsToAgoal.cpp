// Given a number line from 0 to n, you are at x and have to reach y.
// You are given a string consisting of l and r only. l means you go from i to i-1 on number line
// r means you go from i to i+1
// Number of 'distinct subsequences' of this string which result going from x to y

const int mod = 1e9+7;
int solve(string& s, int n, int x, int y){

    int prevSame[s.size()];
    int idxL = -1;
    int idxR = -1;
    for (int i = 0; i < prevSame.size(); i++) {
        if (s[i] == 'l') {
            prevSame[i] = idxL;
            idxL = i;
        } else {
            prevSame[i] = idxR;
            idxR = i;
        }
    }

    // dp[i][j] is number of distinct subsequnces of length i to end up at j
    long dp[s.length+1][n+1];
    memset(dp, 0, sizeof(dp));
    dp[0][x] = 1;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i-1][j];
            if (s[i-1] == 'l') {
                if (j+1 <= n) dp[i][j] += dp[i-1][j+1];
                if (j+1 <= n && prevSame[i-1] >= 0) dp[i][j] -= dp[prevSame[i-1]][j+1];
            } else {
                if (j-1 >= 0) dp[i][j] += dp[i-1][j-1];
                if (j-1 >= 0 && prevSame[i-1] >= 0) dp[i][j] -= dp[prevSame[i-1]][j-1];
            }
            dp[i][j] = (dp[i][j] + mod) % mod;
        }
    }
    return (int)dp[s.length][y];
}
