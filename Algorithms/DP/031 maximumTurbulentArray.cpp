class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {

        if(A.size()==1){
            return 1;
        }else if(A.size()==2){
            return A[0]==A[1]?1:2;
        }

        // find the longest turbulent array till index j
        // For current i, check if Ai>Ai-1<Ai-2 or Ai<Ai-1>Ai-2
        // if it is, then dp[i] = dp[i-1]+1
        // else if we have strictly increasing or decreasing seq, i.e. Ai>Ai-1>Ai-2 or Ai<Ai-1<Ai-2
        // In this case, we have to come to Ai-1 for the next iteration as we now cannot include the elements
        // after the beginning of the previous maximum subarray's start as these three elements would break
        // the turbulent property.
        // So if the two elements are same, they'd have 1 size otherwise 2.


        vector<int> dp(A.size(), 0);
        dp[0] = 1;
        dp[1] = (A[1]==A[0])?1:2;
        int res = 0;
        for(int i=2; i<A.size(); i++){

            if((A[i]>A[i-1] && A[i-1]<A[i-2])||(A[i]<A[i-1]&&A[i-1]>A[i-2])){
                dp[i] = 1+dp[i-1];
            }else{
                dp[i] = A[i]==A[i-1]?1:2;
            }

            res = max(res, dp[i]);

        }
        for(int i:dp)
            cout<<i<<" ";

        return res;
    }
};



class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {

        if(A.size()==1){
            return 1;
        }else if(A.size()==2){
            return A[0]==A[1]?1:2;
        }

        int b = (A[1]==A[0])?1:2; // dp[1]
        int res = 0;
        int curr; // dp[i]

        for(int i=2; i<A.size(); i++){

            if((A[i]>A[i-1] && A[i-1]<A[i-2])||(A[i]<A[i-1]&&A[i-1]>A[i-2])){
                curr = 1+b;
            }else{
                curr = (A[i]==A[i-1]?1:2);
            }
            b = curr;
            res = max(res, curr);

        }

        return res;
    }
};

