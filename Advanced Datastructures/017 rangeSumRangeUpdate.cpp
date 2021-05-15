#include<bits/stdc++.h>
using namespace std;

class segmentTree{
public:
    vector<int> nums;
    vector<int> sTree;
    vector<int> lTree;

    void buildSegmentTree(int start, int last, int treeNode){
        if(start==last){
            sTree[treeNode] = nums[start];
            return;
        }
        int mid = start+(last-start)/2;
        buildSegmentTree(start, mid, treeNode*2);
        buildSegmentTree(mid+1, last, treeNode*2+1);

        sTree[treeNode] = sTree[treeNode*2]+sTree[treeNode*2+1];
        return;
    }
    void updateSegmentTree(int start, int last, int treeNode, int l, int r, int val){
        if(lTree[treeNode]){
            sTree[treeNode] += (last-start+1)*(lTree[treeNode]);
            if(start!=last){
                lTree[treeNode*2+1] += lTree[treeNode];
                lTree[treeNode*2] += lTree[treeNode];
            }
            lTree[treeNode] = 0;

        }
        if(start>r || last<l) return;
        if(start>=l && last<=r){
            sTree[treeNode] += (last-start+1)*val;
            if(start!=last){
                lTree[treeNode*2] += val;
                lTree[treeNode*2+1] += val;
            }
            //lTree[treeNode] = 0;

            return;
        }

        int mid = start+(last-start)/2;
        updateSegmentTree(start, mid, treeNode*2, l, r, val);
        updateSegmentTree(mid+1, last, treeNode*2+1, l, r, val);

        sTree[treeNode] = sTree[treeNode*2]+sTree[treeNode*2+1];
    }
    int querySegmentTree(int start, int last, int treeNode, int l, int r){
        if(start>r || last<l) return 0;
        if(lTree[treeNode]){
            sTree[treeNode] += (last-start+1)*lTree[treeNode];
            if(start!=last){
                lTree[treeNode*2] += lTree[treeNode];
                lTree[treeNode*2+1] += lTree[treeNode];
            }
            lTree[treeNode] = 0;

        }

        if(start>=l && last<=r) return sTree[treeNode];

        int mid = start+(last-start)/2;
        return querySegmentTree(start, mid, treeNode*2, l, r)+querySegmentTree(mid+1, last, treeNode*2+1, l, r);

    }
    segmentTree(vector<int>& nums){
        this->nums = nums;
        sTree.resize(nums.size()*4);
        lTree.resize(nums.size()*4);

        buildSegmentTree(0, nums.size()-1, 1);

    }
    void update(int left, int right, int val){
        updateSegmentTree(0, nums.size()-1, 1, left, right, val);
    }
    int query(int left, int right){
        return querySegmentTree(0, nums.size()-1, 1, left, right);
    }


};
int main(){

    vector<int> v = {0,0,0,0,0,0};

    segmentTree seg(v);
    seg.update(2,5,1);
    seg.update(4,5,12);
    cout<<seg.query(0, 5)<<'\n';
    seg.update(1,1,0);
    cout<<seg.query(0, 5)<<'\n';
    seg.update(0,5,0);
    cout<<seg.query(0, 5)<<'\n';

return 0;
}
