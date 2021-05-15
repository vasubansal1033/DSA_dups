#include<bits/stdc++.h>
using namespace std;

void update(int* BIT, int i, int val, int sz){
    i++;
    for(; i<=sz; i+=(i&(-i))){
        BIT[i]+=val;
    }
}
int getPrefixSum(int* BIT, int i){
    i++;
    int sum = 0;
    for(; i>0; i-=(i&(-i))){
        sum+=BIT[i];
    }
    return sum;
}
int query(int* BIT, int l, int r){
    return getPrefixSum(BIT, r)-getPrefixSum(BIT, l-1);
}
int main(){

    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    int* BIT = new int[n+1];
    memset(BIT, 0, sizeof(int)*(n+1));
    for(int i=0; i<n; i++) update(BIT, i, v[i], n);
    cout<<query(BIT, 3, 4);


return 0;
}



#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int BIT[N];
int n;

int util(int i){
    i++;
    int sum = 0;
    for(; i>0; i-=i&(-i)){
        sum+=BIT[i];
    }
    return sum;

}
int getSum(int l, int r){
    return util(r)-util(l-1);
}
void update(int i, int x){
    i++;
    for(; i<=n; i+=i&(-i)){
        BIT[i]+=x;
    }

}
int main(){

    memset(BIT, 0, sizeof(BIT));

    cin>>n;
    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
        update(i, v[i]);
    }
    cout<<getSum(0, n-1);

}
