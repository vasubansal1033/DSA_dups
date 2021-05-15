#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(long long int i=0; i<n; i++)
typedef long long int lli;

bool isValid(vector<lli>& v, lli k, lli mid){

    lli numStudents = 1;
    lli sum = 0;
    for(lli i=0; i<v.size(); i++){

        if(v[i]>mid)
            return false;
        sum+=v[i];
        if(sum>mid){
            sum = v[i];
            numStudents++;
        }
        if(numStudents>k)
            return false;

    }
    return true;

}
lli ans(vector<lli>& v, lli n, lli k){

    if(k>n){
        return -1;
    }

    if(k==n)
        return *max_element(v.begin(), v.end());

    lli start = *max_element(v.begin(), v.end());
    lli last = accumulate(v.begin(), v.end(), (lli)(0)); // IMPORTANTTTTTTT

    lli rem = -1;
    while(start<=last){
        lli mid = start+(last-start)/2;
        if(isValid(v, k, mid)){
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
    loop(i, t){
        lli n; cin>>n; vector<lli> v(n);
        loop(j, n){
            cin>>v[j];
        }
        lli k; cin>>k;
        cout<<ans(v, n, k)<<endl;
    }


}
