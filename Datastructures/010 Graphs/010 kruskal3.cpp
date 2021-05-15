#include<bits/stdc++.h>
using namespace std;

class edge{

public:
    int u, v, wgt;
    edge(int u, int v, int wgt){
        this->u = u;
        this->v = v;
        this->wgt = wgt;
    }

};

class graph{

    int v, e; vector<edge> adj;

public:
    graph(int v){
        this->v = v;
        e = 0;
    }
    int getEdges(){
        return e;
    }
    int getVertices(){
        return v;
    }
    vector<edge> getAdjacencyList(){
        return adj;
    }

    void addEdge(int u, int v, int wgt){
        adj.push_back(edge(u, v, wgt));
        adj.push_back(edge(v, u, wgt));
        e++;
    }

};

// weighted quickUnion

class unionFind{

    int* componentId; // ith index stores component to which it belongs
    int size_=0; // stores size of componentId
    int* sz; // stores size of ith component
public:
    // unionFind contructor. given n vertices initializes them to be individual components
    unionFind(int n){

        size_ = n;
        componentId = new int[n];
        sz = new int[n];
        for(int i=0; i<n; i++){
            componentId[i] = i;
            sz[i] = 1;
        }
    }
    // returns the root component to which i belongs
    int find_(int i){

        while(i!=componentId[i]){
            componentId[i] = componentId[componentId[i]]; // path compressio - simple one pass variant
            i = componentId[i];
        }
        return i;

    }
    // performs union of x and y's components
    void union_(int x, int y){

        int xId = find_(x); // returns root of the component containing x
        int yId = find_(y);
        if(sz[xId]>sz[yId]){
            componentId[yId] = componentId[xId];
            sz[xId]+=sz[yId];
        }else{
            componentId[xId] = componentId[yId];
            sz[yId]+=sz[xId];
        }

    }
    // checks if x and y belong to the same component
    bool isConnected(int x, int y){
        return componentId[x]==componentId[y];
    }

};


bool myComparator(edge e1, edge e2){
    return e1.wgt<e2.wgt;
}
vector<edge> kruskal(int v, vector<edge> adj){

    // sort edges by weight
    sort(adj.begin(), adj.end(), myComparator);

    unionFind components(v);

    vector<edge> tree_edges; // this vector will hold store the edges in the mst
    int i=0;
    while(tree_edges.size()<v-1){

        edge edge_i = adj[i];

        if(!components.isConnected(edge_i.u, edge_i.v)){


            tree_edges.push_back(edge_i);
            components.union_(edge_i.u, edge_i.v);
        }
        i++;
    }

    return tree_edges;

}


int main(){

    graph g(7);
    g.addEdge(0, 2, 18);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 6);
    g.addEdge(2, 3, 70);
    g.addEdge(1, 4, 20);
    g.addEdge(4, 5, 10);
    g.addEdge(4, 6, 10);
    g.addEdge(5, 6, 5);

    vector<edge> ans = kruskal(g.getVertices(), g.getAdjacencyList());
    for(auto i: ans)
        cout<<i.u+1<<" "<<i.v+1<<" "<<i.wgt<<endl;


return 0;
}
