// space optimized DP
class Solution {
public:
    int longestPalindromeSubseq(string s) {

        if(s.size()==1) return 1;

        vector<vector<int> > dp(2, vector<int>(s.size(), 0));

        for(int i=s.size()-2; i>=0; i--){

            for(int j=i+1; j<s.size(); j++){

                if(s[i]==s[j]){

                    dp[i%2][j] = (i+1!=j-1)?2+dp[(i+1)%2][j-1]:3;

                }

                else
                    dp[i%2][j] = max((i+1!=j)?dp[(i+1)%2][j]:1, (i!=j-1)?dp[i%2][j-1]:1);

            }

        }

        return dp[0][s.size()-1];

    }
};



// DP solution
class Solution {
public:
    int longestPalindromeSubseq(string s) {

        vector<vector<int> > dp(s.size(), vector<int>(s.size(), 0));
        for(int i=0; i<s.size(); i++)
            dp[i][i] = 1;

        for(int i=s.size()-2; i>=0; i--){

            for(int j=i+1; j<s.size(); j++){

                if(s[i]==s[j])
                    dp[i][j] = 2+dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);

            }

        }

        return dp[0][s.size()-1];

    }
};


// First approach -> longest palindromic sequence will be the lcs of original string with reversed string
class Solution {
public:

    int lcs(string& text1, string& text2) {

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

    int longestPalindromeSubseq(string s) {

        string t(s.rbegin(), s.rend());
        return lcs(s, t);

    }
};
