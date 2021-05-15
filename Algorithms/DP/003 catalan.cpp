#include<bits/stdc++.h>

//#include <boost/multiprecision/cpp_int.hpp>
//using boost::multiprecision::cpp_int;

using namespace std;
typedef long long int lli;

//int rcatalan(int n){
//
//    if(n==0){
//        return 1
//    }
//
//    int sum = 0;
//    for(int i=0; i<n; i++){
//        sum+=rcatalan(i)*rcatalan(n-i-1);
//    }
//    return sum;
//}
lli dpCatalan(int n){

    lli arr[n+1];
    arr[0] = 1;

    for(int i=1; i<=n; i++){
        lli sum = 0;
        for(int j=0; j<i; j++){
            sum+=arr[j]*arr[i-j-1];
        }
        arr[i] = sum;
    }

    return arr[n];

}
int main(){

    int t;
    cin>>t;
    for(int i=0; i<t; i++){

        int n; cin>>n;
        cout<<dpCatalan(n)<<endl;

    }

}
