#include<bits/stdc++.h>
using namespace std;

// graph is assumed to be given in adjacency matrix

int fun(vector<int>& weights, int k){

    // weights will be empty if no path exists
    if(weights.size(==0)) return -1;
    sort(weights.begin(), weights.end());
    int sum = 0;
    for(int i=k; i<weights.size(); i++)
        sum+=weights[i];

    return sum;
}

// graph is the adjacency matrix representation
// k is the number of cities magician can remove
// source is the starting city and destination is the city he wants to reach
vector<int> dijkstra(vector<vector<int> >& graph, int k, int source, int destination){

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; // minheap
    vector<bool> visited(graph.size(), false);

    pq.push({0, source});

    vector<int> weights;
    while(!pq.empty()){

        pair<int, int> node = pq.top(); pq.pop();
        int idx = node.second;
        visited[idx] = true;

        for(int i=0; i<graph.size(); i++){
            if(graph[idx][i]>0 && !visited[i]){
                pq.push({graph[idx}[i], i});
                weights.push_back(graph[idx][i]);
                if(i==destination)
                    return weights;

        }

    }

    // if we reach here means no path exists
    return fun({}, k);

}
int main(){



return 0;
}
