class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // store prefix sums in hash table
        unordered_map<int, int> hashmap;
        int sum = 0;

        int count = 0;
        // prefix sum with sum 0 is present
        hashmap[0] = 1;
        for(int i=0; i<nums.size(); i++){

            sum+=nums[i];

            // If hashmap[sum-k] is not present, it will create
            // a pair with key sum-k and value 0
            // so the next if we call it, it will give an iterator
            // the value will be 0, and wastes memory
            // not impact us in this question
            // thus, we used if-else condition
            if(hashmap.find(sum-k)!=hashmap.end())
                count+=hashmap[sum-k];

            hashmap[sum]++;

        }


        return count;

    }
};
