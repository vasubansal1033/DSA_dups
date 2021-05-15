#include<bits/stdc++.h>
using namespace std;

class graph{

    int v, e; vector<pair<int, int> >* adj;
public:
    graph(int v){
        this->v = v;
        e = 0;
        adj = new vector<pair<int, int> >[v];
    }
    int getEdges(){
        return e;
    }
    int getVertices(){
        return v;
    }
    vector<pair<int, int> >* getAdjacencyList(){
        return adj;
    }

    void addEdge(int u, int v, int wgt){
        adj[u].push_back({v, wgt});
        adj[v].push_back({u, wgt});
    }


};

vector<pair<int, int> > prims(int v, vector<pair<int, int> >* adj){

    vector<bool> vis(v, false); // visited array
    vector<int> nbr_tv(v, -1); // neighbour of ith vertex in the mst
    vector<int> dis_tv(v, INT_MAX); // stores minimum weight edge for ith node

    vector<pair<int, int> > te; // list of spanning tree edges

    // start with any vertex
    int s = 0;
    vis[s] =  true; // mark it visited
    for(auto p:adj[s]){ // set the weights of its neighbours, as the current estimates
        nbr_tv[p.first] = s;
        dis_tv[p.first] = p.second;
    }

    // mst will have n-1 edges.
    for(int i=0;i<v-1; i++){

        // choose u s.t. u is not visited and dis_tv[u] is minimum
        int mini = INT_MAX;
        int u;
        for(int j=0; j<v; j++){
            if(!vis[j]){

                if(dis_tv[j]<mini){
                    mini = dis_tv[j]; u = j;
                }

            }
        }

        vis[u] = true;
        te.push_back({u, nbr_tv[u]});
        for(auto p: adj[u]){

            if(!vis[p.first]){
                if(dis_tv[p.first]>p.second){
                    dis_tv[p.first] = p.second;
                    nbr_tv[p.first] = u;
                }
            }

        }


    }

    for(auto i:dis_tv)
        cout<<i<<" ";
    cout<<endl;
    for(auto i:nbr_tv)
        cout<<i<<" ";
    cout<<endl;


    return te;

}

int main(){

//    int v, e; cin>>v>>e;
//    graph g(v);
//    for(int i=0; i<e; i++){
//
//        int u, v, wgt; cin>>u>>v>>wgt;
//        g.addEdge(u, v, wgt);
//
//    }

    graph g(7);
    g.addEdge(0, 2, 18);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 6);
    g.addEdge(2, 3, 70);
    g.addEdge(1, 4, 20);
    g.addEdge(4, 5, 10);
    g.addEdge(4, 6, 10);
    g.addEdge(5, 6, 5);


    vector<pair<int, int> > ans = prims(g.getVertices(), g.getAdjacencyList());
    for(auto p:ans)
        cout<<p.first+1<<" "<<p.second+1<<endl;

return 0;
}
