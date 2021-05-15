// sparse table for range sum

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int sparseTable[N][20];
int n;
vector<int> v;

void buildSparseTable(){

    for(int i=0; i<n; i++) sparseTable[i][0] = v[i];

    for(int j=1; j<20; j++){
        for(int i=0; i+(1<<j)<=n; i++){
            sparseTable[i][j] = sparseTable[i][j-1]+sparseTable[i+(1<<(j-1))][j-1];
        }
    }

}
int query(int l, int r){

    int sum = 0;
    for(int j=19; j>=0; j--){
        if((1<<j)<=r-l+1){
            sum += sparseTable[l][j];
            l+=(1<<j);
        }
    }
    return sum;
}

int main(){

    cin>>n;
    v.resize(n);
    for(int i=0; i<n; i++) cin>>v[i];
    buildSparseTable();

    cout<<query(2, 2);

return 0;
}
