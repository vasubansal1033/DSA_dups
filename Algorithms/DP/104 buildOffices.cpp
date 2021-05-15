/*
As per the given constraint, the matrix size (w*h) cannot exceed 28
which is fairly a small number. Also, the maximum possible value for n is 5.
From little knowledge of combinatorics, we know that there are 28C5 ways
of selecting 5 lots from the given grid at the worst case.
The figure evaluates to 98280 which is a sufficiently a small space
to search over with memoization. Since the maximum value for w*h is 28,
we can represent the entire grid in a single integer bit-mask which along
with the number of building lot left to be set up will form the states of our DP.
To calculate the farthest leftover lot for the end state,
we make use of a Breadth First Search (BFS) by initializing the queue with all points
where we've set up a building.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> dx(4), dy(4);
int w, h, n;

// converts i, j position to position in bitmask
int getIndex(int i, int j){

    if(w<=h) return i+(w*j);
    else return (h*i)+j;

}
// checks whether i, j position in mask is set or not
bool check(int mask, int i, int j){
    return mask&(1<<getIndex(i, j));
}
bool valid(int newX, int newY){

    if(newX>=0 && newY>=0 && newX<w && newY<h){
        return true;
    }
    return false;

}
int bfs(int mask){

    int grid[w][h];
    memset(grid, -1, sizeof(int)*w*h);

    int maxDist = INT_MIN;
    queue<pair<int, int> > q;
    for(int i=0; i<w; i++){
        for(int j=0; j<h; j++){
            if(check(mask, i, j)){
                grid[i][j] = 0;
                q.push({i, j});
            }
        }
    }

//    assert(q.size()==n);

    while(!q.empty()){

        int x = q.front().first, y = q.front().second;
        q.pop();
        maxDist = max(maxDist, grid[x][y]);

        for(int i=0; i<4; i++){
            int newX = x+dx[i];
            int newY = y+dy[i];

            if(!valid(newX, newY)) continue;
            if(grid[newX][newY]==-1){
                grid[newX][newY] = grid[x][y]+1;
                q.push({newX, newY});
            }


        }

    }

    return maxDist;

}

// mask representing the grid, and n is number of offices
map<pair<int, int>, int> dp;
int buildOffice(int mask, int n){

    if(n==0) return bfs(mask);
    if(dp.count({mask, n})) return dp[{mask, n}];

    int minDist = INT_MAX;
    for(int i=0; i<w; i++){
        for(int j=0; j<h; j++){
            if(!check(mask, i, j)){
                int dist = buildOffice(mask|(1<<getIndex(i, j)), n-1);
                minDist = min(minDist, dist);
            }
        }
    }

    return dp[{mask, n}] = minDist;
}

int main(){

    cin>>w>>h>>n; // r = rows, c = cols, n = number of offices
    dx = {1, -1, 0, 0};
    dy = {0, 0, -1, 1};

    dp.clear();
    cout<<buildOffice(0, n);

return 0;
}



/*

//This is a simple brute force soln that passed all test cases.

#include <bits/stdc++.h>

using namespace std;

#define pi pair<int, int>

int minDist(int w, int h, vector<pi> arr){

    int res = 0;

    // for(auto it: arr) cout<<it.first<<" "<<it.second<<endl;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int k1 = 10000;
            for(auto it: arr){
                int k = abs(i - it.first) + abs(j - it.second);
                k1 = min(k1, k);
            }
            res = max(k1, res);
        }
    }

    return res;
}


int findMinDistance(int w, int h, int n) {

    vector<pi> points;

    int ans = INT_MAX;
    int tot = w*h;

    for(int i = 0; i < tot; i++){
        int xi = i/w, yi = i%w;
        points.push_back({xi, yi});
        if(n == 1) ans = min(ans, minDist(w, h, points));
        if(n > 1){
            for(int j = i+1; j < tot; j++){
                int xj = j/w, yj = j%w;
                points.push_back({xj, yj});
                if(n == 2) ans = min(ans, minDist(w, h, points));
                if(n > 2){
                    for(int k = j+1; k < tot; k++){
                        int xk = k/w, yk = k%w;
                        points.push_back({xk, yk});
                        if(n == 3) ans = min(ans, minDist(w, h, points));
                        if(n > 3){
                            for(int l = k+1; l < tot; l++){
                                int xl = l/w, yl = l%w;
                                points.push_back({xl, yl});
                                if(n == 4) ans = min(ans, minDist(w, h, points));
                                if(n > 4){
                                    for(int m = l+1; m < tot; m++){
                                        int xm = m/w, ym = m%w;
                                        points.push_back({xm, ym});
                                        ans = min(ans, minDist(w, h, points));
                                        points.pop_back();
                                    }
                                }
                                points.pop_back();
                            }
                        }
                        points.pop_back();
                    }
                }
                points.pop_back();
            }
        }
        points.pop_back();
    }


    return ans;
}
*/
