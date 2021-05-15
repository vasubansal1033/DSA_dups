typedef unsigned long long int ulli;
class Solution {
public:
    int nthUglyNumber(int n) {

        if(n<=1) return 1;

        vector<int> dp(n);
        dp[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0;

        for(int i=1; i<n; i++){

            dp[i] = min(dp[t2]*2, min(dp[t3]*3, dp[t5]*5));

            if(dp[i]==dp[t2]*2) t2++;
            if(dp[i]==dp[t3]*3) t3++;
            if(dp[i]==dp[t5]*5) t5++;

        }

        return dp[n-1];



    }
};



#include<iostream>
using namespace std;
typedef long long int lli;

lli uglyNumber(int n){

    lli arr[n];
    arr[0] = 1; // arr[i-1] is ith ugly number

    int i2(0), i3(0), i5(0); // maintaining iterators as combinations with different primes wont come otherwise
    lli next_two = arr[i2]*2;
    lli next_three = arr[i3 ]*3;
    lli next_five = arr[i5]*5;

    for(int i=1; i<n; i++){

        lli nextUgly = min(next_two, min(next_three, next_five));
        arr[i] = nextUgly;

        if(nextUgly%2==0){
            i2++;
            next_two=arr[i2]*2;
        }
        if(nextUgly%3==0){
            i3++;
            next_three=arr[i3]*3;
        }
        if(nextUgly%5==0){
            i5++;
            next_five = arr[i5]*5;
        }

    }
    return arr[n-1];
}


int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int n; cin>>n;
        cout<<uglyNumber(n)<<endl;

    }


return 0;
}
