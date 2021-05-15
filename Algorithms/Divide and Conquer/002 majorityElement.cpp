#include<bits/stdc++.h>
using namespace std;

// This function returns the count of k from index start to last
int getFrequency(vector<int>& v, int start, int last, int k){
    int c = 0;
    for(int i = start; i<=last; i++){
        if(v[i]==k)
            c++;
    }
    return c;
}
// Majority element from start to last index
int majority(vector<int>& v, int start, int last){

    // Incase of single element, return that
    if(start==last){
        return v[start];
    }
    // Incase of two elements, if they're same return any one, else return INT_MAX
    if(last-start==1){
        return v[start]==v[last]?v[start]:INT_MIN;
    }

    int mid = start+(last-start)/2;
    int a = majority(v, start, mid); // Calculate majority element in left side
    int b = majority(v, mid+1, last); // Calculate majority element in right side

    // If one side has distinct elements and other side has a majority element that will be the overall answer
    if(a==INT_MIN){
        return b;
    }else if(b==INT_MIN){
        return a;
    }else if(a==b){ // Both side have same majority element
        return a;
    }
    // Finally, if we get different majority elements, we count for each in left and right array
    if(getFrequency(v, start, mid, a)>getFrequency(v, mid+1, last, b))
        return a;
    else return b;

}
int majorityElement(vector<int>& nums) {
    return majority(nums, 0, nums.size()-1);
}
int main(){

    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    cout<<ans(v)<<endl;

return 0;
}
