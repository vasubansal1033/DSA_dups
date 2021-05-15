#include<bits/stdc++.h>
using namespace std;


//int ans(int n, int x, int y, int z){
//
//    if(n==0)
//        return 0;
//
//    int a(0), b(0), c(0);
//
//    if(n>=x)
//        a = 1+ans(n-x, x,y, z);
//    if(n>=y)
//        b = 1+ans(n-y, x, y, z);
//    if(n>=z)
//        c = 1+ans(n-z, x, y, z);
//
//    if(a==0 && b==0 && c==0)
//        return -1;
//    return max(a, max(b, c));
//}

int ans(int n, int x, int y, int z){

    int arr[n+1];
    arr[0] = 0;

    for(int i=1; i<=n ; i++){
        int a(-1), b(-1), c(-1);
        if(i>=x)
            a = arr[i-x];
        if(i>=y)
            b = arr[i-y];
        if(i>=z)
            c = arr[i-z];

        if(a==-1 && b==-1 && c==-1)
            arr[i] = -1;
        else
            arr[i] = 1+max(a, max(b, c)); // adding one here so as to distinguish -1 and 0 case
    }

    if(arr[n]==-1)
        return 0;
    return arr[n];

}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int n; cin>>n;
        int x, y, z; cin>>x>>y>>z;
        cout<<ans(n, x, y, z)<<endl;

    }

return 0;
}
