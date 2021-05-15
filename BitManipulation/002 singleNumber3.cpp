class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int cumXor = 0;
        for(int i=0; i<nums.size(); i++){
            cumXor ^= nums[i];
        }

        // find the rightmost set bit in cumXor
        // This is because we are sure that this bit was different in the original distinct numbers
        // That is why it was set
        int k = cumXor&(~(cumXor-1));

        int a=0, b=0;
        for(int i=0; i<nums.size(); i++){

            // if the kth bit is set then xor with say a and if not then with b.
            // basically we are dividing the entire array into two groups G1 and G2
            // G1 union G2 = array
            // G1 contains a and G2 contains b or vice versa
            // Now if kth bit of any number is set then its duplicate will also be included
            // Similarly if kth bit is not set, then it's duplicate will be included in that set
            // Thus by this partitioning we reduced the problem to singleNumber1
            if(nums[i]&k)
                a = a^nums[i];
            else
                b = b^nums[i];

        }

        return {a, b};

    }
};
