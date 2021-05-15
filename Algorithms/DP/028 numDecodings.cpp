class Solution {
public:
    int numDecodings(string s) {

        vector<int> dp(s.size()+1, 0);

        dp[s.size()] = 1; // empty string can be decoded in 1 way
        dp[s.size()-1] = s[s.size()-1]=='0'?0:1;

        for(int i=s.size()-2; i>=0; i--){

            if(s[i]=='0'){
                dp[i] = 0;
                continue;
            }
            dp[i] = dp[i+1];

            if(s[i]=='1' || (s[i]=='2' && s[i+1]>='0' && s[i+1]<='6'))
                dp[i] += dp[i+2];

        }


        return dp[0];

    }
};
