//https://www.geeksforgeeks.org/minimum-number-of-distinct-elements-after-removing-m-items-set-2/

#include<bits/stdc++.h>
using namespace std;

int util(vector<int>& v, int m){

    unordered_map<int, int> mp;
    for(int i=0; i<v.size(); i++)
        mp[v[i]]++;

    int res = mp.size();

    int freq[v.size()+1];
    memset(freq, 0, sizeof(freq));
    for(auto& it:mp){
        freq[it.second]++;
    }

    for(int i=1; i<v.size()+1; i++){
        if(freq[i]>0){

            int t = min(freq[i], m/i);
            res-=t;
            m-=(i*t);
        }
    }

    return res;

}
int main(){

    int n, m; cin>>n>>m;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    cout<<util(v, m);

return 0;
}
