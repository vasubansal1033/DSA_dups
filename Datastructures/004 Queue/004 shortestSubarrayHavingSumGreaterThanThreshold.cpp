class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {

        vector<int> preSum(A.size()+1);

        // cannot apply sliding window because we stop incrementing i when condition is violated
        // this is because of positive numbers. our sum will only decrease by incrementing from start
        // but since we have negative numbers, our sum can increase by removing from start

        // so that prefix array can be considered
        preSum[0] = 0;
        for(int i=1; i<A.size()+1; i++)
            preSum[i] = preSum[i-1]+A[i-1];

        deque<int> dq;
        int res = INT_MAX;

        // deque stores monotonically increasing prefix sums. stores indices actually
        for(int i=0; i<preSum.size(); i++){

            // Remove from front until condition is satisfied and update results
            // since we are maintaining a monotonically increasing queue
            // once condition gets violated, all the elements on right will also violate it
            while(!dq.empty() && preSum[i] - preSum[dq.front()]>=K){
                res = min(res, i-dq.front());
                dq.pop_front();
            }

            // Maintain monotonically increasing queue condition
            // Elements on the right of above conditions case will anyway violate the condition for i
            // visualize using drawing potatoes of increasing size
            while(!dq.empty() && preSum[i]<=preSum[dq.back()])
                dq.pop_back();


            dq.push_back(i);

        }

        return res==INT_MAX?-1:res;

    }
};
