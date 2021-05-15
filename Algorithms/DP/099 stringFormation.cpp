// Leetcode 1639 - Number of ways to form a target string from a dictionary

// space optimized solution
class Solution {
public:
    int numWays(vector<string>& words, string target) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // freq[i][j] stores frequency of j(j=0 means a) character at ith index in list of words
        int freq[words[0].size()][26];
        int mod = 1e9+7;

        memset(freq, 0, sizeof(freq));

        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words[0].size(); j++){
                freq[j][words[i][j]-'a']++;
            }
        }

        long int dp[2][target.size()+1];

        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for(int i=1; i<=words[0].size(); i++){
            dp[i&1][0] = 1;
            for(int j=1; j<=target.size(); j++)
                dp[i&1][j] = (dp[(i-1)&1][j] + dp[(i-1)&1][j-1]*freq[i-1][target[j-1]-'a'])%mod;

        }

        return dp[(words[0].size())&1][target.size()];
    }
};


class Solution {
public:
    int numWays(vector<string>& words, string target) {

        // freq[i][j] stores frequency of j(j=0 means a) character at ith index in list of words
        int freq[words[0].size()][26];
        int mod = 1e9+7;

        memset(freq, 0, sizeof(freq));

        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words[0].size(); j++){
                freq[j][words[i][j]-'a']++;
            }
        }

        long int dp[words[0].size()+1][target.size()+1];

        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for(int i=1; i<=words[0].size(); i++){
            dp[i][0] = 1;
            for(int j=1; j<=target.size(); j++)
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]*freq[i-1][target[j-1]-'a'])%mod;

        }

        return dp[words[0].size()][target.size()];
    }
};
