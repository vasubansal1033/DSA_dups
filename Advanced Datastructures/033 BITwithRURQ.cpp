#include<bits/stdc++.h>
using namespace std;

// basic BIT functions
void update(int* BIT, int i, int val, int sz){
    i++;
    for(; i<=sz; i+=i&-i){
        BIT[i] = val;
    }
}
int getSum(int* BIT, int i, int sz){
    i++;
    int sum = 0;
    for(; i>0; i-=i&-i){
        sum+=BIT[i];
    }
    return sum;
}
int query(int* BIT, int l, int r, int sz){
    return getSum(BIT, r, sz)-getSum(BIT, l-1, sz);
}

// range update functions
void rangeUpdate(int* BIT1, int* BIT2, int l, int r, int val, int sz){

    // update BIT1
    update(BIT1, l, val, sz);
    update(BIT1, r+1, -val, sz);

    // update BIT2
    update(BIT2, l, val*(l-1), sz);
    update(BIT2, r+1, -val*r, sz);

}
int getSum2(int* BIT1, int* BIT2, int i, int sz){
    return getSum(BIT1, i, sz)*i - getSum(BIT2, i, sz);
}
int rangeSum(int* BIT1, int* BIT2, int l, int r, int sz){
    return getSum2(BIT1, BIT2, r, sz)-getSum2(BIT1, BIT2, l-1, sz);
}

int* constructBIT(int n){
    int* temp = new int[n+1];
    memset(temp, 0, sizeof(int)*(n+1));

    return temp;
}
int main(){

    int n; cin>>n;
//    vector<int> v(n);
//    for(int i=0; i<n; i++) cin>>v[i];

    int* BIT1 = constructBIT(n);
    int* BIT2 = constructBIT(n);

//    rangeUpdate(BIT1, BIT2, 0, 5, 99, n);
    rangeUpdate(BIT1, BIT2, 3, 6, 999, n);

    cout<<rangeSum(BIT1, BIT2, 5, 6, n);

}
