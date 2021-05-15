#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i=0; i<n; i++)
// a c d e f // f
char ans(vector<char> v, char k){

    int start(0), last(v.size()-1);
    char c = '#';
    while(start<=last){
        int mid = last+(start-last)/2;
        if(v[mid]==k){
            start = mid+1;
        }else if(v[mid]<k){
            start = mid+1;
        }else{
            c = v[mid];
            last = mid-1;
        }
    }
    return c;

}
int main(){

    int t; cin>>t;
    loop(i, t){
        int n; char k; cin>>n>>k;
        vector<char> v(n);
        loop(j, n){
            cin>>v[j];
        }
        cout<<ans(v, k)<<endl;
    }



}
