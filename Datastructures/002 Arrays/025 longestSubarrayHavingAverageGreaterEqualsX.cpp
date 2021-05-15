#include<bits/stdc++.h>
using namespace std;

// Find the length of the longest subarray, having average >= X

int util(vector<int>& v, int X){

    // subtract X from every element in v
    // Now consider the prefixSum array of this modified array
    // Task is to find prefixSum[j]>prefixSum[i] such that j-i is maximum
    // prefixSum[j]-prefixSum[i]>0 ensures that average of elements greater than X
    // maximum j-i means longest subarray

    for(int i=0; i<v.size(); i++) v[i] -=X;
    for(int i=1; i<v.size(); i++) v[i] = v[i]+v[i-1];
    vector<int> maximumOnRight(v.size());
    maximumOnRight[v.size()-1] = v[v.size()-1];

    for(int i=v.size()-2; i>=0; i--) maximumOnRight[i] = max(maximumOnRight[i+1], v[i]);

    int res = 0;
    for(int i=0; i<v.size(); i++){

        int lo = i, hi = v.size()-1;
        while(lo<hi){

            int mid = lo+(hi-lo+1)/2;
            if(v[i]<=maximumOnRight[mid]){
                lo = mid;
            }else{
                hi = mid-1;
            }

        }
//        res = max(res, lo-i);
        if(res<lo-i){
            res = lo-i+1;
        }

    }

    return res;

}
int main(){

//    int n, x; cin>>n>>x;
//    vector<int> v(n);

    vector<int> v = {1, 1, 2, -1, -1, 1};
    int x = 1;

//    for(int i=0; i<n; i++) cin>>v[i];

    cout<<util(v, x);

return 0;
}
