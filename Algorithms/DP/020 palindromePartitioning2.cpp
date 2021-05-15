// basic MCM solution with memoization
class Solution {
public:
    bool isPalindrome(string& s, int l, int r){

        if(l==r)
            return true;

        while(l<r){

            if(s[l++]!=s[r--])
                return false;

        }

        return true;

    }
    int minCutUtil(string& s, int l, int r, vector<vector<int> >& dp){

        // single character is a palindrome
        if(l>=r )
            return 0;

        if(isPalindrome(s, l, r)){
            return dp[l][r] = 0;
        }

        if(dp[l][r]!=-1)
            return dp[l][r];

        int ans = INT_MAX;
        for(int k=l; k<r; k++){

            if(!isPalindrome(s, l, k))
                continue;

            int a = dp[l][k]==-1?dp[l][k]=minCutUtil(s, l, k, dp):dp[l][k];
            int b = dp[k+1][r]==-1?dp[k+1][r]=minCutUtil(s, k+1, r, dp):dp[k+1][r];

            int temp = a+b+1;
            ans = min(ans, temp);

        }

        return dp[l][r] =  ans;

    }
    int minCut(string s) {

        if(isPalindrome(s, 0, s.size()-1))
            return 0;
        vector<vector<int> > dp(s.size(), vector<int>(s.size(), -1));
        return minCutUtil(s, 0, s.size()-1, dp);
    }
};
