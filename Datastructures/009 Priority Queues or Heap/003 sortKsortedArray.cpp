#include<bits/stdc++.h>
using namespace std;

vector<int> ans(vector<int> v, int k){

    int n = v.size();
    vector<int> ansV;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    for(int i=0; i<n; i++){
        minHeap.push(v[i]);
        if(minHeap.size()>k){
            ansV.push_back(minHeap.top());
            minHeap.pop();
        }
    }
    while(!minHeap.empty()){
        ansV.push_back(minHeap.top());
        minHeap.pop();
    }
    return ansV;

}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){
        int n, k; cin>>n>>k;
        vector<int> v(n);
        for(int j=0; j<n; j++)
            cin>>v[j];
        v = ans(v, k);
        for(int j=0; j<n; j++)
            cout<<v[j]<<" ";
        cout<<endl;
    }

return 0;
}
