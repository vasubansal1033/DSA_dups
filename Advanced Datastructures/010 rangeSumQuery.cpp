class NumArray {
public:
    vector<int> segmentTree;
    vector<int> nums;
    void buildSegmentTree(vector<int>& nums, vector<int>& segmentTree, int st, int end, int treeNode){

        // base case
        if(st==end){
            segmentTree[treeNode] = nums[st];
            return;
        }

        // recursion
        int mid = st+(end-st)/2;
        buildSegmentTree(nums, segmentTree, st, mid, 2*treeNode);
        buildSegmentTree(nums, segmentTree, mid+1, end, 2*treeNode+1);

        segmentTree[treeNode] = segmentTree[treeNode*2]+segmentTree[treeNode*2+1];

    }
    void updateSegmentTree(vector<int>& nums, vector<int>& segmentTree, int st, int end, int treeNode, int idx, int value){

        // base case
        if(st==end){
            nums[idx] = value;
            segmentTree[treeNode] = value;
            return;
        }

        // recursion
        int mid = st+(end-st)/2;
        if(idx>mid) updateSegmentTree(nums, segmentTree, mid+1, end, 2*treeNode+1, idx, value);
        else updateSegmentTree(nums, segmentTree, st, mid, 2*treeNode, idx, value);

        segmentTree[treeNode] = segmentTree[treeNode*2]+segmentTree[treeNode*2+1];

    }
    int query(vector<int>& segmentTree, int st, int end, int treeNode, int left, int right){

        // base case

        // recursion
        if(st>right || end<left) return 0;
        // interval is completely inside
        if(st>=left && end<=right) return segmentTree[treeNode];

        // partially inside
        int mid = st+(end-st)/2;
        int ans1 = query(segmentTree, st, mid, 2*treeNode, left, right);
        int ans2 = query(segmentTree, mid+1, end, 2*treeNode+1, left, right);

        return ans1+ans2;

    }
    NumArray(vector<int>& nums) {
        if(nums.size()==0) return;
        this->nums = nums;
        segmentTree.resize(4*nums.size());
        buildSegmentTree(nums, segmentTree, 0, nums.size()-1, 1);
    }

    void update(int i, int val) {
        updateSegmentTree(nums, segmentTree, 0, nums.size()-1, 1, i, val);
    }

    int sumRange(int i, int j) {
        return query(segmentTree, 0, nums.size()-1, 1, i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
