#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {

    int i = nums.size()-2; // start from second last index
    int j = nums.size()-1; // index which we want to reach

    while(i>=0){

        // condition for checking if we can reach j from i
        if(i+nums[i]>=j){
            j = i; // if we can reach, then we want to reach i . So update j

        }
        i--; // decrement i


    }

    return j==0; // if at the end, we reach at 0, means we can reach the last element from 0

}

int main(){

    int n; cin>>n; vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    cout<<canJump(v);

return 0;
}
