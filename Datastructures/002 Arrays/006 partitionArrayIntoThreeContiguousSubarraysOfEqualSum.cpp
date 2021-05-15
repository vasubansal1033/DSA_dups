#include<bits/stdc++.h>
using namespace std;

bool canThreePartsEqualSum(vector<int>& A) {

    int sum = accumulate(A.begin(), A.end(), 0);

    if(sum%3!=0 || A.size()<3)
        return false;

    int sum1 = 0, count=0;
    for(int i=0; i<A.size(); i++){

        sum1+=A[i];
        A[i] = sum1;

        if(sum1*3==sum){
            count++;
            sum1=0;
        }

    }
    return count>=3;


}

int main(){

    int n; cin>>n; vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    cout<<canThreePartsEqualSum(v);

}
