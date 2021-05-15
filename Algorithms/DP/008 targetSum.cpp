#include<bits/stdc++.h>
using namespace std;
// same as subset difference problem

int ans(vector<int> nums, int S){


    int sum = (accumulate(nums.begin(), nums.end(), 0));

    if(S>sum)
        return 0;
    sum+=S;

    if(sum%2!=0)
        return 0;

    sum = sum/2;
    int n = nums.size();
    int arr[n+1][sum+1];

    /*
    For all those stuck with the test case where in ZEROS are involved, for example in the LeetCode Problem.
    The reason is that when zeros are involved in the array the INITIALISATION part of the code changes a bit.
    For Example: When the given input is arr=[0,0,0,0,1] the 0th column in the t[n+1][sum+1] matrix will no
    longer be filled with 1's. The reason is that whenever a particular element in the array arr[i] is encountered
    to be 0, the number of subsets in that array(till length i) which would give sum =0 would no longer be 1,
    as now in addition to the empty subset we also have a subset {0} which would give subset sum=0.
    */

    arr[0][0] = 1;
    for(int i=1; i<=n; i++){
        if(nums[i-1]==0){
            arr[i][0] = 2*arr[i-1][0]; // arr[0][0] is one for empty subset. if zero is encounter then we can have empty set or 0 which will give sum equal to 0
        }else{
            arr[i][0] = arr[i-1][0]; // else the number will remain same
        }
    }
    for(int i=1; i<=sum; i++)
        arr[0][i] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(nums[i-1]<=j)
                arr[i][j] = arr[i-1][j-nums[i-1]]+arr[i-1][j];
            else
                arr[i][j] = arr[i-1][j];
        }
    }
    return arr[n][sum];
}

int main(){

    int n, S; cin>>n>>S;
    vector<int> nums(n, 0);
    for(int i=0; i<n; i++)
        cin>>nums[i];
    cout<<ans(nums, S);


return 0;
}

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {

        // Equivalent to subset sum
        // Zero is allowed. So number of 0 subsets is not just by empty subset. Can be more than 1
        // S1+S2 = sum and S2-S1 = target
        // S2 = (sum+target)/2

        int sum = accumulate(nums.begin(), nums.end(), 0);

        // since we have only non negative integers, subset sum cannot exceed total sum
        if(sum<S) return 0;

        sum += S;

        if(sum%2!=0) return 0;

        sum = sum/2;

        int dp[nums.size()+1][sum+1];

        dp[0][0] = 1;
        // number of 0 sum subsets
        for(int i=1; i<nums.size()+1; i++){
            dp[i][0] = (nums[i-1]==0)?(2*dp[i-1][0]):dp[i-1][0];
        }
        // ways to get sum 1 to sum from empty subset
        for(int j=1; j<sum+1; j++){
            dp[0][j] = 0;
        }

        for(int i=1; i<nums.size()+1; i++){

            for(int j=1; j<=sum; j++){

                if(j-nums[i-1]>=0)
                    dp[i][j] = dp[i-1][j-nums[i-1]]+dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];

            }

        }

        return dp[nums.size()][sum];


    }
};

// Space optimized solution

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {

        // Equivalent to subset sum
        // Zero is allowed. So number of 0 subsets is not just by empty subset. Can be more than 1
        // S1+S2 = sum and S2-S1 = target
        // S2 = (sum+target)/2

        int sum = accumulate(nums.begin(), nums.end(), 0);

        // since we have only non negative integers, subset sum cannot exceed total sum
        if(sum<S) return 0;

        sum += S;

        if(sum%2!=0) return 0;

        sum = sum/2;

        int dp[2][sum+1];

        dp[0][0] = 1;

        // // number of 0 sum subsets
        // for(int i=1; i<nums.size()+1; i++){
        //     dp[i][0] = (nums[i-1]==0)?(2*dp[i-1][0]):dp[i-1][0];
        // }
        // ways to get sum 1 to sum from empty subset
        for(int j=1; j<sum+1; j++){
            dp[0][j] = 0;
        }

        for(int i=1; i<nums.size()+1; i++){

            dp[i%2][0] = (nums[i-1]==0)?(2*dp[(i-1)%2][0]):dp[(i-1)%2][0];
            for(int j=1; j<=sum; j++){

                if(j-nums[i-1]>=0)
                    dp[i%2][j] = dp[(i-1)%2][j-nums[i-1]]+dp[(i-1)%2][j];
                else
                    dp[i%2][j] = dp[(i-1)%2][j];

            }

        }

        return dp[nums.size()%2][sum];


    }
};

class Solution {
public:
    int findTargetSumWays(vector<int> nums, int S){

        int sum = (accumulate(nums.begin(), nums.end(), 0));
        if(S>sum)
            return 0;

        // S1 + S2 = sum and S2-S1 = S
        // S+sum = 2*S2
        sum+=S;

        if(sum%2!=0)
            return 0;

        sum = sum/2;
        int n = nums.size();
        int arr[2][sum+1];

        arr[0][0] = 1;

        for(int i=1; i<=sum; i++)
            arr[0][i] = 0;

        for(int i=1; i<=n; i++){

            if(nums[i-1]==0){
                arr[i%2][0] = 2*arr[(i-1)%2][0];
            }else{
                arr[i%2][0] = arr[(i-1)%2][0];
            }

            for(int j=1; j<=sum; j++){
                if(nums[i-1]<=j)
                    arr[i%2][j] = arr[(i-1)%2][j-nums[i-1]]+arr[(i-1)%2][j];
                else
                    arr[i%2][j] = arr[(i-1)%2][j];
            }
        }
        return arr[n%2][sum];
    }

};

