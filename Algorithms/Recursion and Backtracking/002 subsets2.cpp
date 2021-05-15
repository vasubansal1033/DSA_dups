// naive solution
class Solution {
public:

    void subsetsUtil(vector<int>& nums, int start, vector<vector<int> >& result){

        if(nums.size()==start){
            result = {{}};
            return;
        }


        // say nums = 1,2,3
        vector<vector<int> > subsetSol;
        subsetsUtil(nums, start+1, subsetSol);

        // subsetSol contains {}, {2},{3},{2, 3}
        result = subsetSol;
        // add {1}, {1, 2}, {1, 3}, {1, 2, 3}
        for(int i=0; i<subsetSol.size(); i++){

            vector<int> temp = subsetSol[i];
            temp.push_back(nums[start]);

            if(find(result.begin(), result.end(), temp)==result.end())
                result.push_back(temp);

        }

        return;

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        subsetsUtil(nums, 0, result);
        return result;
    }
};


// good Solution
class Solution {
public:

    void subsetsUtil(vector<int>& nums, int start, vector<vector<int> >& result, vector<int> currSet){

        if(start==nums.size()){
            result.push_back(currSet);
            return;
        }

        // find first index which is different then nums[start]
        int i = start+1;
        while(i<nums.size() && nums[i]==nums[i-1])
            i++;

        // include nums[start] 0 times
        subsetsUtil(nums, i, result, currSet);
        for(int k=start; k<i; k++){

            currSet.push_back(nums[start]);
            subsetsUtil(nums, i, result, currSet);

        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int> > result;
        vector<int> currSet;

        sort(nums.begin(), nums.end());
        subsetsUtil(nums, 0, result, currSet);

        return result;

    }
};


// another good Solution

class Solution {
public:

    void subsetsUtil(vector<int>& nums, int start, vector<vector<int> >& result, vector<int> currSet){

        if(start==nums.size()){
            result.push_back(currSet);
            return;
        }

        // dont include anything
        subsetsUtil(nums, nums.size(), result, currSet);

        // ith element is smallest
        for(int i=start; i<nums.size(); i++){


            if(i>start && nums[i]==nums[i-1]) continue;

            // include the start element
            // subproblem is the from start+1
            currSet.push_back(nums[i]);
            subsetsUtil(nums, i+1, result, currSet);
            currSet.pop_back();

        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int> > result;
        vector<int> currSet;

        sort(nums.begin(), nums.end());
        subsetsUtil(nums, 0, result, currSet);

        return result;

    }
};
