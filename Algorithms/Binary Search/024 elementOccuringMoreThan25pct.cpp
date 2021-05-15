#include<bits/stdc++.h>
using namespace std;

// finds the first occurence of target in sorted arr
int firstOccurence(vector<int>& arr, int target){

    int lo(0), hi(arr.size()-1);

    while(lo<hi){

        int mid = lo+(hi-lo)/2;
        if(arr[mid]>=target){
            hi = mid;
        }else{
            lo = mid+1;
        }

    }
    return lo;

}
int findSpecialInteger(vector<int>& arr) {

    // approach
    // find the element at n/4, n/2, 3n/4 index
    // for them find the first occurence in the array
    // if element at start+(n/4) is the same element then that is the element

    int n = arr.size();

    int index = firstOccurence(arr, arr[n/4]);
    if(arr[index+(n/4)]==arr[index])
        return arr[index];

    index = firstOccurence(arr, arr[n/2]);
    if(arr[index+(n/4)]==arr[index])
        return arr[index];

    index = firstOccurence(arr, arr[n*0.75]);
    if(arr[index+(n/4)]==arr[index])
        return arr[index];

    return -1;

}

int main(){

    int n; cin>>n; vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    cout<<

return 0;
}
