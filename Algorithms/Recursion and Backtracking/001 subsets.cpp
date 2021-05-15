class Solution {
public:

    void subsetsUtil(vector<int>& nums, int start, vector<vector<int> >& result, vector<int> currSet){

        result.push_back(currSet);
        if(nums.size()==start){
            // result.push_back(currSet);
            return;
        }

        // no element in the subset
        // subsetsUtil(nums, nums.size(), result, currSet);

        // ith element is the smallest element
        for(int i=start; i<nums.size(); i++){

            currSet.push_back(nums[i]);
            subsetsUtil(nums, i+1, result, currSet);
            currSet.pop_back();

        }


    }
    vector<vector<int>> subsets(vector<int>& nums) {

        // sorting not needed
        // sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        vector<int> currSet;

        subsetsUtil(nums, 0, result, currSet);

        return result;

    }
};


class Solution {
public:

    void subsetsUtil(vector<int>& nums, int start, vector<vector<int> >& result, vector<int> currSet){

        if(nums.size()==start){
            result.push_back(currSet);
            return;
        }

        // no element in the subset
        subsetsUtil(nums, nums.size(), result, currSet);

        // ith element is the smallest element
        for(int i=start; i<nums.size(); i++){

            currSet.push_back(nums[i]);
            subsetsUtil(nums, i+1, result, currSet);
            currSet.pop_back();

        }


    }
    vector<vector<int>> subsets(vector<int>& nums) {

//        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        vector<int> currSet;

        subsetsUtil(nums, 0, result, currSet);

        return result;

    }
};


class Solution {
public:

    vector<vector<int> > subsetsUtil(vector<int>& nums, int start){

        if(nums.size()==start)
            return {{}};

        // say nums = 1,2,3
        vector<vector<int> > subsetSol = subsetsUtil(nums, start+1);
        // subsetSol contains {}, {2},{3},{2, 3}
        vector<vector<int> > result = subsetSol;
        // add {1}, {1, 2}, {1, 3}, {1, 2, 3}
        for(int i=0; i<subsetSol.size(); i++){

            vector<int> temp = subsetSol[i];
            temp.push_back(nums[start]);
            result.push_back(temp);

        }

        return result;



    }
    vector<vector<int>> subsets(vector<int>& nums) {
        return subsetsUtil(nums, 0);
    }
};

// return type is void
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
            result.push_back(temp);

        }

        return;



    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > result;
        subsetsUtil(nums, 0, result);
        return result;
    }
};






class Solution {
public:

    void subsetsUtil(vector<int>& nums, int start, vector<vector<int> >& result, vector<int> currSet){

        if(nums.size()==start){
            result.push_back(currSet);
            return;
        }

        // not include the current element
        subsetsUtil(nums, start+1, result, currSet);

        // include current element
        currSet.push_back(nums[start]);
        subsetsUtil(nums, start+1, result, currSet);

        return;



    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> currSet;
        subsetsUtil(nums, 0, result, currSet);
        return result;
    }
};
