#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)
// This is O(nlogn)
// Inplace mergesort is On2
void merge_(vector<int>& v, int start, int mid, int last){

    int n1 = mid-start+1; int n2 = last-mid;
    vector<int> leftArray(n1);
    vector<int> rightArray(n2);

    for(int i=0; i<n1; i++){
        leftArray[i] = v[start+i];
    }
    for(int j=0; j<n2; j++){
        rightArray[j] = v[j+mid+1];
    }

    int i(0), j(0), k(start);
    while(i<n1 && j<n2){
        if(leftArray[i]<=rightArray[j]){
            v[k] = leftArray[i];
            i++;
        }else{
            v[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        v[k] = leftArray[i];
        i++; k++;
    }
    while(j<n2){
        v[k] = rightArray[j];
        j++; k++;
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
void mergeSortIterative(vector<int>& v){

    int p;
    for(p=2; p<=v.size(); p=p*2){

        for(int i=0; p+i-1<v.size(); i+=p){
            int start = i; int last = i+p-1; int mid = start+(last-start)/2;
            merge_(v, start, mid, last);
        }
    }

    if(p/2<v.size()){
        merge_(v, 0, p/2-1, v.size()-1);
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
        mergeSortIterative(v);
        loop(j, n){
            cout<<v[j]<<" ";
        }
        cout<<endl;
    }

return 0;
}
