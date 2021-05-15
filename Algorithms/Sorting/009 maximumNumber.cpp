// https://leetcode.com/problems/largest-number/

#include<bits/stdc++.h>
using namespace std;

bool myComparator(int m, int n){

    string str1 = to_string(m).append(to_string(n));
    string str2 = to_string(n).append(to_string(m));


    return str1>str2;

}

string largestNumber(vector<int>& nums) {

    int max_ele = *max_element(nums.begin(), nums.end());
    if(max_ele==0)
        return to_string(0);

    sort(nums.begin(), nums.end(), myComparator);

    string str = "";
    for(auto i:nums)
        str.append(to_string(i));

    return str;
}

int main(){

    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    cout<<largestNumber(v);


return 0;
}
