#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {


    int i(0), j(0);

    // i points to non-zero
    // j points to zero
    int n = nums.size();

    while(i<n && j<n){

        while(nums[i]==0){
            i++;
            if(i>=n)
                break;
        }
        if(i>=n)
            break;

        while(nums[j]!=0){
            j++;
            if(j>=n)
                break;
        }
        if(j>=n)
            break;

        if(j<i)
            swap(nums[i], nums[j]);

        i++;

    }

}


int main(){

    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    moveZeroes(v);
    for(auto i:v)
        cout<<i<<" ";

return 0;
}
