class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        if(matrix.size()==0) return 0;

        int dp[2][matrix[0].size()];

        int res = 0;

//         for(int i=0; i<matrix.size(); i++){
//             if(matrix[i][0]=='1') res = dp[i][0] = 1;
//             else dp[i][0] = 0;
//         }
//         for(int j=0; j<matrix[0].size(); j++){
//             if(matrix[0][j]=='1') res = dp[0][j] = 1;
//             else dp[0][j] = 0;
//         }


        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){

                if(i==0 || j==0 || matrix[i][j]=='0'){

                    dp[i%2][j] = matrix[i][j]-'0';

                }else{

                    dp[i%2][j] = min(dp[i%2][j-1], min(dp[(i-1)%2][j-1], dp[(i-1)%2][j]))+1;

                }

                res = max(res, dp[i%2][j]);
            }


        }

        return res*res;
    }
};


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        if(matrix.size()==0) return 0;

        int dp[matrix.size()][matrix[0].size()];

        int res = 0;

//         for(int i=0; i<matrix.size(); i++){
//             if(matrix[i][0]=='1') res = dp[i][0] = 1;
//             else dp[i][0] = 0;
//         }
//         for(int j=0; j<matrix[0].size(); j++){
//             if(matrix[0][j]=='1') res = dp[0][j] = 1;
//             else dp[0][j] = 0;
//         }


        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){

                if(i==0 || j==0 || matrix[i][j]=='0'){

                    dp[i][j] = matrix[i][j]-'0';

                }else{

                    dp[i][j] = min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j]))+1;

                }

                res = max(res, dp[i][j]);
            }


        }

        return res*res;
    }
};


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        if(matrix.size()==0) return 0;

        int dp[matrix.size()][matrix[0].size()];

        int res = 0;

        for(int i=0; i<matrix.size(); i++){
            if(matrix[i][0]=='1') res = dp[i][0] = 1;
            else dp[i][0] = 0;
        }
        for(int j=0; j<matrix[0].size(); j++){
            if(matrix[0][j]=='1') res = dp[0][j] = 1;
            else dp[0][j] = 0;
        }


        for(int i=1; i<matrix.size(); i++){
            for(int j=1; j<matrix[0].size(); j++){

                if(matrix[i][j]=='1'){

                    dp[i][j] = min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j]))+1;

                }else
                    dp[i][j] = 0;

                res = max(res, dp[i][j]);
            }


        }

        return res*res;
    }
};
