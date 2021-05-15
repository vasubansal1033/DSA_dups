class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        // Find the numbers such that
        // all the numbers before it are smaller than it
        // all the numbers to the right of it are greater than it
        // subarray between these two will be the array

        int mini = nums[nums.size()-1];
        int maxi = nums[0];

        int start = -1, last = -2;
        for(int i=1; i<nums.size(); i++){

            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[nums.size()-i-1]);
            if(nums[i]<maxi) last = i;
            if(nums[nums.size()-i-1]>mini) start = nums.size()-i-1;

        }

        return last-start+1;

    }
};
