class Solution {
public:
    class unionFind{
        int* arr;
        int numComponents; // stores number of components
    public:
        unionFind(int n){
            arr = new int[n];
            for(int i=0; i<n; i++)
                arr[i] = i;
            numComponents = n; // initially consider every node as independent component
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
            arr[xId] = yId;
            numComponents--; // at each union, num components will decrease by 1

        }
        int getComponents(){
            return numComponents;
        }
        ~unionFind(){
            delete[] arr;
        }

    };
    int makeConnected(int n, vector<vector<int>>& connections) {

        unionFind components(n);
        int redundant = 0;
        for(auto edge:connections){

            // if they belong to diff components, union
            if(components.find_(edge[0])!=components.find_(edge[1])){
                components.union_(edge[0], edge[1]);
            }else // otherwise, we have a redundant wire
                redundant++;

        }

        return components.getComponents() - 1<=redundant?(components.getComponents()-1):-1;

    }
};
