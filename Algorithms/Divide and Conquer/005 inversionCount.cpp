#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)
typedef unsigned long long int ulli;
// This is O(nlogn)

ulli merge_(vector<int>& v, int start, int mid, int last){

    int n1 = mid-start+1; int n2 = last-mid;
    vector<int> leftArray(n1);
    vector<int> rightArray(n2);
    ulli count = 0;
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
            count+= mid-(start+i)+1;
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
    return count;

}

ulli mergeSort(vector<int>& v, int start, int last){
    if(start>=last)
        return 0;

    ulli count = 0;
    int mid = start+(last-start)/2;
    count+=mergeSort(v, start, mid);
    count+=mergeSort(v, mid+1, last);
    count+=merge_(v, start, mid, last);
    return count;
}
int main(){

    int t; cin>>t;
    loop(i, t){
        int n; cin>>n;
        vector<int> v(n);
        loop(j, n){
            cin>>v[j];
        }
        cout<<mergeSort(v, 0 , n-1)<<endl;


    }

return 0;
}
