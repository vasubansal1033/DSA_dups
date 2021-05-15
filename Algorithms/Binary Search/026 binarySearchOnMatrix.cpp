#include<bits/stdc++.h>
using namespace std;

int matToArray(vector<vector<int> >& matrix, int i){
    int n = matrix[0].size();
    return matrix[i/n][i%n];
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {

    if(matrix.size()==0||matrix[0].size()==0)
        return 0;
    // a[i] = matrix[i/n][i%n]

    int rows = matrix.size();
    int cols = matrix[0].size();

    int lo = 0;
    int hi = rows*cols-1;

    while(lo<hi){

        int mid = lo+(hi-lo)/2;

        if(matToArray(matrix, mid)>=target)
            hi = mid;
        else
            lo = mid+1;

    }

    return matrix[lo/cols][lo%cols]==target;

}

int main(){

    int rows, cols; cin>>rows>>cols;
    vector<vector<int> > matrix(rows, vector<int>(cols, 0));
    for(int i=0; i<rows; i++){
        for(int j=0; j<rows; j++){
            cin>>v[i][j];
        }
    }
    int target; cin>>target;
    cout<<searchMatrix(matrix, target);

}
