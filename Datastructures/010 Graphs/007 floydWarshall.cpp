// All pairs shortest path algorithm
// Calculates the shortest distance between any two pairs of vertices in a graph
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
    }

};

vector<vector<int> > floydWarshall(int v, vector<pair<int, int> >* adj){

    vector<vector<int> > W1(v, vector<int>(v, INT_MAX/2));


    for(int i=0; i<v; i++){
        for(auto p:adj[i]){

            W1[i][p.first] = p.second;

        }
    }

    // In kth iteration, we are finding whether to include the kth vertex in the path joining i and j
    for(int k=0; k<v; k++){

        vector<vector<int> > W2(v, vector<int>(v));
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                W2[i][j] = min(W1[i][j], W1[i][k]+W1[k][j]);
            }
        }

        // copy the W2 matrix into W1 so that it can be used for calculation again
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                W1[i][j] = W2[i][j];
            }
        }

    }

    return W1;


}

int main(){

//    int v, e; cin>>v>>e;
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

    vector<vector<int> > ans = floydWarshall(g.getVertices(), g.getAdjacencyList());

    for(int i=0; i<g.getVertices(); i++){
        for(int j=0; j<g.getVertices(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }


return 0;
}



