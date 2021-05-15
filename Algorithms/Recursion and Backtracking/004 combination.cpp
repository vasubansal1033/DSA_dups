class Solution {
public:

    void combineUtil(int n, int k, int start, vector<vector<int> >& result, vector<int> currSet){

        if(k==0){
            result.push_back(currSet);
            return;
        }

        if(n<=start || n-start<k)
            return;

        // if we have less than k elements left, and we still want >=k elements, we should avoid it

        for(int i=start; i<n-k+1; i++){

            currSet.push_back(i+1);
            combineUtil(n, k-1, i+1, result, currSet);
            currSet.pop_back();

        }



    }
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int> > result;
        vector<int> currSet;

        combineUtil(n, k, 0, result, currSet);
        return result;

    }
};



class Solution {
public:

    void combineUtil(int n, int k, int start, vector<vector<int> >& result, vector<int> currSet){

        if(k==0){
            result.push_back(currSet);
            return;
        }
        if(n-start<k || start==n)
            return;

        // not include current element
        combineUtil(n, k, start+1, result, currSet);
        // include current element

        // current element will be i+1
        currSet.push_back(start+1);
        combineUtil(n, k-1, start+1, result, currSet);



    }
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int> > result;
        vector<int> currSet;

        combineUtil(n, k, 0, result, currSet);
        return result;

    }
};
