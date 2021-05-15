class Solution {
public:

    int find_(vector<int>& components, int i){

    // iterative
        while(components[i]!=i)
            i = components[i];
        return i;


    }

    void union_(vector<int>& components, int x, int y){

        int xComp = find_(components, x);
        int yComp = find_(components, y);

        components[xComp] = yComp;

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        // acc to the question, graph will have only one extra edge from connected tree
        // therefore number of edges = n-1 +1 = n

        vector<int> components(edges.size()+1);
        for(int i=1; i<=edges.size(); i++){
            components[i] = i;
        }

        for(int i=0; i<edges.size(); i++){

            if(find_(components, edges[i][0])==find_(components, edges[i][1]))
                return edges[i];

            union_(components, edges[i][0], edges[i][1]);

        }

        return {};

    }
};
