#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > multiply_matrix(vector<vector<int> > arr1, vector<vector<int> > arr2){

    vector<vector<int> > ans = {{0, 0},{0, 0}};
    ans[0][0] = arr1[0][0]*arr2[0][0]+arr1[0][1]*arr2[1][0];
    ans[0][1] = arr1[0][0]*arr2[0][1]+arr1[0][1]*arr2[1][1];
    ans[1][0] = arr1[1][0]*arr2[0][0]+arr1[1][1]*arr2[1][0];
    ans[1][1] = arr1[1][0]*arr2[0][1]+arr1[1][1]*arr2[1][1];

    return ans;

}
vector<vector<int> > matrix_exponentiation(vector<vector<int> > arr, int n){


    if(n==0){
        vector<vector<int> > arr1 = {{1, 0}, {0, 1}};
        return arr1;
    }
    if(n==1){
        return arr;
    }
    if(n%2==0){
        return multiply_matrix(matrix_exponentiation(arr, n/2), matrix_exponentiation(arr, n/2));
    }
    vector<vector<int> > ans = multiply_matrix(matrix_exponentiation(arr, (n-1)/2), matrix_exponentiation(arr, (n-1)/2));
    return multiply_matrix(arr, ans);
}
int fibb(int n){



    vector<vector<int> > arr = {{1, 1}, {1, 0}};
    vector<vector<int> > ans = {{1, 0}, {0, 1}};

    for(int i=31; i>=0; i--){

        if(n&(1<<i) !=0){

            ans = multiply_matrix(ans, matrix_exponentiation(arr, i));
        }

    }

    return ans[0][0]+ans[0][1];

}
int main(){


    int t; cin>>t;
    for(int i=0; i<t; i++){

        int n; cin>>n;
        cout<<fibb(n)<<endl;

    }
//    vector<vector<int> > v = {{1, 1},{1, 0}};
//    v = multiply_matrix(v, v);
//    for(int i=0; i<2; i++){
//        for(int j=0; j<2; j++){
//            cout<<v[i][j]<<" ";
//        }
//        cout<<endl;
//    }

return 0;
}
