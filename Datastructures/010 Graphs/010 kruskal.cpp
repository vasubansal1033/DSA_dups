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

// naive implementation of union-find
// O(n) worst case
// The commented code is that of quick-union
// Other one is quick-find
int find_(vector<int>& components, int i){
// recursive
//    if(components[i]==i)
//        return i;
//    return find_(components, components[i]);

// iterative
    while(components[i]!=i)
        i = componenets[i];
    return i;

//     return components[i];

}

// O(n)
void union_(vector<int>& components, int x, int y){

    int xComp = find_(components, x);
    int yComp = find_(components, y);

//    if(xComp!=yComp){ // this condition is not required
        components[xComp] = yComp;
//    }

    /*
    // union can also be done by directly storing the root parent in components vector
    // In this case find_ function can directly return the component as components[i] w/o recursion. Thus find_ is O(1)
    */

    // store these before hand in variables
    // using directly inplace of xid and yid can change these in process
//    int xId = components[x];
//    int yId = components[y];
//
//    for(int i=0; i<components.size(); i++){
//
//        if(components[i]==yId){
//            components[i] = xId;
//        }
//    }

}

class graph{

    int v, e;
    vector<edge> adj;

public:
    graph(int v){
        this->v = v;
        e = 0;
    }
    int getVertices(){
        return v;
    }
    int getEdges(){
        return e;
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

bool myComparator(edge e1, edge e2){
    return e1.wgt<e2.wgt;
}

vector<edge> kruskal(int v, vector<edge> adj){

    // sort edges by weight
    sort(adj.begin(), adj.end(), myComparator);


    vector<int> components(v); // components[i] stores the component to which ith vertex belongs
    for(int i=0; i<v; i++)
        components[i] = i;

    vector<edge> tree_edges; // this vector will hold store the edges in the mst
    int i=0;
    while(tree_edges.size()<v-1){

        edge edge_i = adj[i];
        // If selecting this edge forms a cycle
        // or if the end points are in different components
        if(find_(components, edge_i.u)!=find_(components, edge_i.v)){

            // if they don't form a cycle include the edge in the mst.
            // perform union of the two components
            tree_edges.push_back(edge_i);
            union_(components, edge_i.u, edge_i.v);
        }
        // increment the pointer
        // if the edge forms a cycle, move to next
        i++;

    }

    return tree_edges;

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

    vector<edge> ans = kruskal(g.getVertices(), g.getAdjacencyList());
    for(auto i: ans)
        cout<<i.u+1<<" "<<i.v+1<<" "<<i.wgt<<endl;


return 0;
}
