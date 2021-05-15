#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)
int ans(vector<int>& v){

    int n = v.size();

    if(n==1)
        return 0;
    int start(0), last(n-1);

    while(start<=last){
        // check if current array is sorted or not
        if(v[start]<v[last]){
            return start;
        }
        int mid = start+(last-start)/2;
        // check if the current array is sorted in descending order
        if(v[start]>=v[mid] && v[mid]>=v[last]){
            return last;
        }
        // Used slack equality as mid might get equal to start or end
        // check pivot property
        if(v[mid]<v[(mid-1)%n] && v[mid]<=v[(mid+1)%n]){
            return mid;
        }else if(v[mid]<=v[last]){
            last = mid;
        }else if(v[start]<=v[mid]){
            start = (mid+1)%n;
        }

    }
    return -1;

}

int search_(vector<int>& nums, int target) {



    int rotCount = ans(nums);// start==last==mid when we find minimum

    // usual binary search
    int start(0), last(nums.size()-1);
    while(start<=last){
        // calculate the real mid which would be in the actual sorted array
        int mid = start+(last-start)/2;
        int realMid = (mid+rotCount)%(nums.size());
        if(nums[realMid]==target){
            return realMid;
        }
        else if(nums[realMid]>=target){
            last = mid-1;
        }else{
            start = mid+1;
        }
    }

    return -1;

}

int main(){

    int t; cin>>t;
    loop(i, t){
        int n, k; cin>>n>>k;
        vector<int> v(n);
        loop(j, n){
            cin>>v[j];
        }
        cout<<search_(v, k)<<endl;
    }

}
