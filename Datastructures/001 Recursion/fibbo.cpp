#include<iostream>
#include<bits/stdc++.h>
using namespace std;

static int arr[100];

int fibbo(int n){

    std::fill_n(arr,100,-1);

    if(n<=1){

        if(arr[n]==-1){
            arr[n]=n;
            return arr[n];
        }
        return arr[n];

    }
    else if(arr[n]==-1){
        arr[n]=fibbo(n-1)+fibbo(n-2);
        return arr[n];
    }
    return arr[n];

}
int main(){

    cout<<fibbo(6);

return 0;
}
