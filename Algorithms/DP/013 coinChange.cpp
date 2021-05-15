class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int dp[coins.size()+1][amount+1];

        // amount is 0, only 1 way, not to take any coin. this is valid since 0 value coins are not present
        // coins is empty, 0 ways

        for(int i=0; i<coins.size()+1; i++){
            dp[i][0] = 1;
        }
        for(int j=1; j<=amount; j++){
            dp[0][j] = 0;
        }

        for(int i=1; i<coins.size()+1; i++){
            for(int j=1; j<=amount; j++){

                if(j-coins[i-1]>=0)
                    dp[i][j] = dp[i][j-coins[i-1]]+dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[coins.size()][amount];


    }
};


#include<bits/stdc++.h>
using namespace std;

// m is number of coins, n is the number we want
//int ans(vector<int> v, int m, int n){
//
//    if(n==0){
//        return 1;
//    }
//    if(m==0){
//        return 0;
//    }
//
//    if(v[m-1]<=n){
//        return ans(v, m, n-v[m-1])+ans(v, m-1, n);
//    }else{
//        return ans(v, m-1, n);
//    }
//
//}
int ans(vector<int> v, int m, int n){

    int arr[n+1][m+1];
    for(int i=0; i<=m; i++)
        arr[0][i] = 1;
    for(int i=1; i<=n; i++)
        arr[i][0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){

            if(v[j-1]<=i)
                arr[i][j] = arr[i-v[j-1]][j]+arr[i][j-1];
            else
                arr[i][j] = arr[i][j-1];

        }
    }
    return arr[n][m];

}

int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int m; cin>>m;
        vector<int> v(m);
        for(int j=0; j<m; j++){
            cin>>v[j];
        }
        int n; cin>>n;
        cout<<ans(v, m, n)<<endl;

    }

return 0;
}
