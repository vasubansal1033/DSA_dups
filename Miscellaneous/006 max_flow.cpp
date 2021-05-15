// NOTE : This code is for directed graph
// Question on gfg was for undirected graphs.
// This code can be easily modified for undirected graphs
#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int> >& res_graph, int s, int t, vector<int>& parent){

    vector<bool> visited(parent.size(), false);

    for(int i=0; i<parent.size(); i++)
        parent[i] = -1;

    queue<int> q;
    q.push(s);
    parent[s] = -1;

    while(!q.empty()){

        int front = q.front(); q.pop();

        visited[front] = true;

        for(int i=0; i<parent.size(); i++){

            if(!visited[i] && res_graph[front][i]>0){
                q.push(i);
                parent[i] = front;
                if(i==t) return true;
            }

        }

    }
    return false;

}
int max_flow(int v, vector<vector<int> >& edge_list){

    vector<vector<int> > res_graph(v, vector<int>(v, 0));
    for(int i=0; i<edge_list.size(); i++){
        res_graph[edge_list[i][0]][edge_list[i][1]] = edge_list[i][2];

        // Incase of undirected graph, like on gfg website use this.
//        res_graph[edge_list[i][0]][edge_list[i][1]] += edge_list[i][2];
//        res_graph[edge_list[i][1]][edge_list[i][0]] += edge_list[i][2];

    }

    vector<int> parent(v);
    int max_flow = 0;

    // source is 1(0 in our case) and sink is N(v-1 in our case)
    int s = 0;
    int t = v-1;
    while(bfs(res_graph, s, t, parent)){

        int path_flow = INT_MAX;
        for(int curr = t; curr!=s; curr=parent[curr]){
            path_flow = min(path_flow, res_graph[parent[curr]][curr]);
        }

        for(int curr = t; curr!=s; curr=parent[curr]){
            res_graph[parent[curr]][curr]-=path_flow;
            res_graph[curr][parent[curr]]+=path_flow;
        }

        max_flow += path_flow;

    }

    return max_flow;

}
int main()
 {
	//code
	int t; cin>>t;
	for(int i=0; i<t; i++){

	    int V, E; cin>>V>>E;
	    vector<vector<int> > edge_list;
	    for(int j=0; j<E; j++){
	        int u, v, w;
	        cin>>u>>v>>w;
	        // subtract 1 since we will follow 0 based indexing
	        edge_list.push_back({u-1, v-1, w});
	    }

	    cout<<max_flow(V, edge_list)<<'\n';

	}
	return 0;
}
