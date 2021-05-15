// O(n*n*m) solution

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

    for(int k=0; k<mat.size()-1; k++){
        for(int i=0; i<mat.size()-1; i++){
            for(int j=0; j<mat[0].size()-1; j++){
                if(mat[i][j]>mat[i+1][j+1])
                    swap(mat[i][j], mat[i+1][j+1]);
            }
        }
    }

    return mat;
}
