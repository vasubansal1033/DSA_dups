class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {


        /*

         Basic idea:
        1. for any array whose length is l, the first missing positive must be in range [1,...,l+1], so we only have to care about those elements in this range and remove the rest.
        2. we can use the array index as the hash to restore the frequency of each number within the range [1,...,l+1]

        */

        nums.push_back(0);
        int n = nums.size();

        // delete useless element
        for(int i=0; i<n; i++){
            if(nums[i]<0 || nums[i]>=n)
                nums[i] = 0;
        }

        // use the index to record frequency of each element in its number-place
        for(int i=0; i<n; i++){
            nums[nums[i]%n] += n; // frequency of a number is f*n + nums[i] and is placed at nums[nums[i]] which is between 1 and n+1
        }

        for(int i=0; i<n; i++){

            // first non occuring positive number
            if(nums[i]/n==0)
                return i;
        }

        return n;

    }
};
