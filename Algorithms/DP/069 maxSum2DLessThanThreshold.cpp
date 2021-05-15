class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

        int res = INT_MIN;
        for(int l=0; l<matrix[0].size(); l++){

            // this stores the cumulative sum of rows from top to bottom
            // of the portion between l and r inclusive

            vector<int> rowSum(matrix.size(), 0);
            for(int r=l; r<matrix[0].size(); r++){

                for(int i=0; i<matrix.size(); i++)
                    rowSum[i]+=matrix[i][r];

                set<int> cumSum;
                cumSum.insert(0);
                int runSum = 0;
                for(int i=0; i<rowSum.size(); i++){

                    runSum += rowSum[i];
                    // runSum-target<=k -> target>=runSum-k
                    auto it = cumSum.lower_bound(runSum-k); // lower bound gets the first value>=target
                    if(it!=cumSum.end()){
                        res = max(res, runSum-*it);
                    }

                    cumSum.insert(runSum);

                }

            }

        }
        return res;

    }
};
