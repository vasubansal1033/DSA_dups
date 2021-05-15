#include<bits/stdc++.h>
using namespace std;

int numComponents;
int getTop(stack<int>& stk){
	int temp = stk.top(); stk.pop();
	return temp;
}
void dfs(vector<vector<int> >& graph, vector<int>& visited, vector<int>& low, vector<bool>& inStack, stack<int>& stk, int& id, int curr){

	visited[curr] = low[curr] = id++;
	stk.push(curr);
	inStack[curr] = true;

	for(int i=0; i<graph[curr].size(); i++){
		int neighbour = graph[curr][i];
		if(visited[neighbour]==-1){
			dfs(graph, visited, low, inStack, stk, id, neighbour);
		}
		if(inStack[neighbour]){
			low[curr] = min(low[curr], low[neighbour]);
		}
	}

	if(low[curr]==visited[curr]){

		for(int temp = getTop(stk);; temp = getTop(stk)){
			low[temp] = numComponents;
			inStack[temp] = false;
			if(temp==curr) break;
		}

		numComponents++;

	}

}
void util(vector<vector<int> >& edgeList, int n){

	vector<vector<int> > graph(n);
	for(int i=0; i<edgeList.size(); i++){
		graph[edgeList[i][0]-1].push_back(edgeList[i][1]-1);
	}

	vector<int> visited(n, -1), low(n, -1);
	vector<bool> inStack(n, false);
	stack<int> stk;
	int id = 0;

	numComponents = 0;
	for(int i=0; i<n; i++){
		if(visited[i]==-1)
			dfs(graph, visited, low, inStack, stk, id, i);
	}

	// low contains the components
	int temp[numComponents] = {0};
	for(int i=0; i<low.size(); i++) temp[low[i]]++;

	int res = 0;
	for(int i=0; i<numComponents; i++)
		if(temp[i]%2!=0) res+=temp[i];
		else res-=temp[i];
	cout<<res;

}
int main(){

	int n, m; cin>>n>>m; // n nodes, m edges
	vector<vector<int> > edgeList;
	for(int i=0; i<m; i++){
		int u, v; cin>>u>>v;
		edgeList.push_back({u, v});
	}

	util(edgeList, n);

return 0;
}
