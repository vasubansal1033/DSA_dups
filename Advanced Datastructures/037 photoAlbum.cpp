#include<bits/stdc++.h>
using namespace std;

int* BIT;

void update(int i, int val, int sz){
    i++;
    for(; i<=sz; i+=i&-i)
        BIT[i]+=val;

}
int getSum(int i){
    i++;
    int sum = 0;
    for(; i>0; i-=i&-i){
        sum+=BIT[i];
    }
    return sum;

}

// insert at ith zero from end
// then reverse of this array will be the answer

void util(vector<int>& indices, vector<int>& res){

    BIT = new int[indices.size()+1];
    memset(BIT, 0, sizeof(int)*(indices.size()+1));

    for(int i=indices.size()-1; i>=0; i--){

        int num = i; // the number to be inserted

        int idx = indices[i]; // the index where this element has to be inserted
        // Now we have to find idx+1 th zero from right

        int lo = 0, hi = indices.size()-1;
        int zeroIndex = idx+1;
        while(lo<hi){

            int mid = lo+(hi-lo+1)/2;
            int numOnesOnRight = getSum(hi)-getSum(mid-1);
            int numZerosOnRight = hi-mid+1-numOnesOnRight;

            if(numZerosOnRight>=zeroIndex){
                lo = mid;
            }else{
                hi = mid-1;
                zeroIndex-=numZerosOnRight;
            }
        }
        res[lo] = num;
        update(lo, 1, indices.size());

    }

    reverse(res.begin(), res.end());
}
int main(){

//    int n; cin>>n;
//    vector<int> v(n);
//    for(int i=0; i<n; i++) cin>>v[i];

    vector<int> v = {0,1,1,0,3,3};
    vector<int> res(v.size());
    util(v, res);

    for(int i=0; i<res.size(); i++) cout<<res[i]<<" ";


return 0;
}
