#include<bits/stdc++.h>
using namespace std;

int partition_(vector<int>& v, int start, int last){

    int pivot = v[last];
    int pIndex = start; // always points to > pivot

    for(int i=start; i<last; i++){
        if(v[i]<=pivot){
            swap(v[i], v[pIndex]);
            pIndex++;
        }
    }
    swap(v[last], v[pIndex]);
    return pIndex;

}
void quickSort(vector<int>& v, int start, int last){

    if(start>=last) return;

    int pIndex = partition_(v, start, last);
    quickSort(v, start, pIndex-1);
    quickSort(v, pIndex+1, last);

}
int main(){


    int n; cin>>n; vector<int> v(n);
    for(int j=0; j<n; j++){
        cin>>v[j];
    }
    quickSort(v, 0, n-1);
    for(int j=0; j<n; j++)
        cout<<v[j]<<" ";



return 0;
}
