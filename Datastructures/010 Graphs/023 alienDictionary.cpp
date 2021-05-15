#include<bits/stdc++.h>
using namespace std;


string findOrder(string dict[], int N, int K) {

    // Your code here
    unordered_map<char, unordered_set<char> > graph;
    unordered_map<char, int> indegree;
    unordered_set<char> set;

    for(int i=0; i<N-1; i++){

            int k = 0;
            while(k<min(dict[i].size(), dict[i+1].size()) && dict[i][k]==dict[i+1][k])
                k++;
            if(k==min(dict[i].size(), dict[i+1].size()))
                k--;

            // IMPORTANT TO AVOID SELF LOOPS
            if(dict[i][k]!=dict[i+1][k])
                graph[dict[i][k]].insert(dict[i+1][k]);

            set.insert(dict[i][k]);
            set.insert(dict[i+1][k]);

    }

    for(auto i:graph){
        for(auto j:i.second)
            indegree[j]++;
    }

    priority_queue<char, vector<char>, greater<char> > q;
    for(char c:set){

        // if c is not in the indegree map
        // its indegree must be 0
        if(indegree.find(c)==indegree.end()){
            q.push(c);
        }

    }

    string res = "";
    while(!q.empty()){

        char front_ = q.top(); q.pop();
        res.push_back(front_);
        indegree[front_] = -1;

        for(auto i:graph[front_]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }

        }

    }

    return res;

}

int main(){

    string dict[] = { "baa", "abcd", "abca", "cab", "cad" };

    cout<<findOrder(dict, 5, 4);

return 0;
}
