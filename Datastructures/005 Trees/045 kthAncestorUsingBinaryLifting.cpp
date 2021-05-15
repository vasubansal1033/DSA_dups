class TreeAncestor {
public:

    vector<vector<int> > adjList;
    // int up[50005][20]; // up[i][j] stores the 2^jth ancestor of i
    int** up;

    void binary_lifting(int curr, int parent){

        up[curr][0] = parent; // means 2^0th i.e. 1 jump parent, not 0
        for(int i=1; i<20; i++){

            if(up[curr][i-1]!=-1){
                up[curr][i] = up[up[curr][i-1]][i-1];
            }else up[curr][i] = -1;

        }

        for(int i=0; i<adjList[curr].size(); i++){

            int child = adjList[curr][i];
            if(child!=parent){
                binary_lifting(child, curr);
            }

        }

    }
    TreeAncestor(int n, vector<int>& parent) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        adjList.resize(n);

        int root;
        for(int i=0; i<parent.size(); i++){

            if(parent[i]==-1){
                root = i;
                continue;
            }
            adjList[parent[i]].push_back(i);
        }

        // Dynamic memory allocation of 2d array
        up = new int*[n];
        for(int i=0; i<n; i++){
            up[i] = new int[20];
            memset(up[i], -1, sizeof(int)*20);
        }

        // memset(up, -1, sizeof(up));
        binary_lifting(root, -1);

    }

    int getKthAncestor(int node, int k) {

        // base case
        if(k==0 || node==-1) return node;

//         for(int i=0; i<20; i++){

//             if(k>=(1<<i) && (k&(1<<i))){
//                 return getKthAncestor(up[node][i], k-(1<<i)); // answer for 2^i jump is stored in i
//             }

//         }

        // k = k-(k&-k) -> last set bit is removed

        int lastSetBit = log2(k&(-k));
        return getKthAncestor(up[node][(lastSetBit)], k-(k&(-k)));


        return -1;

    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */






// Space efficient
class TreeAncestor {
public:

    vector<vector<int> > adjList;
    // int up[50005][20]; // up[i][j] stores the 2^jth ancestor of i
    int** up;

    void binary_lifting(int curr, int parent){

        up[curr][0] = parent;
        for(int i=1; i<20; i++){

            if(up[curr][i-1]!=-1){
                up[curr][i] = up[up[curr][i-1]][i-1];
            }else up[curr][i] = -1;

        }

        for(int i=0; i<adjList[curr].size(); i++){

            int child = adjList[curr][i];
            if(child!=parent){
                binary_lifting(child, curr);
            }

        }

    }
    TreeAncestor(int n, vector<int>& parent) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        adjList.resize(n);

        int root;
        for(int i=0; i<parent.size(); i++){

            if(parent[i]==-1){
                root = i;
                continue;
            }
            adjList[parent[i]].push_back(i);
        }

        // Dynamic memory allocation of 2d array
        up = new int*[n];
        for(int i=0; i<n; i++){
            up[i] = new int[20];
            memset(up[i], -1, sizeof(int)*20);
        }

        // memset(up, -1, sizeof(up));
        binary_lifting(root, -1);

    }

    int getKthAncestor(int node, int k) {

        // base case
        if(k==0 || node==-1) return node;

        for(int i=19; i>=0; i--){

            if(k>=(1<<i) && (k&(1<<i))){
                return getKthAncestor(up[node][i], k-(1<<i)); // answer for 2^i jump is stored in i
            }

        }

        return -1;

    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */


class TreeAncestor {
public:

    vector<vector<int> > adjList;
    int root = -1;
    int up[50005][20];

    void binary_lifting(int curr, int parent){

        up[curr][0] = parent;

        for(int i=1; i<20; i++){

            if(up[curr][i-1]!=-1)
                up[curr][i] = up[up[curr][i-1]][i-1];
            else up[curr][i] = -1;

        }


        for(int i=0; i<adjList[curr].size(); i++){

            int child = adjList[curr][i];
            if(curr!=parent)
                binary_lifting(child, curr);

        }


    }
    TreeAncestor(int n, vector<int>& parent) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);


        adjList.resize(n);
        for(int i=0; i<parent.size(); i++){

            if(parent[i]==-1){
                root = i;
                continue;
            }

            adjList[parent[i]].push_back(i);
        }

        memset(up, -1, sizeof(up));
        binary_lifting(root, -1);

    }
    int getKthAncestor(int node, int k) {

        // k--;
        if(k==0 || node==-1) return node;

        for(int i=19; i>=0; i--){
            if(k>=(1<<i) && k&(1<<i)){
                return getKthAncestor(up[node][i], k-(1<<i));
            }
        }

        return 0;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
