#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)

void bubbleSort(vector<int>& v){

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(v[j]>v[j+1]){
                v[j] = v[j]+v[j+1];
                v[j+1] = v[j]-v[j+1];
                v[j] = v[j]-v[j+1];
            }
        }
    }

}
int main(){

    int t; cin>>t;
    loop(i, t){
        int n; cin>>n; vector<int> v(n);
        loop(j, n){
            cin>>v[j];
        }
        bubbleSort(v);
        for(int j=0; j<v.size(); j++)
            cout<<v[j]<<" ";
        cout<<endl;
    }

}
