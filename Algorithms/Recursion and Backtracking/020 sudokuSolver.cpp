class Solution {
public:
    void solveSudokuUtil(vector<vector<bool> >& row, vector<vector<bool> >& col, vector<vector<bool> >& box, int rowId, int colId, vector<vector<char> >& currBoard, vector<vector<char> >& res){

        // base case
        if(rowId == 9 && colId ==0){
            res = currBoard;
            return;
        }
        if(rowId>8 || colId>8){
            return;
        }

        if(currBoard[rowId][colId]!='.'){

                if(colId==8){
                    solveSudokuUtil(row, col, box, rowId+1, 0, currBoard, res);
                }else{
                    solveSudokuUtil(row, col, box, rowId, colId+1, currBoard, res);
                }

            return;

        }

        // Recursion
        for(int i=1; i<=9; i++){

            if(!row[rowId][i-1] && !col[colId][i-1] && !box[3*(rowId/3)+colId/3][i-1]){

                currBoard[rowId][colId] = (char)('0'+i);
                row[rowId][i-1] = true;
                col[colId][i-1] = true;
                box[3*(rowId/3)+colId/3][i-1] = true;

                if(colId==8){
                    solveSudokuUtil(row, col, box, rowId+1, 0, currBoard, res);
                }else{
                    solveSudokuUtil(row, col, box, rowId, colId+1, currBoard, res);
                }

                currBoard[rowId][colId] = '.';
                row[rowId][i-1] = false;
                col[colId][i-1] = false;
                box[3*(rowId/3)+colId/3][i-1] = false;




            }

        }

    }
    void solveSudoku(vector<vector<char>>& board) {

        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> box(9, vector<bool>(9, false));
        vector<vector<char> > currBoard = board;

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){

                if(board[i][j]!='.'){
                    row[i][board[i][j]-'0'-1] = true;
                    col[j][board[i][j]-'0'-1] = true;
                    box[3*(i/3)+j/3][board[i][j]-'0'-1] = true;
                }

            }
        }
        solveSudokuUtil(row, col, box, 0, 0, currBoard, board);


    }
};
