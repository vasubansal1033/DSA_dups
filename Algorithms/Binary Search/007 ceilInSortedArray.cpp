#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)
typedef long long int lli;

lli ceil(vector<lli> v, lli k){

    lli start(0), last(v.size()-1);
    lli ans = -1;
    while(start<=last){
        lli mid = last+(start-last)/2;
        if(v[mid]==k)
            return mid;
        else if(v[mid]<k){

            start = mid+1;
        }else{
            ans = mid;
            last = mid-1;
        }
    }
    return ans;

}
int main(){

    int t; cin>>t;
    loop(i, t){
        lli n, k; cin>>n>>k;
        vector<lli> v(n);
        loop(j, n){
            cin>>v[j];
        }
        cout<<ceil(v, k)<<endl;
    }

return 0;
}

