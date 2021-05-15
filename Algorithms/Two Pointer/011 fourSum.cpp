class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        for(int i=0; i<nums.size(); i++){

            int three_sum = target-nums[i];
            for(int j=i+1; j<nums.size(); j++){

                int two_sum = three_sum-nums[j];
                int m = j+1; int n = nums.size()-1;
                while(m<n){

                    if(nums[m]+nums[n]==two_sum){
                        int t1 = nums[m], t2 = nums[n];
                        res.push_back({nums[i], nums[j], nums[m], nums[n]});

                        while(m<n && nums[m]==t1) m++;
                        while(m<n && nums[n]==t2) n--;

                    }else if(nums[m]+nums[n]<two_sum){
                        m++;
                    }else
                        n--;

                }
                while(j<nums.size()-1 && nums[j]==nums[j+1]) j++;

            }
            while(i<nums.size()-1 && nums[i]==nums[i+1]) i++;

        }

        return res;

    }
};
