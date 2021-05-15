#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)

int ans(vector<int> v){

    int start(0), last(v.size()-1);
    while(start<=last){
        int mid = start+(last-start)/2;

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
int main(){

    int t; cin>>t;
    loop(i, t){
        int n; cin>>n;
        vector<int> v(n);
        loop(j, n){
            cin>>v[j];
        }
        cout<<ans(v);
    }

return 0;
}

