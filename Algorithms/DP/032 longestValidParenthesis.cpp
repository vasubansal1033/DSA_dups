class Solution {
public:
    int longestValidParentheses(string s) {

        if(s.size()==0) return 0;
        // find the longest valid parenthesis string 'ending' at index j

        // if ith bracket is opening, then length is 0
        // if ith bracket is closed then check Aj-1 - longest valid string ending at j-1
        // the opening bracket for curr closed bracket will be just before the start of this
        // if we have a opening bracket there, then Ai = 1+Ai-1
        // We also have to check the longest valid string before this opening bracket also.
        // else 0

        vector<int> dp(s.size(), 0);

        dp[0] = 0;
        int res = 0;
        for(int i=1; i<s.size(); i++){

            if(s[i]=='(') dp[i] = 0;
            else{

                // length of longest valid string ending at j-1
                int prevLen = dp[i-1];
                // if the bracket before this string is opening
                if(i-prevLen-1>=0 && s[i-prevLen-1]=='('){

                    dp[i] = 2+dp[i-1];

                    // add the valid string before the opening bracket also
                    if(i-prevLen-2>=0)
                        dp[i]+=dp[i-prevLen-2];

                }else{
                    dp[i] = 0;
                }

            }
            res = max(res, dp[i]);

        }


        return res;

    }
};
