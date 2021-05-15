#include<bits/stdc++.h>
using namespace std;

class graph{

    int v; // number of vertices
    int e; // number of edges
    list<int>* adj; // adjacency list pointer, which will point to array of lists

public:
    graph(int v){
        this->v = v;
        adj = new list<int>[v]; // pointer points to dynamically created array of lists
        e = 0;
    }
    void addEdge(int u, int v){
        adj[u].push_back(v); // add v to u's list
        adj[v].push_back(u); // incase of directed graph, comment this
        e++;
    }

    int getVertices(){
        return v;
    }
    int getEdges(){
        return e;
    }
    list<int>* getAdjacencyList(){
        return adj;
    }

    void dfs(int s){

        static bool* visited = new bool[v]{false}; // avoid this static declaration

        if(visited[s]==false){ // If node not visited

            cout<<s<<" ";
            visited[s]=true;

            for(auto i:adj[s]){
                if(!visited[i]){
    //                    visited[i] = true;
                    dfs(i);
                }
            }

        }


    }

};

void bfs(int v, int s, list<int>* adj){ // s is the starting point for bfs

    bool* visited = new bool[v]; // visited array for vertices
    for(int i=0; i<v;i++){
        visited[i]=false;
    }

    queue<int> q; // declare a queue
    q.push(s); // push starting vertex in queue
    visited[s] = true; // mark it visited

    while(!q.empty()){
        int curr = q.front(); q.pop(); // get first element in queue
        cout<<curr<<" "; // print it

        for(auto i:adj[curr]){ // for neighbours of the current node
            if(visited[i]==false){ // if they're not visited, place them in queue, and mark them visited

                q.push(i);
                visited[i]=true;
            }

        }

    }

}





int main(){

    graph g(4); // declare a graph with 4 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
//    g.bfs(2);

    bfs(g.getVertices(), 2, g.getAdjacencyList());
    cout<<endl;

    g.dfs(2);
    cout<<endl;

    cout<<g.getEdges()<<endl;



return 0;
}

