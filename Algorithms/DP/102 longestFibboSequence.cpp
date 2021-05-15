class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_map<int, int> m;
        for(int i=0; i<A.size(); i++) m[A[i]] = i;

        int dp[A.size()][A.size()];
        memset(dp, 0, sizeof(dp));

        int res = 0;
        for(int i=0; i<A.size(); i++){
            for(int j=i-1; j>=0; j--){

                if(A[i]-A[j]<A[j] && m.count(A[i]-A[j])){

                    int k = m[A[i]-A[j]]; // k->A[i]-A[j], A[j], A[i] forming fibbo sequence
                    dp[j][i] = dp[k][j]+1;
                    res = max(res, dp[j][i]);
                }

            }
        }

        return res+2>2?res+2:0;

    }
};
