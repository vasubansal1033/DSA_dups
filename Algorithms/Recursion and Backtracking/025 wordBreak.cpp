class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        // subproblem is suffix array here
        // eg leetcode
        // l, le, lee are not present. leet is present. so remaining problem is code
        // this is a suffix array
        // smallest subproblem therefore is the last character

        // for O(1) lookup
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        vector<bool> dp(s.size(), false);
        dp[s.size()-1] = dict.find(s.substr(s.size()-1, 1))==dict.end()?false:true;

        string word;
        for(int i=s.size()-2; i>=0; i--){

            word = "";
            for(int j=i; j<s.size(); j++){
                word += s[j];

                if(dict.find(word)==dict.end())
                    continue;

                // word is present
                if(j==s.size()-1 || dp[j+1]){
                    dp[i] = true;
                    break; // break, as we found the curr word in string and the suffix is also breakable
                }


            }

        }

        return dp[0];


    }
};
