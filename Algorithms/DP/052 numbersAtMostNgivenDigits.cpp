class Solution {
public:
    int util(vector<string>& D, string& N1, int idx, bool equal, vector<vector<int> >& dp){

        // base case
        // incase of empty string
        if(idx<0){
            return equal?1:0;
        }
        if(dp[idx][equal]!=-1) return dp[idx][equal];

        int s1 = 0, s2 = 0;
        for(int j=0; j<D.size(); j++){

            if(D[j][0]-'0' < N1[idx]-'0') s1++;
            if(D[j][0]-'0' > N1[idx]-'0') continue;
            if(D[j][0]-'0' == N1[idx]-'0') s2++;

        }

        if(equal){
            return dp[idx][equal] = util(D, N1, idx-1, equal, dp)*s2;
        }else{
            dp[idx][equal] = util(D, N1, idx-1, equal, dp)*D.size();
            dp[idx][equal] += util(D, N1, idx-1, !equal, dp)*s1;

            return dp[idx][equal];
        }


    }
    int atMostNGivenDigitSet(vector<string>& D, int N) {

        string strN = to_string(N);

        int res = 0, prod = 1;
        vector<vector<int> > dp(10, vector<int>(2, -1));
        for(int i=1; i<=strN.size(); i++){

            prod *= D.size();
            if(i<strN.size()){
                res += prod;
            }else{
                res+= util(D, strN, strN.size()-1, 0, dp); // strN.size() digit numbers <= N
                res+= util(D, strN, strN.size()-1, 1, dp); // strN.size() digit numbers == N
            }

        }

        return res;

    }
};
