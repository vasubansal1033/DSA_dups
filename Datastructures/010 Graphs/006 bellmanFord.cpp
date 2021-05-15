// Dijkstra's algorithm fails incase of negative edges
// Therefore we have Bellman ford algorithm
// A negative cycle must not exist as the minimum weight path won't be defined(path go around in that cycle and the weight keeps on decreasing)
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
//        adj[v].push_back({u, wgt});
        e++;
    }

};

vector<int> bellmanFord(int s, int v, vector<pair<int, int> >* adj){

    vector<int> dis(v, INT_MAX/2);
    dis[s] = 0;

    for(int i=0; i<v-1; i++){

        for(int j=0; j<v; j++){

            for(auto p: adj[j]){

                dis[p.first] = min(dis[p.first], dis[j]+p.second);

            }


        }

    }

    return dis;

}

int main(){

//    int v, e; cin>>v>>e;
//
//    graph g(v);
//    for(int i=0; i<e; i++){
//        int u, v, wgt; cin>>u>>v>>wgt;
//        g.addEdge(u, v, wgt);
//    }

    graph g(8);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 5, 2);
    g.addEdge(2, 1, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 3);
    g.addEdge(4, 5, -1);
    g.addEdge(5, 2, -2);
    g.addEdge(6, 5, -1);
    g.addEdge(6, 1, -4);
    g.addEdge(7, 6, 1);
    vector<int> dis = bellmanFord(0, g.getVertices(), g.getAdjacencyList());
    for(int i=0; i<dis.size(); i++)
        cout<<dis[i]<<" ";

return 0;
}
