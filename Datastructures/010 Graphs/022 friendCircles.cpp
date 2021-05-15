class Solution {
public:

    class unionFind{

    public:
        int* components;
        unionFind(int n){
            this->components = new int[n];
            for(int i=0; i<n; i++)
                components[i] = i;
        }
        int find_(int i){

            while(i!=components[i]){
                components[i] = components[components[i]];
                i = components[i];
            }
            return i;

        }
        void union_(int i, int j){

            int iId = find_(i);
            int jId = find_(j);
            components[iId] = jId;

        }
        int distinctComponents(int size){

            unordered_set<int> set_;
            for(int i=0; i<size; i++){
                set_.insert(find_(components[i]));
            }

            return set_.size();

        }

        ~unionFind(){
            delete[] components;
        };

    };
    int findCircleNum(vector<vector<int>>& M) {

        unionFind components(M.size());

        for(int i=0; i<M.size(); i++){

            for(int j=0; j<M[0].size(); j++){

                if(M[i][j]==1){
                    components.union_(i, j);
                }

            }

        }

        return components.distinctComponents(M.size());

    }
};
