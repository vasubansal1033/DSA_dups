// minimum number of insertions and minimum number of deletions will be the same
// these questions are same as the longest palindromic subsequence

class Solution {
public:
    int minInsertions(string s) {

        int dp[s.size()][s.size()];

        memset(dp, 0, sizeof(dp));
        for(int i=0; i<s.size(); i++){
            dp[i][i] = 1;
        }

        for(int i=s.size()-2; i>=0; i--){

            for(int j=i+1; j<s.size(); j++){

                if(s[i]==s[j])
                    dp[i][j] = 2+dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);

            }

        }

        return s.size()-dp[0][s.size()-1];

    }
};
