#include<bits/stdc++.h>
using namespace std;

long long ans(int n, int r){

    r = min(r, n-r);
    if(r==0) return 1;
    if(r==1) return n;

    long long p = 1, q = 1;
    while(r){

        p*= 1LL*n;
        q*= 1LL*r;

        long long m = __gcd(p, q);
        p = p/m;
        q = q/m;

        n--; r--;
    }

    return p;

}
int main(){

    int n, r; cin>>n>>r;
    cout<<ans(n, r);

}
