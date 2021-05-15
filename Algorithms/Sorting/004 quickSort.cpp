#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)

// Choosing the pivot as last element
int partition_(vector<int>& v, int start, int last){

    int pi = v[last];
    int pIndex = start; // points at element greater than pivot
    for(int i=start; i<last; i++){
        if(v[i]<=pi){
            swap(v[i], v[pIndex]);
            pIndex++;
        }
    }
    swap(v[pIndex], v[last]);
    return pIndex;

}
void quickSort(vector<int>& v, int start, int last){
    if(start>=last)
        return;
    int pIndex = partition_(v, start, last);
    quickSort(v, start, pIndex-1);
    quickSort(v, pIndex+1, last);
}
int main(){

    int t; cin>>t;
    loop(i, t){
        int n; cin>>n; vector<int> v(n);
        loop(j, n){
            cin>>v[j];
        }
        quickSort(v, 0, n-1);
        loop(j, n)
            cout<<v[j]<<" ";
        cout<<endl;

    }

return 0;
}
