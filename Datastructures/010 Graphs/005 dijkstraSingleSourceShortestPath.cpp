// Dijkstra's algorithm single source shortest path
// Used to find the shortest path from a fixed vertex and every other vertex
// Works for both directed and undirected graphs
// Negative weights not included

#include<bits/stdc++.h>
using namespace std;

class graph{

    int v, e; vector<pair<int, int> >* adj;

public:
    graph(int v){
        this->v = v;
        e=0;
        adj = new vector<pair<int, int> >[v];
    }
    int getVertices(){
        return v;
    }
    int getEdges(){
        return e;
    }
    vector<pair<int, int> >* getAdjacencyList(){
        return adj;
    }

    void addEdge(int u, int v, int wgt){
        adj[u].push_back({v, wgt});
        adj[v].push_back({u, wgt});

        e++;
    }

};

vector<int> dijkstraAlgo(int s, int v, vector<pair<int, int> >* adj){

    vector<bool> vis(v, false);
    vector<int> dis(v, INT_MAX);

    dis[s] = 0;

    for(int i=0; i<v; i++){

        // find u s.t. u is not visited and dis[u] is min
        int mini = INT_MAX;
        int u;
        for(int j=0; j<v; j++){

            if(!vis[j]){
                if(dis[j]<mini){
                    mini = dis[j];
                    u = j;
                }
            }

        }

        // make u visited, and see if it's neighbouring nodes can be visited cheaply through it
        vis[u] = true;
        for(auto p: adj[u]){ // p is a pair

            int v = p.first;
            int wgt = p.second; // weight of edge connecting u and v
            if(!vis[v]){
                if(dis[v]>dis[u]+wgt){
                    dis[v] = dis[u]+wgt;
                }
            }

        }

    }

    return dis;

}
int main(){

//    int v, e; cin>>v>>e;

//    graph g(v);
//    for(int i=0; i<e; i++){
//        int u, v, wgt; cin>>u>>v>>wgt;
//        g.addEdge(u, v, wgt);
//    }


    graph g(7);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 80);
    g.addEdge(1, 2, 6);
    g.addEdge(2, 3, 70);
    g.addEdge(1, 4, 20);
    g.addEdge(4, 5, 50);
    g.addEdge(4, 6, 10);
    g.addEdge(5, 6, 5);




    vector<int> dis = dijkstraAlgo(0, g.getVertices(), g.getAdjacencyList());
    for(auto i:dis){
        cout<<i<<" ";
    }

return 0;
}
