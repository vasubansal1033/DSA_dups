
#include<bits/stdc++.h>
using namespace std;


// modified bfs to return true as soon as t is found so that tle is not given
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
void traversal(vector<vector<int> >& res_graph, int s, vector<bool>& visited){

    // visited[s] = true;
    // for(int i=0; i<res_graph.size(); i++){

    //     if(!visited[i] && res_graph[s][i]>0)
    //         dfs(res_graph, visited, i);

    // }
    queue<int> q; q.push(s);
    visited[s] = true;
    while(!q.empty()){

        int front = q.front(); q.pop();
        for(int i=0; i<res_graph.size(); i++){

            if(!visited[i] && res_graph[front][i]>0){
                visited[i] = true;
                q.push(i);
            }

        }

    }

}
vector<vector<int> > minCut(vector<vector<int> >& graph, vector<vector<int> >& res_graph, int s, int t){

    vector<int> parent(res_graph.size());

    // source is 1(0 in our case) and N(v-1 in our case)
    while(bfs(res_graph, s, t, parent)){

        int path_flow = INT_MAX;
        for(int curr = t; curr!=s; curr=parent[curr]){
            path_flow = min(path_flow, res_graph[parent[curr]][curr]);
        }

        for(int curr = t; curr!=s; curr=parent[curr]){
            res_graph[parent[curr]][curr]-=path_flow;
            res_graph[curr][parent[curr]]+=path_flow;
        }


    }
    vector<bool> visited(res_graph.size(), false);
    traversal(res_graph, s, visited);

    vector<vector<int> > res;
    for(int i=0; i<res_graph.size(); i++){
        for(int j=0; j<res_graph[0].size(); j++){

            if(graph[i][j] && visited[i] && !visited[j]){
                res.push_back({i, j});
            }
        }
    }


    return res;

}
int main()
 {
	//code
	int T; cin>>T;
	for(int i=0; i<T; i++){

	    int V; cin>>V;
	    vector<vector<int> > res_graph(V, vector<int>(V)), graph(V, vector<int>(V));
	    for(int j=0; j<V; j++)
	        for(int k=0; k<V; k++){
	            cin>>res_graph[j][k];
	            graph[j][k] = res_graph[j][k];
	        }

        int s, t;
        cin>>s>>t;
	    vector<vector<int> > ans = minCut(graph, res_graph, s, t);
	    if(ans.size()==0) cout<<-1;
	    else{

	        for(int j=0; j<ans.size(); j++){
	            cout<<ans[j][0]<<" "<<ans[j][1];
	            if(j!=ans.size()-1) cout<<" ";
	        }

	    }
	    cout<<'\n';

	}
	return 0;
}
