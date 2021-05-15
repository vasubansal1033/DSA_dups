class Solution {
public:
    int mergeSortUtil(vector<int>& nums, int start, int last){

        if(last<=start) return 0;

        int mid = start+(last-start)/2;
        int cnt = mergeSortUtil(nums, start, mid)+mergeSortUtil(nums, mid+1, last);

        int r = mid+1;
        for(int l=start; l<=mid; l++){

            while(r<=last && nums[l]*1L>(nums[r]*2L)) r++;
            cnt += (r-mid-1);
        }

        inplace_merge(nums.begin()+start, nums.begin()+mid+1, nums.begin()+last+1);

        return cnt;
    }
    int reversePairs(vector<int>& nums) {

        if(nums.size()==0) return 0;

        return mergeSortUtil(nums, 0, nums.size()-1);

    }
};
