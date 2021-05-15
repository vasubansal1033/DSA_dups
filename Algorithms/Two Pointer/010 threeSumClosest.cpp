class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        if(nums.size() < 3)
            return 0;

        sort(nums.begin(), nums.end());
        int i, j, k;

        int res = nums[0]+nums[1]+nums[2];
        for(int i=0; i<nums.size()-2; i++){

            j = i+1;
            k = nums.size()-1;

            while(j<k){

                if(abs(nums[i]+nums[j]+nums[k]-target)<abs(res-target)){
                    res = nums[i]+nums[j]+nums[k];
                }

                if(nums[i]+nums[j]+nums[k]<target)
                    j++;
                else if(nums[i]+nums[j]+nums[k]>target)
                    k--;
                else
                    return target;


            }

        }

        return res;

    }
};
