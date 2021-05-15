#include<bits/stdc++.h>
using namespace std;

// Steps are -> If n = a*b, a!=1 and b!=1
// then for util1 -> either N->max(a, b) or N->N-1
// for util2 -> N->min(a, b) or N->N-1

int util1(int n){

    if(n<=3) return n;

    int dp[n+1];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i=0; i<=n; i++){

        if(dp[i]==-1 || dp[i]>dp[i-1]+1)
            dp[i] = 1+dp[i-1];
        for(int j=1; j<=i && j*i<=n; j++)
            if(dp[j*i]==-1 || dp[j*i]>dp[i]+1)
                dp[j*i] = dp[i]+1;

    }

    return dp[n];

}
int util2(int n){

    if(n<=3) return n;

    int dp[n+1];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i=4; i<=n; i++){

        int j = sqrt(i);
        int res = INT_MAX;

        while(j>1){
            if(i%j==0){
                res = min(res, 1+dp[j]);
            }
            j--;
        }
        dp[i] = min(res, dp[i-1]+1);

    }

    return dp[n];

}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int n; cin>>n;
        cout<<util1(n)<<" "<<util2(n)<<'\n';

    }

return 0;
}
