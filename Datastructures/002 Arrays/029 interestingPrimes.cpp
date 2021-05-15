# will not work on GCC compilers. But works on ideone.com

#include<bits/stdc++.h>
using namespace std;

const int N = 1000001;
bool* primes;
vector<long long int> squares;
vector<long long int> quads;

void init(){

//    memset(primes, true, sizeof(primes));
    for(long long int i=0; i<N; i++) primes[i] = true;

    primes[0] = primes[1] = false;
    for(long int i=2; i<N; i++){
        if(primes[i]){
            for(long int j=i*i; j<N; j+=i)
                primes[j] = false;
        }
    }

    for(long long int i=1; i*i<N; i++){
        squares.push_back(i*i);
    }
    for(long long int i=1; (i*i*i*i)<N; i++)
        quads.push_back(i*i*i*i);


}
void util(int n){

    unordered_set<int> res;
    for(long long int i=0; squares[i]<n; i++){
        for(long long int j=0; quads[j]<n; j++){
            if(squares[i]+quads[j]<n && primes[squares[i]+quads[j]])
                res.insert(squares[i]+quads[j]);
        }
    }

    cout<<res.size()<<'\n';
    for(int i:res) cout<<i<<" ";

}
int main(){

    int t; cin>>t;
    primes = new bool[N];
    init();

    for(int i=0; i<t; i++){
        int n; cin>>n;
        util(n);
    }

return 0;
}
