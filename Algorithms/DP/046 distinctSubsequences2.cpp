class Solution {
public:
    int distinctSubseqII(string s) {

        // Two choices -> include/exclude current character
        // If excluded then -> dp[i] = dp[i-1]
        // If included, then two cases -> first occurence or already occured
        // If first occurence, then we add it at the end of all the previous subsequences(dp[i-1]) and also considered it alone(1). So dp[i-1]+1.

        // If already occured, we add it to all the previous subsequences, dp[i-1].
        // However, we have to remove those cases in which its latest previous occurence was not considered, as we would again add the current occurence in those leading to duplication of cases where the previous occurence was considered.

        // To do this, find this latest previous occurence, say at j. We have to find the number of subsequences in which this occurence was not considered, which is dp[j-1].
        // So total are dp[i] += (dp[i-1]-dp[j-1])

        vector<int> dp(s.size());
        unordered_map<char, int> visited;
        int mod = pow(10, 9)+7;

        dp[0] = 1;
        visited[s[0]] = 0;

        for(int i=1; i<s.size(); i++){

            // Exclude the current character
            dp[i] = dp[i-1];

            // If character is new
            if(visited.find(s[i])==visited.end())
                // add the current character to all previous subsequences and only current character(1)
                dp[i] = (dp[i] + dp[i-1]+1)%mod;
            else{
                // If the character is occured again
                int j = visited[s[i]];
                // Find the previous occurence before the current one
                // Now we cannot consider the only current character case, so we don't add 1.
                // From the previous occurence(j), find the number of subsequences in which it was excluded which is dp[j-1].
                if(j==0){
                    dp[i] = (dp[i] + dp[i-1])%mod;
                }else{
                    dp[i] = ((dp[i] + dp[i-1])%mod+(mod-dp[j-1]))%mod;
                }

            }

            visited[s[i]] = i;
        }

        return dp[s.size()-1];

    }
};
