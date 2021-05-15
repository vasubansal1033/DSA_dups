#include<bits/stdc++.h>
using namespace std;
// O(n+m) solution
bool searchMatrix(vector<vector<int>>& matrix, int target) {

    if(matrix.size()==0 || matrix[0].size()==0)
        return false;
    int i(0), j(matrix[0].size()-1);
    while(i<matrix.size() && j>=0){

        if(matrix[i][j]==target)
            return true;
        if(matrix[i][j]>target)
            j--;
        else if(matrix[i][j]<target)
            i++;

    }
    return false;

}
