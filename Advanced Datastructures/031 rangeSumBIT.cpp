// Here update query is to change the value to val
// in last, we had to add val the already placed value
class NumArray {
public:

    int* BIT;
    int sz;

    int getSum(int i){

        int sum = 0;
        for(; i>0; i-=i&-i) sum+=BIT[i];

        return sum;
    }
    NumArray(vector<int>& nums) {

        BIT = new int[nums.size()+1];
        memset(BIT, 0, sizeof(int)*(nums.size()+1));
        sz = nums.size();

        for(int i=0; i<nums.size(); i++) update(i, nums[i]);

    }

    void update(int i, int val) {

        i++; // BITs are 1 indexed
        val -= getSum(i)-getSum(i-1);
        for(; i<=sz; i+=i&-i) BIT[i] += val;

    }

    int sumRange(int i, int j) {
        return getSum(j+1)-getSum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
