#include<bits/stdc++.h>
using namespace std;

int permutationCoefficient(int n, int k){

    // nPk = n*(n-1)*.....*(n-(k-1))) = (n-1)P(k)+k*(n-1)P(k-1)
    if(k==0)
        return 1;
    if(n==0)
        return 0;
    return permutationCoefficient(n-1, k)+ k*permutationCoefficient(n-1, k-1);
}
int dppermutationCoefficient(int n, int k){

    int arr[n+1][k+1];
    for(int i=0; i<=n; i++){
        arr[i][0]=1;
    }
    for(int i=1; i<=k; i++){
        arr[0][i] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            arr[i][j] = arr[i-1][j]+j*arr[i-1][j-1];
        }
    }
    return arr[n][k];

}
int main(){

    int n, k; cin>>n>>k;
    cout<<permutationCoefficient(n, k)<<endl;
    cout<<dppermutationCoefficient(n, k)<<endl;

return 0;
}
