#include<bits/stdc++.h>
using namespace std;

int** up;
int* levels;
vector<vector<int> > adjList;

void binary_lifting(int curr, int parent, int lvl){

    up[curr][0] = parent;
    levels[curr] = lvl;

    for(int i=1; i<20; i++){
        if(up[curr][i-1]!=-1){
            up[curr][i] = up[up[curr][i-1]][i-1];
        }else up[curr][i] = -1;
    }

    for(int i=0; i<adjList[curr].size(); i++){
        int child =  adjList[curr][i];
        if(child!=parent){
            binary_lifting(child, curr, lvl+1);
        }
    }

}

int getKthAncestor(int node, int k) {

    // base case

    if(k==0 || node==-1) return node;

    int lastSetBit = log2(k&(-k));
    return getKthAncestor(up[node][(lastSetBit)], k-(k&(-k)));

}
int main(){

//    ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int n, q; cin>>n>>q;

    vector<int> parents(n+1);
    parents[1] = -1; // general manager
    for(int i=2; i<=n; i++){
        cin>>parents[i];
    }

    up = new int*[n+1];
    for(int i=0; i<=n; i++){
        up[i] = new int[20];
        memset(up[i], -1, sizeof(int)*20);
    }

    levels = new int[n+1];
    memset(levels, 0, sizeof(int)*(n+1));

    adjList.resize(n+1);
    for(int i=2; i<=n; i++){
        adjList[parents[i]].push_back(i);
    }

    binary_lifting(1, -1, 1);

    for(int i=0; i<q; i++){

        int u, v; cin>>u>>v;
        if(levels[u]<levels[v]) swap(u, v);

        u = getKthAncestor(u, levels[u]-levels[v]);

        if(u==v){
            cout<<u<<'\n';
            continue;
        }


        for(int j=19; j>=0; j--){

            if(up[u][j]!=up[v][j]){
                u = up[u][j];
                v = up[v][j];
            }
        }

        cout<<up[u][0]<<'\n';

    }


return 0;
}
