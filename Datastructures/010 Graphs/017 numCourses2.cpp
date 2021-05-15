class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int> > graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for(int i=0; i<prerequisites.size(); i++){
            // edge from [i][1] to [i][0]
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0)
                q.push(i);
        }

        vector<int> res;
        while(!q.empty()){

            int front = q.front(); q.pop();
            res.push_back(front);

            indegree[front] = -1;

            for(int i=0; i<graph[front].size(); i++){

                indegree[graph[front][i]]--;
                if(indegree[graph[front][i]]==0)
                    q.push(graph[front][i]);

            }

        }
        return res.size()!=numCourses?vector<int>():res;

    }
};
