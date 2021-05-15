class Solution {
public:
    int countSetBits(int n){

        int cnt = 0;
        while(n){
            n = n&(n-1);
            cnt++;
        }
        return cnt;

    }
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {

        int dp[s.size()+1];
        dp[0] = 0;

        for(int i=0; i<s.size(); i++){
            dp[i+1] = (dp[i]^(1<<(s[i]-'a')));
        }

        vector<bool> res;
        for(int i=0; i<queries.size(); i++){

            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];

            int temp = countSetBits(dp[r+1]^dp[l]);
            if(k>=(temp/2)) res.push_back(true);
            else res.push_back(false);

        }

        return res;

    }
};
