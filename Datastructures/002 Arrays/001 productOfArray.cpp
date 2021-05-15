#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/product-of-array-except-self/

vector<int> productExceptSelf(vector<int>& nums) {

    vector<int> output(nums.size());

    int prodSoFar = 1;
    for(int i=0; i<nums.size(); i++){
        output[i] = prodSoFar;
        prodSoFar*= nums[i];
    }
    // 1 1 2 6
    prodSoFar = 1;
    for(int i=nums.size()-1; i>=0; i--){

        output[i]*=prodSoFar;
        prodSoFar*=nums[i];

    }

  return output;
}


int main(){

    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    v = productExceptSelf(v);
    for(auto i:v)
        cout<<i<<" ";

return 0;
}
