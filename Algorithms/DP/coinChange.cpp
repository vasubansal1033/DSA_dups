#include<bits/stdc++.h>
using namespace std;


// m is index
int ans2(int n, int m, vector<int> S){

    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(m>S.size() && n>0){
        return 0;
    }
    return ans2(n, m+1, S)+ans2(n-S[m], m, S);
}

int ans(int n, vector<int> S){
    return ans2(n, 0, S);
}

int coinChangeDP(int n, vector<int> S){

    int m = S.size();
    int matrix[m][n+1];

    for(int i=0; i<m; i++){
        matrix[i][0] = 1;
    }

    for(int i=0; i<m; i++){
        for(int j=1; j<=n; j++){

            // including mth coin
            int x = (S[i]>j)?0:(matrix[i][j-S[i]]);
            // dont include mth coin
            int y = (i>0)?matrix[i-1][j]:0;
            matrix[i][j] = x+y;

        }
    }
    return matrix[m-1][n];

}

int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int slen; cin>>slen;
        vector<int> S; // set of change
        for(int i=0; i<slen; i++){
            int temp; cin>>temp;
            S.push_back(temp);
        }
        int n; cin>>n;
        cout<<coinChangeDP(n, S)<<endl;

    }

return 0;
}
