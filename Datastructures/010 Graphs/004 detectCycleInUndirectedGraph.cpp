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

bool isCyclicUtil(int s, vector<int> (adj)[], bool vis[], int parent){


    vis[s] = true;
    for(int i: adj[s]){

        if(!vis[i]){
            if(isCyclicUtil(i, adj, vis, s))
                return true;
        }
        else if(i!=parent){
            return true;
        }

    }

    return false;


}
bool isCyclic(vector<int> adj[], int V)
{
   // Your code here
   bool* vis = new bool[V];
   for(int i=0; i<V; i++)
        vis[i] = false;

   for(int i=0; i<V; i++){
       if(!vis[i])
           if(isCyclicUtil(i, adj, vis, -1))
                return true;
   }

   return false;

}

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
