// DP solution

#include<bits/stdc++.h>
using namespace std;

int ans(vector<int>& v, int l, int r, vector<vector<int>>& dp){

    if(l>=r){
        // l==r single element -> we need atleast two sized matrix
        return 0;
    }

    if(dp[l][r]!=-1)
        return dp[l][r];

    int mini = INT_MAX;
    for(int k=l; k<r; k++){
        int temp = ans(v, l, k, dp) + ans(v, k+1, r, dp) + v[l-1]*v[k]*v[r];
        mini = min(temp, mini);
    }

    return dp[l][r]=mini;
}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int n; cin>>n;
        vector<int> v(n);
        for(int j=0; j<n; j++)
            cin>>v[j];
        vector<vector<int>> dp(n, vector<int>(n, -1));
        cout<<ans(v, 1, n-1, dp)<<endl;

    }

    return 0;
}





#include<bits/stdc++.h>
using namespace std;

int ans(vector<int>& v, int l, int r){

    if(l>=r){
        // l==r single element -> we need atleast two sized matrix
        return 0;
    }

    int mini = INT_MAX;
    for(int k=l; k<r; k++){

        // 40, 20, 30, 10,  30
        // 40x20, 20x30, 30x10, 10x30
        // Ai -> a[i-1] x a[i]

        int temp = ans(v, l, k) + ans(v, k+1, r) + v[l-1]*v[k]*v[r];
        mini = min(temp, mini);
    }

    return mini;
}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int n; cin>>n;
        vector<int> v(n);
        for(int j=0; j<n; j++)
            cin>>v[j];
        cout<<ans(v, 1, n-1)<<endl;

    }

    return 0;
}
