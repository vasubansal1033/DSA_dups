#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
#define loop(i, n) for(int i=0; i<n; i++)

ulli merge_(vector<int>& v, int start, int mid, int last){

    int n1 = mid-start+1;
    int n2 = last-(mid+1)+1;

    vector<ulli> v1(n1), v2(n2);

    for(int i=0; i<n1; i++){
        v1[i] = v[start+i];
    }
    for(int i=0; i<n2; i++){
        v2[i] = v[mid+1+i];
    }

    int i(0), j(0), k(start);
    ulli count = 0;
    while(i<n1 && j<n2){

        if(v1[i]<=v2[j]){
            v[k] = v1[i];
            i++;
        }else{
            count += (n1-i);
            v[k] = v2[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        v[k] = v1[i];
        i++; k++;
    }
    while(j<n2){
        v[k] = v2[j];
        j++; k++;
    }

    return count;
}
ulli mergeSort_(vector<int>& v, int start, int last){

    if(start>=last)
        return 0;

    ulli count = 0;
    int mid = start+(last-start)/2;
    count += mergeSort_(v, start, mid);
    count += mergeSort_(v, mid+1, last);
    count += merge_(v, start, mid, last);

    return count;

}

ulli ans(vector<int>& v){
    return mergeSort_(v, 0, v.size()-1);
}
int main(){

    int t; cin>>t;
    loop(i, t){

        int n; cin>>n; vector<int> v(n);
        loop(j, n){
            cin>>v[j];
        }
        cout<<ans(v)<<endl;

    }

}
