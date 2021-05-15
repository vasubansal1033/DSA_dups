#include<bits/stdc++.h>
using namespace std;

int getMask(int n){

    int ans = 0;
    while(n!=0){
        ans = ans|(1<<(n%10));
        n = n/10;
    }

    return ans;
}
int util(int arrayMask, vector<int>& dp, vector<int>& v){

    if(arrayMask==0) return 0;
    if(dp[arrayMask]!=-1) return dp[arrayMask];

    for(int i=0; i<v.size(); i++){

        int mask = getMask(v[i]);
        if((arrayMask|mask)==arrayMask){
            dp[arrayMask] = max(max(dp[arrayMask^mask], 0)+v[i], dp[arrayMask]);
        }

    }

    return dp[arrayMask];

}
int ans(vector<int>& v){

    int res = 0;
    vector<int> dp(1<<10, -1);
    for(int i=0; i<(1<<10); i++){

        res = max(res, util(i, dp, v));

    }

    return res;

}
int main(){

   vector<int> v = { 22, 132, 4, 45, 12, 223 };
   cout<<ans(v);

return 0;
}
