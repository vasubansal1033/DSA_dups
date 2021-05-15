// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {

    int i(0), j(numbers.size()-1);

    while(i<j){

        if(numbers[i]+numbers[j]==target)
            return {i+1, j+1};
        if(numbers[i]+numbers[j]<target)
            i++;
        else if(numbers[i]+numbers[j]>target)
            j--;

    }


    return {i+1, j+1};

}

int main(){

    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    int target; cin>>target;

    vector<int> ans = twoSum(v, target);
    for(int i:ans)
        cout<<i<<" ";


return 0;
}
