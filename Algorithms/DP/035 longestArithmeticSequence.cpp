// Reversed the second innerloop, leads to better optimization
// Latest common difference will have longest sequence
// So no need of taking max
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {

        // dp[i] contains a map, which stores all the c.d of nums[i] with prev elements and the length of the respected sequence
        vector<unordered_map<int, int> > dp(A.size());
        int res = 0;

        for(int i=0; i<A.size(); i++){

            for(int k=0; k<i; k++){

                int cd = A[i]-A[k];
                if(dp[k].find(cd)!=dp[k].end())
                    dp[i][cd] =  1+dp[k][cd];
                else{
                    dp[i][cd] =  2;
                }

                res = max(res, dp[i][cd]);

            }



        }

        return res;

    }
};


// O(N2)
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {

        // dp[i] contains a map, which stores all the c.d of nums[i] with prev elements and the length of the respected sequence
        vector<unordered_map<int, int> > dp(A.size());
        int res = 0;

        for(int i=0; i<A.size(); i++){

            for(int k=i-1; k>=0; k--){

                int cd = A[i]-A[k];
                if(dp[k].find(cd)!=dp[k].end())
                    dp[i][cd] = max(dp[i][cd], 1+dp[k][cd]);
                else{
                    dp[i][cd] = max(dp[i][cd], 2);
                }

                res = max(res, dp[i][cd]);

            }



        }

        return res;

    }
};
