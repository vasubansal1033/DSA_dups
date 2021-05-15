// n2logk solution
class Solution {
public:
    int superEggDrop(int k, int n) {

        vector<vector<int> > dp(k+1, vector<int>(n+1, INT_MAX));

        // if number of floors is 0 -> we dont need any move. If given one floor, we can only use 1 move
        // if we have 1 egg, it'll break at top in the worst case.
        for(int i=0; i<=k; i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        for(int j=0; j<=n; j++)
            dp[1][j] = j;


        for(int i=2; i<=k; i++){
            for(int j=2; j<=n; j++){

                int lo(1), hi(j);
                while(lo<hi){

                    int mid = lo+(hi-lo)/2;
                    int left = dp[i-1][mid-1];
                    int right = dp[i][j-mid];

                    if(left<right)
                        lo = mid+1;
                    else
                        hi = mid;

                }
                dp[i][j] = 1+max(dp[i-1][lo-1], dp[i][j-lo]);


//                 for(int m=1; m<=j; m++){

//                     dp[i][j] = min(dp[i][j], 1+max(dp[i-1][m-1], dp[i][j-m]));


//                     // // taking maximum moves taken when egg is broken or not broken(for worst case consideration)
//                     // int temp = 1+max(dp[i-1][m-1], dp[i][j-m]);
//                     // // we have to minimize the number of moves
//                     // dp[i][j] = min(dp[i][j], temp);



//                 }

            }
        }

        return dp[k][n];

    }
};




// DP memoized
class Solution {
public:
    int superEggDropUtil(int k, int n, vector<vector<int> >& dp){

        // base case
        // if eggs are 1

        if(n<=1)
            return dp[k][n] = n;
        if(k==1)
            return dp[k][n] = n;
        // if floors are 0 or 1


        if(dp[k][n]!=-1)
            return dp[k][n];

        int res = INT_MAX;
        for(int j=1; j<=n; j++){

            // case when egg broke
            int a = dp[k-1][j-1]!=-1?dp[k-1][j-1]:superEggDropUtil(k-1, j-1, dp);
            // case when egg doesnot break
            int b = dp[k][n-j]!=-1?dp[k][n-j]:superEggDropUtil(k, n-j, dp);

            // we have to consider the worst case for total attempts
            int temp = 1+max(a, b);
            res = min(res, temp);
        }

        return dp[k][n] = res;

    }
    int superEggDrop(int K, int N) {

        vector<vector<int> > dp(K+1, vector<int>(N+1, -1));
        return superEggDropUtil(K, N, dp);

    }
};
