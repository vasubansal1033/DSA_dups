#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9+7;

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x; cin>>n>>m>>x;
    int ans=1;

    vector <int> dp1(n,1);
    int dp2[n]; memset(dp2, 0, sizeof(dp2));
    if(x!=1){
        dp1[0]=1; dp2[0]=0;
        for(int i=1;i<n;i++){
            dp1[i] = ((dp1[i-1]*(m-2))%mod + (dp2[i-1]*(m-1))%mod)%mod;
            dp2[i] = dp1[i-1];
        }
        cout<<dp2[n-1];
    }
    else{
        dp1[0]=0; dp2[0]=1;
        for(int i=1;i<n;i++){
            dp1[i] = ((dp1[i-1]*(m-2))%mod + (dp2[i-1]*(m-1))%mod )%mod;
            dp2[i] = dp1[i-1];
        }
        cout<<dp2[n-1];
    }

}

// my approach
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
const int N = 1e2+5;
int dp[N][N][N];

int solve(int n, int m, int lastGuest){

    if(n==1 || n==2){
        return 1;
    }

    if(dp[n][m][lastGuest]!=-1) return dp[n][m][lastGuest];

    long long int res = 0;
    for(int i=1; i<=m; i++)
        if(n!=3){
            if(i!=lastGuest){
                res += solve(n-1, m, i);
                res = res%mod;
            }
        }else if(n==3){
            if(i!=lastGuest && i!=1){
                res += solve(n-1, m, i);
                res = res%mod;
            }
        }

    return dp[n][m][lastGuest] = res;
}

int main(){

    int n, m, x; cin>>n>>m>>x;
    memset(dp, -1, sizeof(dp));
    cout<<solve(n, m, x);

return 0;
}
