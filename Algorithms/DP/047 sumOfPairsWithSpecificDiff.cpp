#include<bits/stdc++.h>
using namespace std;

int ans(vector<int>& v, int k){

    sort(v.begin(), v.end());

    vector<int> dp(v.size());
    dp[0] = 0;
    dp[1] = (v[1]-v[0]<k)?(v[0]+v[1]):0;

    for(int i=2; i<v.size(); i++){

        if(v[i]-v[i-1]<k){

            // If we consider i and i-1, then sum will be dp[i-2] + v[i-1] + v[i]
            dp[i] = max(dp[i-2]+v[i-1]+v[i], dp[i-1]);

        }else{
            dp[i] = dp[i-1];
        }

    }
    return dp[v.size()-1];

}
int main()
 {
	//code
	int t; cin>>t;
	for(int i=0; i<t; i++){

	    int n; cin>>n; vector<int> v(n);
	    for(int j=0; j<n; j++)
	        cin>>v[j];
	    int k; cin>>k;
	    cout<<ans(v, k)<<'\n';

	}
	return 0;
}
