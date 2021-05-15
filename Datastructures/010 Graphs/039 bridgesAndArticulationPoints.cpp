#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> >& graph, vector<int>& visited, vector<int>& low, vector<bool>& isArt, vector<vector<int> >& res, int& outEdgeCount, int root, int curr, int parent, int& id){

    if(parent==root) outEdgeCount++; // this means that the root from which we started as one outEdge to this node

    visited[curr] = low[curr] = id++;
    for(int& neighbour:graph[curr]){

        if(neighbour==parent) continue;
        if(visited[neighbour]==-1){
            dfs(graph, visited, low, isArt, res, outEdgeCount, root, neighbour, curr, id);
            low[curr] = min(low[curr], low[neighbour]);

            // articulation point found by bridges
            if(visited[curr]<low[neighbour]){
                res.push_back({curr, neighbour});
                isArt[curr] = true;
            }
            // articulation point found by cycle
            if(visited[curr]==low[neighbour]){
                isArt[curr] = true;
            }

        }else{

            low[curr] = min(low[curr], low[neighbour]);

        }

    }

}
void getBridgesAndVertices(int numVertices, vector<vector<int> >& edgeList){

    vector<vector<int> > graph(numVertices);
    for(int i=0; i<edgeList.size(); i++){
        graph[edgeList[i][0]].push_back(edgeList[i][1]);
        graph[edgeList[i][1]].push_back(edgeList[i][0]);
    }

    int id = 0, outEdgeCount = 0;
    vector<int> visited(numVertices, -1), low(numVertices, -1);
    vector<bool> isArt(numVertices, false);
    vector<vector<int> > res;

    for(int i=0; i<numVertices; i++){

        if(visited[i]==-1){
            outEdgeCount = 0; // reset outEdgeCount
            dfs(graph, visited, low, isArt, res, outEdgeCount, i, i, -1, id);
            isArt[i] = (outEdgeCount>1)?true:false;
        }

    }

    // print articulation points and bridges in required order
    int p = 0;
    for(int i=0; i<isArt.size(); i++)
        if(isArt[i]) p++;
    cout<<p<<'\n';
    for(int i=0; i<isArt.size(); i++)
        if(isArt[i]) cout<<i<<" ";

    cout<<'\n';
    cout<<res.size()<<'\n';
    sort(res.begin(), res.end());
    for(int i=0; i<res.size(); i++)
        cout<<min(res[i][0], res[i][1])<<" "<<max(res[i][0], res[i][1])<<'\n';

}
int main(){

    int numVertices; cin>>numVertices;
    int numEdges; cin>>numEdges;
    vector<vector<int> > edgeList;
    for(int i=0; i<numEdges; i++){

        int u, v; cin>>u>>v;
        edgeList.push_back({u, v});

    }

    getBridgesAndVertices(numVertices, edgeList);


}

