typedef pair<int, pair<int, int> > p;
// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX
class unionFind{
    int* arr;
    public:
        unionFind(int V){
            this->arr = new int[V];
            for(int i=0; i<V; i++)
                arr[i] = i;
        }
        int find_(int x){

            while(x!=arr[x]){
                arr[x] = arr[arr[x]];
                x = arr[x];
            }

            return x;

        }
        void union_(int x, int y){
            int xId = find_(x);
            int yId = find_(y);
            this->arr[xId] = yId;
        }


};
int spanningTree(int V, int E, vector<vector<int>> &graph) {
    // code here
    priority_queue<p, vector<p>, greater<p> > minHeap;

    // insert all edges in minheap
    for(int i=0; i<V; i++){
        for(int j=i; j<V; j++){

            if(graph[i][j]!=INT_MAX)
                minHeap.push({graph[i][j], {i, j}});

        }
    }
    unionFind components(V);

    int sum = 0;
    while(!minHeap.empty()){

        auto minEdge = minHeap.top(); minHeap.pop();

        // if this edge forms a cycle, ignore it
        if(components.find_(minEdge.second.first)==components.find_(minEdge.second.second))
            continue;
        // union them
        components.union_(minEdge.second.first, minEdge.second.second);
        // add the weight
        sum+=minEdge.first;
    }

    return sum;

}
