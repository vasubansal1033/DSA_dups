class Solution {
public:

    vector<vector<int> > permuteUtil(vector<int>& nums, int start){

        if(nums.size()==start){
            return {{}};
        }

        // 1,2,3

        vector<vector<int> > permuteSol = permuteUtil(nums, start+1);
        // permuteUtil -> {{2, 3}, {3, 2}}
        // add 1 at every possible location and add it to result
        vector<vector<int> > result;
        for(auto vec:permuteSol){

            for(int i=0; i<=vec.size(); i++){

                vector<int> temp = vec;
                temp.insert(temp.begin()+i, nums[start]);
                result.push_back(temp);

            }

        }

        return result;

    }
    vector<vector<int>> permute(vector<int>& nums) {
        return permuteUtil(nums, 0);
    }
};


// a bit better
class Solution {
public:

    void permuteUtil(vector<int>& nums, int start, vector<vector<int> >& result){

        if(nums.size()==start){
            result =  {{}};
            return;
        }

        // 1,2,3

        vector<vector<int> > permuteSol;
        permuteUtil(nums, start+1, permuteSol);

        // permuteUtil -> {{2, 3}, {3, 2}}
        // add 1 at every possible location and add it to result

        for(auto vec:permuteSol){

            for(int i=0; i<=vec.size(); i++){

                vector<int> temp = vec;
                temp.insert(temp.begin()+i, nums[start]);
                result.push_back(temp);

            }

        }

        return;

    }
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > result;
        permuteUtil(nums, 0, result);

        return result;
    }
};


// decision based framework
class Solution {
public:

    void permuteUtil(vector<int>& nums, vector<vector<int> >& result, vector<int> currSet, vector<bool>& bitmap){

        if(currSet.size()==nums.size()){

            result.push_back(currSet);
            return;

        }

        for(int i=0; i<nums.size(); i++){

            if(!bitmap[i]){

                currSet.push_back(nums[i]);
                bitmap[i] = true;
                permuteUtil(nums, result, currSet, bitmap);

                currSet.pop_back();
                bitmap[i] = false;

            }

        }



    }
    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> currSet;
        vector<bool> bitmap(nums.size(), false);

        permuteUtil(nums, result, currSet, bitmap);

        return result;
    }
};
