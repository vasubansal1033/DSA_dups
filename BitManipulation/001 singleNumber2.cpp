class Solution {
public:
    int singleNumber(vector<int>& nums) {

        // If we check each bit of every number, then number of ones for each bit is 3k or 3k+1
        // If number is 3k, means that this bit is not set in the unique number
        // If number is 3k+1, means that this bit is set in the unique number

        int res = 0, countOnes;
        for(int i=0; i<32; i++){

            countOnes = 0;
            for(int j=0; j<nums.size(); j++)
                countOnes += nums[j] & (1<<i)?1:0;

            if(countOnes%3==1)
                res = res|(1<<i);

        }

        return res;


    }
};
