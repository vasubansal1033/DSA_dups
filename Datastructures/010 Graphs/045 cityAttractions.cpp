// https://leetcode.com/discuss/interview-question/515737/sap-labs-oa

#include<bits/stdc++.h>
using namespace std;

int n, m, max_t;
int ans = 0;

vector<int> beauty, u, v, t;
vector<pair<int, int>> adj[10000];
bool vis[10000];

void dfs(int s, int t, int ct){

    if(t > max_t)
        return;

    if(s ==0 ){
        ans = max(ans, ct);
    }

    for(int i=0;i<adj[s].size();i++){

        int x = adj[s][i].first;
        int d = adj[s][i].second;

        if(vis[x])
            dfs(x, t + d, ct);
        else{
            vis[x] = true;
            dfs(x, t+d, ct + beauty[x]);
            vis[x] = false;
        }

    }

}

void solve(){

    for(int i=0;i<m;i++){
        adj[u[i]].push_back({v[i], t[i]});

        adj[v[i]].push_back({u[i], t[i]});
    }

    vis[0] = true;
    dfs(0, 0, beauty[0]);

}

int main(){

    /*
    5 5 60
    3 7 5 6 8
    0 2 2 0 1
    1 0 3 4 3
    10 16 13 20  15
    */

    cin>>n>>m>>max_t;

    beauty.resize(n);
    u.resize(m);
    v.resize(m);
    t.resize(m);

    for(int i=0;i<n;i++)
        cin>>beauty[i];

    for(int i=0;i<m;i++)
        cin>>u[i];

    for(int i=0;i<m;i++)
        cin>>v[i];

    for(int i=0;i<m;i++)
        cin>>t[i];

    solve();

    cout<<ans<<endl;

return 0;
}


