class Solution {
public:
    int subarraysDivByK(vector<int>& A, int k) {

        // in hashmap we'll store the number of prefix arrays with a given remainder
        unordered_map<int, int> hashmap;
        int sum = 0;
        int count = 0;

        // prefix array with remainder 0(if nums[0] is divisible by k, for that case)
        hashmap[0] = 1;
        for(int i=0; i<A.size(); i++){

            sum+=A[i];

            // remainders must be positive framework
            int r3 = sum%k;
            if(r3<0)
                r3+=k;

            if(hashmap.find(r3)!=hashmap.end())
                count+=hashmap[r3];


//             int r3 = sum%k;

//             r3-r2 ==0 when r2 is r3, r3-k or k+r3

//             if(hashmap.find(r3)!=hashmap.end())
//                 count+=hashmap[r3];

//             if(hashmap.find(r3-k)!=hashmap.end())
//                 count+=hashmap[r3-k];

//             if(hashmap.find(k+r3)!=hashmap.end())
//                 count+=hashmap[k+r3];

            hashmap[r3]++;

        }

        return count;

    }
};
