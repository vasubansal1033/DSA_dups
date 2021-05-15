class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        if(nums.size()<3) return false;

        vector<int> res;
        for(int i=0; i<nums.size(); i++){

            int temp = lower_bound(res.begin(), res.end(), nums[i])-res.begin();
            if(temp==res.size()){

                res.push_back(nums[i]);

            }else{

                res[temp] = nums[i];

            }

            if(res.size()>=3) return true;

        }

        return false;

    }
};
