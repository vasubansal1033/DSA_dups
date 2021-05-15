#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>& v, int min1, int min2, int start){

    // base case
    if(start==(int)v.size()){
        return 0;
    }

    // check for lane1
    int ans1 = 0, ans2 = 0;
    if(v[start]<=min1){
        ans1 = max(ans1, 1+solve(v, v[start], min2, start+1));
    }else{
        ans1 = max(ans1, solve(v, min1, min2, start+1));
    }

    // check for lane2
    if(v[start]<=min2){
        ans2 = max(ans2, 1+solve(v, min1, v[start], start+1));
    }else{
        ans2 = max(ans2, solve(v, min1, min2, start+1));
    }

    return max(ans1, ans2);


}
void util(vector<int>& v){



}
int main(){

    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    cout<<solve(v, INT_MAX, INT_MAX, 0);


    return 0;
}
