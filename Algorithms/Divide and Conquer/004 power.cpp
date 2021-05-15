#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;
#define loop(i, n) for(int i=0; i<n; i++)
#define MOD 1000000007
ulli rev(ulli n){

    if(n<10)
        return n;
    ulli r = 0;
    while(n!=0){
        r=r*10+n%10;
        n = n/10;
    }
    return r;

}
ulli power(ulli n, ulli r){

    if(r==0)
        return 1;
    if(r==1)
        return n%MOD;

    ulli a = power(n, r/2)%MOD;
    if(r&1){
        return (((a*a)%MOD)*(n%MOD))%MOD;
    }
    return (a*a)%MOD;

}
ulli ans(ulli n){
    return power(n, rev(n));
}

int main(){

    int t; cin>>t;
    loop(i, t){

        ulli n; cin>>n;
        cout<<ans(n)<<endl;

    }


return 0;
}
