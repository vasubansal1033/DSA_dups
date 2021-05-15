#include<bits/stdc++.h>
using namespace std;
bool isSafe(unordered_map<int, unordered_set<int> >& graph, vector<int>& coloring, int c, int num){

    for(int i:graph[num]){
            if(coloring[i]==c) return false;
    }

    return true;

}
bool graphColoringUtil(unordered_map<int, unordered_set<int> >& graph, vector<int>& coloring, int num, int m){

    // base case: if all vertices are colored
    if(num==coloring.size()) return true;

    for(int c=1; c<=m; c++){

        if(isSafe(graph, coloring, c, num)){

            coloring[num] = c;
            if(graphColoringUtil(graph, coloring, num+1, m))
                return true;

                coloring[num] = -1;

        }

    }
    return false;

}
bool graphColoringUtil(int numVertices, unordered_map<int, unordered_set<int> >& graph, int m){

    vector<int> coloring(numVertices, -1);

    if(!graphColoringUtil(graph, coloring, 0, m))
        return false;

    return true;

}
void graphColoring(int numVertices, vector<vector<int>>& edgeList, int m) {

    unordered_map<int, unordered_set<int> > graph;
    for(int i=0; i<edgeList.size(); i++){
            graph[edgeList[i][0]].insert(edgeList[i][1]);
            graph[edgeList[i][1]].insert(edgeList[i][0]);

    }

    if(graphColoringUtil(numVertices, graph, m))
        cout<<1;
    else
        cout<<0;


}

int main()
 {
	//code
	int t; cin>>t;
	for(int i=0; i<t; i++){

	    int numVertices; cin>>numVertices;
	    int m; cin>>m;
	    int numEdges; cin>>numEdges;
	    vector<vector<int> > edgeList;
	    for(int j=0; j<numEdges; j++){
	        int u, v; cin>>u>>v;
	        edgeList.push_back({u-1, v-1});
	    }
	    graphColoring(numVertices, edgeList, m);
	    cout<<'\n';

	}
	return 0;
}
