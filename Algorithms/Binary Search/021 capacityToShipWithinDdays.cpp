#include<bits/stdc++.h>
using namespace std;

// this function returns the number of days it'll take given a capacity cap
int fun(vector<int>& weights, int cap){

    int sum=0;
    int count = 0;
    for(int i=0; i<weights.size(); i++){

        if(sum+weights[i]<=cap){
            sum+=weights[i];
        }else{
            sum = weights[i];
            count++;
        }

    }
    return count+1;

}
int shipWithinDays(vector<int>& weights, int D) {

    int lo = *max_element(weights.begin(), weights.end()); // capacity has to be atleast the maximum element
    int hi = accumulate(weights.begin(), weights.end(), 0);; // maximum it can take all of the weights

    // predicate is s.t. we get FFFFTTTTT
    // find the first true
    while(lo<hi){

        int mid = lo+(hi-lo)/2;

        if(fun(weights, mid)<=D){
            hi = mid;
        }else{
            lo = mid+1;
        }

    }

    return lo;

}

int main(){

    int n, D;
    cin>>n>>D;

    for(int i=0; i<n; i++)
        cin>>v[i];

    cout<<shipWithinDays(v, D);

return 0;
}
