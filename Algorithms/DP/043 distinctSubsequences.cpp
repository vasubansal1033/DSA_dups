// reverse the ordering of j loop, so that we can use just 1 row
class Solution {
public:
    int numDistinct(string s, string t) {

        if(s.size()==0 || t.size()==0) return 0;

        vector<unsigned int> dp(t.size()+1, 0);

        dp[0] = 1;

        for(int i=1; i<=s.size(); i++){

            for(int j=t.size(); j>=1; j--){

                if(s[i-1]==t[j-1])
                    dp[j] = dp[j-1]+dp[j];
                else
                    dp[j] = dp[j];

            }

        }

        return dp[t.size()];

    }
};


class Solution {
public:
    int numDistinct(string s, string t) {

        if(s.size()==0 || t.size()==0) return 0;

        vector<vector<unsigned int> > dp(2, vector<unsigned int>(t.size()+1, 0));

        dp[0][0] = dp[1][0] = 1;

        for(int i=1; i<=s.size(); i++){

            for(int j=1; j<=t.size(); j++){

                if(s[i-1]==t[j-1])
                    dp[i%2][j] = dp[(i-1)%2][j-1]+dp[(i-1)%2][j];
                else
                    dp[i%2][j] = dp[(i-1)%2][j];

            }

        }

        return dp[s.size()%2][t.size()];

    }
};

class Solution {
public:
    int numDistinct(string s, string t) {

        if(s.size()==0 || t.size()==0) return 0;

        vector<vector<unsigned int> > dp(s.size()+1, vector<unsigned int>(t.size()+1, 0));

        for(int i=0; i<=s.size(); i++)
            dp[i][0] = 1;

        for(int i=1; i<=s.size(); i++){

            for(int j=1; j<=t.size(); j++){

                if(s[i-1]==t[j-1])
                    dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];

            }

        }

        return dp[s.size()][t.size()];

    }
};
