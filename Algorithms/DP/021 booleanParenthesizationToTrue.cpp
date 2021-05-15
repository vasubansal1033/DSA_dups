#include<bits/stdc++.h>
using namespace std;

int ansUtil(string& str, int l, int r, bool isTrue, vector<vector<vector<int> > >& dp){

    // base case
    if(l>r)
        return 0;
    if(l==r){
        if(isTrue){
            return dp[l][r][1] = (str[l]=='T');
        }else{
            return dp[l][r][0] = (str[l]=='F');
        }
    }

    if(isTrue){
        if(dp[l][r][1]!=-1)
            return dp[l][r][1];
    }else{
        if(dp[l][r][0]!=-1)
            return dp[l][r][0];
    }

    int cnt = 0;
    for(int k=l+1; k<r; k+=2){


        int a, b, c, d;

        a = dp[l][k-1][1]!=-1?dp[l][k-1][1]:(dp[l][k-1][1]=ansUtil(str, l, k-1, true, dp)%1003);
        b = dp[l][k-1][0]!=-1?dp[l][k-1][0]:(dp[l][k-1][0]=ansUtil(str, l, k-1, false, dp)%1003);
        c = dp[k+1][r][1]!=-1?dp[k+1][r][1]:(dp[k+1][r][1]=ansUtil(str, k+1, r, true, dp)%1003);
        d = dp[k+1][r][0]!=-1?dp[k+1][r][0]:(dp[k+1][r][0]=ansUtil(str, k+1, r, false, dp)%1003);

        switch(str[k]){
            case '|':{

                if(isTrue)
                    cnt+=(a*c+a*d+b*c)%1003;
                else
                    cnt+=(b*d)%1003;

            } break;
            case '&':{

                if(isTrue)
                    cnt+=(a*c)%1003;
                else
                    cnt+=(a*d+b*c+b*d)%1003;
            } break;
            case '^':{

                if(isTrue)
                    cnt+=(a*d+b*c)%1003;
                else
                    cnt+=(a*c+b*d)%1003;

            }
        }
    }
    if(isTrue)
        return dp[l][r][1] = cnt%1003;
    else
        return dp[l][r][0] = cnt%1003;

}
int ans(string& str){
    vector<vector<vector<int> > > dp(str.size()+1, vector<vector<int>>(str.size()+1, vector<int>(2, -1)));
    return ansUtil(str, 0, str.size()-1, true, dp);
}
int main()
 {
	//code
	int t; cin>>t;
	for(int i=0; i<t; i++){

        int n; cin>>n;
        string str; cin>>str;
        cout<<ans(str)<<endl;
	}

	return 0;
}
