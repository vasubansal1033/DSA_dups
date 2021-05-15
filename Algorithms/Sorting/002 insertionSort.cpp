#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)

void insertionSort(vector<int>& v){

    for(int i=1; i<v.size(); i++){

        int temp = v[i];
        int j=i-1;
        while(j>=0 && v[j]>temp){ // and because the first i elements are sorted in ascending order, if it's greater than the current, the it'll be greater the earlier elements also
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = temp;
    }

}
int main(){

    int t; cin>>t;
    loop(i, t){
        int n; cin>>n; vector<int> v(n);
        loop(j, n){
            cin>>v[j];
        }
        insertionSort(v);
        loop(j, n){
            cout<<v[j]<<" ";
        }
        cout<<endl;
    }


}
