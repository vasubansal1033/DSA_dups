#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(long long int i=0; i<n; i++)
typedef long long int lli;

bool isValid(vector<lli>& v, lli n, lli m, lli mid){

    lli numStudents = 1;
    lli sum = 0;
    for(lli i=0; i<n; i++){

        if(sum+v[i]>mid){
            sum = v[i];
            numStudents++;
            if(numStudents>m)
                return false;
            }else{
                sum+=v[i];
            }

    }
    return true;

}
lli ans(vector<lli>& v, lli n, lli k){

    if(k>n){
        return -1;
    }
    lli start=INT_MIN, last=0;
    for(lli i=0; i<n; i++){
        start = max(start, v[i]);
        last+=v[i];
    }

    lli rem = -1;
    while(start<=last){
        lli mid = start+(last-start)/2;
        if(isValid(v, n, k, mid)){
            rem = mid;
            last = mid-1;
        }else{
            start = mid+1;
        }

    }

    return rem;

}
int main(){

    lli t; cin>>t;
    while(t--){
        lli n; cin>>n; vector<lli> v(n);
        for(lli j=0; j<n; j++){
            cin>>v[j];
        }
        lli k; cin>>k;
        cout<<ans(v, n, k)<<endl;
    }

return 0;
}
