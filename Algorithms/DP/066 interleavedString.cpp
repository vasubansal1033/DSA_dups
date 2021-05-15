


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        // dp[i][j] -> index i at s1
        // index j at s2
        // string s3 from 0 to i+j.
        // dp[i][j] = true if s3 from 0 to i+j can be interveved
        // by s1.substr(0, i) and s2.substr(0, j)

        if(s1.size()+s2.size()!=s3.size()) return false;

        vector<vector<bool> > dp(2, vector<bool>(s2.size()+1));
        for(int i=0; i<=s1.size(); i++){
            for(int j=0; j<=s2.size(); j++){

                if(i==0 && j==0) dp[i][j] = true;
                else if(i==0)
                    dp[i%2][j] = dp[i%2][j-1] && s2[j-1]==s3[i+j-1];
                else if(j==0)
                    dp[i%2][j] = dp[(i-1)%2][j] && s1[i-1]==s3[i+j-1];
                else
                    dp[i%2][j] = (dp[i%2][j-1] && s2[j-1]==s3[i+j-1])||(dp[(i-1)%2][j] && s1[i-1]==s3[i+j-1]);

            }
        }

        return dp[s1.size()%2][s2.size()];

    }
};


// reduced ON3 to ON2. 3 variables are redundant. 2 states are sufficient for representing unique state
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        // dp[i][j] -> index i at s1
        // index j at s2
        // string s3 from 0 to i+j.
        // dp[i][j] = true if s3 from 0 to i+j can be interveved
        // by s1.substr(0, i) and s2.substr(0, j)

        if(s1.size()+s2.size()!=s3.size()) return false;

        vector<vector<bool> > dp(s1.size()+1, vector<bool>(s2.size()+1));
        for(int i=0; i<=s1.size(); i++){
            for(int j=0; j<=s2.size(); j++){

                if(i==0 && j==0) dp[i][j] = true;
                else if(i==0)
                    dp[i][j] = dp[i][j-1] && s2[j-1]==s3[i+j-1];
                else if(j==0)
                    dp[i][j] = dp[i-1][j] && s1[i-1]==s3[i+j-1];
                else
                    dp[i][j] = (dp[i][j-1] && s2[j-1]==s3[i+j-1])||(dp[i-1][j] && s1[i-1]==s3[i+j-1]);

            }
        }

        return dp[s1.size()][s2.size()];

    }
};


typedef vector<int> v1;
typedef vector<v1> v2;
typedef vector<v2> v3;
class Solution {
public:
    bool util(string& s1, string& s2, string& s3, int i, int j, int k, v3& dp){

        // base case
        if(k==s3.size()){

            if(i==s1.size() && j==s2.size()) return dp[i][j][k] = true;
            else return dp[i][j][k] = false;

        }

        if(dp[i][j][k]!=-1) return dp[i][j][k];

        if(s3[k]==s1[i] && s3[k]==s2[j])
            return dp[i][j][k]=util(s1, s2, s3, i+1, j, k+1, dp)||util(s1, s2, s3, i, j+1, k+1, dp);
        if(s3[k]==s1[i])
            return dp[i][j][k]=util(s1, s2, s3, i+1, j, k+1, dp);
        if(s3[k]==s2[j])
            return dp[i][j][k]=util(s1, s2, s3, i, j+1, k+1, dp);

        return dp[i][j][k] = false;

    }
    bool isInterleave(string s1, string s2, string s3) {

        v3 dp(s1.size()+5, v2(s2.size()+5, v1(s3.size()+5, -1)));
        return util(s1, s2, s3, 0, 0, 0, dp);

    }
};
