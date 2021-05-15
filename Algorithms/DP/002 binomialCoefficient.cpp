#include<bits/stdc++.h>
using namespace std;

int binomialCoefficient(int n, int k){

    // nCn = nC0 = 1
    if(n==k || k==0){
        return 1;
    }
    // (n+1)C(r+1) = nCr+nC(r+1)
    return binomialCoefficient(n-1, k)+binomialCoefficient(n-1, k-1);

}
int dpBinomialCoefficient(int n, int k){

    int arr[n+1][k+1];
    // base case initialization
    for(int i=0; i<=n; i++){ // 0C0 is 1
        arr[i][0] = 1;
    }
    for(int i=1; i<=k; i++){
        arr[0][i] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            arr[i][j] = arr[i-1][j]+arr[i-1][j-1];
        }
    }
    return arr[n][k];
}
int main(){

    int n, k;
    cin>>n>>k;
    cout<<binomialCoefficient(n,k)<<endl;
    cout<<dpBinomialCoefficient(n, k)<<endl;


}
