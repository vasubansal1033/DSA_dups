class Solution {
public:
    int VISITING = 1;
    int VISITED = 2;
    bool dfs(vector<vector<int> >& graph, vector<int>& visited, int curr){

        if(visited[curr]) return visited[curr] == VISITING;

        visited[curr] = VISITING;
        for(int i=0; i<graph[curr].size(); i++){
            int neighbour = graph[curr][i];
            if(dfs(graph, visited, neighbour)) return true;
        }

        visited[curr] = VISITED;
        return false;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        ios_base::sync_with_stdio(0);
        cin.tie(0);

        vector<int> res;
        vector<int> visited(graph.size(), 0);

        for(int i=0; i<graph.size(); i++){
            if(!visited[i]){
                dfs(graph, visited, i);
            }
        }

        for(int i=0; i<graph.size(); i++){
            if(visited[i]==VISITED) res.push_back(i);
        }

        return res;
    }
};
