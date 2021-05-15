#include<bits/stdc++.h>
using namespace std;

class graph{

    int v; int e; vector<int>* adj;

public:

    graph(int v){
        this->v = v;
        this->e = 0;
        this->adj = new vector<int>[v];
    }
    int getEdges(){
        return e;
    }
    int getVertices(){
        return v;
    }
    vector<int>* getAdjacencyList(){
        return adj;
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        e++;
    }

};

// V is number of vertices, adj is the adjacency list
int* topoSort(int V, vector<int>* adj) {

    // set inDegree of all vertices
    int inDegree[V] = {0};
    int lpt[V] = {0};

    for(int i=0; i<V; i++){
        for(int j=0; j<adj[i].size(); j++){
            inDegree[adj[i][j]]++;
        }
    }

    int* ans = new int[V]; int ansIndex = 0;

    // Push all vertices with indegree 0 into a queue
    queue<int> q;
    for(int i=0; i<V; i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){

        int u = q.front(); q.pop();
        ans[ansIndex++] = u;

        // Delete the vertex with indegree 0 from graph. Decrease the indegree of corresponding connected vertices
        for(int i=0; i<adj[u].size(); i++){

            inDegree[adj[u][i]]--;
            lpt[adj[u][i]] = max(lpt[adj[u][i]], 1+lpt[u]); // update the longest path

            // If indegree of resulting vertex becomes 0, add it to queue
            if(inDegree[adj[u][i]]==0){
                q.push(adj[u][i]);
            }
        }
    }

    cout<<"The length of the longest path in this DAG is: "<<lpt[V-1]+1<<endl;
    return ans;
}


int main(){

    int e, v; cin>>e>>v;
    graph g(v);

//    for(int i=0; i<e; i++){
//        int u, v; cin>>u>>v;
//        g.addEdge(u, v);
//    }

    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 7);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(3, 7);
    g.addEdge(4, 7);
    g.addEdge(5, 6);
    g.addEdge(6, 7);

    int* ans = topoSort(g.getVertices(), g.getAdjacencyList());

    for(int i=0; i<g.getVertices(); i++){
        cout<<ans[i]<<" ";
    }



return 0;
}
