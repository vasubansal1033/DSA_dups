#include<bits/stdc++.h>
using namespace std;


int ans(vector<int>& v){

    int i(0), j(v.size()-1);
    int count_(0);
    while(i<j){

        if(v[i]<v[j]){
            i++;
            v[i]+=v[i-1];
            count_++;
        }else if(v[i]>v[j]){
            j--;
            v[j]+=v[j+1];
            count_++;
        }else{
            i++;
            j--;
        }


    }
    return count_;

}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int n; cin>>n; vector<int> v(n);
        for(int j=0; j<n; j++)
            cin>>v[j];

        cout<<ans(v)<<endl;

    }


return 0;
}
