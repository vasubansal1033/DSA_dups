class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& size){

        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]==0) return;
        if(visited[x][y]) return;

        visited[x][y] = true;
        size++;
        dfs(grid, visited, x+1, y, size);
        dfs(grid, visited, x-1, y, size);
        dfs(grid, visited, x, y+1, size);
        dfs(grid, visited, x, y-1, size);

        return;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        if(grid.size()==0) return 0;

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int res = 0;
        int size;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){

                size = 0;
                if(!visited[i][j] && grid[i][j]==1){
                    dfs(grid, visited, i, j, size);
                }
                res = max(res, size);

            }
        }

        return res;

    }

};
