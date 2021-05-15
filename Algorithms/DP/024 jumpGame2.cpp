class Solution {
public:
    int jump(vector<int>& nums) {

        if(nums.size()<2) return 0;

        int steps = 1, i, curEnd = 0, newEnd=0;

        for(i=0; i<=curEnd; ++i){

            // update newEnd, farthest possible index from current indenx
            newEnd = max(newEnd, i+nums[i]);

            // If we can reach the end, return ans
            if(newEnd>=(nums.size()-1)) return steps;

            // end of the current level, move to the next level
            if(i==curEnd){
                curEnd = newEnd;
                ++steps;
            }

        }

        return INT_MAX; // curEnd = newEnd, can not reach the end
    }
};


class Solution {
public:
    int jump(vector<int>& nums) {

        vector<unsigned int> dp(nums.size(), INT_MAX);

        unsigned int currIndex(0);
        dp[currIndex] = 0;

        while(currIndex<nums.size()-1){

            for(unsigned int i=currIndex+1; i<=currIndex+nums[currIndex]; i++){

                if(i==nums.size()){
                    return dp[nums.size()-1];
                }
                dp[i] = min(dp[i], dp[currIndex]+1);
            }

            currIndex++;

        }

        return dp[nums.size()-1];

    }
};
