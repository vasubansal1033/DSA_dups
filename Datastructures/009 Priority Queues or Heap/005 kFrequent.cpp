#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
vector<int> topKFrequent(vector<int>& nums, int k){

    // most -> minheap
    unordered_map<int, int> eleFreq;
    for(int i=0; i<nums.size(); i++)
        eleFreq[nums[i]]++;

    priority_queue<p, vector<p>, greater<p> > minHeap;
    for(auto i = eleFreq.begin(); i!=eleFreq.end(); i++){

        minHeap.push({i->second, i->first});
        if(minHeap.size()>k)
            minHeap.pop();

    }
    vector<int> ans;
    while(!minHeap.empty()){
        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return ans;

}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int n, k; cin>>n>>k; vector<int> v(n);
        for(int j=0; j<n; j++)
            cin>>v[j];
        vector<int> ans= topKFrequent(v, k);
        for(auto x:ans)
            cout<<x<<" ";
        cout<<endl;

    }

return 0;
}
