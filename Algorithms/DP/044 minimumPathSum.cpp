class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        vector<vector<int> > dp(2, vector<int>(grid[0].size()+1, INT_MAX));

        for(int i=grid.size()-1; i>=0; i--){

            for(int j=grid[0].size()-1; j>=0; j--){

                if(i==grid.size()-1 && j==grid[0].size()-1){
                    dp[i%2][j] = grid[i][j];
                }else{
                    dp[i%2][j] = min(dp[(i+1)%2][j], dp[i%2][j+1])+grid[i][j];
                }

            }

        }

        return dp[0][0];

    }
};


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        vector<vector<int> > dp(grid.size()+1, vector<int>(grid[0].size()+1, INT_MAX));

        for(int i=grid.size()-1; i>=0; i--){

            for(int j=grid[0].size()-1; j>=0; j--){

                if(i==grid.size()-1 && j==grid[0].size()-1){
                    dp[i][j] = grid[i][j];
                }else{
                    dp[i][j] = min(dp[i+1][j], dp[i][j+1])+grid[i][j];
                }

            }

        }

        return dp[0][0];

    }
};
