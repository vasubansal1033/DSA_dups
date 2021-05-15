class Solution {
public:

    void dfs(vector<int>& low,
             vector<int>& visitedId,
             vector<vector<int>>& graph,
             int current,
             int parent,
             int id,
             vector<vector<int>>& res) {

        visitedId[current] = id;
        low[current] = id;
        id++;

        for (int neighbour : graph[current]) {

            if (neighbour == parent) {
                continue;
            }

            if (visitedId[neighbour]==-1) {
                dfs(low, visitedId, graph, neighbour, current, id, res);
                low[current] = min(low[current], low[neighbour]);
                if (visitedId[current] < low[neighbour]) {
                    res.push_back({current, neighbour});
                }
            } else {
                low[current] = min(low[current], visitedId[neighbour]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {


        // construct the graph
        vector<vector<int>> graph(n);
        for(int i=0; i<connections.size(); i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }


        // low[i] stores the lowest id node reachable from i
        vector<int> low(n);
        // visitedId[i] stores the order in which i came in dfs
        vector<int> visitedId(n, -1);
        vector<vector<int> > res;

        dfs(low, visitedId, graph, 0, -1, 0, res);

        for(int i:low)
            cout<<i<<" ";

        cout<<endl;
        for(int i:visitedId)
            cout<<i<<" ";

        return res;
    }

};
