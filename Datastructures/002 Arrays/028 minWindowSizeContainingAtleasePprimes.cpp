#include<bits/stdc++.h>
using namespace std;


const int N = 1000001;
int* primes;

void sieve(){

    for(int i=0; i<N; i++) primes[i] = 1;

    primes[0] = 0;
    primes[1] = 0;
    for(long int i=2; i<N; i++){

        if(primes[i]==1){
            for(long int j=i*i; j<N; j+=i)
                primes[j] = 0;
        }

    }

    for(int i=2; i<N; i++) primes[i] += primes[i-1];

//    for(int i=0; i<20; i++) cout<<primes[i]<<" ";

}
bool isPossible(int a, int b, int p, int sz){

    int l = a, r = a+sz-1;
    while(r<=b){

        if(primes[r]-primes[l-1]>=p){
            l++; r++;
        }else return false;

    }

    return true;

}
int main(){

    int t; cin>>t;

    primes = new int[N];
    sieve();

    for(int i=0; i<t; i++){

        int a, b, p; cin>>a>>b>>p;
        int lo = 1, hi = b-a+1;
        while(lo<hi){

            int mid = lo+(hi-lo)/2;

            if(isPossible(a, b, p, mid)) hi = mid;
            else lo = mid+1;

        }
        if(isPossible(a, b, p, hi))
            cout<<hi<<'\n';
        else cout<<-1<<'\n';

    }

return 0;
}
