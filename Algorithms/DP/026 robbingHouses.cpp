
// bottom up with space optimization
class Solution {
public:
//     int fun(vector<int>& nums, int idx, vector<int>& dp){

//         // base case
//         if(nums.size()<=idx) return dp[idx] = 0;

//         if(dp[idx]!=-1) return dp[idx];

//         int temp1 = nums[idx] + (dp[idx+2]!=-1?dp[idx+2]:fun(nums, idx+2, dp));
//         int temp2 = dp[idx+1]!=-1?dp[idx+1]:fun(nums, idx+1, dp);

//         return dp[idx] =  max(temp1, temp2);

//     }
    int rob(vector<int>& nums) {

        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];

        // vector<int> dp(nums.size()+5, -1);

        // dp[nums.size()] = 0;
        // dp[nums.size()-1] = nums[nums.size()-1];

        int a = 0; // nums[i+2]
        int b = nums[nums.size()-1]; // nums[i+1]
        int ans;
        for(int i=nums.size()-2; i>=0; i--){
            ans = max(nums[i]+a, b);

            a = b;
            b = ans;

        }

        return ans;

    }
};



// Memoized
class Solution {
public:
    int fun(vector<int>& nums, int idx, vector<int>& dp){

        // base case
        if(nums.size()<=idx) return dp[idx] = 0;

        if(dp[idx]!=-1) return dp[idx];

        int temp1 = nums[idx] + (dp[idx+2]!=-1?dp[idx+2]:fun(nums, idx+2, dp));
        int temp2 = dp[idx+1]!=-1?dp[idx+1]:fun(nums, idx+1, dp);

        return dp[idx] =  max(temp1, temp2);

    }
    int rob(vector<int>& nums) {

        vector<int> dp(nums.size()+5, -1);
        return fun(nums, 0, dp);
    }
};
