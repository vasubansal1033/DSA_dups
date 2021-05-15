#include<bits/stdc++.h>
using namespace std;

vector<int> ans(vector<int> v, int k, int x){

    int n = v.size();
    priority_queue<pair<int, int> > maxHeap;
    for(int i=0; i<n; i++){

        if(abs(x-v[i])!=0) // if we dont want the same element
            maxHeap.push({abs(x-v[i]), v[i]});
        if(maxHeap.size()>k)
            maxHeap.pop();

    }
    vector<int> ansV;
    while(!maxHeap.empty()){
        ansV.push_back(maxHeap.top().second);
        maxHeap.pop();
    }
    return ansV;

}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int n; cin>>n;
        vector<int> v(n);
        for(int j=0; j<n; j++)
            cin>>v[j];
        int k, x; cin>>k>>x;
        vector<int> ansV = ans(v, k, x);
        for(auto i:ansV)
            cout<<i<<" ";
        cout<<endl;

    }

return 0;
}
