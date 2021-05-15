class Solution {
public:

    int majorityElement(vector<int>& nums) {

        int a, cnt=0;
        for(int i=0; i<nums.size(); i++){

            if(cnt==0){
                a = nums[i];
                cnt++;
            }
            else if(a==nums[i])
                cnt++;
            else
                cnt--;

        }
        cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==a)
                cnt++;
        }

        if(cnt>nums.size()/2)
            return a;
        return -1;

    }
};
