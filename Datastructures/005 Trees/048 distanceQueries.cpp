#include<bits/stdc++.h>
using namespace std;

int n, q;
vector<vector<int> > adjList;
int **up;
int* levels;

void binary_lifting(int curr, int parent, int lvl){

    up[curr][0] = parent;
    levels[curr] = lvl;
    for(int i=1; i<20; i++){
        if(up[curr][i-1]!=-1) up[curr][i] = up[up[curr][i-1]][i-1];
        else up[curr][i] = -1;
    }
    for(int i=0; i<adjList[curr].size(); i++){
        int child = adjList[curr][i];
        if(child!=parent){
            binary_lifting(child, curr, lvl+1);
        }
    }

}
int getKthAncestor(int u, int k){
    if(k==0 || u==-1) return u;

    int lastSetBit = log2(k&(-k));
    return getKthAncestor(up[u][lastSetBit], k-(k&(-k)));

}
int getLCA(int u, int v){

    if(levels[u]<levels[v]) swap(u, v);

    u = getKthAncestor(u, levels[u]-levels[v]);
    if(u==v) return u;

    for(int j=19; j>=0; j--){
        if(up[u][j]!=up[v][j]){
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>>n>>q;
    vector<vector<int> > edgeList;
    for(int i=0; i<n-1; i++){
        int u, v; cin>>u>>v;
        edgeList.push_back({u-1, v-1});
    }

//    for(int i=0; i<edgeList.size(); i++) cout<<edgeList[i][0]<<" "<<edgeList[i][1]<<'\n';

    adjList.resize(n);
    for(int i=0; i<edgeList.size(); i++){
        adjList[edgeList[i][0]].push_back(edgeList[i][1]);
        adjList[edgeList[i][1]].push_back(edgeList[i][0]);
    }

    up = new int*[n];
    for(int i=0; i<n; i++){
        up[i] = new int[20];
        memset(up[i], -1, sizeof(int)*20);
    }
    levels = new int[n];
    memset(levels, -1, sizeof(int)*n);

    binary_lifting(0, -1, 0);

    for(int i=0; i<q; i++){
        int u, v; cin>>u>>v;
        u--; v--;
        int lca = getLCA(u, v);

        cout<<(levels[u]-levels[lca])+(levels[v]-levels[lca])<<'\n';
    }

return 0;
}
