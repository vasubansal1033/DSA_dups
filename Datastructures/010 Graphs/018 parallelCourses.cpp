#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/discuss/interview-question/509340/Uber-or-Phone-or-Parallel-Courses


int findSemesters(int numCourses, vector<vector<int>>& prerequisites) {

    // Given a vector of courses and their pre-requisites, find the minimum number of semesters required to complete all the courses
    // [i, j] -> j is the prerequisite of i
    // we can take as many courses as we want in a semester
    // if you can't return -1

    // Idea -> Model this as a graph problem. In a particular semester we can take only those courses for which we already completed prerequisites
    // That is, indegree is 0

    vector<vector<int> > graph(numCourses);
    vector<int> indegree(numCourses, 0);

    // construct adjacency list and indegree for all nodes
    for(int i=0; i<prerequisites.size(); i++){
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        indegree[prerequisites[i][0]]++;
    }

    int semesters = 0;
    queue<int> q;
    for(int i=0; i<numCourses; i++){
        if(indegree[i]==0)
            q.push(i);
    }
    int numNodes = 0;
    while(!q.empty()){

        int sz = q.size();
        for(int i=0; i<sz; i++){

            int front_ = q.front(); q.pop();
            for(int j=0; j<graph[front_].size(); j++){
                indegree[graph[front_][j]]--;
                if(indegree[graph[front_][j]]==0)
                    q.push(graph[front_][j]);

            }

            numNodes++;

        }

        semesters++;

    }

    return numNodes==numCourses?semesters:-1;


}

int main(){

    int numCourses = 3;
    vector<vector<int> > prerequisites = {{0, 1}, {1, 0}};
    cout<<findSemesters(numCourses, prerequisites);

return 0;
}

