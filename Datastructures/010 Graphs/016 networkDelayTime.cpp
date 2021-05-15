class Solution {
public:
    int dijkstra(int K, int N, vector<vector<pair<int, int> > >& graph){

        vector<bool> visited(N+1, false);
        vector<int> distance(N+1, INT_MAX);

        distance[K] = 0;
        for(int i=1; i<=N; i++){

            // find nearest u
            int u, mini = INT_MAX;
            for(int j=1; j<=N; j++){

                if(!visited[j] && mini>distance[j]){
                    mini = distance[j];
                    u = j;
                }
            }

            // make u visited, and check all its neighbours if they can be visited cheaply through u
            visited[u] = true;
            for(int j=0; j<graph[u].size(); j++){

                auto p = graph[u][j];

                if(!visited[p.second]){

                    if(distance[p.second]>distance[u]+p.first){

                        distance[p.second] = distance[u]+p.first;
                    }

                }

            }

        }

        int res = *max_element(distance.begin()+1, distance.end());
        return res!=INT_MAX?res:-1;

    }
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {

        vector<vector<pair<int, int> > > graph(N+1);

        for(int i=0; i<times.size(); i++){

            graph[times[i][0]].push_back({times[i][2], times[i][1]});

        }

        return dijkstra(K, N, graph);

    }
};



class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {

        vector<vector<pair<int, int> > > graph(N+1);

        for(int i=0; i<times.size(); i++){
            graph[times[i][0]].push_back({times[i][2], times[i][1]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        vector<bool> visited(N+1, false);

        pq.push({0, K});

        int res = INT_MIN;
        int countNodes = 0;
        while(!pq.empty()){

            auto minEle = pq.top(); pq.pop();

            // if already visited, ignore
            if(visited[minEle.second]) continue;

            visited[minEle.second] = true;

            res = max(res, minEle.first);
            countNodes++;

            for(int i=0; i<graph[minEle.second].size(); i++){

                if(!visited[graph[minEle.second][i].second])
                    pq.push({ minEle.first+graph[minEle.second][i].first ,graph[minEle.second][i].second});

            }
        }

        return countNodes==N?res:-1;

    }
};
