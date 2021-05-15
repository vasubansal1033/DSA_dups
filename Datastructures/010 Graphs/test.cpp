#include<bits/stdc++.h>
using namespace std;

class graph{

    int v; // number of vertices
    int e; // number of edges
    vector<int>* adj; // array of vectors

public:
    graph(int v){
        this->v = v;
        adj = new vector<int>[v];
        e = 0;
    }
    // return number of edges
    int getEdges(){
        return e;
    }
    // add an un-directed edge between u and v
    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
        e++;
    }
    // perform bfs and dfs from vertex s
    void bfs(int s){

        bool* vis = new bool[v];
        for(int i=0; i<v; i++)
            vis[i] = false;

        queue<int> q; q.push(s); vis[s] = true;

        while(!q.empty()){

            int curr = q.front(); q.pop();
            cout<<curr<<" ";
            for(int i:adj[curr]){
                if(!vis[i]){
                    q.push(i); vis[i] = true;
                }
            }

        }

    }
    void dfs(int s){

        static bool* vis = new bool[v];

        if(!vis[s]){

            cout<<s<<" "; vis[s] = true;
            for(int i: adj[s]){
                if(!vis[i]){
                    dfs(i);
                }
            }

        }


    }



};

int main(){

    graph g(4); // declare a graph with 4 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.bfs(2);
    cout<<endl;
    g.dfs(2);
    cout<<endl;
    cout<<g.getEdges()<<endl;


return 0;
}
