#include<bits/stdc++.h>
using namespace std;

int peakIndexInMountainArray(vector<int>& A) {

    if(A.size()>=3){


        int start(0), last(A.size()-1);
        while(start<last){

            int mid = start+(last-start+1)/2; // using high mid as last is getting reduced less than half
            // predicate function
            // we want the last occurence of T
            if(A[mid]>A[mid-1]){
                start = mid;
            }else{
                last = mid-1;
            }

        }

     return start;
    }
    return -1;

}

int main(){

    int n; cin>>n; vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    cout<<peakIndexInMountainArray(v);

}
