#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long mod = 1000000009;

int main(){

	int t;cin>>t;
	ll n,x,y; cin>>n>>x>>y;
	ll a[n+1];
	for(int i =1;i<=n;i++) cin>>a[i];
	if(x == 0 && y ==0){
		cout<<n<<endl;
		return 0;
	}

	ll dp[n+1][x+2][y+2][2];
	memset(dp, 0, sizeof(dp));

	for(int i =1;i<=n;i++){
		for(int j = i-1;j>0;j--){
			if(a[i]>a[j])
				dp[i][0][0][0] = (++dp[i][0][0][0])%mod;
			else
				dp[i][0][0][1] = (++dp[i][0][0][1])%mod;
		}
	}

    // this is state optimized approach
    // difference of local minima and maxima incase of distinct elements can be -1, 0, 1
	for(int i =1;i<=n;i++){
		for(int j =1;j<i;j++){
			if(a[i]>a[j]){
				for(int k = 0;k<=x;k++){
					if(k+1<=y){
						dp[i][k][k+1][0] = (dp[i][k][k+1][0]+dp[j][k][k+1][0])%mod;
						dp[i][k+1][k+1][0] = (dp[i][k+1][k+1][0]+dp[j][k][k+1][1])%mod;
					}
					if(k<=y){
						dp[i][k][k][0] = (dp[i][k][k][0]+dp[j][k][k][0])%mod;
						dp[i][k+1][k][0] = (dp[i][k+1][k][0]+dp[j][k][k][1])%mod;
					}
					if(k-1<=y && k>0){
						dp[i][k][k-1][0] = (dp[i][k][k-1][0]+dp[j][k][k-1][0])%mod;
						dp[i][k+1][k-1][0] = (dp[i][k+1][k-1][0]+dp[j][k][k-1][1])%mod;
					}
				}
			}
			else{
				for(int k = 0;k<=y;k++){
					if(k+1<=x){
						dp[i][k+1][k][1] = (dp[i][k+1][k][1]+dp[j][k+1][k][1])%mod;
						dp[i][k+1][k+1][1] = (dp[i][k+1][k+1][1]+dp[j][k+1][k][0])%mod;
					}
					if(k<=x){
						dp[i][k][k][1] = (dp[i][k][k][1]+dp[j][k][k][1])%mod;
						dp[i][k][k+1][1] = (dp[i][k][k+1][1]+dp[j][k][k][0])%mod;
					}
					if(k-1<=x && k>0){
						dp[i][k-1][k][1] = (dp[i][k-1][k][1]+dp[j][k-1][k][1])%mod;
						dp[i][k-1][k+1][1] = (dp[i][k-1][k+1][1]+dp[j][k-1][k][0])%mod;
					}
				}
			}
		}
	}
	long long total = 0;
	for(int i =1;i<=n;i++){
		total = (total+(dp[i][x][y][0]+dp[i][x][y][1])%mod)%mod;
	}
	cout<<total<<endl;
	return 0;
}
