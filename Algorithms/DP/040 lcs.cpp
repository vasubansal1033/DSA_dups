class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        vector<vector<int> > dp(2, vector<int>(text2.size()+1, 0));

        for(int i = text1.size()-1; i>=0; i--){

            for(int j = text2.size()-1; j>=0; j--){

                if(text1[i] == text2[j])
                    dp[i%2][j] = dp[(i+1)%2][j+1]+1;
                else
                    dp[i%2][j] = max(dp[(i+1)%2][j], dp[i%2][j+1]);

            }

        }

        return dp[0][0];

    }
};


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        vector<vector<int> > dp(text1.size()+1, vector<int>(text2.size()+1, 0));

        for(int i = text1.size()-1; i>=0; i--){

            for(int j = text2.size()-1; j>=0; j--){

                if(text1[i] == text2[j])
                    dp[i][j] = dp[i+1][j+1]+1;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);

            }

        }

        return dp[0][0];

    }
};
