#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> >& graph, string& visited, int curr, int parent, set<string>& paths){

    visited[curr] = '0'+parent+1;
    for(auto& neighbour:graph[curr]){

        if(neighbour==parent) continue;
        if(visited[neighbour]=='.'){
            dfs(graph, visited, neighbour, curr, paths);
        }else{
            paths.insert(visited);
            //return;
        }
    }

    visited[curr] = '.';
    return;

}
int util(int n, vector<vector<int> >& edgeList){

    vector<vector<int> > graph(n);
    for(int i=0; i<edgeList.size(); i++){
        graph[edgeList[i][0]].push_back(edgeList[i][1]);
        graph[edgeList[i][1]].push_back(edgeList[i][0]);
    }


    int cnt = 0;
    string visited = "....";
    set<string> paths;
    dfs(graph, visited, 0, -1, paths);

    for(string i:paths) cout<<i<<'\n';

    return paths.size();

}
int main(){

    int e;
    int n;
    cin>>n>>e;
    vector<vector<int> > edgeList;
    for(int i=0; i<e; i++){
        int a, b; cin>>a>>b;
        edgeList.push_back({a-1, b-1});
       // edgeList.push_back({b-1, a-1});
    }

    cout<<util(n, edgeList);

return 0;
}
