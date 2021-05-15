


// DP memoized
class Solution {
public:
    int util(vector<int>& nums1, vector<int>& nums2, vector<vector<int> >& dp, int idx, bool isNums1, int sum){

        // base case
        if((isNums1 && idx==nums1.size()) || (!isNums1 && idx==nums2.size())){
            return dp[idx][!isNums1] = sum;
        }

        if(isNums1){

            // move front in current array
            int ans = util(nums1, nums2, dp, idx+1, isNums1, sum+nums1[idx]);

            // auto it = nums2.lower_bound(nums1[idx]);
            auto it = find(nums2.begin(), nums2.end(), nums1[idx]);
            if(it!=nums2.end()){
                int temp = it-nums2.begin();
                ans = max(ans, util(nums1, nums2, dp, temp+1, !isNums1, sum+nums1[idx]));
            }

            return dp[idx][!isNums1] = ans;

        }
        int ans = util(nums1, nums2, dp, idx+1, isNums1, sum+nums2[idx]);

        auto it = find(nums1.begin(), nums1.end(), nums2[idx]);
        if(it!=nums1.end()){
            int temp = it-nums1.begin();
            ans = max(ans, util(nums1, nums2, dp, temp+1, !isNums1, sum+nums2[idx]));
        }

        return dp[idx][!isNums1] = ans;

    }
    int maxSum(vector<int>& nums1, vector<int>& nums2) {

        vector<vector<int> > dp(nums1.size()+nums2.size()+5, vector<int>(2));

        return max(util(nums1, nums2, dp, 0, 1, 0), util(nums1, nums2, dp, 0, 0, 0));
    }
};
