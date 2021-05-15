#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/container-with-most-water/
// different from rain-water trapping

// correctness
// at every step, we are finding the best possible answer for the minimum height
int maxArea(vector<int>& height) {

    int p1(0), p2(height.size()-1);

    int res = INT_MIN;
    while(p1<p2){

        int water = min(height[p1], height[p2])*(p2-p1);

        if(res<water)
            res = water;
        else
            if(height[p1]==min(height[p1], height[p2]))
                p1++;
            else
                p2--;


    }

    return res;

}

int main(){

    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    cout<<maxArea(v);

return 0;
}
