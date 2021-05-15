class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int a; // stores maximum product subarray ending at i
        int b; // stores minimum product subarray ending at i

        a = b = nums[0];
        int res = nums[0];

        for(int i=1; i<nums.size(); i++){

            int temp1 = a; int temp2 = b;
            a = max({temp1*nums[i], temp2*nums[i], nums[i]});
            b = min({temp1*nums[i], temp2*nums[i], nums[i]});

            res = max(res, a);
        }

        return res;
    }
};


class Solution {
public:
    int maxProduct(vector<int>& nums) {

        vector<int> dp1(nums.size(), 0); // stores maximum product subarray ending at i
        vector<int> dp2(nums.size(), 0); // stores minimum product subarray ending at i

        dp1[0] = dp2[0] = nums[0];
        int res = nums[0];

        for(int i=1; i<nums.size(); i++){

            dp1[i] = max({dp1[i-1]*nums[i], dp2[i-1]*nums[i], nums[i]});
            dp2[i] = min({dp1[i-1]*nums[i], dp2[i-1]*nums[i], nums[i]});

            res = max(res, dp1[i]);
        }

        return res;
    }
};
