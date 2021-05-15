class Solution {
public:

    void combinationSum3Util(int k, int n, int start, vector<vector<int> >& result, vector<int> currSet, int k_){

        if(n==0 && currSet.size()==k_){
           result.push_back(currSet);
           return;
        }

        // because we have already sorted
        if(k<=0 || n<start)
            return;

        // ith number is minimum
        // upper bound is 9-k+1
        // k can be maximum 9
        // suppose k=4
        // then we can have only (1,2,3,4), (2,3,4,5).... (6,7,8,9)
        // start varies from 1 to 6 which is 9-4+1
        for(int i=start; i<=9-k+1; i++){

            currSet.push_back(i);
            combinationSum3Util(k-1, n-i, i+1, result, currSet, k_);
            currSet.pop_back();

        }


    }
    vector<vector<int>> combinationSum3(int k, int n) {

        if(n>45 || k==0)
            return {};

        vector<vector<int> > result;
        vector<int> currSet;

        combinationSum3Util(k, n, 1, result, currSet, k);

        return result;
    }
};



class Solution {
public:

    void combinationSum3Util(int k, int n, int i, vector<vector<int> >& result, vector<int> currSet, int k_){

        // strict inequality as otherwise solutions containing 9 wont come
        if(i>10 || n<0)
            return;

        if(currSet.size()==k_){

            if(n==0)
                result.push_back(currSet);
            return;

        }


        if(i<=n){

            // include i
            currSet.push_back(i);
            combinationSum3Util(k-1, n-i, i+1, result, currSet, k_);

            // not include i
            currSet.pop_back();
            combinationSum3Util(k, n, i+1, result, currSet, k_);
        }else{
            combinationSum3Util(k, n, i+1, result, currSet, k_);
        }


    }
    vector<vector<int>> combinationSum3(int k, int n) {

        if(n>45 || k==0)
            return {};

        vector<vector<int> > result;
        vector<int> currSet;

        combinationSum3Util(k, n, 1, result, currSet, k);

        return result;
    }
};
