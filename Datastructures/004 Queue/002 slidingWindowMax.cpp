class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;
        vector<int> res;

        for(int i=0; i<nums.size(); i++){

            // At index i, considering window from (i-k+1) to i
            // We are maintaining a monotonic decreasing deque containing the respective indices
            // front stores the max.

            // if front index goes out of window remove it
            // while inserting, remove from the back until the back is less than current number

            while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();
            while(!dq.empty() && dq.front()<i-k+1) dq.pop_front();

            dq.push_back(i);
            if(i>=k-1){
                res.push_back(nums[dq.front()]);
            }

        }

        return res;

    }
};
