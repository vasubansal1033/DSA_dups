class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> color(n); // 0: uncolored; 1: color A; -1: color B

        queue<int> q; // queue, resusable for BFS

        for (int i = 0; i < n; i++) {

          if (color[i]) continue; // skip already colored nodes

          // BFS with seed node i to color neighbors with opposite color
          color[i] = 1; // color seed i to be A (doesn't matter A or B)
          for (q.push(i); !q.empty(); q.pop()) {
            int cur = q.front();
            for (int neighbor : graph[cur])
            {
              if (!color[neighbor]) // if uncolored, color with opposite color
              { color[neighbor] = -color[cur]; q.push(neighbor); }

              else if (color[neighbor] == color[cur])
                return false; // if already colored with same color, can't be bipartite!
            }
          }
        }

        return true;
      }
};


class Solution {
public:
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
                else
                    coloring[num] = -1;

            }

        }
        return false;

    }
    bool graphColoring(int numVertices, unordered_map<int, unordered_set<int> >& graph, int m){

        vector<int> coloring(numVertices, -1);

        if(!graphColoringUtil(graph, coloring, 0, m))
            return false;

        return true;

    }
    bool isBipartite(vector<vector<int>>& graph_) {

        unordered_map<int, unordered_set<int> > graph;
        for(int i=0; i<graph_.size(); i++){
            for(int j=0; j<graph_[i].size(); j++){

                graph[i].insert(graph_[i][j]);
                graph[graph_[i][j]].insert(i);
            }
        }

        return graphColoring(graph_.size(), graph, 2);

    }
};
