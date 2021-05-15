#include<bits/stdc++.h>
using namespace std;

//int ans(int n, int w, vector<int>& val, vector<int>& weights){
//
//    if(n==0||w==0)
//        return 0;
//    if(weights[n-1]<=w){
//        return max(val[n-1]+ans(n, w-weights[n-1], val, weights),
//                   ans(n-1, w, val, weights));
//    }else{
//        return ans(n-1, w, val, weights);
//    }
//
//}

int dpSolution(int n, int w, vector<int>& val, vector<int>& weights){

    int arr[n+1][w+1];

    for(int i=0; i<=n; i++)
        arr[i][0] = 0;
    for(int i=1; i<=w; i++)
        arr[0][i] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){

            if(weights[i-1]<=j){
                arr[i][j] = max(val[i-1]+arr[i][j-weights[i-1]],
                                arr[i-1][j]);
            }else{
                arr[i][j] = arr[i-1][j];
            }

        }
    }
    return arr[n][w];
}
int main(){


    int t; cin>>t;
    for(int i=0; i<t; i++){

        int n, w; cin>>n>>w;
        vector<int> val(n, 0), weights(n,0);
        for(int j=0; j<n; j++)
            cin>>val[j];
        for(int j=0; j<n; j++)
            cin>>weights[j];
//        cout<<ans(n, w, val, weights)<<endl;
        cout<<dpSolution(n, w, val, weights)<<endl;
    }

return 0;
}
