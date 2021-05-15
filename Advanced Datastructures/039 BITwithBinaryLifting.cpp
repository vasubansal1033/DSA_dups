#include<bits/stdc++.h>
using namespace std;

int* BIT;
int sz;

void update(int i, int val){
    i++;
    for(; i<=sz; i+=i&-i){
        BIT[i]+=val;
    }
}
int getSum(int i){
    int sum = 0;
    for(; i>0; i-=i&-i) sum+=BIT[i];
    return sum;
}
// lower_bound prefix sum. First index where prefix sum is >= val
int lowerBound(int val){

    int sum = 0, pos = 0;
    for(int i=log2(sz); i>=0; i--){
        if(pos+(1<<i)<=sz && sum+BIT[pos+(1<<i)]<val){
            sum+=BIT[pos+(1<<i)];
            pos+=(1<<i);
        }
    }

    return pos+1; // pos+1 because pos will have value less than val

}
int main(){

    //    int n; cin>>n;
//    vector<int> v(n);
//    for(int i=0; i<n; i++) cin>>v[i];

    vector<int> v = {1,0,2,1,1,3,0,4,2,5,2,2,3,1,0,2};
    sz = v.size();

    BIT = new int[v.size()+1];
    memset(BIT, 0, sizeof(int)*(v.size()+1));

    for(int i=0; i<v.size(); i++) update(i, v[i]);

    cout<<lowerBound(27)<<" "<<getSum(lowerBound(27));

return 0;
}
