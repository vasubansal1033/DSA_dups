class Solution {
public:
    int util(vector<vector<int> >& matrix, vector<vector<int> >& dp, int i, int j){

        if(i<0||j<0||i>=matrix.size()||j>=matrix[0].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        dp[i][j] = 1;

        if(j+1<matrix[0].size() && matrix[i][j]>matrix[i][j+1])
            dp[i][j] = max(dp[i][j], 1+util(matrix, dp, i, j+1));

        if(j-1>=0 && matrix[i][j]>matrix[i][j-1])
            dp[i][j] = max(dp[i][j], 1+util(matrix, dp, i, j-1));

        if(i+1<matrix.size() && matrix[i][j]>matrix[i+1][j])
            dp[i][j] = max(dp[i][j], 1+util(matrix, dp, i+1, j));

        if(i-1>=0 && matrix[i][j]>matrix[i-1][j])
            dp[i][j] = max(dp[i][j], 1+util(matrix, dp, i-1, j));

        return dp[i][j];

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        if(matrix.size()==0) return 0;

        vector<vector<int> > dp(matrix.size(), vector<int>(matrix[0].size(), -1));

        int res = 1;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(dp[i][j]==-1)
                    res = max(res, util(matrix, dp, i, j));
            }
        }

        return res;
    }
};
