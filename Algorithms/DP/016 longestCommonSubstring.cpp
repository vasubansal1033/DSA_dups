#include<bits/stdc++.h>
using namespace std;

// recursive
int lcs(string str1, string str2, int m, int n, int cnt){

    if(m==0||n==0)
        return cnt;
    if(str1[m-1]==str2[n-1]){
        return lcs(str1, str2, m-1, n-1, cnt+1);
    }else{
        return max(cnt, max(lcs(str1, str2, m, n-1, 0),
                   lcs(str1, str2, m-1, n, 0)));
    }

}
// dynamic
int dplcs(string str1, string str2, int m, int n){

    int arr[m+1][n+1];
    for(int i=0; i<=m; i++)
        arr[i][0] = 0;
    for(int i=1; i<=n; i++)
        arr[0][i] = 0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){

            if(str1[i-1]==str2[j-1])
                arr[i][j] = 1+arr[i-1][j-1];
            else
                arr[i][j] = 0;

        }
    }

    int maxi = INT_MIN;
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){

            if(arr[i][j]>maxi)
                maxi = arr[i][j];

        }
    }
    return maxi;

}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int m, n; cin>>m>>n;
        string str1, str2; cin>>str1>>str2;
        cout<<dplcs(str1, str2, m, n)<<endl;

    }

return 0;
}
