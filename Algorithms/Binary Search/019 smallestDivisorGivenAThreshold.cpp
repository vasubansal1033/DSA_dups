#include<bits/stdc++.h>
using namespace std;


int divSum(vector<int>& nums, int div){

    int sum = 0;
    for(int i=0; i<nums.size(); i++){
        sum+=ceil((nums[i]*1.0/div));
    }

    return sum;


}
int smallestDivisor(vector<int>& nums, int threshold) {

    int lo = 1;
    int hi = INT_MIN;

    // hi is the maximum element
    for(int i=0; i<nums.size(); i++){
        if(nums[i]>hi)
            hi = nums[i];
    }

    while(lo<hi){

        int mid = lo+(hi-lo)/2;


        if(divSum(nums, mid)<=threshold){
            hi = mid;
        }else{
            lo = mid+1;
        }
        cout<<lo<<" "<<mid<<" "<<hi<<endl;

    }


    return lo;

}


int main(){

    int n, threshold; cin>>n>>threshold; vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    cout<<smallestDivisor(v, threshold);

}
