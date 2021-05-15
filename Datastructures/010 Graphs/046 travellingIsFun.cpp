class unionFind{
public:
    int* componentId;
    unionFind(int n){
        this->componentId = new int[n];
        for(int i=0; i<n; i++){
            componentId[i] = i;
        }

    }
    int find_(int x){

        while(x!=componentId[x]){
            componentId[x] = componentId[componentId[x]];
            x = componentId[x];
        }
        return x;

    }
    void union_(int x, int y){
        int xId = find_(x);
        int yId = find_(y);
        componentId[xId] = yId;
    }
    ~unionFind(){
        delete[] componentId;
    }


};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if(n==0){
            vector<bool> res(queries.size(), false);
            return res;
        }

        unionFind components(n+1);
        for(int i=threshold+1; i<=n/2; i++){
            for(int j=2; j*i<=n; j++){
                components.union_(i, i*j);
            }
        }
        // for(int i=1; i<=n; i++){
        //     for(int j=1; j<=n; j++){
        //         if(__gcd(i, j)>threshold)
        //             components.union_(i, j);
        //     }
        // }

        vector<bool> res;
        for(int i=0; i<queries.size(); i++){

            if(components.find_(queries[i][0])==components.find_(queries[i][1]))
                res.push_back(1);
            else res.push_back(0);

        }

        return res;

    }
};



vector connectedCities(ll n, ll g, vector ori, vector des){
    // Complete this function
    vector v[n+1];
    for(ll i=g+1;i<=n;i++){
        for(ll j=2*i;j<=n;j+=i){
            v[i].push_back(j);
            v[j].push_back(i);
        }
    }

    queue q;
    ll c=0;
    vector vis(n+1,-1);
    for(ll i=1;i<=n;i++){

        if(vis[i]==-1){
            c++;
            vis[i]=c;
            q.push(i);
            while(!q.empty()){

                int p=q.front();
                q.pop();
                vis[p]=c;
                for(int j=0;j<v[p].size();j++){
                    if(vis[v[p][j]]==-1){
                        vis[v[p][j]]=c;
                        q.push(v[p][j]);
                    }
                }
            }
        }
    }
    vector ans;
    for(ll i=0;i<ori.size();i++){
        if(vis[ori[i]]==vis[des[i]]) ans.push_back(1);
        else ans.push_back(0);
    }
    return ans;
}



// brute force finding gcd
#include<bits/stdc++.h>
using namespace std;

class unionFind{
public:
    int* componentId;
    unionFind(int n){
        this->componentId = new int[n];
        for(int i=0; i<n; i++) componentId[i] = i;
    }
    int find_(int x){
        while(x!=componentId[x]){
            componentId[x] = componentId[componentId[x]];
            x = this->componentId[x];
        }
        return x;
    }
    void union_(int x, int y){

        int xId = find_(x);
        int yId = find_(y);

        this->componentId[xId] = yId;
    }

    ~unionFind(){
        delete[] componentId;
    }

};
int main(){


    vector<int> originCities = {1,2,4,6};
    vector<int> destinationCities = {3,3,3,4};

    int n = 6; // number of cities
    int g = 1; // threshold value

    vector<bool> isPossible(originCities.size());

    unionFind components(n+1);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(__gcd(i, j)>g) components.union_(i, j);
        }
    }

    for(int i=0; i<originCities.size(); i++){
        if(components.find_(originCities[i])==components.find_(destinationCities[i]))
            isPossible[i] = true;
        else isPossible[i] = false;
    }

    for(int i=0; i<isPossible.size(); i++) cout<<isPossible[i]<<" ";

}
