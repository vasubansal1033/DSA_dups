// optimal sol at end
typedef pair<int, int> p;
class Solution {
public:
    int minJumps(vector<int>& arr) {

        if(arr.size()!=1 && arr[0]==arr[arr.size()-1]) return 1;

        unordered_map<int, set<int> > mymap;
        for(int i=0; i<arr.size(); i++){
            mymap[arr[i]].insert(i);
        }

        queue<p> q;
        q.push({0, 0});
        vector<bool> visited(arr.size(), false);

        while(!q.empty()){

            p front = q.front(); q.pop();

            if(visited[front.second]) continue;

            visited[front.second] = true;

            // cout<<front.second<<" ";

            if(front.second==arr.size()-1) return front.first;

            if(front.second-1>=0 && !visited[front.second-1])
                q.push({front.first+1, front.second-1});

            if(front.second+1<arr.size() && !visited[front.second+1])
                q.push({front.first+1, front.second+1});

            for(int neighbour:mymap[arr[front.second]]){

                if(!visited[neighbour] && neighbour!=front.second){
                    q.push({front.first+1, neighbour});
                    mymap[arr[front.second]].erase(neighbour);
                }

            }


        }

        return -1;


    }
};


class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> indicesOfValue;
        for (int i = 0; i < n; i++)
            indicesOfValue[arr[i]].push_back(i);
        vector<bool> visited(n); visited[0] = true;
        queue<int> q; q.push(0);
        int step = 0;
        while (!q.empty()) {
            for (int size = q.size(); size > 0; --size) {
                int i = q.front(); q.pop();
                if (i == n - 1) return step; // Reached to last index
                vector<int>& next = indicesOfValue[arr[i]];
                next.push_back(i - 1); next.push_back(i + 1);
                for (int j : next) {
                    if (j >= 0 && j < n && !visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
                next.clear(); // avoid later lookup indicesOfValue arr[i]
            }
            step++;
        }
        return 0;
    }
};
