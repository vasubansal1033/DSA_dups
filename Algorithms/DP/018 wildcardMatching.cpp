class Solution {
public:
    bool isMatch(string s, string p) {

        int m = s.size();
        int n = p.size();

        if(m==0 && n==0) return true;
        if(n==0) return false;

        bool dp[2][n+1];
        memset(dp, false, sizeof(dp));

        dp[0][0] = true;
        for(int i=1; i<=p.size(); i++){

            if(p[i-1]=='*') dp[0][i] = dp[0][i-1];

        }

        // if i>0, j==0, dp[i][0] = false;
        for(int i=1; i<=s.size(); i++){
            for(int j=p.size(); j>=1; j--){

                if(p[j-1]=='?' || s[i-1]==p[j-1])
                    dp[i%2][j] = dp[(i-1)%2][j-1];
                else if(p[j-1]=='*')
                    // Treat '*' as empty string -> dp[i][j] = dp[i][j-1]
                    // I can say that '*' sequence will include the ith char of s. dp[i][j] = dp[i-1][j]
                    dp[i%2][j] = dp[i%2][j-1] || dp[(i-1)%2][j];

            }
        }

        return dp[m%2][n];



    }
};

class Solution {
public:
    bool isMatch(string s, string p) {

        int n = s.length();
        int m = p.length();

        // If pattern is empty
        if(n!=0 && m==0){
            return 0;
        }
        // If string is empty but pattern consists of only *
        if(n==0 && m==1 && (p[m-1] =='*')){
            return 1;
        }
        // If string is empty but pattern consists of only ?
         if(n==0 && m==1 && (p[m-1] =='?')){
            return 0;
        }
        // If both are empty
        if(n==0 && m==0){
            return 1;
        }
        bool dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        // Both are empty case
        dp[0][0] = true;

        // We'll treat * as empty, and check if previous part matched
        for(int i = 1;i<=m;i++){
            if(p[i-1]=='*'){
            dp[0][i] = dp[0][i-1];
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(p[j-1]=='?' || s[i-1]==p[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] =='*'){
                    // dp[i-1][j] - treat * as empty string
                    // dp[i][j-1]
                    dp[i][j] = ( dp[i-1][j] || dp[i][j-1] );
                }
                // else
                //     dp[i][j] = false;
            }
        }        return dp[n][m];
    }
};
