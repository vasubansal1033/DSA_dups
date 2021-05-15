class Solution {
public:

    int getOverlap(string& a, string& b){

        int n1 = a.size(), n2 = b.size();
        int ans;
        for(int i=0; i<n1; i++){

            int j=i, k=0;
            while(j<n1 && k<n2 && a[j]==b[k]){
                j++; k++;
            }
            if(j==n1){
                ans = k;
                break;
            }

        }

        return ans;
    }
    // initially prev = 0. We follow 1based indexing to store dp[mask][prev] for starting
    int util(vector<string>& A, int prev, int mask, vector<vector<int> >& dp, vector<vector<int> >& overlap, vector<vector<int> >& path){

        // base case
        if(mask == (1<<(A.size()))-1) return 0;


        if(dp[mask][prev]!=-1) return dp[mask][prev];

        int res = INT_MAX, minPath = 0;
        // recursion
        for(int i=0; i<A.size(); i++){

            if(!(mask&(1<<i))){

                int c1;
                if(prev==0){
                    c1 = A[i].size();
                }else{
                    c1 = A[i].size()-overlap[prev-1][i];
                }

                c1 += util(A, i+1, mask|(1<<i), dp, overlap, path);
                if(c1<res){
                    res = c1;
                    minPath = i;
                }

            }
        }

        path[mask][prev] = minPath;
        return dp[mask][prev] = res;

    }
    string shortestSuperstring(vector<string>& A) {

        // Step 1. first construct an overlap matrix, overlap[i][j] stores overlap length of ith and jth string
        vector<vector<int> > overlap(A.size(), vector<int>(A.size()));
        for(int i=0; i<overlap.size(); i++){
            for(int j=0; j<overlap[0].size(); j++){
                overlap[i][j] = getOverlap(A[i], A[j]);
            }
        }
        int n = A.size();

        // Step 2. DP
        vector<vector<int> > dp((1<<n), vector<int>(n+1, -1));
        vector<vector<int> > path((1<<n), vector<int>(n+1, -1));
        int res = util(A, 0, 0, dp, overlap, path);

        int mask=0, prev = 0;
        string ans = "";
        while(mask<(1<<(A.size()))-1){

            int temp = path[mask][prev];
            if(prev==0){
                ans += A[temp];
            }else{
                ans += A[temp].substr(overlap[prev-1][temp], A[temp].size()-overlap[prev-1][temp]);
            }
            mask = mask | (1<<(temp));
            prev = temp+1;

        }
        return ans;
    }
};
