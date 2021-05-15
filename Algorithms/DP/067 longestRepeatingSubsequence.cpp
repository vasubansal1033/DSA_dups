int Solution::anytwo(string A) {

    vector<vector<int> > dp(2, vector<int>(A.size()+1, 0));

    for(int i=1; i<=A.size(); i++){
        for(int j=1; j<=A.size(); j++){

            if(A[i-1]==A[j-1] && i!=j)
                dp[i%2][j] = 1+dp[(i-1)%2][j-1];
            else
                dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-1]);

        }
    }

    return dp[A.size()%2][A.size()]>=2;

}
