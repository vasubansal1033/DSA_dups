#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)
// 6 5 2 4 5


void selectionSort(vector<int>& v){

    for(int i=0; i<v.size()-1; i++){
        int j, k;
        for(j=i,k=i; j<v.size(); j++){
            if(v[j]<v[k])
                k = j;
        }
        swap(v[i], v[k]);

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
        selectionSort(v);
        loop(j, n){
            cout<<v[j]<<" ";
        }
        cout<<endl;
    }

return 0;
}
