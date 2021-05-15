#include<bits/stdc++.h>
using namespace std;

void uniquePathsIIIUtil(vector<vector<int> >& grid, pair<int, int> start, pair<int, int>& finish, int& count_, vector<vector<bool> >& visited, int& steps, int currSteps){

    // base case
    if(start.first==finish.first && start.second==finish.second && currSteps-1 == steps){
        count_++;
        return;
    }

    // move right
    if(start.first+1<grid.size() && !visited[start.first+1][start.second] && grid[start.first+1][start.second]!=-1){

        visited[start.first+1][start.second] = true;
        uniquePathsIIIUtil(grid, {start.first+1, start.second}, finish, count_, visited, steps, currSteps+1);
        visited[start.first+1][start.second] = false;
    }
    // move left
    if(start.first-1>=0 && !visited[start.first-1][start.second] && grid[start.first-1][start.second]!=-1){

        visited[start.first-1][start.second] = true;
        uniquePathsIIIUtil(grid, {start.first-1, start.second}, finish, count_, visited, steps, currSteps+1);
        visited[start.first-1][start.second] = false;
    }

    // move up
    if(start.second+1<grid[0].size() && !visited[start.first][start.second+1] && grid[start.first][start.second+1]!=-1){

        visited[start.first][start.second+1] = true;
        uniquePathsIIIUtil(grid, {start.first, start.second+1}, finish, count_, visited, steps, currSteps+1);
        visited[start.first][start.second+1] = false;
    }

    // move up
    if(start.second-1>=0 && !visited[start.first][start.second-1] && grid[start.first][start.second-1]!=-1){

        visited[start.first][start.second-1] = true;
        uniquePathsIIIUtil(grid, {start.first, start.second-1}, finish, count_, visited, steps, currSteps+1);
        visited[start.first][start.second-1] = false;
    }



}
int uniquePathsIII(vector<vector<int>>& grid) {

    pair<int, int> start, finish;
    int steps = 0;
    int currSteps = 0;
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            if(grid[i][j]==1)
                start = {i, j};
            else if(grid[i][j]==2)
                finish = {i, j};
            if(grid[i][j]==0)
                steps++;
        }
    }

    int count_ = 0;
    vector<vector<bool> > visited(grid.size(), vector<bool>(grid[0].size(), false));
    visited[start.first][start.second] = true;
    uniquePathsIIIUtil(grid, start, finish, count_, visited, steps, currSteps);

    return count_;

}

int main(){

    vector<vector<int> > grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    cout<<uniquePathsIII(grid);

return 0;
}

