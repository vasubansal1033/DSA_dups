typedef vector<int> v1;
typedef vector<v1> v2;
typedef vector<v2> v3;
typedef vector<v3> v4;

class Solution {
public:
    int util(int x1, int y1, int x2, int y2, v4& dp, v2& grid){

        if(x1==grid.size()-1 && y1==grid.size()-1){
            return grid[x1][y1] !=-1 ?grid[x1][y1]:INT_MIN/2;
        }

        if(x1==grid.size()||y1==grid.size()||x2==grid.size()||y2==grid.size()||grid[x1][y1]==-1||grid[x2][y2]==-1) return INT_MIN/2;

        if(dp[x1][y1][x2][y2]!=-1) return dp[x1][y1][x2][y2];

        int cherries = 0;
        if(x1==x2 && y1==y2) cherries = grid[x1][y1];
        else cherries = grid[x1][y1]+grid[x2][y2];

        return dp[x1][y1][x2][y2] = cherries+max(max(util(x1+1, y1, x2+1, y2, dp, grid), util(x1, y1+1, x2, y2+1, dp, grid)), max(util(x1+1, y1, x2, y2+1, dp, grid), util(x1, y1+1, x2+1, y2, dp, grid)));

    }
    int cherryPickup(vector<vector<int>>& grid) {

        v4 dp(51, v3(51, v2(51, v1(51, -1))));

        int res = util(0,0,0,0, dp, grid);
        return res>0?res:0;

    }
};
