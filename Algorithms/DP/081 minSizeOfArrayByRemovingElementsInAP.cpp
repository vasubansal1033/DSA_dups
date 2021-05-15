// https://www.geeksforgeeks.org/find-minimum-possible-size-of-array-with-given-rules-for-removal/

#include<bits/stdc++.h>
using namespace std;

int dp[500][500];
int util1(vector<int>& v, int start, int last, int k){

    if(last-start+1<3) return dp[start][last] = last-start+1;
    if(dp[start][last]!=-1) return dp[start][last];

    // We can either choose not to remove the element
    // or the given element can be removed in two ways
    // Here i is equivalent to start
    // 1st -> a[i], a[i+1], a[i+2] are in AP
    // 2nd -> a[i], a[l], a[r] are in AP "AND" the subarray from i+1 to l-1 AND l+1 to r-1 can be removed completely
    // There answer for this case will be the minimum size of subarray from r+1 to last
    int res = 1+util1(v, start+1, last, k); // not remove the first element

    for(int l=start+1; l<=last-1; l++){
        for(int r = l+1; r<=last; r++){

            int ans1 = util1(v, start+1, l-1, k);
            int ans2 = util1(v, l+1, r-1, k);

            if(ans1==0 && ans2==0 && v[l]-v[start]==k && v[r]-v[l]==k)
                res = min(res, util1(v, r+1, last, k));

        }
    }

    return dp[start][last] = res;

}
int util(vector<int>& v, int k){

    memset(dp, -1, sizeof(dp));
    return util1(v, 0, v.size()-1, k);
}
int main(){

    int n, k; cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    cout<<util(v, k);

return 0;
}
