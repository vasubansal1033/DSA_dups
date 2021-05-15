#include<bits/stdc++.h>
using namespace std;

typedef vector<int> v1d;
typedef vector<v1d> v2d;
typedef vector<v2d> v3d;

int ans(string& str1, string& str2, string& str3){

    v3d dp(str1.size()+5, v2d(str2.size()+5, v1d(str3.size()+5, 0)));

    for(int k=str3.size()-1; k>=0; k--){
        for(int j=str2.size()-1; j>=0; j--){
            for(int i=str1.size()-1; i>=0; i--){

                if(str1[i]==str2[j] && str2[j]==str3[k]){
                    dp[i][j][k] = 1+dp[i+1][j+1][k+1];
                }

                else{
                    dp[i][j][k] = max({dp[i+1][j][k], dp[i][j+1][k], dp[i][j][k+1]});
                }


            }
        }
    }

    return dp[0][0][0];

}
int main()
 {
	//code
	int t; cin>>t;
	for(int i=0; i<t; i++){

        int m, j, k;
        cin>>m>>j>>k;
	    string str1, str2, str3;
	    cin>>str1>>str2>>str3;
	    cout<<ans(str1, str2, str3)<<'\n';

	}
	return 0;
}
