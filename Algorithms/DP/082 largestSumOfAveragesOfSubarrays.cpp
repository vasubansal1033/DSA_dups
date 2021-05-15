class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {

        if(K==1){
            return accumulate(A.begin(), A.end(), 0)*1.0/A.size();
        }
        if(K>=A.size()) return accumulate(A.begin(), A.end(), 0);

        int sum  = 0;
        vector<int> prefixSum(A.size()+1);
        prefixSum[0] = 0;
        for(int i=1; i<A.size()+1; i++) prefixSum[i] = A[i-1]+prefixSum[i-1];

        double dp[A.size()+1][K+1];
        memset(dp, 0.0, sizeof(dp));

        for(int i=1; i<=A.size(); i++)
            dp[i][1] = (1.0)*prefixSum[i]/(i);

        // Essentially, we dont need to calculate answers for dp[i][k] for i<k as it will result in sum of numbers from that index
        for(int k=2; k<=K; k++){
            for(int i=k; i<=A.size(); i++){
                for(int j=i-1; j>=k-1; j--){

                    dp[i][k] = max(dp[i][k], dp[j][k-1]+(prefixSum[i]-prefixSum[j])*1.0/(i-j));

                }
            }
        }

        for(int i=0; i<=A.size(); i++){
            for(int j=0; j<=K; j++)
                cout<<dp[i][j]<<" ";
            cout<<'\n';
        }

        return dp[A.size()][K];

    }

};



class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {

        if(K==1){
            return 1.0*accumulate(A.begin(), A.end(), 0)/A.size();
        }
        if(K>=A.size())
            return accumulate(A.begin(), A.end(), 0);

        // dp[i][k] -> largest sum of average from 0 to i, with atmost k groups
        // dp[i][k] = max(dp[i][k], dp[j][k-1]+average of array from j+1 to i). j less than i
        // sum of array from j+1 to i = prefixSum[i]-prefixSum[j]
        vector<int> prefixSum(A.size()+1);
        prefixSum[0] = 0;
        for(int i=1; i<A.size()+1; i++) prefixSum[i] = prefixSum[i-1]+A[i-1];

        double dp[A.size()+1][K+1];
        memset(dp, 0.0, sizeof(dp));

        // K=0, invalid input. K=1, average of sum till that index
        for(int i=1; i<A.size()+1; i++)
            dp[i][1] = 1.0*prefixSum[i]/i;

        for(int k=2; k<=K; k++){
            for(int i=2; i<=A.size(); i++){

                for(int j=i-1; j>=0; j--)
                    dp[i][k] = max(dp[i][k], dp[j][k-1]+1.0*(prefixSum[i]-prefixSum[j])/(i-j));

            }
        }

        return dp[A.size()][K];

    }
};
