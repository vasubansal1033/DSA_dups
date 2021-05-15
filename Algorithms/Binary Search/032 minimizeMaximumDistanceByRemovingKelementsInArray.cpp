// different from 030 in two ways
// Here we have to remove k elements to get the answer
// Minimize the maximum distance

#include <bits/stdc++.h>
using namespace std;

int ans(vector<int>& v, int k){

    int lo = 0, hi = INT_MAX;
    int n = v.size();
    // finding the longest subarray with max consecutive diff less than mid
    while(lo<hi){

        int mid = lo+(hi-lo)/2;
        int cnt = 1, cmax = 1;

        for(int i=1; i<n; i++){

            if(v[i]-v[i-1]>mid)
                cnt = 1;
            else
                cnt++;
            cmax = max(cmax, cnt);

        }

        if(n-cmax<=k){
            hi = mid;
        }else{
            lo = mid+1;
        }

    }

    return lo;

}
int main() {

    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    cout<<ans(v, k);

}
