#include<bits/stdc++.h>
using namespace std;

// sparse table for idempotent functions
// like minimum, maximum, gcd, or, and etc.

int n;
vector<int> v;
const int N = 1e5;
int sparseTable[N][20];
int log_[N]; // log_[i] = log2(i)

void buildSparseTable(){

    for(int i=0; i<n; i++) sparseTable[i][0] = v[i];

    for(int j=1; j<20; j++){
        for(int i=0; i+(1<<j)<=n; i++){
            sparseTable[i][j] = min(sparseTable[i][j-1], sparseTable[i+(1<<(j-1))][j-1]);
        }
    }

}
int query(int l, int r){
    int j = log_[r-l+1];
    int res = min(sparseTable[l][j], sparseTable[r-(1<<j)+1][j]);
    return res;
}
int main(){

    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++) cin>>v[i];

    // precompute log_ values for O(1) queries
    log_[1] = 0;
    for(int i=2; i<=n; i++) log_[i] = log_[i/2]+1;
    buildSparseTable();

    cout<<query(3, 5);


return 0;
}
