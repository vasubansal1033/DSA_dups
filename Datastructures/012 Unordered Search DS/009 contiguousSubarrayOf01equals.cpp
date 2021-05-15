class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        // maps index to numZeros-numOnes till that index
        unordered_map<int, int> m2;

        int sum = 0;
        int res = INT_MIN;
        for(int i=0; i<nums.size(); i++){

            sum+=nums[i]!=0?1:-1;

            if(sum==0){
                res = i+1;
            }else{

                if(m2.find(sum)!=m2.end()){
                    res = max(res, i - m2[sum]);
                }else
                    m2[sum] = i;

            }

        }

        return res==INT_MIN?0:res;


    }
};
