#include<bits/stdc++.h>
using namespace std;
#define loop(i, n) for(int i=0; i<n; i++)

// 1 2 3 4 5
int miniAns(vector<int>& v, int start, int last){

    if(start==last){
        return v[start];
    }
    if(last-start==1){
        return min(v[start], v[last]);
    }
    int mid = start+(last-start)/2;
    return min(miniAns(v, start, mid),
               miniAns(v, mid+1, last));

}
int mini(vector<int>& v){
    // Subproblem - Divide into halves. Find minimum of both and minimum of these is the answer
    return miniAns(v, 0, v.size()-1);
}
int maxiAns(vector<int>& v, int start, int last){

    if(start==last){
        return v[start];
    }
    if(last-start==1){
        return max(v[start], v[last]);
    }
    int mid = start+(last-start)/2;
    return max(maxiAns(v, start, mid),
               maxiAns(v, mid+1, last));

}
int maxi(vector<int>& v){
    return maxiAns(v, 0, v.size()-1);
}

int main(){

    int n; cin>>n;
    vector<int> v(n);
    loop(i, n){
        cin>>v[i];
    }
    cout<<mini(v)<<" "<<maxi(v)<<endl;

}
