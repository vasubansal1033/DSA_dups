class Solution {
public:

    void grayCodeUtil(int n, vector<int>& arr){

        // base case
        if(n == 0){
            arr = {0};
            return;
        }

        // for n=3, you get 000, 001, 011, 010 which is basically sol for n=2
        // then reverse this array and make the first bit 1 and push to array
        // 110, 111, 101, 100

        grayCodeUtil(n-1, arr);

        int sz = arr.size();
        int var = pow(2, n-1);
        for(int i=sz-1; i>=0; i--){
            arr.push_back(var+arr[i]);
        }

        return;

    }
    vector<int> grayCode(int n) {

        vector<int> arr;

        grayCodeUtil(n, arr);

        return arr;

    }
};
