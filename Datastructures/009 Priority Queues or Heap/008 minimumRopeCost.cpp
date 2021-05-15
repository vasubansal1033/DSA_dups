#include<bits/stdc++.h>
using namespace std;
typedef long int li;
li ans(vector<li> v){

    priority_queue<li, vector<li>, greater<li> > minHeap;
    for(li i=0; i<v.size(); i++){
        minHeap.push(v[i]);
    }
    li sum =0;
    while(minHeap.size()>1){

        li first = minHeap.top(); minHeap.pop();
        li second = minHeap.top(); minHeap.pop();
        sum+=(first+second);
        minHeap.push(first+second);
    }

    return sum;

}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        li n; cin>>n; vector<li> v(n);
        for(li j=0; j<n; j++)
            cin>>v[j];
        cout<<ans(v)<<endl;

    }

}
