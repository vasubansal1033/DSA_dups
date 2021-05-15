#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
int dp[100000][6][6];

int util(int n, int k, int x, int last){

    // base case
    if(n==1) return 1;
    if(dp[n][x][last]!=-1) return dp[n][x][last];

    // if last==x, then i can place any element
    long long int val = 0;
    if(last==x){
        for(int i=1; i<=k; i++){
            val+=util(n-1, k, x, i);
            val = val%mod;
        }
    }else{

        for(int i=1; i<=k; i++){
            if(i!=last){
                val+=util(n-1, k, x, i);
                val = val%mod;
            }
        }

    }
    return dp[n][x][last] = val;

}
int main(){

    int n, k, x;
    memset(dp, -1, sizeof(dp));
    cin>>n>>k>>x;

    int res = 0;
    for(int i=1; i<=k; i++){
        res+=util(n, k, x, i);
        res = res%mod;
    }

    cout<<res;
}
