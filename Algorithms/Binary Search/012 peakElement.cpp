#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)


int ans(vector<int>& v) {

    int n = v.size();
    int lo = 0;
    int hi = n-1;

    while(lo<hi){

        int mid = lo+(hi-lo)/2;

        if(mid==0){
            if(v[mid]>v[mid+1])
                return mid;
            else
                lo = mid+1;
        }else if(mid==n-1){
            if(v[mid]>v[mid-1])
                return mid;
            else
                hi = mid-1;
        }

        else if(v[mid]>v[mid-1] && v[mid]>v[mid+1]){
            return mid;
        }else if(v[mid]<v[mid-1]){
            hi = mid-1;
        }else if(v[mid]<v[mid+1]){
            lo = mid+1;
        }

    }

    return lo;

}

int main(){

    int t; cin>>t;
    loop(i, t){
        int n; cin>>n;
        vector<int> v(n);
        loop(j, n){
            cin>>v[j];
        }
        cout<<ans(v)<<endl;
    }

return 0;
}
