#include<bits/stdc++.h>
using namespace std;

int numComponents = 0;
int id = 0;

int getTop(stack<int>& stk){
    int temp = stk.top();
    stk.pop();
    return temp;
}
void dfs(vector<vector<int> >& adjacencyList, vector<int>& visited, vector<int>& low, vector<bool>& inStack, stack<int>& stk, int curr){

    stk.push(curr);
    inStack[curr] = true;
    visited[curr] = low[curr] = id++;

    // visit all neighbours and update curr's lowlink values if neighbour present in stack
    for(int i=0; i<adjacencyList[curr].size(); i++){
        int neighbour = adjacencyList[curr][i];
        if(visited[neighbour]==-1){
            dfs(adjacencyList, visited, low, inStack, stk, neighbour);
        }
        if(inStack[neighbour]){
            low[curr] = min(low[curr], low[neighbour]);
        }

    }

    // if curr is starting of a scc, then pop all elements from the stack
    // until curr is encountered

    if(visited[curr]==low[curr]){

        for(int temp = getTop(stk);; temp = getTop(stk)){

            inStack[temp] = false;
            low[temp] = visited[curr]; // just to make sure that every node in scc has same number as starting node
            if(temp==curr) break;

        }
        numComponents++;

    }

}
int scc(int V, vector<vector<int> >& edgeList){

    vector<vector<int> > adjacencyList(V);
    numComponents = 0;
    id = 0;
    for(int i=0; i<edgeList.size(); i++){
        adjacencyList[edgeList[i][0]].push_back(edgeList[i][1]);
    }

    vector<int> visited(V, -1); // stores visited id of each node
    vector<int> low(V, -1); // stores lowest id of a node reachable from this
    vector<bool> inStack(V, -1); // stores whether the current node is present in stack
    stack<int> stk;

    for(int i=0; i<V; i++){

        if(visited[i]==-1){
            dfs(adjacencyList, visited, low, inStack, stk, i);
        }

    }

    for(int i=0; i<low.size(); i++) cout<<low[i]<<" ";
    // low contains which node belongs to which component
    return numComponents;
}
int main(){

    int V, e;
    cin>>V>>e;
    vector<vector<int> > edgeList;
    for(int i=0; i<e; i++){
        int u, v;
        cin>>u>>v;
        edgeList.push_back({u-1, v-1}); // remove -1 if 0 based indices
    }

    cout<<scc(V, edgeList);


return 0;
}
