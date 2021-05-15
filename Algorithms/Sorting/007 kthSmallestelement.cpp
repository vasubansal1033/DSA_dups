// quickselect

#include<bits/stdc++.h>
using namespace std;

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
//void quickSort(vector<int>& v, int start, int last){
//
//    if(start>=last)
//        return;
//
//    int partitionIndex = partition_(v, start, last);
//    quickSort(v, start, partitionIndex);
//    quickSort(v, partitionIndex+1, last);
//
//
//}
int kthSmallest(vector<int>& v, int k){

   int start = 0;
   int last = v.size()-1;

   while(last>start){

        int j = partition_(v, start, last);
        if(j<k){
            start = j+1;
        }else if(j>k){
            last = j-1;
        }else return v[k];

   }
   return v[k];


}
int main(){

//    int n, k; cin>>n>>k;
//    vector<int> v(n);
//    for(int i=0; i<n; i++){
//        cin>>v[i];
//    }
    int n(6), k(0);
    vector<int> v = {7, 3, 4, 20, 15, 10};
    cout<<kthSmallest(v, k);


return 0;
}
