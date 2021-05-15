#include<bits/stdc++.h>
using namespace std;

void factorize(int n){

    vector<int> factors;
    for(int i=2; i*i<=n; i++){

        while(n%i==0){
            factors.push_back(i);
            n = n/i;
        }

    }
    if(n!=1) factors.push_back(n);
    for(int i=0; i<factors.size(); i++)
        cout<<factors[i]<<" ";


}
int main(){

    int n; cin>>n;
    factorize(n);

}
