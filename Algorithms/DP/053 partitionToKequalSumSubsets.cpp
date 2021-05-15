class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {

        // first approach was that we have to choose k subsets of sum partitionSum
        // So have a visited array and select ith element approach in solution
        // to get find k subsets.
        // This is also known as DFS approach

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%k!=0) return false;

        // solve the equivalent problem of partitioning set with sum = partitionSum.
        int partitionSum = sum/k;

        int n = nums.size();
        vector<int> map((1<<n)+2, -1); // stores remainder of chosen elements
        map[0] = 0;

        for(int mask = 0; mask<(1<<n); mask++){

            if(map[mask]==-1) continue; // invalid
            for(int j=0; j<n; j++){

                if(!(mask & (1<<j)) && map[mask]+nums[j]<=partitionSum)

                    // modulus is so that we can ignore the sum of already formed groups
                    // say map[x] and x = k*partitionSum + rem, we don't need the first term
                    map[mask | (1<<j)] = (map[mask]+nums[j])%partitionSum;
                    // dp[mask|(1<<j)] = (dp[mask]+nums[j]==sum)?0:(dp[mask]+nums[j]);

            }

        }

        return map[(1<<n)-1]==0;

    }
};

class Solution {
public:
    bool isSet(int& bitmask, int i){

        if(bitmask & (1<<i) ) return true;
        else return false;

    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%k!=0) return false;

        int partitionSum = sum/k;
        vector<int> map((1<<16) + 2, -1);
        map[0] = 0;
        for(int i=0; i < (1<<nums.size()); i++){

            if(map[i]==-1) continue;
            for(int j=0; j<nums.size(); j++){

                if(!isSet(i, j) && (nums[j]+map[i])<=partitionSum)
                    map[i | (1<<j)] = (nums[j]+map[i])%partitionSum;

            }

        }

        return map[(1<<(nums.size()))-1]==0;

    }
};
