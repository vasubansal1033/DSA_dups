#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)
// 1 1 3 5 4 6
void merge_(vector<int>& v, int start, int mid, int last){

    // The half sorted is already overall sorted
    if(v[mid]<=v[mid+1])
        return;

    int i(start), j(mid+1);
    while(i<=mid && j<=last){

        if(v[i]<=v[j])
            i++;
        else{

            // Shift all the elements between ith and jth towards left by one. Store the jth element. Finally copy it at correct place
            int temp = v[j], tempIndex = j;
            while(tempIndex>i){
                v[tempIndex] = v[tempIndex-1];
                tempIndex--;
            }
            v[i] = temp;
            i++;
            j++;
            mid++;
        }
        loop(a, v.size()){
            cout<<v[a]<<" ";
        }
        cout<<endl;
    }

}
void mergeSort(vector<int>& v, int start, int last){

    if(start>=last)
        return;

    int mid = start+(last-start)/2;
    mergeSort(v, start, mid);
    mergeSort(v, mid+1, last);
    merge_(v, start, mid, last);
}
int main(){

    int t; cin>>t;
    loop(i, t){
        int n; cin>>n;
        vector<int> v(n);
        loop(j, n){
            cin>>v[j];
        }
        mergeSort(v, 0, n-1);
        loop(j, n){
            cout<<v[j]<<" ";
        }
        cout<<endl;
    }

return 0;
}
