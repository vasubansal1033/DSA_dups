// Given an array of 2*N integers, we can play N rounds. In each round we can choose two numbers
// and add roundNumber*gcd of two numbers to our score. We remove these two elements and keep on going.
// Maximize the total score

// Approach -> DP with bitmasking

#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;

// global variables for recursion. Don't have to pass through functions
// Also array size can be huge
const ulli N = (1<<20)+5; // maximum size of array was 20
ulli dp[N]; // dp array. stores answers for mask
vector<ulli> v; // stores the array of numbers
ulli n;

// function to calculate number of set bits in mask
ulli countSetBits(ulli mask){

    ulli cnt = 0;
    while(mask){
        mask = mask&(mask-1);
        cnt++;
    }
    return cnt;

}
ulli util(ulli mask){

    // base case
    // if all numbers are chosen, we cannot choose new number
    // so we get score 0
    if(mask==(1<<20)-1) return 0;
    // memo return step
    if(dp[mask]!=-1) return dp[mask];

    // find the round number from count of set bits in mask
    ulli rounds = 1+countSetBits(mask)/2;

    ulli res = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){

            // find i and j such that ith and jth element are not chosen at round i
            // among all possibilities, choose the i and j which will maximize the score

            if(!(mask&(1<<i)) && !(mask&(1<<j))){

                res = max(res, util(mask|(1<<i)|(1<<j))+rounds*(__gcd(v[i], v[j])));

            }

        }
    }

    return dp[mask] = res;

}
int main(){

    cin>>n; n = n*2;
    v.resize(n);
    for(int i=0; i<n; i++) cin>>v[i];

    memset(dp, -1, sizeof(dp));

    ulli mask = 0;
    cout<<util(mask);

}

// TOP DOWN APPROACH

#include<bits/stdc++.h>
using namespace std;

typedef int ulli;
const int N = ((1<<20)+5);
ulli dp[N];
vector<ulli> v;
ulli n;

ulli countSetBits(ulli mask){
    ulli cnt = 0;
    while(mask){
        mask = mask&(mask-1);
        cnt++;
    }
    return cnt;
}
ulli util(ulli mask){

	if(mask==0) return 0;
    if(dp[mask]!=-1) return dp[mask];

    ulli roundsLeft = countSetBits(mask);
    roundsLeft = n-roundsLeft;
    roundsLeft = roundsLeft/2; // number of set bits show 2*pairs chosen.
    roundsLeft++;

    ulli res = 0;

    for(int i=0; i<n; i++){

        if(!(mask & (1<<i))) continue;
        for(int j=i+1; j<n; j++){

            if(!(mask & (1<<j))) continue;

            res = max(res, util(mask^(1<<i)^(1<<j))+roundsLeft*(__gcd(v[i], v[j])));

        }

    }

    return dp[mask] = res;

}
int main(){

    cin>>n;
    n = n*2;
    v.resize(n);
    for(int i=0; i<n; i++) cin>>v[i];

    ulli mask = (1<<n)-1;
    memset(dp, -1, sizeof(dp));

    cout<<util(mask);

return 0;
}

