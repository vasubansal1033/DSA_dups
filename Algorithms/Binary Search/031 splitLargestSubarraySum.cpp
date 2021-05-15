class Solution {
public:
    bool isPossible(vector<int>& nums, int m, int maxsubArraySum){

        int sum = 0;
        int cnt = 1; // we have one subarray to start with
        for(int i=0; i<nums.size(); i++){

            sum+=nums[i];
            if(sum>maxsubArraySum){
                sum = nums[i];
                cnt++;

                if(cnt>m) return false;

            }

        }
        // cnt can be less than m also, because we are constraining the sum of a subarray to maximum
        // if cnt is less than m, we can then obviously break into smaller subarrays.
        return cnt<=m;

    }
    int splitArray(vector<int>& nums, int m) {

        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);

        while(lo<hi){

            int mid = lo+(hi-lo)/2;
            if(isPossible(nums, m, mid)){
                hi = mid;
            }else{
                lo = mid+1;
            }


        }

        return hi;

    }
};
