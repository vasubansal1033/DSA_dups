// First look at O(N2) solution
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {

        // recurrence
        // Take decision on first element. The subproblem is a suffix matrix
        // dp[i] -> answer for suffix array starting from i
        // Decision -> not include nums[i].
        // If include then consider nums[i]+max(dp[i+1], dp[i+2],... dp[i+k]) s.t. i+k<=n-1

        vector<int> dp(nums.size());
        dp[nums.size()-1] = nums[nums.size()-1];
        int n = nums.size();
        int res = INT_MIN;
        for(int i=nums.size()-2; i>=0; i--){

            dp[i] = INT_MIN/2;
            for(int j=i+1; j<=min(i+k, n-1); j++)
                dp[i] = max({dp[i], nums[i]+dp[j]});

			// It could be possible that taking only the current element is enough
            dp[i] = max(dp[i], nums[i]);
			// final answer is the maximum of all subproblems
            res = max(res, dp[i]);
        }

        return res;

    }
};


class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {

        // recurrence
        // decision on last element
        // dp[i] -> answer for suffix array starting from i
        // not include nums[i], answer is dp[i+1]
        // include then answer is nums[i]+max(dp[i+1], dp[i+2],... dp[i+k]) s.t. i+k<=n-1

        vector<int> dp(nums.size());
        dp[nums.size()-1] = nums[nums.size()-1];
        int n = nums.size();
        int res = INT_MIN;

        deque<int> dq;

        for(int i=nums.size()-2; i>=0; i--){

            dp[i] = INT_MIN/2;
            // We need maximum of future k dp[i]'s
            // Instead of traversal, we can make it a O(1) operation, using idea from sliding window maximum
            while(!dq.empty() && dp[dq.back()]<dp[i+1]) dq.pop_back();
            while(!dq.empty() && dq.front()>i+k) dq.pop_front();
            dq.push_back(i+1);

            dp[i] = max(dp[i],nums[i]+dp[dq.front()]);
            dp[i] = max(dp[i], nums[i]);
            res = max(res, dp[i]);


        }


        return res;

    }
};
