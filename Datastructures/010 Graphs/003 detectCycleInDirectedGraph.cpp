#include<bits/stdc++.h>
using namespace std;


class graph{

    int v, e; vector<int>* adj;

public:
    graph(int v){
        this->v = v;
        e = 0;
        adj = new vector<int>[v];
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

// Incase of a cycle, toplogical sort wont run on all nodes. It won't be able to find nodes with indegree 0 after sometime.
bool topoSortCycleDetect(int V, vector<int> adj[]){

    int visited=0;
    int indegree[V] = {0};
    for(int i =0;i<V;i++){

        for(int j =0;j<adj[i].size();j++){
            indegree[adj[i][j]]++;
        }
    }

    queue<int> q;
    for(int i =0;i<V;i++){
        if(indegree[i]==0)
        q.push(i);
    }

    while(!q.empty()){

        int u =q.front();
        q.pop();

        visited++;
        for(int j =0; j <adj[u].size();j++){
            indegree[adj[u][j]]--;
            if(indegree[adj[u][j]]==0)
            q.push(adj[u][j]);
        }
    }

    if(visited<V)
        return true;
    else
        return false;
}
bool isCyclic(int V, vector<int> adj[]){
    return topoSortCycleDetect(V,adj);
}

/*
// Recursive solution

bool isCyclicUtil(int s, vector<int> (adj[]), bool vis[], bool recStack[]){

    vis[s] = true; recStack[s] = true;

    for(auto i:adj[s]){

        if(!vis[i] && isCyclicUtil(i, adj, vis, recStack)){
            return true;
        }else if(recStack[i]){
            return true;
        }

    }
    recStack[s] = false;
    return false;

}
bool isCyclic(int V, vector<int> adj[]){

    bool vis[V] = {false};
    bool recStack[V] = {false};

    for(int i=0; i<V; i++){
            if(isCyclicUtil(i, adj, vis, recStack))
                return true;

    }

    return false;

}

*/

int main(){

    int v, e; cin>>v>>e;
    graph g(v);
    for(int i=0; i<e; i++){
        int u, int v; cin>>u>>v;
        g.addEdge(u, v);
    }

    cout<<isCyclic(g.getVertices(), g.getAdjacencyList())<<endl;

return 0;
}
