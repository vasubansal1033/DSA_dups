//https://www.geeksforgeeks.org/split-array-into-minimum-number-of-subarrays-having-gcd-of-its-first-and-last-element-exceeding-1/
// Above link assumes i<j. Original question i<=j, that is single element can be considered

#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve(){

    int n,i,j; cin>>n;

    int A[n+1], DP[n+1];
    for(i=1; i<=n; i++) cin>>A[i];
    memset(DP, 0, sizeof(DP));

    unordered_map<int, int> M;
    for(i=1; i<=n; i++){

        vector<int> factors;
        factors.push_back(A[i]);
        for(j=2; j*j<=A[i]; j++){
            if(A[i]%j==0){
                if(j*j==A[i]){
                    factors.push_back(j);
                }
                else{
                    factors.push_back(j);
                    factors.push_back(A[i]/j);
                }
            }
        }
        int ans=DP[i-1]+1;
        for(j=0;j<factors.size();j++){
            if(M.find(factors[j])==M.end()){
                M[factors[j]]=DP[i-1];
            }
            else
                ans=min(ans,M[factors[j]]+1);
        }
        DP[i]=ans;
    }
    cout<<DP[n]<<endl;
}
int32_t main()
{
    boost;
    int  t=1;
    // cin>>t;
    for(int i=1;i<=t;i++)
    {
        //cout<<"Case #"<<i<<": ";
        solve();
    }
}
