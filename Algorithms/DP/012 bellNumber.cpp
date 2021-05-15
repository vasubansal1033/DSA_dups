#include<bits/stdc++.h>
using namespace std;

int stirlingNumber(int n, int k){

    if(n==k || k==1)
        return 1;
    if(n!=0 && k==0)
        return 0;

    return k*stirlingNumber(n-1, k)+stirlingNumber(n-1, k-1);
}
int ans(int n){
    int sum = 0;
    for(int i=0; i<=n; i++)
        sum+=stirlingNumber(n, i);
    return sum;


}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int n; cin>>n;
        cout<<ans(n)<<endl;

    }

return 0;
}
