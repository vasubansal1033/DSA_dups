// This code is for Segment Tree with Range Updates and Range Query
// Uses Lazy propagation

#include<bits/stdc++.h>
using namespace std;

class segmentTree{
public:
    vector<int> sTree;
    vector<int> lazyTree;
    vector<int>* ptr;

    void buildSegmentTree(int st, int last, int treeNode){

        if(st==last){
            sTree[treeNode] = (*ptr)[st];
            return;
        }
        int mid = st+(last-st)/2;
        buildSegmentTree(st, mid, treeNode*2);
        buildSegmentTree(mid+1, last, treeNode*2+1);

        sTree[treeNode] = sTree[treeNode*2]+sTree[treeNode*2+1];

    }
    void updateSegmentTree(int st, int last, int treeNode, int left, int right, int val){

        // if lazyTree node has non-zero value, means there are pending updates
        if(lazyTree[treeNode]){
            sTree[treeNode] += (last-st+1)*lazyTree[treeNode];

            // if not leaf node, then update for updates in lazy tree
            if(st!=last){
                lazyTree[treeNode*2] += lazyTree[treeNode];
                lazyTree[treeNode*2+1] += lazyTree[treeNode];
            }
            // reset as we have updated for treeNode
            lazyTree[treeNode] = 0;
        }

        if(st>right || last<left) return;
        if(st>=left && last<=right){

            sTree[treeNode] += (last-st+1)*val;

            // if not leaf node, then update for updates in lazy tree
            if(st!=last){
                lazyTree[treeNode*2] += val;
                lazyTree[treeNode*2+1] += val;
            }
            return;
        }

        int mid = st+(last-st)/2;
        updateSegmentTree(st, mid, treeNode*2, left, right, val);
        updateSegmentTree(mid+1, last, treeNode*2+1, left, right, val);

        sTree[treeNode] = sTree[treeNode*2]+sTree[treeNode*2+1];

    }
    int querySegmentTree(int st, int last, int treeNode, int left, int right){

        if(st>right || last<left) return 0;

        if(lazyTree[treeNode]){

            sTree[treeNode] += (last-st+1)*lazyTree[treeNode];
            if(st!=last){
                lazyTree[treeNode*2] += lazyTree[treeNode];
                lazyTree[treeNode*2+1] += lazyTree[treeNode];
            }
            lazyTree[treeNode] = 0;

        }

        if(st>=left && last<=right) return sTree[treeNode];

        int mid = st+(last-st)/2;
        return querySegmentTree(st, mid, treeNode*2, left, right)+querySegmentTree(mid+1, last, treeNode*2+1, left, right);

    }

    // constructor
    segmentTree(vector<int> v){
        ptr = &v;
        sTree.resize(v.size()*4);
        lazyTree.resize(v.size()*4);

        buildSegmentTree(0, v.size()-1, 1);
    }
    void update(int left, int right, int val){
        updateSegmentTree(0, (*ptr).size()-1, 1, left, right, val);
    }
    int query(int left, int right){
        querySegmentTree(0, (*ptr).size()-1, 1, left, right);
    }
    void display(){
        return;
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
    seg.update(0,5,-7);
    cout<<seg.query(0, 5)<<'\n';


return 0;
}
