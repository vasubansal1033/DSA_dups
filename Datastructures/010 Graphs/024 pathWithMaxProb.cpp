class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {

        vector<vector<pair<double, int> > > graph(n);
        vector<bool> visited(n, false);
        for(int i=0; i<edges.size(); i++){

            graph[edges[i][0]].push_back({succProb[i], edges[i][1]});
            graph[edges[i][1]].push_back({succProb[i], edges[i][0]});

        }

        priority_queue<pair<double, int> > pq;
        pq.push({1.0, start});

        double res = INT_MIN*1.0;
        while(!pq.empty()){


            pair<double, int> maxEle = pq.top(); pq.pop();
            if(visited[maxEle.second])
                continue;

            visited[maxEle.second] = true;

            if(maxEle.second==end){
                res = max(res, maxEle.first);
                continue;
            }

            for(int i=0; i<graph[maxEle.second].size(); i++){

                if(visited[graph[maxEle.second][i].second]) continue;
                double prob = graph[maxEle.second][i].first;
                pq.push({maxEle.first*prob, graph[maxEle.second][i].second});

            }


        }
        return res==INT_MIN*1.0?0:res;

    }
};
