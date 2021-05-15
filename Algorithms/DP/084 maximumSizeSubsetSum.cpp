#include<bits/stdc++.h>
using namespace std;

void util(vector<int>& v, int sum){

    bool dp[v.size()+1][sum+1];
    int cnt[v.size()+1][sum+1];

    // i=0, array is empty, false and -1
    // j=0, sum is 0, true and 1 way(dont take any element)
    for(int j=1; j<=sum; j++){
        dp[0][j] = false;
        cnt[0][j] = -1;
    }
    for(int i=0; i<=v.size(); i++){
        dp[i][0] = true;
        cnt[i][0] = 0;
    }

    for(int i=1; i<v.size()+1; i++){
        for(int j=1; j<=sum; j++){

            dp[i][j] = dp[i-1][j];
            cnt[i][j] = cnt[i-1][j];
            if(j>=v[i-1]){
                dp[i][j] = dp[i][j]||dp[i-1][j-v[i-1]];

                if(dp[i][j])
                    cnt[i][j] = max(cnt[i-1][j], 1+cnt[i-1][j-v[i-1]]);
            }

        }
    }

//    for(int i=0; i<v.size()+1; i++){
//        for(int j=0; j<=sum; j++){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<'\n';
//    }

    cout<<dp[v.size()][sum]<<" "<<cnt[v.size()][sum];

}
int main(){

    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    util(v, k);

return 0;
}
