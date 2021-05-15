#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
map<lli, lli> memo;

// recursive sol
lli ans(lli n){

    if(n<=4){
        return memo[n];
    }

    if(memo.find(n)==memo.end()){
        memo[n] = max(n, ans(n/2)+ans(n/3)+ans(n/4));
        return memo[n];
    }
    return memo[n];

}

lli dpAns(lli n){

    if(n<=4){
        return n;
    }
    int arr[n];
    for(int i=0; i<5; i++){
        arr[i] = i;
    }
    for(int i=5; i<=n; i++){
        arr[i] = max(i, arr[i/2]+arr[i/3]+arr[i/4]);
    }

    return arr[n];

}
int main(){


    memo[0] = 0; memo[1] = 1; memo[2] = 2; memo[3] = 3; memo[4] = 4;


//    for continuous input
    lli n;
    while(cin>>n){
        cout<<ans(n)<<endl;
        cout<<dpAns(n)<<endl;
    }

return 0;
}
