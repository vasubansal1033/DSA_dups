class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {

        vector<int> preXor(arr.size());

        int cumXor = 0;
        for(int i=0; i<arr.size(); i++){
            cumXor = cumXor^arr[i];
            preXor[i] = cumXor;
        }

        vector<int> res;
        for(int i=0; i<queries.size(); i++){

            int l = 0;
            if(queries[i][0]==0){
                l = 0;
            }else{
                l = preXor[queries[i][0]-1];
            }
            int r = 0;
            if(queries[i][1]==0){
                r = arr[0];
            }else{
                r = preXor[queries[i][1]];
            }
            res.push_back(l^r);

        }

        return res;

    }
};
