#include<bits/stdc++.h>
using namespace std;

// this function calculates the mutated sum
int fun(vector<int>& arr, int num){

    int sum = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]<=num){
            sum+=arr[i];
        }else{
            sum+=num;
        }
    }

    return sum;

}

int findBestValue(vector<int>& arr, int target) {

    int hi = 0;
    for(int i=1; i<arr.size(); i++){
        if(arr[i]>arr[hi]){
            hi = i;
        }
    }
    // search space is between target divided by size to the maximum element in array
    hi = arr[hi];
    int lo = target/arr.size();

    // create a diff variable to store difference
    int diff = INT_MAX, ans;

    while(lo<hi){

        int mid = lo+(hi-lo)/2;

        // if diff is lower then previous, update it and store the value of mid
        if(abs(fun(arr, mid)-target)<diff){

            diff = abs(fun(arr, mid)-target);
            ans = mid;
        }
        // if fun is lower than target, try increasing mid
        if(fun(arr, mid)<target){
            lo = mid+1;
        }
        // if fun is higher than target, try decreasing mid
        else{
            hi = mid-1;
        }

    }

    // at the end answer is between ans and lo
    if(abs(fun(arr, ans)-target)<abs(fun(arr, lo)-target))
        return ans;
    else if(abs(fun(arr, ans)-target)>abs(fun(arr, lo)-target))
        return lo;
    // if both have same diff, then return the minimum of the two
    else return min(lo, ans);

}
int main(){

    int n; cin>>n; vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    cout<<


return 0;
}
