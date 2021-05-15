#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)
typedef long double ld;
double ans(double n){

    double start(0), last(n), mid;
    loop(i, 1000){
        mid = start+(last-start)/2.0;
        if(mid*mid==n){
            return mid;
        }else if(mid*mid-n>0){
            last = mid;
        }else{
            start = mid;
        }
    }
    return mid;

}
int main(){

    int t; cin>>t;
    loop(i, t){
        double n; cin>>n; cout<<setprecision(30)<<ans(n)<<endl;
    }

return 0;
}
