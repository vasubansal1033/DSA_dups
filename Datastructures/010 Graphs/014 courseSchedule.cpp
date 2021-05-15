class Solution {
public:
    bool dfs(vector<vector<int> >& graph, vector<int>& visited, int startNode, int rank){

        visited[startNode] = rank;

        // INT_MAX -> already visited and not in current path's call stack
        // -1 -> not visited
        // otherwise visited and in current call stack. means cycle is present

        bool b = false;
        for(int i=0; i<graph[startNode].size(); i++){

            if(visited[graph[startNode][i]]==INT_MAX)
                continue;
            if(visited[graph[startNode][i]]==-1){

                b =  b||dfs(graph, visited, graph[startNode][i], rank+1);
                if(b)
                    return true;

            }
            if(visited[graph[startNode][i]]<rank)
                return true;

        }
        visited[startNode] = INT_MAX;

        return b;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int> > graph(numCourses);
        vector<int> visited(numCourses, -1);

        // step 1 -> create graph
        for(int i=0; i<prerequisites.size(); i++){

            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);

        }

        // step 2 -> check if there is a cycle
        bool res = false;
        for(int i=0; i<numCourses; i++){

            if(visited[i]==-1){
                res = res||dfs(graph, visited, i, 0);
                if(res)
                    return false;
            }

        }

        // if there's a cycle then cant take course
        return !res;

    }
};




class Solution {
public:
    bool dfs(vector<vector<int> >& graph, vector<int>& visited, int startNode, int rank){

        visited[startNode] = rank;

        // INT_MAX -> already visited and not in current path's call stack
        // -1 -> not visited
        // otherwise visited and in current call stack. means cycle is present

        bool b = false;
        for(int i=0; i<graph[startNode].size(); i++){

            if(visited[graph[startNode][i]]==INT_MAX)
                continue;
            if(visited[graph[startNode][i]]==-1){

                b =  b||dfs(graph, visited, graph[startNode][i], rank+1);

            }
            if(visited[graph[startNode][i]]<rank)
                return true;

        }
        visited[startNode] = INT_MAX;

        return b;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int> > graph(numCourses);
        vector<int> visited(numCourses, -1);

        // step 1 -> create graph
        for(int i=0; i<prerequisites.size(); i++){

            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);

        }

        // step 2 -> check if there is a cycle
        bool res = false;
        for(int i=0; i<numCourses; i++){

            if(visited[i]==-1)
                res = res||dfs(graph, visited, i, 0);

        }

        // if there's a cycle then cant take course
        return !res;

    }
};
