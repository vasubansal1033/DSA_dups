#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)
int binarySearch(vector<int> v, int k){

    int start(0), last(v.size()-1);
    // start equals to last is also a valid condition!!!!
    while(start<=last){
        int mid = start+(last-start)/2;
        if(v[mid]==k)
            return mid;
        else if(v[mid]>k){
            last = mid-1;
        }else{
            start = mid+1;
        }
    }
    return -1; // reached here, means element not found

}
int main(){

    int n; cin>>n;
    vector<int> v(n);
    loop(i, n){
        cin>>v[i];
    }
    int first(v[0]), last(v[n-1]);
    if(first>last){
        // use BS for decreasing order
    }else if(first<last){
        // use BS for increasing order
    }else{
        // all elements are same, don't do anything
    }

return 0;
}
