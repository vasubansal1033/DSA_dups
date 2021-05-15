class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        int size = strs.size();

        // track zero and one count of strs[i] string
        int freqCount[strs.size()];
        memset(freqCount, 0, sizeof(freqCount));

        // populate zero and one count of strings in strs
        for(int i=0;i<size;i++){

            for(int j=0; j<strs[i].size(); j++)
                if(strs[i][j]=='0') freqCount[i]++;

        }

        // M*N dp vector where dp[i][j] track max largest subset possible for m = i and n = j
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));

        // loop through the strings of strs (consider each string once)
        for(int k=0;k<size;k++){
            int zc = freqCount[k];
            int oc = strs[k].size()-freqCount[k];

            // generate result from target <m,n> to <zc,oc>
            for(int i=m;i>=zc;i--){
                for(int j=n;j>=oc;j--){
                    // ignore <0,0> state
                    if(i==0 && j==0) continue;

                    // get largest subset possible for dp[i][j]
                    dp[i][j] = max(dp[i][j], dp[i-zc][j-oc]+1);
                }
            }
        }

        // largest subset possible for target <m,n> => <zero,one>
        return dp[m][n];
    }
};


class Solution {
public:
    int dp[101][101][601];
    int zeros[601], ones[601];

    int util(vector<string>& strs, int m, int n, int start){

        // base case
        if(start==strs.size()){
            return dp[m][n][start] = 0;
        }
        if(dp[m][n][start]!=-1){
            return dp[m][n][start];
        }

        // exclude
        int ans1 = util(strs, m, n, start+1);

        // include
        int ans2 = INT_MIN;
        int z = zeros[start], o = ones[start];
        if(m>=z && n>=o)
            ans2 = 1+util(strs, m-z, n-o, start+1);

        return dp[m][n][start] = max(ans1, ans2);

    }
    int findMaxForm(vector<string>& strs, int m, int n) {

        memset(dp, -1, sizeof(dp));
        memset(zeros, 0, sizeof(zeros));
        memset(ones, 0, sizeof(ones));

        for(int i=0; i<strs.size(); i++){
            for(int j=0; j<strs[i].size(); j++){
                if(strs[i][j]=='0') zeros[i]++;
                else ones[i]++;
            }
        }

        return util(strs, m, n, 0);

    }
};
