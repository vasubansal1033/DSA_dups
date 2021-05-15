class Solution {
public:
    int dp[51][51][51];
    int util(vector<vector<int>>& grid, int r1, int c1, int c2){

        // r1+c1 = r2+c2
        int r2 = r1+c1-c2;
        if(r1>=grid.size() || r2>=grid.size() || c1>=grid.size() || c2>=grid.size() || grid[r1][c1]==-1 || grid[r2][c2]==-1) return INT_MIN;

        if(dp[r1][c1][c2]!=-1) return dp[r1][c1][c2];

        if(r1==grid.size()-1 && c1==grid.size()-1) return grid[r1][c1];

        int ans = grid[r1][c1];
        // if points are not same then add for other person
        if(c1!=c2) ans+=grid[r2][c2];

        // (down, down), (right, right), (right, down), (down, right)
        int temp = max(util(grid, r1+1, c1, c2), util(grid, r1+1, c1, c2+1));
        temp = max(temp, util(grid, r1, c1+1, c2+1));
        temp = max(temp, util(grid, r1, c1+1, c2));

        ans += temp;

        return dp[r1][c1][c2] = ans;

    }
    int cherryPickup(vector<vector<int>>& grid) {

        memset(dp, -1, sizeof(dp));
        return max(0, util(grid, 0, 0, 0));

    }
};
