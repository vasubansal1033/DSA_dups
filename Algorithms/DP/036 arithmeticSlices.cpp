// Space optimized solution
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {

        // less than three elements cannot be in AP
        if(A.size()<3) return 0;

        // less than 3 elements cannot constitute AP
        int prevDp = 0; // dp[i-1]
        // No AP means their difference is 0
        int prevDiff = 0; // diff[i-1]

        int sum = 0;
        for(int i=2; i<A.size(); i++){

            int currDp = 0;

            if(A[i]-A[i-1]==A[i-1]-A[i-2]){
                currDp = 1;
            }

            if(A[i]-A[i-1]==prevDiff){
                currDp += prevDp;
            }
            prevDiff = A[i]-A[i-1];
            prevDp = currDp;
            sum+=currDp;

        }

        return sum;

    }
};


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {

        // less than three elements cannot be in AP
        if(A.size()<3) return 0;

        // no of subarrays, which are in AP
        // Let dp[i] store the length of AP subarray ending at i
        // Each element of A can be atmost 1 times the last element of AP subarray ending at it.
        // diff[i] will store the difference of the AP ending at i. Again for each element only one difference will be present. Because we are talking about subarrays/

        vector<int> dp(A.size(), 0);
        vector<int> diff(A.size(), 0);

        // less than 3 elements cannot constitute AP
        dp[0] = 0;
        dp[1] = 0;
        // No AP means their difference is 0
        diff[0] = 0; diff[1] = 0;

        int sum = 0; // We have to find all Arithmetic slices
        for(int i=2; i<A.size(); i++){

            // If the three elements form AP, then atleast 1 AP exists
            if(A[i]-A[i-1]==A[i-1]-A[i-2]){
                dp[i] = 1;
            }
            // If difference with i-1 is same as the difference of APs ending at i-1, then current element can also be included in that AP.
            if(A[i]-A[i-1]==diff[i-1]){
                dp[i] += dp[i-1];
            }
            diff[i] = A[i]-A[i-1];

            sum+=dp[i];

        }

        return sum;

    }
};
