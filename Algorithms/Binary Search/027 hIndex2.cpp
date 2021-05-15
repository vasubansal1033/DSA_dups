#include<bits/stdc++.h>
using namespace std;

int ceilInArray(vector<int>& citations, int target){

    int lo(0), hi(citations.size()-1);

    while(lo<hi){

        int mid = lo+(hi-lo)/2;
        if(citations[mid]>=target)
            hi = mid;
        else
            lo = mid+1;
    }

    return lo;

}
int hIndex(vector<int>& citations) {

    int n = citations.size();
    if(n==0)
        return 0;

    if(citations[n-1]==0)
        return 0;


    int lo(0), hi(n);

    while(lo<hi){

        int mid = lo+(hi-lo+1)/2;
        if(n-ceilInArray(citations, mid)>=mid){
            lo = mid;
        }else{
            hi = mid-1;
        }

    }

    return lo;

}

int main(){

    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    cout<<hIndex(v);

return 0;
}
