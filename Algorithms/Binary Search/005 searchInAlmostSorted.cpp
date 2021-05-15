#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)

int ans(vector<int> v, int k){

    int n = v.size();
    int l(0), r(n-1);
    while(l<=r){
        int mid = r+(l-r)/2;
        if(v[mid]==k){
            return mid;
        }else if(mid-1>=l && v[mid-1]==k){
            return mid-1;
        }else if(mid+1<=r && v[mid+1]==k){
            return mid+1;
        }else if(v[mid]<k){
            l = mid+2;
        }else{
            r = mid-2;
        }


    }
    return -1;

}
int main(){

    int t; cin>>t;
    loop(i, t){
        int n, k; cin>>n>>k;
        vector<int> v(n);
        loop(j, n){
            cin>>v[j];
        }
        cout<<ans(v, k)<<endl;
    }

return 0;
}
