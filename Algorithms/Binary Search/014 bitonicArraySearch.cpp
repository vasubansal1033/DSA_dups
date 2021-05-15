#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)
typedef long long int lli;
lli binarySearch(vector<lli>& v, lli k, lli start, lli last, lli key){

    if(key==0) // array is sorted in ascending order
    {
        while(start<=last){
            lli mid = start+(last-start)/2;
            if(v[mid]==k){
                return mid;
            }else if(v[mid]>k){
                last = mid-1;
            }else{
                start = mid+1;
            }
        }
        return -1;
    }else{

        while(start<=last){
            lli mid = start+(last-start)/2;
            if(v[mid]==k){
                return mid;
            }else if(v[mid]<k){
                last = mid-1;
            }else{
                start = mid+1;
            }
        }
        return -1;

    }
    return -1;

}
lli peak(vector<lli>& v){

    lli start(0), last(v.size()-1);
    while(start<=last){
        lli mid = start+(last-start)/2;

        if(mid!=0 && mid!=v.size()-1){
            if(v[mid]>v[mid-1] && v[mid]>v[mid+1]){
                return mid;
            }else if(v[mid]<v[mid+1]){
                start = mid+1;
            }else if(v[mid]<v[mid-1]){
                last = mid-1;
            }
        }else{
            if(mid==0){
                if(v[mid]>v[mid+1])
                    return mid;
                else start = mid+1;

            }else if(mid==v.size()-1){
                if(v[mid]>v[mid-1])
                    return mid;
                else last = mid-1;
            }
        }
    }

}
lli ans(vector<lli> v, lli k){

    if(v.size()==1){
        return v[0]==k?0:-1;
    }else if(v.size()==2){
        return v[0]==k?0:v[1]==k?1:-1;
    }

    lli start(0), last(v.size()-1);
    // 1 2 5 3 2 1
    lli peakIndex = peak(v);
    lli a = binarySearch(v, k, 0, peakIndex-1, 0);
    lli b = binarySearch(v, k, peakIndex, v.size()-1, 1);

    if(a+b+1<0)
        return -1;
    else return a+b+1;

}
int main(){

    int t; cin>>t;
    loop(i, t){

        lli n, k; cin>>n; vector<lli> v(n);
        loop(j, n){
            cin>>v[j];
        }
        cin>>k;
        cout<<ans(v, k)<<endl;

    }

return 0;
}
