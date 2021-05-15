#include<bits/stdc++.h>
using namespace std;

// this function calculates the sum of matrix with bottom right corner at botR_x and botR_y and of length l
int getSum(vector<vector<int> >& sumMatrix, int botR_x, int botR_y, int l){

    int topL_x = botR_x-l;
    int topL_y = botR_y-l;

    int sum_ = 0;
    sum_+=sumMatrix[botR_x][botR_y];

    if(topL_y>=0)
        sum_-=sumMatrix[botR_x][topL_y];
    if(topL_x>=0)
        sum_-=sumMatrix[topL_x][botR_y];
    if(topL_x>=0 && topL_y>=0)
        sum_+=sumMatrix[topL_x][topL_y];

    return sum_;

}

int maxSideLength(vector<vector<int>>& mat, int threshold) {

    int rows(mat.size()), cols(mat[0].size());

    // sumMatrix consists of sum of matrix whose bottom right corner is
    // i,j th element and top-left corner is 0,0
    vector<vector<int> > sumMatrix(rows, vector<int>(cols, 0));
    for(int i=0; i<rows; i++){
        int rowSum = 0;
        for(int j=0; j<cols; j++){
            rowSum+=mat[i][j];
            if(i==0)
                sumMatrix[i][j] = rowSum;
            else{
                sumMatrix[i][j] = sumMatrix[i-1][j]+rowSum;
            }
        }
    }

    // find maxLength for every i,j element and store maximum in it.
    int res = 0;
    for(int i=0; i<rows; i++){

        for(int j=0; j<cols; j++){

            // minimum length can be 1 and maximum can be the minimum of rows and column
            int lo(1), hi(min(i, j)+1); // adding 1 because of zero-based indexing
            while(lo<hi){

                int mid = lo+(hi-lo+1)/2;
                // F*T* predicate, we want last F
                if(getSum(sumMatrix, i, j, mid)>threshold)
                    hi = mid-1;
                else
                    lo = mid;

            }
            // sanity check
            if(getSum(sumMatrix, i, j, lo)<=threshold)
                res = max(res, lo);

        }

    }

    return res;

}


int main(){

    int rows, cols; cin>>rows>>cols;

    vector<vector<int> > v(rows, vector<int>(cols, 0));
//    for(int i=0; i<rows; i++){
//        for(int j=0; j<cols; j++){
//            cin>>v[i][j];
//        }
//    }

    v = {{1,1,1,1},{1,0,0,0},{1,0,0,0},{1,0,0,0}};

    int threshold; cin>>threshold;

//    cout<<maxSideLength(v, threshold);
    v = fun(v);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


return 0;
}
