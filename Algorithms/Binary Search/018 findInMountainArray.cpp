#include<bits/stdc++.h>
using namespace std;

int findInMountainArray(int target, MountainArray &mountainArr) {

    int sz = mountainArr.length();
    int start(0), last(sz-1);

    // find the peak index
    while(start<last){

        int mid = start+(last-start+1)/2;
        if(mountainArr.get(mid)>mountainArr.get(mid-1)){
            start = mid;
        }else{
            last = mid-1;
        }

    }

    int peakIndex = start;
    start = 0, last = peakIndex;

    // search in start to peak index part
    while(start<last){

        int mid = start+(last-start+1)/2;
        if(mountainArr.get(mid)<=target) // so as to get the first occurence
            start = mid;
        else{
            last = mid-1;
        }

    }

    // if found then return
    if(mountainArr.get(start)==target)
        return start;

    // else search in remaining part
    start = peakIndex+1, last = sz-1;

    while(start<last){

        int mid = start+(last-start+1)/2;
        // this part is in decreasing order
        if(mountainArr.get(mid)>=target)
            start = mid;
        else{
            last = mid-1;
        }

    }
    if(mountainArr.get(start)==target)
        return start;


  return -1;
}

int main(){

    int n; cin>>n; vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    cout<<findInMountainArray(v);

}
