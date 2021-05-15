#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)

int ans(vector<int>& v){

    int n = v.size();

    if(n==1)
        return v[0];
    int start(0), last(n-1);

    while(start<=last){
        // check if current array is sorted or not
        if(v[start]<v[last]){
            return v[start];
        }
        int mid = start+(last-start)/2;
        // check if the current array is sorted in descending order
        if(v[start]>=v[mid] && v[mid]>=v[last]){
            return v[last];
        }
        // Used slack equality as mid might get equal to start or end
        // check pivot property
        if(v[mid]<v[(mid-1)%n] && v[mid]<=v[(mid+1)%n]){
            return v[mid];
        }else if(v[mid]<=v[last]){
            last = mid;
        }else if(v[start]<=v[mid]){
            start = (mid+1)%n;
        }

    }
    return -1;

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
