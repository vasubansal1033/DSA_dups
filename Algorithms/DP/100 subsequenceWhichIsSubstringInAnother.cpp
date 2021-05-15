#include<bits/stdc++.h>
using namespace std;

int util(string& a, string& b){

    int dp[a.size()+1][b.size()+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    int res = 0;
    for(int i=1; i<=(int)a.size(); i++){
        for(int j=1; j<=(int)b.size(); j++){

            if(a[i-1]==b[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = dp[i-1][j];
            res = max(res, dp[i][j]);
        }
    }

    return res;

}
int main(){
	//code
	int t; cin>>t;
	for(int i=0; i<t; i++){

	    int x, y; cin>>x>>y;
	    string a, b;
	    cin>>a>>b;
	    cout<<util(a, b)<<'\n';

	}

	return 0;
}
