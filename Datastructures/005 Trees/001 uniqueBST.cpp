class Solution {
public:

    int fun(int n, vector<int>& dp){

        if(n==1)
            return dp[1] = 1;
        if(dp[n]!=-1)
            return dp[n];

        int sum = 0;

        if(dp[n-1]==-1){
            dp[n-1] = fun(n-1, dp);
            sum += dp[n-1]*2;
        }

        else sum+= dp[n-1]*2;

        for(int k=1; k<=n-2; k++){

            int a, b;
            if(dp[n-1-k]!=-1)
                a=dp[n-1-k];
            else{
                dp[n-1-k] = fun(n-1-k, dp);
                a=dp[n-1-k];
            }

            if(dp[k]!=-1)
                b=dp[k];
            else{
                dp[k]=fun(k, dp);
                b=dp[k];
            }
            sum+=a*b;

        }

        return dp[n] = sum;

    }
    int numTrees(int n) {

//         if(n==1)
//             return 1;

//         int sum = 0;

//         sum += numTrees(n-1)*2;
//         for(int k=1; k<=n-2; k++){
//             sum += numTrees(n-1-k)*numTrees(k);
//         }

//         return sum;
        vector<int> dp(n+1, -1);
        return fun(n, dp);
    }
};
