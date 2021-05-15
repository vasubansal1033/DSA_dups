class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n ? nums[0] : 0;
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }
private:
    int robber(vector<int>& nums, int l, int r) {
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};



class Solution {
public:

    int rob2(vector<int>& nums) {

        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];

        int a = 0;
        int b = nums[nums.size()-1];
        int ans;
        for(int i=nums.size()-2; i>=0; i--){
            ans = max(nums[i]+a, b);

            a = b;
            b = ans;

        }

        return ans;

    }
    int rob(vector<int>& nums) {

        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];

        vector<int> temp(nums.begin(), nums.end()-1);
        int ans1 = rob2(temp);
        vector<int> temp2(nums.begin()+1, nums.end());
        int ans2 = rob2(temp2);

        return max(ans1, ans2);


    }
};
