#include<bits/stdc++.h>
using namespace std;

vector<int> ans(vector<int> v, int k){

    priority_queue<int, vector<int>, greater<int> > minHeap;
    for(int i=0; i<v.size(); i++){

        minHeap.push(v[i]);
        if(minHeap.size()>k)
            minHeap.pop();

    }
    vector<int> ansV;
    while(!minHeap.empty()){
        ansV.push_back(minHeap.top());
        minHeap.pop();
    }
    reverse(ansV.begin(), ansV.end());
    return ansV;

}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int n, k; cin>>n>>k;
        vector<int> v(n);
        for(int j=0; j<n; j++)
            cin>>v[j];
        vector<int> ansV = ans(v, k);
        for(int j=0; j<ansV.size(); j++)
            cout<<ansV[j]<<" ";
        cout<<endl;

    }


return 0;
}
