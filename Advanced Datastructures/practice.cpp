#include<bits/stdc++.h>
using namespace std;

void update(int* BIT, int i, int val, int sz){
    i++;
    for(; i<=sz; i+=(i&(-i))){
        BIT[i]+=val;
    }
}
int getSum(int* BIT, int i){
    i++;
    int sum = 0;
    for(; i>0; i-=i&(-i)){
        sum+=BIT[i];
    }
    return sum;
}
int lb(int* BIT, int val, int sz){
    int sum = 0, pos = 0;
    for(int i=19; i>=0; i--){
        if(pos+(1<<i)<=sz && sum+BIT[pos+(1<<i)]<val){
            sum+=BIT[pos+(1<<i)];
            pos+=(1<<i);
        }
    }
    return pos+1;
}
int main(){

    vector<int> v = {1,0,2,1,1,3,0,4,2,5,2,2,3,1,0,2};
    int sz = v.size();

    int* BIT = new int[sz+1];
    memset(BIT, 0, sizeof(int)*(sz+1));
    for(int i=0; i<sz; i++) update(BIT, i, v[i], sz);

    cout<<lb(BIT, 27, sz)<<" "<<getSum(BIT, lb(BIT, 27, sz));
}
