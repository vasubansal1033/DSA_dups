#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> >& graph, int start, int parent, bool& flag, int mask){

	int n = graph.size();
	if(mask==(1<<n)-1){
		flag = true;
		return;
	}

	for(int i=0; i<graph[start].size(); i++){
		int neighbour = graph[start][i];
		if(neighbour==parent || (mask&(1<<neighbour))) continue;

		mask = mask|(1<<neighbour);
		dfs(graph, neighbour, start, flag, mask);

		mask = mask^(1<<neighbour);

	}

}
void util(vector<vector<int> >& edgeList, int n){

	vector<vector<int> > graph(n);
	for(int i=0; i<edgeList.size(); i++){
		graph[edgeList[i][0]-1].push_back(edgeList[i][1]-1);
		graph[edgeList[i][1]-1].push_back(edgeList[i][0]-1);
	}

	bool flag = false;
	for(int i=0; i<n; i++){
		int mask = 1<<i;
		dfs(graph, i, -1, flag, mask);
		if(flag) break;
	}


	if(flag)
		cout<<"Yes"<<'\n';
	else cout<<"No"<<'\n';

}
int main(){

	int t; cin>>t;
	for(int i=0; i<t; i++){

		int n, m; cin>>n>>m; // n is vertices, m edges
		vector<vector<int> > edgeList;
		for(int j=0; j<m; j++){
			int u, v; cin>>u>>v;
			edgeList.push_back({u, v});
		}

		util(edgeList, n);


	}

return 0;
}
