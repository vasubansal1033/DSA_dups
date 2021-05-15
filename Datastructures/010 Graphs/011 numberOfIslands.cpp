class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){

        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]=='0') return;
        if(visited[x][y]) return;

        visited[x][y] = true;
        dfs(grid, visited, x+1, y);
        dfs(grid, visited, x-1, y);
        dfs(grid, visited, x, y+1);
        dfs(grid, visited, x, y-1);

        return;

    }
    int numIslands(vector<vector<char>>& grid) {

        if(grid.size()==0) return 0;

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int cnt = 0;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){

                if(!visited[i][j] && grid[i][j]=='1'){
                    cnt++;
                    dfs(grid, visited, i, j);
                }

            }
        }

        return cnt;

    }
};
