#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;


class myComparator{
public:
    int operator()(p& p1, p& p2){

        if(p1.first<p2.first)
            return true;
        else if(p1.first>p2.first)
            return false;
        else{
            if(p1.second>p2.second)
                return true;
            else return false;
        }

    }
};
vector<int> frequencySort(vector<int> v){

    unordered_map<int, int> freqMap;
    for(int i=0; i<v.size(); i++)
        freqMap[v[i]]++;

    priority_queue<p, vector<p>, myComparator> maxHeap;
    for(auto i: freqMap)
        maxHeap.push({i.second, i.first}); // freq, element
    vector<int> ans;
    while(!maxHeap.empty()){

        p temp = maxHeap.top();
        int j = temp.first;
        while(j>0){
            ans.push_back(temp.second);
            j--;
        }

        maxHeap.pop();

    }
    return ans;

}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int n; cin>>n; vector<int> v(n);
        for(int j=0; j<n; j++)
            cin>>v[j];
        v = frequencySort(v);
        for(auto j:v)
            cout<<j<<" ";
        cout<<endl;
    }

}
