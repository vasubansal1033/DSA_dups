class Solution {
public:

    void dfs(vector<vector<int>>& A, int x, int y){

        if(x<0 || y<0 || x>=A.size() || y>=A[0].size() || A[x][y]==0)
            return;

        A[x][y] = 0;
        dfs(A, x+1, y);
        dfs(A, x-1, y);
        dfs(A, x, y+1);
        dfs(A, x, y-1);


    }
    int numEnclaves(vector<vector<int>>& A) {


        for(int i=0; i<A.size(); i++){

            if(A[i][0]==1)
                dfs(A, i, 0);
            if(A[i][A[0].size()-1]==1)
                dfs(A, i, A[0].size()-1);

        }
        for(int j=0; j<A[0].size(); j++){

            if(A[0][j]==1)
                dfs(A, 0, j);
            if(A[A.size()-1][j]==1)
                dfs(A, A.size()-1, j);

        }

        int cnt = 0;
        for(int i=0; i<A.size(); i++){
            for(int j=0; j<A[0].size(); j++)
                if(A[i][j]==1) cnt++;
        }

        return cnt;
    }
};
