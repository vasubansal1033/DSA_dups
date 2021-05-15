// O(N) with space optimization
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {

        if(nums.size()==0) return nums.size();



        int prevIncrease = 1, prevDecrease = 1;
        int increase = 1, decrease = 1;
        for(int i=1; i<nums.size(); i++){

            if(nums[i]>nums[i-1]){
                increase = max(increase, prevDecrease+1);
                decrease = prevDecrease;
                prevIncrease = increase;
            }else if(nums[i]<nums[i-1]){

                decrease = max(decrease, prevIncrease+1);
                increase = prevIncrease;
                prevDecrease = decrease;
            }else{
                decrease = prevDecrease;
                increase = prevIncrease;
            }

        }

        return max(increase, decrease);


    }
};



// O(N) solution
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {

        if(nums.size()==0) return nums.size();

        vector<int> increase(nums.size(), 0); // increase stores the longest wiggle subsequence "upto" index i with the last two elements increasing

        vector<int> decrease(nums.size(), 0); // decrease stores the longest wiggle subsequence "upto" index i with the last two elements decreasing

        increase[0] = decrease[0] = 1;
        for(int i=1; i<nums.size(); i++){

            if(nums[i]>nums[i-1]){
                increase[i] = max(increase[i], decrease[i-1]+1);
                decrease[i] = decrease[i-1];
            }else if(nums[i]<nums[i-1]){

                decrease[i] = max(decrease[i], increase[i-1]+1);
                increase[i] = increase[i-1];
            }else{
                decrease[i] = decrease[i-1];
                increase[i] = increase[i-1];
            }

        }

        return max(increase[nums.size()-1], decrease[nums.size()-1]);


    }
};



// O(N2)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {

        if(nums.size()==0) return 0;

        vector<int> increase(nums.size(), 0);
        vector<int> decrease(nums.size(), 0);

        increase[0] = decrease[0] = 1;
        int res = 1;
        for(int i=1; i<nums.size(); i++){

            for(int k=i-1; k>=0; k--){

                if(nums[i]>nums[k]){
                    increase[i] = max(increase[i], decrease[k]+1);
                }else if(nums[i]<nums[k]){
                    decrease[i] = max(decrease[i], 1+increase[k]);
                }

            }

            res = max({res, increase[i], decrease[i]});

        }

        return res;


    }
};
