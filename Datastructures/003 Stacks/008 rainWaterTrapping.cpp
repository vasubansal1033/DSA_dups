#include<bits/stdc++.h>
using namespace std;

int ans(vector<int> v){

    int n = v.size();
    vector<int> maxLeft(n), maxRight(n);
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){

        if(v[i]>maxi)
            maxi = v[i];
        maxLeft[i] = maxi;
    }
    maxi = INT_MIN;
    for(int i=n-1; i>=0; i--){

        if(v[i]>maxi)
            maxi = v[i];
        maxRight[i] = maxi;
    }
    for(int i=0; i<n; i++){
        v[i] = min(maxLeft[i], maxRight[i])-v[i];
    }

    return accumulate(v.begin(), v.end(), 0);

}
int main(){

    int t; cin>>t;
    for(int i=0; i<t; i++){

        int n; cin>>n; vector<int> v(n);
        for(int j=0; j<n; j++)
            cin>>v[j];
        cout<<ans(v)<<endl;

    }

return 0;
}
