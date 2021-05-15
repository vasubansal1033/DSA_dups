class Solution {
public:
    int mergeSortUtil(vector<long>& prefixSum, int lower, int upper, int start, int last){

        if(last==start) return prefixSum[start]>=lower && prefixSum[start]<=upper;

        int mid = start+(last-start)/2;
        int cnt = mergeSortUtil(prefixSum, lower, upper, start, mid)+mergeSortUtil(prefixSum, lower, upper, mid+1, last);

        int i=mid+1, j=mid+1;
        for(int l=start; l<=mid; l++){

            while(i<=last && prefixSum[i]-prefixSum[l]<lower) i++;
            while(j<=last && prefixSum[j]-prefixSum[l]<=upper) j++;

            // now, we have prefixSum[i]-prefixSum[l]>=lower
            // prefixSum[j]-prefixSum[l]>upper or prefixSum[j-1]-prefixSum[l]<=upper
            // so required answer will be -> j-1-i+1 = j-i
            cnt+=j-i;

        }

        inplace_merge(prefixSum.begin()+start, prefixSum.begin()+mid+1, prefixSum.begin()+last+1);

        return cnt;

    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {

        if(nums.size()==0) return 0;

        // Merge sort like approach on prefixSum array
        // Calculate answers for left half and right half. Now these will be sorted also
        // Then find all subarrays where one index is in left half and other is in right half
        // Add these

        vector<long> prefixSum(nums.size());
        prefixSum[0] = nums[0];
        for(int i=1; i<prefixSum.size(); i++)
            prefixSum[i] = nums[i]+prefixSum[i-1];

        return mergeSortUtil(prefixSum, lower, upper, 0, nums.size()-1);

    }
};
