#include<bits/stdc++.h>
using namespace std;

int dp[20][20][(1<<15)+5];

void dfs(vector<vector<int> >& graph, int start, int parent, vector<int>& maxLen, int mask, int len){

	int n = graph.size();
	if(mask==(1<<n)-1){
		dp[start][parent+1][mask] = maxLen[start] = max(maxLen[start], len);
		return;
	}

	if(dp[start][parent+1][mask]!=-1){
		maxLen[start] = max(maxLen[start], dp[start][parent+1][mask]);
		return;
	}

	dp[start][parent+1][mask] = maxLen[start] = max(maxLen[start], len);

	for(int i=0; i<(int)graph[start].size(); i++){
		int neighbour = graph[start][i];
		if(neighbour==parent || (mask&(1<<neighbour))) continue;

		mask = mask|(1<<neighbour);
		dfs(graph, neighbour, start, maxLen, mask, len+1);

		mask = mask^(1<<neighbour);

	}

}
void util(vector<vector<int> >& edgeList, int n){

	vector<vector<int> > graph(n);
	for(int i=0; i<edgeList.size(); i++){
		graph[edgeList[i][0]-1].push_back(edgeList[i][1]-1);
		graph[edgeList[i][1]-1].push_back(edgeList[i][0]-1);
	}

	vector<int> maxLen(graph.size(), 0);
	for(int i=0; i<n; i++){
		int mask = 1<<i;
		dfs(graph, i, -1, maxLen, mask, 0);
	}

	for(int i=0; i<graph.size(); i++)
		cout<<maxLen[i]<<" ";
	cout<<'\n';

}
int main(){

	int t; cin>>t;
	for(int i=0; i<t; i++){

		memset(dp, -1, sizeof(dp));
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
