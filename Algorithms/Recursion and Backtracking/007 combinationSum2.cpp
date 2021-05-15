class Solution {
public:

    void combinationSum2Util(vector<int>& candidates, int target, int start, vector<vector<int> >& result, vector<int> currSet){


        // base case
        if(target==0){
            result.push_back(currSet);
            return;
        }

        if(start==candidates.size() || candidates[start]>target)
            return;


        // ith element is minimum
        for(int i=start; i<candidates.size(); i++){

            if(i>start && candidates[i]==candidates[i-1])
                continue;

            if(candidates[i]<=target){
                currSet.push_back(candidates[i]);
                combinationSum2Util(candidates, target-candidates[i], i+1, result, currSet);
                currSet.pop_back();
            }else{
                return;
            }

        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int> > result;
        vector<int> currSet;

        combinationSum2Util(candidates, target, 0, result, currSet);

        return result;

    }
};


