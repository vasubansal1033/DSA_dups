#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)

int ans(vector<int> v, int k){

    int start(0), last(v.size()-1);
    while(start<=last){
        int mid = start+(last-start)/2;
        if(v[mid]==k){
            return 0;
        }else if(v[mid]>k){
            last = mid-1;
        }else{
            start = mid+1;
        }
    }
    if(start==-1) return abs(k-v[last]);
    else if(last==-1) return abs(k-v[start]);
    else if(start==v.size()) return abs(k-v[last]);
    else if(last==v.size()) return abs(k-v[start]);
    else
    return min(abs(k-v[start]),
               abs(k-v[last]));

}
int main(){

    int t; cin>>t;
    loop(i, t){
        int n, k; cin>>n>>k;
        vector<int> v(n);
        loop(j, n ){
            cin>>v[j];
        }
        cout<<ans(v, k)<<endl;

    }

return 0;
}
