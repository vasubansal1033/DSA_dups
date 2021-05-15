#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int dp[51][101][51][101];

int util(int n, int m, int totCost, int lastEle){

    if(n==1){
        if(totCost==0) return dp[n][m][totCost][lastEle] = 1;
        else return dp[n][m][totCost][lastEle] = 0;
    }
    if(dp[n][m][totCost][lastEle]!=-1) return dp[n][m][totCost][lastEle];

    long long int val = 0;

    // we can place elements from 1 to lastEle if the last element was lastEle
    // without increasing the cost
    val += util(n-1, m, totCost, lastEle)*lastEle;
    val = val%mod;
    // including elements greater than lastEle, will increase the cost by 1
    // so recurse for totCost-1
    for(int i=lastEle+1; i<=m; i++){
        val += util(n-1, m, totCost-1, i);
        val = val%mod;
    }

    return dp[n][m][totCost][lastEle] = val;

}

// include a new dimension called lastElement
vector<int> arrayCount(vector<int> n, vector<int> m, vector<int> totCost){

    vector<int> res;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n.size(); i++){

        long long int val = 0;
        for(int j=1; j<=m[i]; j++){
            val+= util(n[i], m[i], totCost[i], j);
            val = val%mod;
        }
        res.push_back(val);
    }
    return res;
}
int main(){

    vector<int> res = arrayCount({4,2,3,4},{4,3,3,3},{2,1,2,2});
    for(auto& i:res) cout<<i<<" ";

return 0;
}
