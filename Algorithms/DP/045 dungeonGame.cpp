class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        vector<vector<int> > dp(dungeon.size()+1, vector<int>(dungeon[0].size()+1, INT_MAX/2));

        dp[dungeon.size()-1][dungeon[0].size()-1] = dungeon[dungeon.size()-1][dungeon[0].size()-1]>=0?1:(1-dungeon[dungeon.size()-1][dungeon[0].size()-1]);

        for(int i=dungeon.size()-1; i>=0; i--){
            for(int j=dungeon[0].size()-1; j>=0; j--){

                if(i==dungeon.size()-1 && j==dungeon[0].size()-1)
                    continue;

                dp[i][j] = min(max(1, dp[i+1][j]-dungeon[i][j]),
                               max(1, dp[i][j+1]-dungeon[i][j]));

            }
        }

        return dp[0][0];

    }
};
