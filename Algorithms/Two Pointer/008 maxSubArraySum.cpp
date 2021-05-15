// This is also known as Kadane's algorithm
// We maintain a current sum and maximum sum which gets updated at the end of every iteration
// currSum -> Should we include the current number or should we start new from this

#include<bits/stdc++.h>
using namespace std;


int maxSubArray(vector<int>& nums){

    if(nums.size()<=0)
        return 0;

    int i=0;
    int currSum = nums[0];
    int maxSum = nums[0];
    i++;

    while(i<nums.size()){

        if(currSum+nums[i]>nums[i]){
            currSum+=nums[i];
            i++;
        }else{
            currSum = nums[i];
            i++;
        }

        maxSum = max(maxSum, currSum);

    }

    return maxSum;

}
int main(){

    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    cout<<maxSubArray(v);


return 0;
}
