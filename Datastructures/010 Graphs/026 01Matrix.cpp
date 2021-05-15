class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        if(mat.size()==0) return {};

        int n=mat.size(), m=mat[0].size();

        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dp[i][j]=0;
                }
            }
        }

        if(q.size() == n*m) return dp;

        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();

            if(x>0 && dp[x-1][y]==INT_MAX) {dp[x-1][y] = dp[x][y]+1; q.push({x-1,y});}
            if(y>0 && dp[x][y-1]==INT_MAX) {dp[x][y-1] = dp[x][y]+1; q.push({x,y-1});}
            if(x<n-1 && dp[x+1][y]==INT_MAX) {dp[x+1][y] = dp[x][y]+1; q.push({x+1,y});}
            if(y<m-1 && dp[x][y+1]==INT_MAX) {dp[x][y+1] = dp[x][y]+1; q.push({x,y+1});}

        }

        return dp;
    }
};
