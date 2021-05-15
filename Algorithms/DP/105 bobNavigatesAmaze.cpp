#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'minMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY maze
 *  2. INTEGER x
 *  3. INTEGER y
 */
typedef pair<int,int> pii;
typedef unordered_map<int, int> umii;

void all_bfs(vector<vector<int>> &maze, vector<pii> &nodes, unordered_map<int, umii> &adj_list, unordered_map<int, umii> &node_pos_map) {

    int tot_nodes = nodes.size(), rows = maze.size(), cols = maze[0].size();
    for(int i=0; i<tot_nodes; i++){

        unordered_map<int, unordered_set<int>> vis;
        queue<pair<int, pii>> q;
        q.push({0, {nodes[i].first, nodes[i].second}});
        vis[nodes[i].first] = unordered_set<int>();
        vis[nodes[i].first].insert(nodes[i].second);

        while (!q.empty()){

            pair<int, pii> f = q.front(); q.pop();
            int dis = f.first, x = f.second.first, y = f.second.second;

            if((nodes[i].first != x || nodes[i].second != y) &&
               (maze[x][y] == 2 || (x==0 && y==0) ||
                (x == nodes[tot_nodes-1].first && y == nodes[tot_nodes-1].second))) {

                int node_pos = node_pos_map[x][y];
                if(adj_list.find(i) == adj_list.end()) adj_list[i] = unordered_map<int, int>();
                adj_list[i][node_pos] = dis;
            }

            if(x-1 >= 0 && maze[x-1][y] != 1 && (vis.find(x-1) == vis.end() || vis[x-1].find(y) == vis[x-1].end())) {
                if(vis.find(x-1) == vis.end())
                    vis[x-1] = unordered_set<int>();
                vis[x-1].insert(y);
                q.push({dis+1, {x-1,y}});
            }

            if(x+1 < rows && maze[x+1][y] != 1 && (vis.find(x+1) == vis.end() || vis[x+1].find(y) == vis[x+1].end())) {
                if(vis.find(x+1) == vis.end())
                    vis[x+1] = unordered_set<int>();
                vis[x+1].insert(y);
                q.push({dis+1, {x+1,y}});
            }

            if(y-1 >= 0 && maze[x][y-1] != 1 && (vis.find(x) == vis.end() || vis[x].find(y-1) == vis[x].end())) {
                vis[x].insert(y-1);
                q.push({dis+1, {x,y-1}});
            }

            if(y+1 < cols && maze[x][y+1] != 1 && (vis.find(x) == vis.end() || vis[x].find(y+1) == vis[x].end())) {
                vis[x].insert(y+1);
                q.push({dis+1, {x,y+1}});
            }

        }
    }
}
int get_bits_set(int k) {
    int cnt = 0;
    while(k){
        cnt++;
        k-=k&-k;
    }
    return cnt;
}

int all_path_perms(vector<vector<int>>& maze, unordered_map<int, umii>& adj_list, vector<pii> &nodes) {
    int tot_nodes = nodes.size();
    int last_mask = 1<<(tot_nodes-1);

    // For every mask (subset of nodes with path starting from (0,0)), we store shortest
    // distance to traverse the nodes in the mask for every possible last node in the path
    vector<umii> dp(last_mask, umii());
    dp[0][0] = 0;
    for(int mask = 0; mask < last_mask; mask++) {

        int total_bits_set = get_bits_set(mask);
        for(pii prev_node_and_dist_thus_far : dp[mask]) {
            int previous_node = prev_node_and_dist_thus_far.first;
            int cur_dist = prev_node_and_dist_thus_far.second;
            for(int i=1; i<tot_nodes; i++){
                // Alice position can only be last node (bit) to be traversed (set)
                // in the mask
                if(i == tot_nodes-1 && total_bits_set != tot_nodes-2)
                    continue;

                if(!(mask&(1<<(i-1)))) {
                    int prospective_path_len = cur_dist + adj_list[previous_node][i];
                    if(dp[mask|(1<<(i-1))].find(i) == dp[mask|(1<<(i-1))].end() ||
                        dp[mask|(1<<(i-1))][i] > prospective_path_len) {
                        dp[mask|(1<<(i-1))][i] = prospective_path_len;
                    }
                }
            }
        }

    }
    int min_dist = 1e9;
    for(pii prev_node_and_dist_thus_far : dp[last_mask - 1])
        // The map size is only 1 as last node is always Alice position.
        if(prev_node_and_dist_thus_far.second < min_dist)
            min_dist = prev_node_and_dist_thus_far.second;

    return min_dist;
}

int minMoves(vector<vector<int>> maze, int x, int y) {
    int shortest_path_len = (int)1e9;
    int rows = maze.size(), cols = maze[0].size(), tot_coins;
    vector<pii> nodes;
    unordered_map<int, unordered_map<int, int>> node_pos_map;
    nodes.push_back({0,0});
    node_pos_map[0] = unordered_map<int, int>();
    node_pos_map[0][0] = 0;

    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            if(maze[i][j] == 2)
                nodes.push_back({i,j});
            if(node_pos_map.find(i) == node_pos_map.end())
                node_pos_map[i] = unordered_map<int, int>();
            node_pos_map[i][j] = nodes.size()-1;
        }
    }
    nodes.push_back({x,y});
//    cout<<nodes.size()<<endl;
    if(node_pos_map.find(x) == node_pos_map.end())
        node_pos_map[x] = unordered_map<int, int>();
    node_pos_map[x][y] = nodes.size()-1;

    unordered_map<int, unordered_map<int, int>> adj_list;

    all_bfs(maze, nodes, adj_list, node_pos_map);

    if(adj_list[0].size() != nodes.size()-1) return -1;

    return all_path_perms(maze, adj_list, nodes);
}
int main(){

    int m, n, x, y;
    cin>>m>>n>>x>>y;
    vector<vector<int>> maze(m, vector<int>(n, 0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cin>>maze[i][j];
    }

    cout<<minMoves(maze, x, y);

}

// 8 8 2 2
// 0 0 2 0 0 0 2 0
// 0 2 0 0 0 0 2 0
// 0 0 0 2 0 0 0 0
// 0 0 2 1 1 0 0 1
// 0 2 2 0 2 2 0 1
// 0 0 0 0 0 0 0 0
// 1 0 1 0 0 0 0 0
// 0 1 0 0 0 0 0 0
