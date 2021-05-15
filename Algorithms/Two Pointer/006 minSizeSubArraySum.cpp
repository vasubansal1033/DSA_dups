#include<bits/stdc++.h>
using namespace std;

int ans(vector<int>& nums, int s){

    if(nums.size()<=0)
        return 0;

    int i(0), j(0);
    // initialize sum with first element
    int sum = nums[0];
    int res = INT_MAX;

    while(true){

        if(sum<s && j<nums.size()-1){
            sum+=nums[++j];
        }else if(sum>=s && i<nums.size()){
            res = min(res, j-i+1);
            sum-=nums[i++];
        }else{
            // will reach here if either index is out of bounds
            break;
        }
        // incase there's an element >= to s
        // i will cross j when at that element
        if(i>j){
            return 1;
        }

    }

    return res==INT_MAX?0:res;

}
int main(){

    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    int s; cin>>s;
    cout<<ans(v, s);

return 0;
}
