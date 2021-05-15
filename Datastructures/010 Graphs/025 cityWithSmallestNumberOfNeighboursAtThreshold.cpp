class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int> > dp(n, vector<int>(n, 0));

        for(int i=0; i<edges.size(); i++){

            dp[edges[i][0]][edges[i][1]] = edges[i][2];
            dp[edges[i][1]][edges[i][0]] = edges[i][2];

        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j || dp[i][j]!=0)
                    continue;

                dp[i][j] = 10009;
            }
        }


        for(int k=0; k<n; k++){

            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
                }
            }

        }

        int res = 0;
        int cities = 0;
        for(int j=0; j<n; j++){

            if(dp[0][j]>0 && dp[0][j]<=distanceThreshold)
                    cities++;

        }

        for(int i=1; i<n; i++){

            int sum = 0;
            for(int j=0; j<n; j++){

                if(dp[i][j]>0 && dp[i][j]<=distanceThreshold)
                    sum++;

            }
            if(sum<=cities){
                cities = sum;
                res = i;
            }


        }

        return res;

    }
};
