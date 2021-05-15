#include<bits/stdc++.h>
using namespace std;

// recursive solution
//int maxValue(vector<int>& val, vector<int>& weights, int n, int W){
//
//    // base case from the minimum condition
//    // W - size, n number of items
//    if(W==0||n==0){
//        return 0;
//    }
//    if(weights[n-1]<=W){
//        return max(val[n-1]+maxValue(val, weights, n-1, W-weights[n-1]),
//                   maxValue(val, weights, n-1, W));
//    }else{
//        return maxValue(val, weights, n-1, W);
//    }
//
//}
// memoization or DP solution
//int maxValue(vector<int>& val, vector<int>& weights, int n, int W, vector<vector<int> > &t){
//
//    // n+1 by W+1 matrix of all -ones
//
//    if(n==0||W==0){
//        return 0;
//    }
//
//    if(t[n][W]!=-1){
//        return t[n][W];
//    }
//    if(weights[n-1]<=W){
//        return t[n][W] = max(val[n-1]+maxValue(val, weights, n-1, W-weights[n-1], t),
//                                  maxValue(val, weights, n-1, W, t));
//    }else{
//        return t[n][W] = maxValue(val, weights, n-1, W, t);
//    }
//}
//
//int ans(vector<int>& val, vector<int>& weights, int n, int W){
//
//    vector<vector<int> > t(n+1, vector<int>(W+1, -1)); // dont use static variables for recursive functions.
//    return maxValue( val,  weights,  n,  W, t);
//
//}

// bottom-up approach
int maxValue(vector<int>& val, vector<int>& weights, int n, int W){

    int t[n+1][W+1];
    // Initialization using base case
    for(int i=0; i<=n; i++){
        for(int j=0; j<=W; j++){
            if(i==0||j==0){
                t[i][j]=0;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){

            if(weights[i-1]<=j){
                t[i][j] = max(val[i-1]+t[i-1][j-weights[i-1]], t[i-1][j]);
            }else{
                t[i][j] = t[i-1][j];
            }

        }
    }
    }
    return t[n][W];

}

int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int n, W; cin>>n>>W;
        vector<int> val(n);
        for(int j=0; j<n;j++){
            cin>>val[j];
        }
        vector<int> weights(n);
        for(int j=0; j<n;j++){
            cin>>weights[j];
        }

//        cout<<ans(val, weights, n, W)<<endl;
        cout<<maxValue(val, weights, n, W)<<endl;

    }


return 0;
}
