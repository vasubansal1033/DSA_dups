class Solution {
public:

    void solveNQueensUtil(int row, vector<bool>& cols, vector<bool>& d1, vector<bool>& d2, vector<vector<string> >& result, vector<string>& currSol){

        // base case
        if(row<0){
            result.push_back(currSol);
            return;
        }

        int n = cols.size();

        for(int i=0; i<n; i++){

            if(!cols[i] && !d1[row-i+n-1] && !d2[row+i]){

                currSol[row][i] = 'Q';
                cols[i] = true; d1[row-i+n-1] = true; d2[row+i] = true;
                solveNQueensUtil(row-1, cols, d1, d2, result, currSol);
                currSol[row][i] = '.';

                cols[i] = false; d1[row-i+n-1] = false; d2[row+i] = false;


            }

        }


    }
    vector<vector<string>> solveNQueens(int n) {

        vector<bool> cols(n, false), d1(2*n-1, false), d2(2*n-1, false);
        vector<vector<string> > result;

        vector<string> currSol(n, string(n, '.'));

        solveNQueensUtil(n-1, cols, d1, d2, result, currSol);

        return result;

    }
};
