class Solution {
public:

    void totalNQueensUtil(int row, vector<bool>& cols, vector<bool>& d1, vector<bool>& d2, int& count){

        // base case
        if(row<0){
            count++;
            return;
        }

        // place queen at row and recursive call for every valid position
        // d1 is any principal diagonal. See i-j for every possible diagonal.
        // d2 is the other diagonal. See i+j of every diagonal
        // Use i-j and i+j to check if that diagonal is available
        int n = cols.size();
        for(int i=0; i<n; i++){

            if(!cols[i] && !d1[row-i+n-1] && !d2[row+i]){

                cols[i] = true; d1[row-i+n-1] = true; d2 [row+i] = true;
                totalNQueensUtil(row-1, cols, d1, d2, count);
                cols[i] = false; d1[row-i+n-1] = false; d2 [row+i] = false;

            }

        }


    }
    int totalNQueens(int n) {

        int count = 0;
        vector<bool> cols(n, false);
        vector<bool> d1(2*n-1, false);
        vector<bool> d2(2*n-1, false);

        totalNQueensUtil(n-1, cols, d1, d2, count);

        return count;

    }
};
