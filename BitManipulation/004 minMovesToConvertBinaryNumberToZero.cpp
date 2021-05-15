//https://stackoverflow.com/questions/54812971/programming-minimum-steps-required-to-convert-a-binary-number-to-zero

#include<bits/stdc++.h>
using namespace std;

int util(int n){

    int bit = n<0?1:0; // checking for sign bit

    int res = bit;
    for(int i=0; i<31; i++){

        n = n<<1;
        int sign = n<0?1:0;
        bit = (bit+sign)%2;

        res = (res<<1)+bit;
    }

    return res;
}
int main(){

    int n; cin>>n;
    cout<<util(n);

return 0;
}
