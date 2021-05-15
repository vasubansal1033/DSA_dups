class Solution {
public:

    int util(vector<vector<int> >& A, int i, int j, vector<vector<int> >& dp){

        if(i>0 && (j<0 || j>=A.size())) return INT_MAX/2;
        if(i==A.size()-1)
            return dp[i][j] = A[i][j];

        if(i>=0 && dp[i][j]!=-1) return dp[i][j];

        if(i==-1){
            int res = INT_MAX;
            for(int j=0; j<A[0].size(); j++){
                res = min(min(res, A[0][j]+util(A, 1, j, dp)), min(A[0][j]+util(A, 1, j-1, dp), A[0][j]+util(A, 1, j+1, dp)));
            }
            return res;
        }
        return dp[i][j] = min(A[i][j]+util(A, i+1, j-1, dp), min(A[i][j]+util(A, i+1, j, dp), A[i][j]+util(A, i+1, j+1, dp)));

    }
    int minFallingPathSum(vector<vector<int>>& A) {
        if(A.size()==0) return 0;
        if(A.size()==1){

            int res = INT_MAX;
            for(int i=0; i<A[0].size(); i++)
                res = min(res, A[0][i]);
            return res;
        }
        vector<vector<int> > dp(A.size(), vector<int>(A[0].size(), -1));
        return util(A, -1, -1, dp);
    }
};
