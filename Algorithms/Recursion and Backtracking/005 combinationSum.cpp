class Solution {
public:

    void combinationSumUtil(vector<int>& candidates, int target, vector<int> currSet, int start, vector<vector<int> >& result){

        if(target==0){

            result.push_back(currSet);
            return;

        }
        if(target<candidates[start] || start==candidates.size())
            return;

        // choose ith element minimum
        for(int i=start; i<candidates.size(); i++){

            if(candidates[i]<=target){
            currSet.push_back(candidates[i]);
            combinationSumUtil(candidates, target-candidates[i], currSet, i, result);
            currSet.pop_back();
            }else{
                return;
            }

        }


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> currSet;
        vector<vector<int> > result;

        sort(candidates.begin(), candidates.end());

        combinationSumUtil(candidates, target, currSet, 0, result);

        return result;

    }
};


class Solution {
public:

    void combinationSumUtil(vector<int>& candidates, int target, vector<int> currSet, int start, vector<vector<int> >& result){

        if(candidates.size()==start){
            if(target==0)
                result.push_back(currSet);
            return;
        }

        if(candidates[start]<=target){

            // include it
            // choosing with replacement
            currSet.push_back(candidates[start]);
            combinationSumUtil(candidates, target-candidates[start], currSet, start, result);

            // don't include it
            currSet.pop_back();
            combinationSumUtil(candidates, target, currSet, start+1, result);

        }else{

            // we can't include it
            combinationSumUtil(candidates, target, currSet, start+1, result);

        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> currSet;
        vector<vector<int> > result;
        combinationSumUtil(candidates, target, currSet, 0, result);

        return result;

    }
};
